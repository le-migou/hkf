#pragma once
#include <string_view>
    using namespace std::literals;
#include "hkf.hpp"
#include "database.hpp"

#include <ranges>
#include <sstream>
#include <fmt/ostream.h>
    using fmt::print, fmt::println;

    namespace 
calculisto::thermodynamics::hkf::supcrt92
{
    namespace
header
{
    constexpr auto
program = R"(
 ***** SUPCRT92: input/output specifications for this run

            USER-SPECIFIED  CON FILE  containing 
            T-P-D grid & option switches: {:20}

            USER-SPECIFIED  RXN FILE  containing 
            chemical reactions: {:20}

            THERMODYNAMIC DATABASE: {:20}

            SUPCRT-GENERATED  TAB FILE  containing 
            tabulated reaction properties (this file): {:20}

            SUPCRT-GENERATED  PLT FILES  containing 
            reaction properties for x-y plots: {:20} etc.

 ***** summary of option switches 

            isat, iopt, iplot, univar, noninc:  {:2d} {:2d} {:2d} {:2d} {:2d}

 ***** summary of state conditions 

            ISO{:12}:  min, max, increment:  {:10.4f}  {:10.4f}  {:10.4f}
            {:10} range: min, max, increment:  {:10.4f}  {:10.4f}  {:10.4f}

)"sv;

    constexpr auto
reaction = R"(
************************************ REACTION {:2}  ************************************

 REACTION TITLE: 

      {:80}


 REACTION STOICHIOMETRY: 

         COEFF.   NAME                   FORMULA
        -------   --------------------   --------------------
)";

    constexpr auto
minerals_1 = R"(

 STANDARD STATE PROPERTIES OF THE SPECIES AT 25 DEG C AND 1 BAR


                                           ...... MINERALS ...... 


                           DELTA G        DELTA H           S              V              Cp     
       NAME               (cal/mol)      (cal/mol)     (cal/mol/K)     (cc/mol)      (cal/mol/K) 
  --------------------  -------------  -------------  -------------  -------------  -------------
)"sv;

    constexpr auto
minerals_2 = R"(

                             MAIER-KELLY COEFFICIENTS                                PHASE TRANSITION DATA
       NAME              a(10**0)    b(10**3)    c(10**-5)  T limit (C)  Htr (cal/mol)   Vtr (cc/mol)   dPdTtr (bar/K)
  --------------------  ----------  ----------  ----------  -----------  -------------  --------------  --------------
)"sv;

    constexpr auto
gases_1 = R"(


                                           ...... GASES ......


                           DELTA G        DELTA H           S              V              Cp
       NAME               (cal/mol)      (cal/mol)     (cal/mol/K)      (cc/mol)     (cal/mol/K)
  --------------------  -------------  -------------  -------------  -------------  -------------
)"sv;

    constexpr auto
gases_2 = R"(

                             MAIER-KELLY COEFFICIENTS
       NAME              a(10**0)    b(10**3)    c(10**-5)  T limit (C)
  --------------------  ----------  ----------  ----------  ----------
)"sv;

    constexpr auto
aqueous_species_1 = R"(
    

                                     ...... AQUEOUS SPECIES ......


                           DELTA G        DELTA H           S              V              Cp
       NAME               (cal/mol)      (cal/mol)     (cal/mol/K)      (cc/mol)     (cal/mol/K)
  --------------------  -------------  -------------  -------------  -------------  -------------
)"sv;

    constexpr auto
aqueous_species_2 = R"(

                                                  EQUATION-OF-STATE COEFFICIENTS
       NAME              a1(10**1)     a2(10**-2)    a3(10**0)     a4(10**-4)    c1(10**0)     c2(10**-4)   omega(10**-5)
  --------------------  ------------  ------------  ------------  ------------  ------------  ------------  -------------
)"sv;

    constexpr auto
reaction_standard_state = R"(


 STANDARD STATE PROPERTIES OF THE REACTION AT 25 DEG C AND 1 BAR


                                                   DELTA G     DELTA H     DELTA S     DELTA V    DELTA Cp 
  PRES(bars)  TEMP(degC)  DH2O(g/cc)    LOG K       (cal)       (cal)      (cal/K)       (cc)      (cal/K)  
  ----------  ----------  ----------  ----------  ----------  ----------  ----------  ----------  ----------
)"sv;

    constexpr auto
reactions = R"(


 STANDARD STATE PROPERTIES OF THE REACTION AT ELEVATED TEMPERATURES AND PRESSURES 


                                                   DELTA G     DELTA H     DELTA S     DELTA V    DELTA Cp 
  PRES(bars)  TEMP(degC)  DH2O(g/cc)    LOG K       (cal)       (cal)      (cal/K)       (cc)      (cal/K)  
  ----------  ----------  ----------  ----------  ----------  ----------  ----------  ----------  ----------

)"sv;

    constexpr auto
minerals_details = R"(

 DETAILS


                                           ...... MINERALS ...... 


                           DELTA G        DELTA H           S              V              Cp     
       NAME               (cal/mol)      (cal/mol)     (cal/mol/K)     (cc/mol)      (cal/mol/K) 
  --------------------  -------------  -------------  -------------  -------------  -------------
)"sv;
} // namespace header


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

    template <class Number>
    struct
run_result_t
{
        std::vector <reaction_data_t>
    reactions_data;
        std::vector <reaction_properties_t <Number>>
    reactions_properties_at_standard_state;
        std::vector <std::vector <reaction_properties_t <Number>>>
    reactions_properties;
};

    template <class Number>
    auto
run (
      run_t const& run
    , database_t const& database
    , equation_of_state_h2o_t <Number> const& eos_h2o
){
        auto
    r = run_result_t <Number> {};
    for (auto const& reaction: run.reactions)
    {
        r.reactions_data.push_back (get_reaction_data (reaction, database));
            const auto&
        reaction_data = r.reactions_data.back ();
        r.reactions_properties_at_standard_state.push_back (
            compute_properties (reaction, reaction_data, T_ref, P_ref, eos_h2o)
        );

        // Reactions
            auto&
        reactions = r.reactions_properties.emplace_back ();
        for (auto P = run.isomin; P <= run.isomax; P += run.isoinc)
        {
                const auto
            pressure = P * 1e5;
            for (auto T = run.v2min; T <= run.v2max; T += run.v2inc)
            {
                    const  auto
                temperture = T + 273.15;
                reactions.push_back (compute_properties (
                      reaction
                    , reaction_data
                    , temperture
                    , pressure
                    , eos_h2o
                ));
            }
        }
    }
    return r;
}
    namespace
detail
{
    // Print values if they are valid (in the sense of supcrt, 999999 denotes an
    // invalid value).
        inline auto
    print_or_not (std::ostream& o, double value, std::string_view format, int width)
    {
        if (value !=  999999.) print (o, fmt::runtime (format), value);
        print (o, "{}", std::string (width, ' '));
    }
}

    template <class Number>
    auto
to_string (run_t const& run, run_result_t <Number> const& run_result)
{
        using std::views::enumerate, detail::print_or_not;
        auto
    r = std::ostringstream {};
    print (
          r
        , header::program
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
    for (auto const& [reaction_index, reaction]: enumerate (run.reactions))
    {
            const auto&
        reaction_data = run_result.reactions_data.at (reaction_index);
            const auto&
        standard_state = run_result.reactions_properties_at_standard_state.at (reaction_index);

        // Stoichiometry
        print (r, header::reaction, reaction_index + 1, reaction.title);
        for (auto const& [mineral_index, mineral]: enumerate (reaction.minerals))
        {
                const auto&
            data = reaction_data.minerals.at (mineral_index);
            println (
                  r
                , "      {:9.3f}   {:20}   {:30}"
                , mineral.coefficient
                , mineral.name
                , data.chemical_formula_structural
            );
        }
        for (auto const& [gas_index, gas]: enumerate (reaction.gases))
        {
                const auto&
            data = reaction_data.gases.at (gas_index);
            println (
                  r
                , "      {:9.3f}   {:20}   {:30}"
                , gas.coefficient
                , gas.name
                , data.chemical_formula_structural
            );
        }
        for (auto const& [aqueous_species_index, aqueous_species]: enumerate (reaction.aqueous_species))
        {
                const auto&
            data = reaction_data.aqueous_species.at (aqueous_species_index);
            println (
                  r
                , "      {:9.3f}   {:20}   {:30}"
                , aqueous_species.coefficient
                , aqueous_species.name
                , data.chemical_formula_structural
            );
        }
        println (
              r
            , "      {:9.3f}   {:20}   {:30}"
            , reaction.h2o
            , "H2O"
            , "H2O"
        );

        // Standard state properties of the species
        fmt::print (r, header::minerals_1);
        for (const auto& [index, data]: enumerate (reaction_data.minerals))
        {
            println (
                  r
                , "  {:20}  {:10.0f}     {:10.0f}        {:8.3f}       {:8.3f}        {:6.1f}      "
                , data.name
                  // database: units OK for output
                , data.DG
                , data.DH
                , data.S
                , data.V
                  // /!\ Computed value: in SI!
                , standard_state.minerals.at (index).isobaric_heat_capacity * calorie_per_joule
            );
        }
        fmt::print (r, header::minerals_2);
        for (const auto& data: reaction_data.minerals)
        {
            print (
                  r
                , "  {:20} {:9.3f}   {:9.3f}   {:9.3f}     {:7.2f}"
                , data.name
                , data.a[0]
                , data.b[0] * 1e3
                , data.c[0] * 1e-5
                , data.T[0] - 273.15
            );
            if (data.max_phase_transition_count == 0)
            {
                r << '\n';
                continue;
            }
            print_or_not (r, data.DHt[0],   "       {:6.0f}", 6);
            print_or_not (r, data.DVt[0],   "    {:7.3f}", 6 + 3);
            print_or_not (r, data.dP_dT[0], "{:7.3f}", 7 + 3);
            r << '\n';
            for (auto i = 1; i <= data.max_phase_transition_count; ++i)
            {
                print (
                      r
                    , "    post-transition {:1d}  {:9.3f}   {:9.3f}   {:9.3f}     {:7.2f}"
                    , i
                    , (data.a[i])
                    , (data.b[i]) * 1e3
                    , (data.c[i]) * 1e-5
                    , (data.T[i]) - 273.15
                );
                if (i == data.max_phase_transition_count) 
                {
                    r << '\n';
                    break;
                }
                print_or_not (r, data.DHt[i],   "       {:6.0f}", 6);
                print_or_not (r, data.DVt[i],   "    {:7.3f}", 6 + 3);
                print_or_not (r, data.dP_dT[i], "{:7.3f}", 7 + 3);
                r << '\n';
            }
        }
        fmt::print (r, header::gases_1);
        for (const auto& [index, data]: enumerate (reaction_data.gases))
        {
            println (
                  r
                , "  {:20}   {:10.0f}     {:10.0f}       {:8.3f}          {:2.0f}           {:6.1f}      "
                , data.chemical_formula_structural
                  // database: units OK for output
                , data.DG
                , data.DH
                , data.S
                , data.V
                  // /!\ Computed value: in SI!
                , standard_state.gases.at (index).isobaric_heat_capacity * calorie_per_joule
            );
        }
        fmt::print (r, header::gases_2);
        for (const auto& data: reaction_data.gases)
        {
            println (
                  r
                , "  {:20} {:9.3f}   {:9.3f}   {:9.3f}     {:7.2f}      "
                , data.chemical_formula_structural
                , data.a
                , data.b * 1e3
                , data.c * 1e-5
                , data.T_max - 273.15
            );
        }
        fmt::print (r, header::aqueous_species_1);
        for (const auto& [index, data]: enumerate (reaction_data.aqueous_species))
        {
            println (
                  r
                , "  {:20}   {:10.0f}     {:10.0f}       {:8.3f}       {:> 6.1f}           {:6.1f}      "
                , data.chemical_formula_structural
                  // database: units OK for output
                , data.DG
                , data.DH
                , data.S
                  // /!\ Computed value: in SI!
                , standard_state.aqueous_species.at (index).volume * 1e6
                , standard_state.aqueous_species.at (index).isobaric_heat_capacity * calorie_per_joule
            );
        }
        println (
              r
            , "  {:20}   {:10.0f}     {:10.0f}       {:8.3f}          {:2.0f}           {:6.1f}      "
            , "H2O"
            , standard_state.h2o.gibbs_energy / joule_per_calorie 
            , standard_state.h2o.enthalpy / joule_per_calorie 
            , standard_state.h2o.entropy / joule_per_calorie 
            , standard_state.h2o.volume
            , standard_state.h2o.isobaric_heat_capacity / joule_per_calorie
        );
        fmt::print (r, header::aqueous_species_2);
        for (const auto& [index, data]: enumerate (reaction_data.aqueous_species))
        {
            println (
                  r
                , "  {:20}      {:6.4f}       {: 6.4f}       {: 6.4f}       {: 6.4f}      {: 8.4f}       {: 6.4f}       {: 6.4f}"
                , data.name
                , data.a_1 * 1e1
                , data.a_2 * 1e-2
                , data.a_3 * 1e0
                , data.a_4 * 1e-4
                , data.c_1 * 1e0
                , data.c_2 * 1e-4
                , data.omega * 1e-5
            );
        }

        // Standard state
        fmt::print (r, header::reaction_standard_state);
        {
                const auto
            log_K = 
                -standard_state.reaction.gibbs_energy * calorie_per_joule
                / std::numbers::ln10 
                / gas_constant_in_cal_per_mol_per_K 
                / T_ref
            ;
            println (
                r
                , "   {:8.3f}    {:8.3f}    {:8.3f}    {:8.3f} {:10.0f}  {:10.0f}    {:10.3f}   {:8.3f}   {:8.3f}"
                , P_ref * 1e-5
                , T_ref - 273.15
                , standard_state.h2o.density * 1e-3
                , log_K
                , standard_state.reaction.gibbs_energy / joule_per_calorie 
                , standard_state.reaction.enthalpy / joule_per_calorie 
                , standard_state.reaction.entropy / joule_per_calorie 
                , standard_state.reaction.volume * 1e6
                , standard_state.reaction.isobaric_heat_capacity / joule_per_calorie
            );
        }
        if (1)
        { // {{{
            // -vvv- Details -vvv-
            fmt::print (r, header::minerals_details);
            for (auto const& [index, properties]: enumerate (standard_state.minerals))
            {
                println (
                    r
                    , "  {:20}   {:10.0f}     {:10.0f}       {:8.3f}          {:2.0f}           {:6.1f}      "
                    , reaction.minerals.at (index).name
                    , properties.gibbs_energy
                    , properties.enthalpy
                    , properties.entropy
                    , properties.volume * 1e6
                    , properties.isobaric_heat_capacity
                );
            }
            fmt::print (r, header::gases_1);
            for (auto const& [index, properties]: enumerate (standard_state.gases))
            {
                println (
                    r
                    , "  {:20}   {:10.0f}     {:10.0f}       {:8.3f}          {:2.0f}           {:6.1f}      "
                    , reaction.gases.at (index).name
                    , properties.gibbs_energy
                    , properties.enthalpy
                    , properties.entropy
                    , properties.volume * 1e6
                    , properties.isobaric_heat_capacity
                );
            }
            fmt::print (r, header::aqueous_species_1);
            for (auto const& [index, properties]: enumerate (standard_state.aqueous_species))
            {
                println (
                    r
                    , "  {:20}   {:10.0f}     {:10.0f}       {:8.3f}          {:2.0f}           {:6.1f}      "
                    , reaction.aqueous_species.at (index).name
                    , properties.gibbs_energy
                    , properties.enthalpy
                    , properties.entropy
                    , properties.volume * 1e6
                    , properties.isobaric_heat_capacity
                );
            }
            println (
                    r
                , "  {:20}   {:10.0f}     {:10.0f}       {:8.3f}          {:2.0f}           {:6.1f}      "
                , "H2O"
                , standard_state.h2o.gibbs_energy
                , standard_state.h2o.enthalpy
                , standard_state.h2o.entropy
                , standard_state.h2o.volume * 1e6
                , standard_state.h2o.isobaric_heat_capacity
            );
            // -^^^- Details -^^^-
        } // }}}

        // Reactions
        fmt::print (r, header::reactions);
            const auto&
        reactions = run_result.reactions_properties.at (reaction_index);
            auto
        reaction_iter = reactions.begin ();
        for (auto P = run.isomin; P <= run.isomax; P += run.isoinc)
        {
            for (auto T = run.v2min; T <= run.v2max; T += run.v2inc)
            {
                    const auto
                log_K = 
                    -reaction_iter->reaction.gibbs_energy * calorie_per_joule
                    / std::numbers::ln10 
                    / gas_constant_in_cal_per_mol_per_K 
                    / (T + 273.15)
                ;
                println (
                    r
                    , "   {:8.3f}    {:8.3f}    {:8.3f}    {:8.3f} {:10.0f}  {:10.0f}    {:10.3f}   {:8.3f}   {:8.3f}\n"
                    , P
                    , T
                    , reaction_iter->h2o.density * 1e-3
                    , log_K
                    , reaction_iter->reaction.gibbs_energy / joule_per_calorie 
                    , reaction_iter->reaction.enthalpy / joule_per_calorie 
                    , reaction_iter->reaction.entropy / joule_per_calorie 
                    , reaction_iter->reaction.volume * 1e6
                    , reaction_iter->reaction.isobaric_heat_capacity / joule_per_calorie
                );
                if (0)
                { // {{{
                    // -vvv- Details -vvv-
                    fmt::print (r, header::minerals_details);
                    for (auto const& [index, properties]: enumerate (reaction_iter->minerals))
                    {
                        println (
                            r
                            , "  {:20}   {:10.0f}     {:10.0f}       {:8.3f}          {:2.0f}           {:6.1f}      "
                            , reaction.minerals.at (index).name
                            , properties.gibbs_energy
                            , properties.enthalpy
                            , properties.entropy
                            , properties.volume * 1e6
                            , properties.isobaric_heat_capacity
                        );
                    }
                    fmt::print (r, header::gases_1);
                    for (auto const& [index, properties]: enumerate (reaction_iter->gases))
                    {
                        println (
                            r
                            , "  {:20}   {:10.0f}     {:10.0f}       {:8.3f}          {:2.0f}           {:6.1f}      "
                            , reaction.gases.at (index).name
                            , properties.gibbs_energy
                            , properties.enthalpy
                            , properties.entropy
                            , properties.volume * 1e6
                            , properties.isobaric_heat_capacity
                        );
                    }
                    fmt::print (r, header::aqueous_species_1);
                    for (auto const& [index, properties]: enumerate (reaction_iter->aqueous_species))
                    {
                        println (
                            r
                            , "  {:20}   {:10.0f}     {:10.0f}       {:8.3f}          {:2.0f}           {:6.1f}      "
                            , reaction.aqueous_species.at (index).name
                            , properties.gibbs_energy
                            , properties.enthalpy
                            , properties.entropy
                            , properties.volume * 1e6
                            , properties.isobaric_heat_capacity
                        );
                    }
                    println (
                            r
                        , "  {:20}   {:10.0f}     {:10.0f}       {:8.3f}          {:2.0f}           {:6.1f}      "
                        , "H2O"
                        , reaction_iter->h2o.gibbs_energy
                        , reaction_iter->h2o.enthalpy
                        , reaction_iter->h2o.entropy
                        , reaction_iter->h2o.volume * 1e6
                        , reaction_iter->h2o.isobaric_heat_capacity
                    );
                    // -^^^- Details -^^^-
                } // }}}
                ++reaction_iter;
            }
        }
    }
    return r.str ();
}
} // namespace calculisto::thermodynamics::hkf::supcrt92
