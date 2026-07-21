#include "sprons92.hpp"
#include "calculisto/iapws/r6_inverse.hpp"
#include "calculisto/iapws/r8.hpp"
    using namespace calculisto::iapws;
#include <vector>
#include <ranges>
    using namespace std::literals;
#include <fmt/core.h>
    using fmt::println, fmt::print;
#include "format_strings.hpp"

    namespace
detail
{
/*
    namespace
legacy
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
} // namespace legacy
*/
    // HKF
        constexpr auto
    a_f_1 = 0.3666666e2;
        constexpr auto
    a_f_2 = -0.1504956e-9;
        constexpr auto
    a_f_3 = 0.5017997e-13;

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
        println ("    f: T= {}, P= {}. f= {}", T, P, r);
        return 
              (pow (t, 4.8) + a_f_1 * pow (t, 16))
            * (a_f_2 * pow (p, 3) + a_f_3 * pow (p, 4))
        ;

    }
        constexpr auto
    df_dp (const auto& T, auto const& P)
    {
            const auto
        t = (T - 155.) / 300;
            const auto
        p = 1000. - P;
            using std::pow;
        return
              (pow (t, 4.8) + a_f_1 * pow (t, 16))
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
              (0.016 * pow (t, 3.8) + 16 * a_f_1 * pow (t, 15) / 300)
            * (3 * a_f_2 * pow (p, 2) + 4 * a_f_3 * pow (p, 3))
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
              (0.0608  * pow (t, 2.8) /300 + a_f_1 * pow (t, 14) / 375)
            * (3 * a_f_2 * pow (p, 2) + 4 * a_f_3 * pow (p, 3))
        ;
    }

        constexpr auto
    a_g_1 = -0.2037662e1;
//          -0.2037662D+01
        constexpr auto
    a_g_2 = 0.5747000e-2;
 //         0.5747000D-02
        constexpr auto
    a_g_3 = -0.6557892e-5;
  //        -0.6557892D-05
        constexpr auto
    b_g_1 = 0.6107361e1;
   //       0.6107361D+01
        constexpr auto
    b_g_2 = -0.1074377e-1;
//          -0.1074377D-01
        constexpr auto
    b_g_3 = 0.1268348e-4;
//          0.1268348D-04 


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
    // eq. 49
        constexpr auto
    g (const auto& T, auto const& D, auto const& P)
    {
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
        r = a_g (t) * pow (1. - d, b_g (t)) - (t >= 155. && t <= 355 ? f (t, P) : 0.);
        return r;
    }
        constexpr auto
    dg_dp (const auto& T, auto const& D, auto const& P)
    {
            const auto
        t = T - 273.15;
            const auto
        d = D / 1e3;
            [[maybe_unused]]
            const auto
        p = P * 1e5;
            const auto
        b = b_g (t);
            using std::pow;
        return -a_g (t) * b * pow (1. - d, b - 1) - (t >= 155. && t <= 355 ? f (t, P) : 0.);
    //f (t, P);
    }
        constexpr auto
    dg_dt (const auto& T, auto const& D, auto const& P)
    {
            const auto
        t = T - 273.15;
            const auto
        d = D / 1e3;
            const auto
        p [[maybe_unused]] = P * 1e5;
            using std::pow;
        return pow (1. - d, b_g (t)) * (
            da_g_dt (t) + a_g (t) * db_g_dt (t) * log (1 - d)
        ) - df_dt (t, P);
    }
        constexpr auto
    dg_dtt (const auto& T, auto const& D, auto const& P)
    {
            const auto
        t = T - 273.15;
            const auto
        d = D / 1e3;
            const auto
        p [[maybe_unused]] = P * 1e5;
            const auto
        a = a_g (t);
            const auto
        db = db_g_dt (t);
            using std::pow;
        return pow (1. - d, b_g (t)) * (
            da_g_dtt () + log (1 - d) * (
                  2 * da_g_dt (t) * db 
                + a * db * db * log (1 - d) 
                + a * db_g_dtt ()
            )
        ) - df_dt (t, P);
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
      .filename_con = "file not saved"
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
hkf
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
    D = r6_inverse::density_pt (P * 1e5, T); // kg/m3
        const auto
    Z = r8::born::z (D, T);
        const auto
    Q = r8::born::q (D, T);
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
    r_ = 41.84 * (
          data.a_1 
        + data.a_2 / P_ 
        + data.a_3 / T_ 
        + data.a_4 / P_ / T_
        - omega * Q
        - (Z + 1) * domegadp
    );
    /*
    println (
          "D= {}\nZ= {}\nQ= {}\nomega_ref= {}\nr_ref= {}\ng = {}\nr= {}\nomega= {}\ndomegadp= {}\nmolar_volume= {}"
        , D
        , Z
        , Q
        , data.omega
        , re_ref
        , g
        , r
        , omega
        , domegadp
        , r_
    );
    */
    return r_;
    /*
    return 41.84 * (
          data.a_1 
        + data.a_2 / P_ 
        + data.a_3 / T_ 
        + data.a_4 / P_ / T_
        - omega * Q
        - (Z + 1) * domegadp
    );
    */
}
// eq. 62
    constexpr auto
heat_capacity_isobaric (sprons92::aqueous_species_t const& data, double T, double P)
{
        const auto
    P_ = P + 2600e5;
        const auto
    T_ = T - 228;
        const auto
    D = r6_inverse::density_pt (P, T);
        const auto
    X = r8::born::x (D, T);
        const auto
    Y = r8::born::y (D, T);
        const auto
    Z = r8::born::z (D, T);
        constexpr auto
    eta = 1.66027e5; // Å.cal.mol-1
    // This is eq. 56. The code adds a `gref` term here that doesn't appear in
    // the paper. The code is at react92d.f:838.
        const auto
    re_ref = Z * Z / (data.omega / eta + Z / 3.082);
        const auto
    g = detail::g (D / r8::detail::molar_mass_of_water, T, P);
        const auto
    r = re_ref + fabs (Z) * g;
        const auto
    omega = eta * (Z * Z / r - Z / (3.082 + g));
        const auto
    domegadp = eta * ( -fabs (pow (Z, 3)) / r / r + Z / pow (3.080 + g, 2)) 
        * detail::dg_dp(T, D, P)
    ;
        const auto
    dgdt = detail::dg_dt(T, D, P);
        const auto
    dgdtt = detail::dg_dtt(T, D, P);
    // The code does not consider the temperature dependency of Z when
    // differentiating omega, react92d.f:845.
        [[maybe_unused]]
        const auto
    domegadt = eta * ( -fabs (pow (Z, 3)) / r / r + Z / pow (3.080 + g, 2)) 
        * dgdt
    ;
        const auto
    domegadtt = eta * (
          2 * dgdt * dgdt * (pow (Z, 4) / pow (r, 3) - Z / pow (3.080 + g, 3))
        - dgdtt * (fabs (pow (Z, 3)) / pow (r, 2) - Z / pow (3.080 + g, 2))
    );
    return data.c_1 + data.c_2 / T_ / T_ - 2 * T / pow (T_, 3) * (
            data.a_3 * (P - 1e5) + data.a_4 * log (P_ / (2600e5 + 1e5))
        ) 
        + omega * T * X 
        + 2 * T * Y * domegadp 
        + T * (Z + 1) * domegadtt
    ;
}
} // namespace hkf
//
    auto
f (run_t const& run)
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
            const auto
        T = 273.15 + 25.;
            const auto
        P = 1.; // 1 bar
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
            if (data.phase_transition_count == 0)
            {
                println (
                      "  {:20} {:9.3f}   {:9.3f}   {:9.3f}     {:7.2f}"
                    , data.name
                    , data.a[0]
                    , data.b[0] * 1e3
                    , data.c[0] * 1e-5
                    , data.T_max - 273.15
                );
                continue;
            }
            print (
                  "  {:20} {:9.3f}   {:9.3f}   {:9.3f}     {:7.2f}      "
                , data.name
                , data.a[0]
                , data.b[0] * 1e3
                , data.c[0] * 1e-5
                , data.T[0] - 273.15
            );
            //"{:6.0f}         {:7.3f}         {:7.3f}     \n"
            print_or_not (data.DHt[0],   "{:6.0f}", 6);
            print_or_not (data.DVt[0],   "     {:7.3f}", 7 + 3);
            print_or_not (data.dP_dT[0], "{:7.3f}", 7 + 3);
            puts ("");
            for (auto i = 1; i <= data.phase_transition_count; ++i)
            {
                print (
                      "    post-transition {:1d}  {:9.3f}   {:9.3f}   {:9.3f}     {:7.2f}       "
                    , i
                    , (i == data.phase_transition_count ? data.a_n : data.a[i])
                    , (i == data.phase_transition_count ? data.b_n : data.b[i]) * 1e3
                    , (i == data.phase_transition_count ? data.c_n : data.c[i]) * 1e-5
                    , (i == data.phase_transition_count ? data.T_max : data.T[i]) - 273.15
                );
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
            V = hkf::molar_volume (data, T, P);
                const auto
            cp = hkf::heat_capacity_isobaric (data, T, P);
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
        {
        }
        /*
        print (header_aqueous_species_2);
        for (const auto& [coeff, data]: aqueous_species)
        {
            print (
                  "  {:20} {:9.3f}   {:9.3f}   {:9.3f}     {:7.2f}      \n"
                , data.chemical_formula_structural
                , data.a
                , data.b * 1e3
                , data.c * 1e-5
                , data.T_max - 273.15
            );
        }
        */
    }
    /*
    for (const auto& m: r.reactions[0].minerals)
    {
            const auto
        index = sprons92::mineral_name_to_index.find (m.first);
        if (index == sprons92::mineral_name_to_index.end ())
        {
            print ("Mineral not found: {}\n", m.first);
            exit (1);
        }
            const auto&
        data = sprons92::minerals.at (index->second);
            const auto
        T = 273.16 + 25.;
            const auto
        cp = data.a[0] + data.b[0] * T + data.c[0] / T / T;
        puts ("STANDARD STATE PROPERTIES OF THE SPECIES AT 25 DEG C AND 1 BAR\n");
        print ("{}  {} {} {} {} {}\n", data.name, data.DG, data.DH, data.S, data.V, cp);
    }
    */
}


    int
main ()
{
    f (skarn);
}
