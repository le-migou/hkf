#include "sprons92.hpp"
#include "hkf.hpp"
#include "calculisto/iapws/r6_inverse.hpp"
#include "calculisto/iapws/r8.hpp"
#include "born.hpp"

    using namespace calculisto::thermodynamics;
#include <vector>
#include <algorithm>
#include <ranges>
#include <numbers>
    using namespace std::literals;
#include <fmt/core.h>
    using fmt::println, fmt::print;
#include "format_strings.hpp"


    struct
component_t
{
        std::string
    name;
        double
    coefficient;
};

    struct
reaction_t
{
        std::string
    title;
        std::vector <component_t>
    minerals;
        std::vector <component_t>
    gases;
        std::vector <component_t>
    aqueous_species;
        double
    h2o;
};

    struct
run_t
{
        std::string
    filename_con;
        std::string
    filename_rxn;
        std::string
    filename_databse;
        std::string
    filename_tab;
        std::string
    filename_plt;
        int
      isat
    , iopt
    , iplot
    , univar
    , noinc
    ;
        std::string
    isovar;
        double
      isomin
    , isomax
    , isoinc
    ;
        std::string
    incv;
        double
      v2min
    , v2max
    , v2inc
    ;
        std::vector <reaction_t>
    reactions;
};

    const auto
skarn = run_t
{
      .filename_con = "skarn.con"
    , .filename_rxn = "skarn.rxn"
    , .filename_databse = "dprons92.dat"
    , .filename_tab = "skarn.tab"
    , .filename_plt = "skdef1.kxy"
    , .isat = 0
    , .iopt = 2
    , .iplot = 1
    , .univar = 0
    , .noinc = 0
    , .isovar = "BARS(bars)"
    , .isomin = 500
    , .isomax = 5000
    , .isoinc = 500
    , .incv = "TEMP(degC)"
    , .v2min = 0
    , .v2max = 1000
    , .v2inc = 100
    , .reactions = {
      {
          .title = "skarn reaction"
        , .minerals = {
                { "ANDRADITE",    -1. }
              , { "QUARTZ",        3. }
              , { "CALCITE",       3. }
              , { "CHALCOPYRITE",  2. }
          }
        , .gases = {
                { "CARBON-DIOXIDE", -3. }
          }
        , .aqueous_species = {
                { "H2S,aq", -4. }
              , { "Cu+",    -2. }
              , { "H+",      2. }
          }
          , .h2o = 3.
      }}
};

// Print values if they are valid (in the sense of supcrit, 999999 denotes an
// invalid value).
    auto
print_or_not (double value, std::string_view format, int width)
{
    if (value !=  999999.) print (fmt::runtime (format), value);
    print ("{}", std::string (width, ' '));
}

    namespace
calculisto::thermodynamics::hkf
{
// EOS for aqueous_species (eq. 45)
    constexpr auto
molar_volume (sprons92::aqueous_species_t const& data, double T, double P)
{
        const auto
    P_ = P + 2600; // bar
        const auto
    T_ = T - 228; // K
        const auto
    D = iapws::r6_inverse::density_pt (P * 1e5, T);
        const auto
    dDdP = 1 / iapws::r6::d_pressure_d_density_dt (D, T);
        const auto
    dEdD = iapws::r8::d_relative_permittivity_d_density_at_temperature_dt (D, T);
        const auto
    E = iapws::r8::relative_permittivity_dt (D, T);
        const auto
    Z = born::z (E);
        const auto
    Q = born::q (E, dDdP, dEdD);
        constexpr auto
    eta = 1.66027e5; // Å.cal.mol-1
    // This is eq. 56. The code adds a `gref` term here that doesn't appear in
    // the paper. The code is at react92d.f:838.
        const auto
    re_ref = Z * Z / (data.omega / eta + Z / 3.082);
        const auto
    g = D < 1e3 ? detail::g (T, D, P) : 0.;
        const auto
    dg_dp = D < 1e3 ? detail::dg_dp(T, D, P) : 0.;
        const auto
    r = re_ref + fabs (Z) * g;
        const auto
    omega = eta * (Z * Z / r - Z / (3.082 + g));
        const auto
    domegadp = eta * ( -fabs (pow (Z, 3)) / r / r + Z / pow (3.080 + g, 2)) 
        * dg_dp;
    
        const auto
    r_ = bar_cm3_per_calorie * (
          data.a_1 
        + data.a_2 / P_ 
        + data.a_3 / T_ 
        + data.a_4 / P_ / T_
        - omega * Q
        - (Z + 1) * domegadp
    );
    return r_;
}
// eq. 62
    constexpr auto
heat_capacity_isobaric (sprons92::aqueous_species_t const& data, double T, double P)
{
        const auto
    Psi = 2600.; // bar
        const auto
    Theta = 228.; // K
        const auto
    D = iapws::r6_inverse::density_pt (P * 1e5, T);
        const auto
    dDdT = iapws::r6::d_density_d_temperature_dt (D, T);
        const auto
    E = iapws::r8::relative_permittivity_dt (D, T);
        const auto
    dEdT = iapws::r8::d_relative_permittivity_d_temperature_at_density_dt (D, T);
        const auto
    dEdD = iapws::r8::d_relative_permittivity_d_density_at_temperature_dt (D, T);
        const auto
    d2EdT = iapws::r8::d_relative_permittivity_d2_temperature_at_pressure_dt(D, T, dDdT);
        const auto
    Z = born::z (E);
        const auto
    Y = born::y (E, dEdT, dEdD, dDdT);
        const auto
    X = born::x (E, d2EdT, Y);
        constexpr auto
    eta = 1.66027e5; // Å.cal.mol-1
    // This is eq. 56. The code adds a `gref` term here that doesn't appear in
    // the paper. The code is at react92d.f:838.
    // News flash: gref is in fact set to zero. 
        const auto
    re_ref = Z * Z / (data.omega / eta + Z / 3.082);
        const auto
    g = detail::g (D / iapws::molar_mass, T, P);
        const auto
    r = re_ref + fabs (Z) * g;
        const auto
    omega = eta * (Z * Z / r - Z / (3.082 + g));
        const auto
    dgdt = detail::dg_dt(T, D, P);
        const auto
    dgdtt = detail::dg_dtt(T, D, P);
    // The code does not consider the temperature dependency of Z when
    // differentiating omega, react92d.f:845.
        [[maybe_unused]]
        const auto
    domegadt = -eta * (fabs (pow (Z, 3)) / r / r - Z / pow (3.080 + g, 2)) 
        * dgdt
    ;
        const auto
    domegadtt = 
          2 * eta * (
            fabs ((pow (Z, 4)) / pow (r, 3) - Z / pow (3.080 + g, 3))
          ) * dgdt * dgdt 
        - eta * (
            fabs (pow (Z, 3)) / r / r - Z / pow (3.080 + g, 2)
        ) * dgdtt
    ;
    return 
          data.c_1 + data.c_2 / pow (T - Theta, 2) 
        - 2 * T / pow (T - Theta, 3) * (
            data.a_3 * (P - 1) + data.a_4 * log ((P + Psi) / (Psi + 1))
        ) 
        + omega * T * X 
        + 2 * T * Y * domegadt 
        + T * (Z + 1) * domegadtt
    ;
} 

    namespace
detail
{
    constexpr auto
Cp (auto T, auto a, auto b, auto c)
{
        const auto
    r = a + b * T + c / T / T;
    return r;
}
    constexpr auto
int_Cp_dT (auto T1, auto T2, auto a, auto b, auto c)
{
    return a * (T2 - T1) + b / 2 * (T2 * T2 - T1 * T1) - c * (1 / T2 - 1 / T1);
}
    constexpr auto
int_Cp_dlnT (auto T1, auto T2, auto a, auto b, auto c)
{
    return a * log (T2 / T1) + b * (T2 - T1) - c / 2 * (1 / T2 / T2 - 1 / T1 / T1);
}
} // namespace detail

// Thermodynamic properties of mineral and gases
// Eqs. 77-81
    auto
thermodynamic_properties (sprons92::mineral_t const& data, double T, double P)
{
        using std::min;
        auto
    Ta = T_ref;
        auto
    Tb = min (T, data.T[0]);
        auto
    V = data.V;
        auto
    S = 
          data.S 
        + detail::int_Cp_dlnT (Ta, Tb, data.a[0], data.b[0], data.c[0])
    ;
        auto
    int_V_dP = data.V * (P - P_ref) * calorie_per_bar_cm3;
        auto
    H = 
          data.DH 
        + detail::int_Cp_dT (Ta, Tb, data.a[0], data.b[0], data.c[0])
        + int_V_dP
    ;
        auto
    G = 
          data.DG
        + detail::int_Cp_dT (Ta, Tb, data.a[0], data.b[0], data.c[0])
        - detail::int_Cp_dlnT (Ta, Tb, data.a[0], data.b[0], data.c[0]) * T
        + int_V_dP
    ;
    // Phase transitions at T_t_i, P_t_i (phi_P), volume terms
    {
            int
        phase_index;
        for (phase_index = 0; phase_index <= data.max_phase_transition_count; ++phase_index)
        {
                const auto
            T_t_at_P_t = data.T[phase_index] + (P - P_ref) / (data.dP_dT[phase_index] == 0 ? 1. : data.dP_dT[phase_index]);
            if (T < T_t_at_P_t) break;
                const auto
            P_t_at_T_t = P_ref + (T - data.T[phase_index]) * data.dP_dT[phase_index];

            // WARNING: Paper-code inconsistency here
            // Paper: -sum_{P_{t_i,T}}^P
            // Code: sum_{P_{ref}}^{P_{t_i,T}}
            // Paper: eqs. 78, 79
            // Code: reac92d.f:409,419,420,425,426
                const auto
            int_V_dP_tran = data.DVt [1] * (P_t_at_T_t - P_ref) * calorie_per_bar_cm3;

            V += data.DVt[phase_index - 1];
            int_V_dP += int_V_dP_tran;
            H -= int_V_dP_tran;
            G -= int_V_dP_tran;
        }
    }
    // Phase transitions at T_t_i, P_r (phi_T), Cp terms
        int
    phase_index = 0;
    for (; phase_index <= data.max_phase_transition_count; ++phase_index)
    {
        if (T < data.T[phase_index]) break;
        Ta = Tb;
        Tb = min (T, data.T[phase_index]);
            const auto
        int_Cp_dT = detail::int_Cp_dT (Ta, Tb, data.a[phase_index], data.b[phase_index], data.c[phase_index]);
            const auto
        int_Cp_dlnT = detail::int_Cp_dlnT (Ta, Tb, data.a[phase_index], data.b[phase_index], data.c[phase_index]);
        H +=
                int_Cp_dT
            + data.DHt[phase_index-1]
        ;
        G +=
                int_Cp_dT
            - int_Cp_dlnT * T
            + data.DHt[phase_index-1] * (T / data.T[phase_index - 1] - 1)
        ;
    }
        const auto
    Cp = detail::Cp (
          T
        , data.a[phase_index]
        , data.b[phase_index]
        , data.c[phase_index]
    );
    if (data.name == "QUARTZ" || data.name == "COESITE")
    {
        H -= int_V_dP;
        G -= int_V_dP;
            constexpr auto
        VPrTra = 22.688e0;
            constexpr auto
        Vdiff = 2.047e0; 
            constexpr auto
        k = 38.5;
            constexpr auto 
        VPtTta = 0.23348e2;
            constexpr auto
        VPrTtb = 0.2372e2;
            constexpr auto
        Stran = 0.342;
            constexpr auto
        aa = 0.549824e3;
            constexpr auto
        ba = 0.65995;
            constexpr auto
        ca = -0.4973e-4;
            const auto
        Ttran = data.T[0];

            const auto
        phase = (T <= Ttran || P >= P_ref + k * (T - data.T[0])) ? 1 : 2;
            const auto
        [ P_star, S_star ] = [&]()
        {
            if (T <= data.T[0])
            {
                return std::tuple { P_ref, 0. };
            }
            if (phase == 2)
            {
                return std::tuple { P, 0. };
            }
            return std::tuple { P_ref + k * (T - Ttran), Stran };
        }();
        V = (phase == 2) ? VPrTtb : (
            VPrTra 
            + ca * (P - P_ref) 
            + (VPtTta - VPrTra - ca * (P - P_ref)) * (T - T_ref) 
                /
            (Ttran + (P - P_ref) / k - T_ref)
        );
            const auto
        GVterm = [&]()
        {
            if (data.name == "COESITE") 
            {
                V -= Vdiff;
                return calorie_per_bar_cm3 * (
                    (VPrTra - Vdiff) * (P - P_star) 
                    + (VPrTtb - Vdiff) * (P_star - P_ref) 
                    - 0.5 * ca * (2 * P_ref * (P - P_star) 
                    - (P * P - P_star * P_star)) 
                    - ca * k * (T - T_ref) * (P - P_star) 
                    + k * (ba + aa * ca * k) * (T - T_ref) 
                        * log ((aa + P / k) / (aa + P_star / k))
                );
            }
            return calorie_per_bar_cm3 * (
                VPrTra * (P - P_star) 
                + VPrTtb * (P_star - P_ref) 
                - 0.5 * ca * (2 * P_ref * (P - P_star) - (P * P - P_star * P_star))
                - ca * k * (T - T_ref) * (P - P_star) 
                + k * (ba + aa * ca * k) * (T - T_ref) 
                    * log ((aa + P / k)/(aa + P_star / k))
            );
        }();
            const auto
        SVterm = calorie_per_bar_cm3 * (
            - k * (ba + aa * ca * k) * log ((aa + P / k)/(aa + P_star / k)) 
            + ca * k * (P - P_star)) - S_star
        ;
        G = G + GVterm;
        S = S + SVterm;
        H = H + GVterm + T * SVterm;
    }
    return std::tuple { V, Cp, S, H, G };
}
// Same as for minerals except no phase transition
    auto
thermodynamic_properties (sprons92::gas_t const& data, double T, double P)
{
        const auto
    V = data.V;
        const auto
    S = 
          data.S 
        + detail::int_Cp_dlnT (T_ref, T, data.a, data.b, data.c)
    ;
        const auto
    int_V_dP = data.V * (P - P_ref) * calorie_per_bar_cm3;
        const auto
    H = 
          data.DH 
        + detail::int_Cp_dT (T_ref, T, data.a, data.b, data.c)
        + int_V_dP
    ;
        const auto
    G = 
          data.DG
        + detail::int_Cp_dT (T_ref, T, data.a, data.b, data.c)
        - detail::int_Cp_dlnT (T_ref, T, data.a, data.b, data.c) * T
        + int_V_dP
    ;
        const auto
    Cp = detail::Cp (
          T
        , data.a
        , data.b
        , data.c
    );
    // FIXME: H2O,g
    return std::tuple { V, Cp, S, H, G };
}

    auto
thermodynamic_properties (
      sprons92::aqueous_species_t const& data
    , auto const& T
    , auto const& P
    , auto const& D
    , auto const& Q
    , auto const& Z
    , auto const& Y
    , auto const& X
){
    // V, eq. 45
        constexpr auto
    Psi = 2600.;
        constexpr auto
    Omega = 228.;
        const auto
    P_plus_Psi = P + Psi; // bar
        const auto
    P_ref_plus_Psi = P_ref + Psi; // bar
        const auto
    T_minus_Omega = T - Omega; // K
        const auto
    T_ref_minus_Omega = T_ref - Omega; // K
        constexpr auto
    eta = 1.66027e5; // Å.cal.mol-1
    // This is eq. 56. The code adds a `gref` term here that doesn't appear in
    // the paper. The code is at react92d.f:838.
    // News flash: gref is in fact set to zero. 
        const auto
    re_ref = Z * Z / (data.omega / eta + Z / 3.082);
        const auto
    g = D < 1e3 ? detail::g (T, D, P) : 0.;
        const auto
    dg_dp = D < 1e3 ? detail::dg_dp(T, D, P) : 0.;
        const auto
    r = re_ref + fabs (Z) * g;
        const auto
    omega = eta * (Z * Z / r - Z / (3.082 + g));
        const auto
    domegadp = eta * ( -fabs (pow (Z, 3)) / r / r + Z / pow (3.080 + g, 2)) 
        * dg_dp;
        const auto
    V = bar_cm3_per_calorie * (
          data.a_1 
        + data.a_2 / P_plus_Psi 
        + data.a_3 / T_minus_Omega 
        + data.a_4 / P_plus_Psi / T_minus_Omega
        - omega * Q
        - (Z + 1) * domegadp
    );
    // Cp, eq. 62
        const auto
    dgdt = detail::dg_dt(T, D, P);
        const auto
    dgdtt = detail::dg_dtt(T, D, P);
    // The code does not consider the temperature dependency of Z when
    // differentiating omega, react92d.f:845.
        [[maybe_unused]]
        const auto
    domegadt = -eta * (fabs (pow (Z, 3)) / r / r - Z / pow (3.080 + g, 2)) 
        * dgdt
    ;
        const auto
    domegadtt = 
          2 * eta * (
            fabs ((pow (Z, 4)) / pow (r, 3) - Z / pow (3.080 + g, 3))
          ) * dgdt * dgdt 
        - eta * (
            fabs (pow (Z, 3)) / r / r - Z / pow (3.080 + g, 2)
        ) * dgdtt
    ;
        const auto 
    Cp =
          data.c_1 + data.c_2 / pow (T_minus_Omega, 2) 
        - 2 * T / pow (T_minus_Omega, 3) * (
            data.a_3 * (P - 1) + data.a_4 * log ((P + Psi) / (Psi + 1))
        ) 
        + omega * T * X 
        + 2 * T * Y * domegadt 
        + T * (Z + 1) * domegadtt
    ;
    // S, eq. 61
        constexpr auto
    Y_at_Pr_Tr = -0.5798650444e-4 ;
        const auto
    S = 
          data.S 
        + data.c_1 * log (T / T_ref)
        - data.c_2 / Omega * (
              1 / T_minus_Omega 
            - 1 / T_ref_minus_Omega
            + 1 / Omega * log (T_ref * T_minus_Omega / T / T_ref_minus_Omega)
          )
        + pow (1 / T_minus_Omega, 2) * (
              data.a_3 * (P - P_ref)
            + data.a_4 * log (P_plus_Psi / P_ref_plus_Psi)
          )
        + omega * Y 
        + (Z + 1) * domegadt
        - data.omega * Y_at_Pr_Tr
    ;
    // H, eq. 60
        constexpr auto
    Z_at_Pr_Tr = -0.1278034682e-1;
        const auto
    H = 
          data.DH
        - data.c_1 * (T - T_ref)
        - data.c_2 * (1 / T_minus_Omega - 1 / T_ref_minus_Omega)
        + data.a_1 * (P - P_ref)
        + data.a_2 * log (P_plus_Psi / P_ref_plus_Psi)
        + 2 / T_minus_Omega / T_ref_minus_Omega / T_ref_minus_Omega * (
              data.a_3 * (P - P_ref) 
            + data.a_4 * log (P_plus_Psi / P_ref_plus_Psi)
          )
        - omega * (Z + 1)
        + omega * T * Y
        + T * (Z + 1) * domegadt
        + data.omega * (Z_at_Pr_Tr + 1)
        - data.omega * T_ref * Y_at_Pr_Tr
    ;
    // G, eq. 59
        const auto
    G = 
          data.DG
        - data.S * (T - T_ref)
            // WARNING: Paper-code inconsistency here
            // Paper: (T * log (T / T_ref) - T - T_ref)
            // Code:  (T * log (T / T_ref) - T + T_ref)
            // Paper: eq. 59
            // Code: reac92d.f:794
        - data.c_1 * (T * log (T / T_ref) - T + T_ref)
        + data.a_1 * (P - P_ref)
        + data.a_2 * log (P_plus_Psi / P_ref_plus_Psi)
        - data.c_2 * (
              (1 / T_minus_Omega - 1 / T_ref_minus_Omega) * -T_minus_Omega / Omega
            - T / Omega / Omega * log (T_ref * T_minus_Omega / T / T_ref_minus_Omega)
          )
        + 1 / T_minus_Omega * (
              data.a_3 * (P - P_ref)
            + data.a_4 * log (P_plus_Psi / P_ref_plus_Psi)
          )
        - omega * (Z + 1)
        + data.omega * (Z_at_Pr_Tr + 1)
        + data.omega * Y_at_Pr_Tr * (T - T_ref)
    ;
    return std::tuple { V, Cp, S, H, G };
}
} // namespace hkf

    auto
supcrt92 (run_t const& run)
{
    print (
          header
        , run.filename_con
        , run.filename_rxn
        , run.filename_databse
        , run.filename_tab
        , run.filename_plt
        , run.isat
        , run.iopt
        , run.iplot
        , run.univar
        , run.noinc
        , run.isovar
        , run.isomin
        , run.isomax
        , run.isoinc
        , run.incv
        , run.v2min
        , run.v2max
        , run.v2inc

    );
    for (const auto& [i, rxn]: std::views::enumerate (run.reactions))
    {
        // Stoichiometry
        print (header_reaction, i + 1, rxn.title);
            auto
        minerals = std::vector <std::pair <double, sprons92::mineral_t const&>>
        {};
        for (const auto& mineral: rxn.minerals)
        {
                const auto
            mineral_index = sprons92::mineral_name_to_index.find (mineral.name);
            if (mineral_index == sprons92::mineral_name_to_index.end ())
            {
                println ("Mineral not found: {}", mineral.name);
                exit (1);
            }
                const auto&
            data = sprons92::minerals.at (mineral_index->second);
            minerals.emplace_back (mineral.coefficient, data);
            println (
                  "      {:9.3f}   {:20}   {:30}"
                , mineral.coefficient
                , mineral.name
                , data.chemical_formula_structural
            );
        }
            auto
        gases = std::vector <std::pair <double, sprons92::gas_t const&>>
        {};
        for (const auto& gas: rxn.gases)
        {
                const auto
            gas_index = sprons92::gas_name_to_index.find (gas.name);
            if (gas_index == sprons92::gas_name_to_index.end ())
            {
                println ("gas not found: {}", gas.name);
                exit (1);
            }
                const auto&
            data = sprons92::gases.at (gas_index->second);
            gases.emplace_back (gas.coefficient, data);
            println (
                  "      {:9.3f}   {:20}   {:30}"
                , gas.coefficient
                , gas.name
                , data.chemical_formula_structural
            );
        }
            auto
        aqueous_species = std::vector <std::pair <double, sprons92::aqueous_species_t const&>>
        {};
        for (const auto& aq_species: rxn.aqueous_species)
        {
                const auto
            aqueous_species_index = sprons92::aqueous_species_name_to_index.find (aq_species.name);
            if (aqueous_species_index == sprons92::aqueous_species_name_to_index.end ())
            {
                println ("aqueous_species not found: {}", aq_species.name);
                exit (1);
            }
                const auto&
            data = sprons92::aqueous_species.at (aqueous_species_index->second);
            aqueous_species.emplace_back (aq_species.coefficient, data);
            println (
                  "      {:9.3f}   {:20}   {:30}"
                , aq_species.coefficient
                , aq_species.name
                , data.chemical_formula_structural
            );
        }
        println (
              "      {:9.3f}   {:20}   {:30}"
            , rxn.h2o
            , "H2O"
            , "H2O"
        );
        // End of Stoichiometry

        // Standard state properties at:
            const auto
        T = T_ref;
            const auto
        P_in_bar = P_ref;
        // Minerals
        print (header_minerals_1);
        for (const auto& [coeff, data]: minerals)
        {
                const auto
            cp = data.a[0] + data.b[0] * T + data.c[0] / T / T;
            println (
                  "  {:20}  {:10.0f}     {:10.0f}        {:8.3f}       {:8.3f}        {:6.1f}      "
                , data.name
                , data.DG
                , data.DH
                , data.S
                , data.V
                , cp
            );
        }
        print (header_minerals_2);
        for (const auto& [coeff, data]: minerals)
        {
            print (
                    "  {:20} {:9.3f}   {:9.3f}   {:9.3f}     {:7.2f}"
                , data.name
                , data.a[0]
                , data.b[0] * 1e3
                , data.c[0] * 1e-5
                , data.T[0] - 273.15
            );
            if (data.max_phase_transition_count == 0)
            {
                puts ("");
                continue;
            }
            print_or_not (data.DHt[0],   "       {:6.0f}", 6);
            print_or_not (data.DVt[0],   "    {:7.3f}", 6 + 3);
            print_or_not (data.dP_dT[0], "{:7.3f}", 7 + 3);
            puts ("");
            for (auto i = 1; i <= data.max_phase_transition_count; ++i)
            {
                print (
                      "    post-transition {:1d}  {:9.3f}   {:9.3f}   {:9.3f}     {:7.2f}"
                    , i
                    , (data.a[i])
                    , (data.b[i]) * 1e3
                    , (data.c[i]) * 1e-5
                    , (data.T[i]) - 273.15
                );
                print_or_not (data.DHt[i],   "       {:6.0f}", 6);
                print_or_not (data.DVt[i],   "    {:7.3f}", 6 + 3);
                print_or_not (data.dP_dT[i], "{:7.3f}", 7 + 3);
                puts ("");
            }
        }
        print (header_gases_1);
        for (const auto& [coeff, data]: gases)
        {
                const auto
            cp = data.a + data.b * T + data.c / T / T;
            println (
                  "  {:20}   {:10.0f}     {:10.0f}       {:8.3f}          {:2.0f}           {:6.1f}      "
                , data.chemical_formula_structural
                , data.DG
                , data.DH
                , data.S
                , data.V
                , cp
            );
        }
        print (header_gases_2);
        for (const auto& [coeff, data]: gases)
        {
            println (
                  "  {:20} {:9.3f}   {:9.3f}   {:9.3f}     {:7.2f}      "
                , data.chemical_formula_structural
                , data.a
                , data.b * 1e3
                , data.c * 1e-5
                , data.T_max - 273.15
            );
        }
        print (header_aqueous_species_1);
        for (const auto& [coeff, data]: aqueous_species)
        {
                const auto
            V = hkf::molar_volume (data, T, P_in_bar);
                const auto
            cp = hkf::heat_capacity_isobaric (data, T, P_in_bar);
            println (
                  "  {:20}   {:10.0f}     {:10.0f}       {:8.3f}          {:2.0f}           {:6.1f}      "
                , data.chemical_formula_structural
                , data.DG
                , data.DH
                , data.S
                , V
                , cp
            );
        }
        // H2O
            const auto
        D = iapws::r6_inverse::density_pt (P_in_bar * 1e5, T);
        {
            println (
                  "  {:20}   {:10.0f}     {:10.0f}       {:8.3f}          {:2.0f}           {:6.1f}      "
                , "H2O"
                , h2o_standard_state_gibbs / joule_per_calorie 
                , h2o_standard_state_enthalpy / joule_per_calorie 
                , h2o_standard_state_entropy / joule_per_calorie 
                , h2o_standard_state_molar_volume * 1000
                , h2o_standard_state_isobaric_heat_capacity / joule_per_calorie
            );
                const auto
            V_ = 1 / D * 1e6 * iapws::molar_mass;
                const auto
            Cp_ = 
                  iapws::r6::massic_isobaric_heat_capacity_dt (D, T) 
                * calorie_per_joule 
                * iapws::molar_mass
            ;
                const auto
            S_ = 
                  iapws::r6::massic_entropy_dt (D, T) 
                * calorie_per_joule
                * iapws::molar_mass
            ;
                const auto
            H_ = 
                  iapws::r6::massic_enthalpy_dt (D, T) 
                * calorie_per_joule 
                * iapws::molar_mass
            ;
                const auto
            G_ = H_ - T * S_;
            println (
                  "  {:20}  {:10.0f}     {:10.0f}        {:8.3f}       {:8.3f}        {:6.1f}      "
                , "H2O (IAPWS)"
                , G_
                , H_
                , S_
                , V_
                , Cp_
            );
        }
        // H2O, IAPWS
        /*
            const auto
        V_h2o = 1 / D * 1e6 * iapws::molar_mass;
            const auto
        Cp_h2o = 
                iapws::r6::massic_isobaric_heat_capacity_dt (D, T) 
            * calorie_per_joule 
            * iapws::molar_mass
        ;
            const auto
        S_h2o = 
                iapws::r6::massic_entropy_dt (D, T) 
            * calorie_per_joule
            * iapws::molar_mass
        ;
            const auto
        H_h2o = 
                iapws::r6::massic_enthalpy_dt (D, T) 
            * calorie_per_joule 
            * iapws::molar_mass
        ;
            const auto
        G_h2o = H_h2o - T * S_h2o;
        */
        // H2O, CODATA
            const auto
        G_h2o = h2o_standard_state_gibbs / joule_per_calorie;
            const auto
        H_h2o = h2o_standard_state_enthalpy / joule_per_calorie;
            const auto
        S_h2o = h2o_standard_state_entropy / joule_per_calorie;
            const auto
        V_h2o = h2o_standard_state_molar_volume * 1000;
            const auto
        Cp_h2o = h2o_standard_state_isobaric_heat_capacity / joule_per_calorie;
            const auto
        D_h2o = h2o_standard_state_molar_volume / iapws::molar_mass;
        print (header_aqueous_species_2);
        for (const auto& [coeff, data]: aqueous_species)
        {
            println (
                  "  {:20}    {:8.4f}      {:8.4f}      {:8.4f}      {:8.4f}      {:8.4f}      {:8.4f}      {:8.4f}"
                , data.chemical_formula_structural
                , data.a_1 * 1e1
                , data.a_2 * 1e-2
                , data.a_3
                , data.a_4 * 1e-4
                , data.c_1
                , data.c_2 * 1e-4
                , data.omega * 1e-5
            );
        }

// =============================================================================
            constexpr auto
        print_details = false;
        if (print_details)
        {
            println ("\n\n ==== Details of reaction calculations ====");
        }
        // FIXME: for each reaction
            const auto&
        reaction = run.reactions.at (0);
            auto
        V = 0.;
            auto
        Cp = 0.;
            auto
        S = 0.;
            auto
        H = 0.;
            auto
        G = 0.;
        if (print_details)
        {
            print (header_minerals_1);
        }
        for (const auto& [coeff, data]: minerals)
        {
                const auto
            [ V_, Cp_, S_, H_, G_ ] = hkf::thermodynamic_properties (data, T_ref, P_ref);
            V  += V_  * coeff;
            Cp += Cp_ * coeff;
            S  += S_  * coeff;
            H  += H_  * coeff;
            G  += G_  * coeff;
            if (print_details)
            {
                println (
                      "  {:20}  {:10.0f}     {:10.0f}        {:8.3f}       {:8.3f}        {:6.1f}      {:6.1f}"
                    , data.name
                    , G_
                    , H_
                    , S_
                    , V_
                    , Cp_
                    , coeff
                );
            }
        }
        if (print_details)
        {
            print (header_gases_1);
        }
        for (const auto& [coeff, data]: gases)
        {
                const auto
            [ V_, Cp_, S_, H_, G_ ] = hkf::thermodynamic_properties (data, T_ref, P_ref);
            V  += V_  * coeff;
            Cp += Cp_ * coeff;
            S  += S_  * coeff;
            H  += H_  * coeff;
            G  += G_  * coeff;
            if (print_details)
            {
                println (
                    "  {:20}  {:10.0f}     {:10.0f}        {:8.3f}       {:8.3f}        {:6.1f}      {:6.1f}"
                    , data.name
                    , G_
                    , H_
                    , S_
                    , V_
                    , Cp_
                    , coeff
                );
            }
        }
        if (print_details)
        {
            print (header_aqueous_species_1);
        }
        for (const auto& [coeff, data]: aqueous_species)
        {
                const auto
            dDdP = 1 / iapws::r6::d_pressure_d_density_dt (D, T);
                const auto
            dEdD = iapws::r8::d_relative_permittivity_d_density_at_temperature_dt (D, T);
                const auto
            dDdT = iapws::r6::d_density_d_temperature_dt (D, T);
                const auto
            dEdT = iapws::r8::d_relative_permittivity_d_temperature_at_density_dt (D, T);
                const auto
            d2EdT = iapws::r8::d_relative_permittivity_d2_temperature_at_pressure_dt(D, T, dDdT);
                const auto
            E = iapws::r8::relative_permittivity_dt (D, T);
                const auto
            Q = born::q (E, dDdP, dEdD);
                const auto
            Z = born::z (E);
                const auto
            Y = born::y (E, dEdT, dEdD, dDdT);
                const auto
            X = born::x (E, d2EdT, Y);
                const auto
            [ V_, Cp_, S_, H_, G_ ] = hkf::thermodynamic_properties (
                  data
                , T_ref
                , P_ref
                , D
                , Q
                , Z
                , Y
                , X
            );
            V  += V_  * coeff;
            Cp += Cp_ * coeff;
            S  += S_  * coeff;
            H  += H_  * coeff;
            G  += G_  * coeff;
            if (print_details)
            {
                println (
                    "  {:20}  {:10.0f}     {:10.0f}        {:8.3f}       {:8.3f}        {:6.1f}      {:6.1f}"
                    , data.name
                    , G_
                    , H_
                    , S_
                    , V_
                    , Cp_
                    , coeff
                );
            }
        }
        // H2O
        {
            V  += V_h2o  * reaction.h2o;
            Cp += Cp_h2o * reaction.h2o;
            S  += S_h2o  * reaction.h2o;
            H  += H_h2o  * reaction.h2o;
            G  += G_h2o  * reaction.h2o;
            if (print_details)
            {
                println (
                    "  {:20}  {:10.0f}     {:10.0f}        {:8.3f}       {:8.3f}        {:6.1f}      {:6.1f}"
                    , "H2O"
                    , G_h2o
                    , H_h2o
                    , S_h2o
                    , V_h2o
                    , Cp_h2o
                    , reaction.h2o
                );
            }
        }
        if (print_details)
        {
            println ("\n\n ==== End of details of reaction calculations ====");
        }
        print (header_reaction_standard_state);
            const auto
        log_K = -G / std::numbers::ln10 / gas_constant / T;
        println (
            "   {:8.3f}    {:8.3f}    {:8.3f}    {:8.3f}  {:10.0f}   {:10.0f}   {:8.3f}   {:8.3f}   {:8.3f}"
            , P_ref
            , T_ref - 273.15
            , D_h2o
            , log_K
            , G
            , H
            , S
            , V
            , Cp
        );
    }
}


    int
main ()
{
    supcrt92 (skarn);
}
