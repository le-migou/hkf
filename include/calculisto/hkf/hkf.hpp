#pragma once
#include "database.hpp"
#include <string>
#include <vector>
#include <cmath>
#include <ranges>

#include <fmt/format.h>
    using fmt::println;

// Equations and tables numbers refer to the paper:

// Helgeson, H. C., Kirkham, D. H., & Flowers, G. C. (1981). Theoretical
// prediction of the thermodynamic behavior of aqueous electrolytes by high
// pressures and temperatures; IV, Calculation of activity coefficients, osmotic
// coefficients, and apparent molal and standard and relative partial molal
// properties to 600 degrees C and 5kb. American journal of science, 281(10),
// 1249-1516.
// https://doi.org/10.2475/ajs.281.10.1249

// All the thermodynamic properties computed here are molal (i.e. per mole)

// WARNING: The database units are expected to be those of SUPCRT's prons92 (for
// now). In particular energies are in calorie. 
// We provided the results in SI units.

    namespace 
calculisto::thermodynamics::hkf 
{
    constexpr auto 
T_ref = 273.15 + 25.; // K
    constexpr auto 
P_ref = 1e5; // Pa

    constexpr auto 
joule_per_calorie = 4.184;
    constexpr auto 
calorie_per_joule = 1 / joule_per_calorie;
    constexpr auto 
bar_cm3_per_calorie = 10 * joule_per_calorie;
    constexpr auto 
calorie_per_bar_cm3 = 1 / bar_cm3_per_calorie;


// CODATA
// Cox, J.D.,Wagman, D.D., Medvedev, V.A. (Eds.), 1989. 
// CODATA Key Values for Thermodynamics. 
// CODATA Series on Thermodynamic Properties. Hemisphere, New York, p. 271. 
    constexpr auto
h2o_standard_state_gibbs                  = -237140.; // J/mol
    constexpr auto
h2o_standard_state_enthalpy               = -285830.; // J/mol
    constexpr auto
h2o_standard_state_entropy                = 69.95;    // J/mol/K

// Don't have a source for these...
// But we don't use them, so...
/*
    constexpr auto
h2o_standard_state_molar_volume           = 18.1e-3;  // m3/mol
    constexpr auto
h2o_standard_state_isobaric_heat_capacity = 75.28;    // J/mol/K
*/
    constexpr auto
gas_constant_in_cal_per_mol_per_K = 1.9872; // cal/mol/K


    namespace
detail // {{{
{
        namespace
    legacy // {{{
    {
        // Born functions from the supcrt92 paper are considered lagacy here because
        // we use the IAPWS formulation.
            constexpr auto
        a_e_1 = 0.1470333593e2;
            constexpr auto
        a_e_2 = 0.2128462733e3;
            constexpr auto
        a_e_3 = -0.1154445173e3;
            constexpr auto
        a_e_4 = 0.1955210915e2;
            constexpr auto
        a_e_5 = -0.8330347980e2;
            constexpr auto
        a_e_6 = 0.3213240048e2;
            constexpr auto
        a_e_7 = -0.6694098645e1;
            constexpr auto
        a_e_8 = -0.3786202045e2;
            constexpr auto
        a_e_9 = 0.6887359646;
            constexpr auto
        a_e_10 = -0.2729401652e2;
            constexpr auto
        k_1 (auto const& T_hat)
        {
            return a_e_1 / T_hat;;
        }
            constexpr auto
        k_2 (auto const& T_hat)
        {
            return a_e_2 / T_hat + a_e_3 + a_e_4 * T_hat;
        }
            constexpr auto
        k_3 (auto const& T_hat)
        {
            return a_e_5 / T_hat + a_e_6 + a_e_7 * T_hat * T_hat;
        }
            constexpr auto
        k_4 (auto const& T_hat)
        {
            return a_e_8 / T_hat / T_hat + a_e_9 / T_hat + a_e_10;
        }
            constexpr auto
        epsilon (auto const& T, auto const& D)
        {
                const auto
            T_hat = T / 298.15;
                const auto
            rho_hat = D / 1e3;
                using std::pow;
            return
                1.
                + k_1 (T_hat) * rho_hat
                + k_2 (T_hat) * pow (rho_hat, 2)
                + k_3 (T_hat) * pow (rho_hat, 3)
                + k_4 (T_hat) * pow (rho_hat, 4)
            ;
        }
            constexpr auto
        Z (auto const& T, auto const& D)
        {
            return 1 / epsilon (T, D);
        }
    } // }}} namespace legacy

    // Table 3
        constexpr auto
    a_f_1 = 0.3666666e2;
        constexpr auto
    a_f_2 = -0.1504956e-9;
        constexpr auto
    a_f_3 = 0.5017997e-13;

    // Eq. 52
        constexpr auto
    f (const auto& T, auto const& P)
    {
            const auto
        t = (T - 155) / 300;
            const auto
        p = 1000 - P;
            using std::pow;
            const auto
        r =
              (pow (t, 4.8) + a_f_1 * pow (t, 16))
            * (a_f_2 * pow (p, 3) + a_f_3 * pow (p, 4))
        ;
        return r;
    }
        constexpr auto
    df_dp (const auto& T, auto const& P)
    {
            const auto
        t = (T - 155.) / 300;
            const auto
        p = 1000 - P;
            using std::pow;
        return
            - (pow (t, 4.8) + a_f_1 * pow (t, 16))
            * (3 * a_f_2 * pow (p, 2) + 4 * a_f_3 * pow (p, 3))
        ;
    }
        constexpr auto
    df_dt (const auto& T, auto const& P)
    {
            const auto
        t = (T - 155.) / 300;
            const auto
        p = 1000. - P;
            using std::pow;
        return
              (4.8 * pow (t, 3.8) + 16 * a_f_1 * pow (t, 15))
            * (a_f_2 * pow (p, 3) + a_f_3 * pow (p, 4)) / 300
        ;
    }
        constexpr auto
    df_dtt (const auto& T, auto const& P)
    {
            const auto
        t = (T - 155.) / 300;
            const auto
        p = 1000. - P;
            using std::pow;
        return
              (4.8 * 3.8 * pow (t, 2.8) + 16 * 15 * a_f_1 * pow (t, 14))
            * (a_f_2 * pow (p, 3) + a_f_3 * pow (p, 4)) / 300 / 300
        ;
    }

    // Table 2
        constexpr auto
    a_g_1 = -0.2037662e1;
        constexpr auto
    a_g_2 = 0.5747000e-2;
        constexpr auto
    a_g_3 = -0.6557892e-5;
        constexpr auto
    b_g_1 = 0.6107361e1;
        constexpr auto
    b_g_2 = -0.1074377e-1;
        constexpr auto
    b_g_3 = 0.1268348e-4;

    // Eq. 50
        constexpr auto
    a_g (const auto& T)
    {
        return a_g_1 + a_g_2 * T + a_g_3 * T * T;
    }
        constexpr auto
    da_g_dt (const auto& T)
    {
        return a_g_2 + 2 * a_g_3 * T;
    }
        constexpr auto
    da_g_dtt (/*const auto& T*/)
    {
        return 2 * a_g_3;
    }
    // Eq. 51
        constexpr auto
    b_g (const auto& T)
    {
        return b_g_1 + b_g_2 * T + b_g_3 * T * T;
    }
        constexpr auto
    db_g_dt (const auto& T)
    {
        return b_g_2 + 2 * b_g_3 * T;
    }
        constexpr auto
    db_g_dtt (/*const auto& T*/)
    {
        return 2 * b_g_3;
    }
    // Eq. 49
        constexpr auto
    g (const auto& T, auto const& D, auto const& P)
    {
        // NOTE:
        if (D >= 1000.) return 0.;
        // T: K -> °C
            const auto
        t = T - 273.15;
        // D: kg/m3 -> g/cm3
            const auto
        d = D / 1e3;
            const auto
        p [[maybe_unused]] = P * 1e5;
        // T in °C
        // D in g/cm^3
        // P in bar
            using std::pow;
            [[maybe_unused]]
            const auto
        a = a_g (t);
            [[maybe_unused]]
            const auto
        b = b_g (t);
            const auto
        r =
              a_g (t) * pow (1. - d, b_g (t))
            - (t >= 155. && t <= 355 ? f (t, P) : 0.);
        return r;
    }
        constexpr auto
    dg_dt (const auto& T, auto const& D, auto const& P)
    {
        // NOTE:
        if (D >= 1000.) return 0.;
            const auto
        t = T - 273.15;
            const auto
        d = D / 1e3;
            const auto
        p [[maybe_unused]] = P * 1e5;
            using std::pow, std::log;
            const auto
        r =
              a_g (t) * pow (1. - d, b_g (t)) * db_g_dt (t) * log (1 - d)
            + da_g_dt (t) * pow (1. - d, b_g (t))
            - (t >= 155. && t <= 355 ? df_dt (t, P) : 0.)
        ;
        return r;
    }
        constexpr auto
    dg_dp (const auto& T, [[maybe_unused]] auto const& D, auto const& P)
    {
        // NOTE:
        if (D >= 1000.) return 0.;
            const auto
        t = T - 273.15;
            const auto
        r =
            - (t >= 155. && t <= 355 ? df_dp (t, P) : 0.);
        ;
        return r;
    }
        constexpr auto
    dg_dtt (const auto& T, auto const& D, auto const& P)
    {
        // NOTE:
        if (D >= 1000.) return 0.;
            const auto
        t = T - 273.15;
            const auto
        d = D / 1e3;
            const auto
        p [[maybe_unused]] = P * 1e5;
            using std::pow, std::log;
            const auto
        r =
              a_g (t) * pow (1. - d, b_g (t)) * db_g_dtt () * log (1 - d)
            + a_g (t) * (( pow (1. - d, b_g (t)) * db_g_dt (t) * log (1 - d) )) * db_g_dt (t) * log (1 - d)
            + da_g_dt (t) * pow (1. - d, b_g (t)) * db_g_dt (t) * log (1 - d)

            + da_g_dt (t) * (( pow (1. - d, b_g (t)) * db_g_dt (t) * log (1 - d) ))
            + da_g_dtt () * pow (1. - d, b_g (t))

            - (t >= 155. && t <= 355 ? df_dtt (t, P) : 0.)
        ;
        return r;
    }

    // Eq. 81
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

} // }}} namespace detail


    template <class Number>
    struct
molal_properties_h2o_t 
{
        Number
      volume
    , isobaric_heat_capacity
    , entropy
    , enthalpy
    , gibbs_energy
    , density
    , born_q
    , born_z
    , born_y
    , born_x
    ;
        auto
    operator * (Number a) const
    {
        return molal_properties_h2o_t {
              volume                 * a
            , isobaric_heat_capacity * a
            , entropy                * a
            , enthalpy               * a
            , gibbs_energy           * a
            , density                * a
            , born_q
            , born_z
            , born_y
            , born_x
        };
    }
};

    template <class Number>
    class
equation_of_state_h2o_t
{
public:
        virtual
        molal_properties_h2o_t <Number>
    compute_properties (Number const& T, Number const& P) const = 0;
};

    template <class Number>
    struct
molal_properties_t
{
        Number
      volume
    , isobaric_heat_capacity
    , entropy
    , enthalpy
    , gibbs_energy
    ;
        auto&
    operator += (molal_properties_t const& other)
{
        volume                 += other.volume;
        isobaric_heat_capacity += other.isobaric_heat_capacity;
        entropy                += other.entropy;
        enthalpy               += other.enthalpy;
        gibbs_energy           += other.gibbs_energy;
        return *this;
    }
        auto&
    operator += (molal_properties_h2o_t <Number> const& other)
    {
        volume                 += other.volume;
        isobaric_heat_capacity += other.isobaric_heat_capacity;
        entropy                += other.entropy;
        enthalpy               += other.enthalpy;
        gibbs_energy           += other.gibbs_energy;
        return *this;
    }
        auto
    operator * (Number a) const
    {
        return molal_properties_t {
              volume                 * a
            , isobaric_heat_capacity * a
            , entropy                * a
            , enthalpy               * a
            , gibbs_energy           * a
        };
    }
};

    namespace
detail
{
    constexpr auto 
P_ref_in_bar = 1.; // bar

// Thermodynamic properties of minerals
// Eqs. 77-81
    auto
compute_properties (data_mineral_t const& data, auto const& T, auto const& P)
{
        using std::min;
        const auto
    P_in_bar = P * 1e-5;
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
    int_V_dP = data.V * (P_in_bar - P_ref_in_bar) * calorie_per_bar_cm3;
        auto
    H =
          data.DH
        + detail::int_Cp_dT (Ta, Tb, data.a[0], data.b[0], data.c[0])
        + int_V_dP
    ;
        auto
    G =
          data.DG
        - data.S * (T - T_ref)
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
            T_t_at_P_t = data.T[phase_index] + (P_in_bar - P_ref_in_bar) / (data.dP_dT[phase_index] == 0 ? 1. : data.dP_dT[phase_index]);
            if (T < T_t_at_P_t) break;
                const auto
            P_t_at_T_t = P_ref_in_bar + (T - data.T[phase_index]) * data.dP_dT[phase_index];

            // WARNING: Paper-code inconsistency here
            // Paper: -sum_{P_{t_i,T}}^P_in_bar
            // Code: sum_{P_{ref}}^{P_{t_i,T}}
            // Paper: eqs. 78, 79
            // Code: reac92d.f:409,419,420,425,426
                const auto
            int_V_dP_tran = data.DVt[phase_index] * (P_t_at_T_t - P_ref_in_bar) * calorie_per_bar_cm3;

            V += data.DVt[phase_index];
            int_V_dP += int_V_dP_tran;
            H -= int_V_dP_tran;
            G -= int_V_dP_tran;
        }
    }
    // Phase transitions at T_t_i, P_r (phi_T), Cp terms
        int
    phase_index = 0;
    if (data.max_phase_transition_count > 0)
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
            + data.DHt[phase_index]
        ;
        G +=
                int_Cp_dT
            - int_Cp_dlnT * T
            + data.DHt[phase_index] * (T / data.T[phase_index] - 1)
        ;
    }
        const auto
    Cp = detail::Cp (
          T
        , data.a[phase_index]
        , data.b[phase_index]
        , data.c[phase_index]
    );
    // Adjust for quartz compressibility
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
        phase = (T <= Ttran || P_in_bar >= P_ref_in_bar + k * (T - data.T[0])) ? 1 : 2;
            const auto
        [ P_star, S_star ] = [&]()
        {
            if (T <= data.T[0])
            {
                return std::tuple { P_ref_in_bar, 0. };
            }
            if (phase == 2)
            {
                return std::tuple { P_in_bar, 0. };
            }
            return std::tuple { P_ref_in_bar + k * (T - Ttran), Stran };
        }();
        V = (phase == 2) ? VPrTtb : (
            VPrTra
            + ca * (P_in_bar - P_ref_in_bar)
            + (VPtTta - VPrTra - ca * (P_in_bar - P_ref_in_bar)) * (T - T_ref)
                /
            (Ttran + (P_in_bar - P_ref_in_bar) / k - T_ref)
        );
            const auto
        GVterm = [&]()
        {
            if (data.name == "COESITE")
            {
                V -= Vdiff;
                return calorie_per_bar_cm3 * (
                    (VPrTra - Vdiff) * (P_in_bar - P_star)
                    + (VPrTtb - Vdiff) * (P_star - P_ref_in_bar)
                    - 0.5 * ca * (2 * P_ref_in_bar * (P_in_bar - P_star)
                    - (P_in_bar * P_in_bar - P_star * P_star))
                    - ca * k * (T - T_ref) * (P_in_bar - P_star)
                    + k * (ba + aa * ca * k) * (T - T_ref)
                        * log ((aa + P_in_bar / k) / (aa + P_star / k))
                );
            }
            return calorie_per_bar_cm3 * (
                VPrTra * (P_in_bar - P_star)
                + VPrTtb * (P_star - P_ref_in_bar)
                - 0.5 * ca * (2 * P_ref_in_bar * (P_in_bar - P_star) - (P_in_bar * P_in_bar - P_star * P_star))
                - ca * k * (T - T_ref) * (P_in_bar - P_star)
                + k * (ba + aa * ca * k) * (T - T_ref)
                    * log ((aa + P_in_bar / k)/(aa + P_star / k))
            );
        }();
            const auto
        SVterm = calorie_per_bar_cm3 * (
            - k * (ba + aa * ca * k) * log ((aa + P_in_bar / k)/(aa + P_star / k))
            + ca * k * (P_in_bar - P_star)) - S_star
        ;
        G = G + GVterm;
        S = S + SVterm;
        H = H + GVterm + T * SVterm;
    }
println ("    {} DV= {}", data.name, V);
    // Back to SI
    return molal_properties_t { 
          V * 1e-6
        , Cp * joule_per_calorie
        , S * joule_per_calorie
        , H * joule_per_calorie
        , G  * joule_per_calorie
    };
}

// Thermodynamic properties of gases
// Same as for minerals except no phase transition
    auto
compute_properties (data_gas_t const& data, auto const& T, auto const& P)
{
        const auto
    P_in_bar = P * 1e-5;
        const auto
    V = data.V;
        const auto
    S =
          data.S
        + detail::int_Cp_dlnT (T_ref, T, data.a, data.b, data.c)
    ;
        const auto
    int_V_dP = data.V * (P_in_bar - P_ref_in_bar) * calorie_per_bar_cm3;
        const auto
    H =
          data.DH
        + detail::int_Cp_dT (T_ref, T, data.a, data.b, data.c)
        + int_V_dP
    ;
        const auto
    G =
          data.DG
        - data.S * (T - T_ref)
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
println ("    {} DV= {}", data.name, V);
    // Back to SI
    return molal_properties_t { 
          V * 1e-6
        , Cp * joule_per_calorie
        , S * joule_per_calorie
        , H * joule_per_calorie
        , G  * joule_per_calorie
    };
}

// Thermodynamic properties of aqueous species
    auto
compute_properties (
      data_aqueous_species_t const& data
    , auto const& T
    , auto const& P
    , auto const& D
    , auto const& Q
    , auto const& Z
    , auto const& Y
    , auto const& X
){
        const auto
    P_in_bar = P * 1e-5;
    // V, eq. 45
        constexpr auto
    Psi = 2600.;
        constexpr auto
    Omega = 228.;
        const auto
    P_plus_Psi = P_in_bar + Psi; // bar
        const auto
    P_ref_plus_Psi = P_ref_in_bar + Psi; // bar
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
    g = D < 1e3 ? detail::g (T, D, P_in_bar) : 0.;
        const auto
    dg_dp = D < 1e3 ? detail::dg_dp(T, D, P_in_bar) : 0.;
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
println ("      a1: {}", data.a_1                              );
println ("      a2: {}", data.a_2 / P_plus_Psi                 );
println ("      a3: {}", data.a_3 / T_minus_Omega              );
println ("      a4: {}", data.a_4 / P_plus_Psi / T_minus_Omega );
println ("      Vq: {}", - omega * Q - (Z + 1) * domegadp);
println ("      w : {}", omega);
println ("      Q : {}", Q);
println ("      Z : {}", Z);
println ("      dw: {}", domegadp);
    // Cp, eq. 62
        const auto
    dgdt = detail::dg_dt(T, D, P_in_bar);
        const auto
    dgdtt = detail::dg_dtt(T, D, P_in_bar);
    // The code does not consider the temperature dependency of Z when
    // differentiating omega, react92d.f:845.
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
            data.a_3 * (P_in_bar - 1) + data.a_4 * log ((P_in_bar + Psi) / (Psi + 1))
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
              data.a_3 * (P_in_bar - P_ref_in_bar)
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
            // WARNING: Paper-code inconsistency here
            // Paper: -c_1(T - T_r)
            // Code:  +c_1(T - T_r)
            // Paper: eq. 60
            // Code: reac92d.f:783
        + data.c_1 * (T - T_ref)
        - data.c_2 * (1 / T_minus_Omega - 1 / T_ref_minus_Omega)
        + data.a_1 * (P_in_bar - P_ref_in_bar)
        + data.a_2 * log (P_plus_Psi / P_ref_plus_Psi)
        + 2 / T_minus_Omega / T_ref_minus_Omega / T_ref_minus_Omega * (
              data.a_3 * (P_in_bar - P_ref_in_bar)
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
        + data.a_1 * (P_in_bar - P_ref_in_bar)
        + data.a_2 * log (P_plus_Psi / P_ref_plus_Psi)
        - data.c_2 * (
              (1 / T_minus_Omega - 1 / T_ref_minus_Omega) * -T_minus_Omega / Omega
            - T / Omega / Omega * log (T_ref * T_minus_Omega / T / T_ref_minus_Omega)
          )
        + 1 / T_minus_Omega * (
              data.a_3 * (P_in_bar - P_ref_in_bar)
            + data.a_4 * log (P_plus_Psi / P_ref_plus_Psi)
          )
        - omega * (Z + 1)
        + data.omega * (Z_at_Pr_Tr + 1)
        + data.omega * Y_at_Pr_Tr * (T - T_ref)
    ;
println ("    {} DV= {}", data.name, V);
    // Back to SI
    return molal_properties_t { 
          V * 1e-6
        , Cp * joule_per_calorie
        , S * joule_per_calorie
        , H * joule_per_calorie
        , G  * joule_per_calorie
    };
}
} // namespace detail

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
reaction_data_t 
{
    // NOTE: we copy the data from the DB
        std::vector <data_mineral_t>
    minerals;
        std::vector <data_gas_t>
    gases;
        std::vector <data_aqueous_species_t>
    aqueous_species;
};

    template <class Number>
    struct
reaction_properties_t
{
        std::vector <molal_properties_t <Number>>
    minerals;
        std::vector <molal_properties_t <Number>>
    gases;
        std::vector <molal_properties_t <Number>>
    aqueous_species;
        molal_properties_h2o_t <Number>
    h2o;
        molal_properties_t <Number>
    reaction;
};

    inline auto
get_reaction_data (
      reaction_t const& reaction
    , database_t const& database
){
        auto
    r = reaction_data_t {};
    for (const auto& mineral: reaction.minerals)
    {
            const auto
        data = database.get_mineral (mineral.name);
        r.minerals.emplace_back (data);
    }
    for (const auto& gas: reaction.gases)
    {
            const auto
        data = database.get_gas (gas.name);
        r.gases.emplace_back (data);
    }
    for (const auto& aqueous_species: reaction.aqueous_species)
    {
            const auto
        data = database.get_aqueous_species (aqueous_species.name);
        r.aqueous_species.emplace_back (data);
    }
    return r;
}

    template <class Number>
    auto
compute_properties (
      reaction_t const& reaction
    , reaction_data_t const& reaction_data
    , auto const& T
    , auto const& P
    , equation_of_state_h2o_t <Number> const& eos_h2o
){
        using std::views::zip;
        auto
    r = reaction_properties_t <Number> {};
    r.h2o = eos_h2o.compute_properties (T, P);
    r.reaction = { 0, 0, 0, 0, 0 };
    for (const auto& [mineral, data]: zip (reaction.minerals, reaction_data.minerals))
    {
            const auto
        properties = compute_properties (data, T, P);
        r.minerals.emplace_back (properties);
        r.reaction += properties * mineral.coefficient;
    }
println ("  DV= {}", r.reaction.volume);
    for (const auto& [gas, data]: zip (reaction.gases, reaction_data.gases))
    {
            const auto
        properties = compute_properties (data, T, P);
        r.gases.emplace_back (properties);
        r.reaction += properties * gas.coefficient;
    }
println ("  DV= {}", r.reaction.volume);
    for (const auto& [aqueous_species, data]: zip (reaction.aqueous_species, reaction_data.aqueous_species))
    {
            const auto
        properties = compute_properties (
              data
            , T
            , P
            , r.h2o.density
            , r.h2o.born_q
            , r.h2o.born_z
            , r.h2o.born_y
            , r.h2o.born_x
        );
        r.aqueous_species.emplace_back (properties);
        r.reaction += properties * aqueous_species.coefficient;
    }
println ("  DV= {}", r.reaction.volume);
    r.reaction += r.h2o * reaction.h2o;
println ("  DV= {}", r.reaction.volume);
    return r;
}
} // namespace calculisto::thermodynamics::hkf
