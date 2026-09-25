#pragma once
#include <string_view>
    using namespace std::literals;


    constexpr auto
header = R"(
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
header_reaction = R"(
************************************ REACTION {:2}  ************************************

 REACTION TITLE: 

      {:80}


 REACTION STOICHIOMETRY: 

         COEFF.   NAME                   FORMULA
        -------   --------------------   --------------------
)";

    constexpr auto
header_minerals_1 = R"(

 STANDARD STATE PROPERTIES OF THE SPECIES AT 25 DEG C AND 1 BAR


                                           ...... MINERALS ...... 


                           DELTA G        DELTA H           S              V              Cp     
       NAME               (cal/mol)      (cal/mol)     (cal/mol/K)     (cc/mol)      (cal/mol/K) 
  --------------------  -------------  -------------  -------------  -------------  -------------
)"sv;

    constexpr auto
header_minerals_2 = R"(

                             MAIER-KELLY COEFFICIENTS                                PHASE TRANSITION DATA
       NAME              a(10**0)    b(10**3)    c(10**-5)  T limit (C)  Htr (cal/mol)   Vtr (cc/mol)   dPdTtr (bar/K)
  --------------------  ----------  ----------  ----------  -----------  -------------  --------------  --------------
)"sv;

    constexpr auto
header_gases_1 = R"(


                                           ...... GASES ......


                           DELTA G        DELTA H           S              V              Cp
       NAME               (cal/mol)      (cal/mol)     (cal/mol/K)      (cc/mol)     (cal/mol/K)
  --------------------  -------------  -------------  -------------  -------------  -------------
)"sv;

    constexpr auto
header_gases_2 = R"(

                             MAIER-KELLY COEFFICIENTS
       NAME              a(10**0)    b(10**3)    c(10**-5)  T limit (C)
  --------------------  ----------  ----------  ----------  ----------
)"sv;

    constexpr auto
header_aqueous_species_1 = R"(
    

                                     ...... AQUEOUS SPECIES ......


                           DELTA G        DELTA H           S              V              Cp
       NAME               (cal/mol)      (cal/mol)     (cal/mol/K)      (cc/mol)     (cal/mol/K)
  --------------------  -------------  -------------  -------------  -------------  -------------
)"sv;

    constexpr auto
header_aqueous_species_2 = R"(

                                                  EQUATION-OF-STATE COEFFICIENTS
       NAME              a1(10**1)     a2(10**-2)    a3(10**0)     a4(10**-4)    c1(10**0)     c2(10**-4)   omega(10**-5)
  --------------------  ------------  ------------  ------------  ------------  ------------  ------------  -------------
)"sv;

    constexpr auto
header_reaction_standard_state = R"(

 STANDARD STATE PROPERTIES OF THE REACTION AT 25 DEG C AND 1 BAR


                                                   DELTA G     DELTA H     DELTA S     DELTA V    DELTA Cp 
  PRES(bars)  TEMP(degC)  DH2O(g/cc)    LOG K       (cal)       (cal)      (cal/K)       (cc)      (cal/K)  
  ----------  ----------  ----------  ----------  ----------  ----------  ----------  ----------  ----------
)"sv;
