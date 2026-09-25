#pragma once
#include <string_view>
#include <array>

    namespace
calculisto::thermodynamics::hkf
{
    namespace
detail
{
        struct
    data_base_t
    {
        // line 1
            std::string_view
        name;                         // mname, gname, aname
            std::string_view
        chemical_formula_structural;  // mform, gform, aform
        // line 2
            std::string_view
        abbreviation;
            std::string_view
        chemical_formula_elemental;
        // line 3
            std::string_view
        reference;
            std::string_view
        date;
        // line 4
            double
        DG;                     // Gfmin, Gfgas, Gfaqs
            double
        DH;                     // Hfmin, Hfgas, Hfaqs
            double
        S;                     // SprTrm, SPrTrg, SPrTra
    };
} // namespce detail

    struct
data_gas_t
    : detail::data_base_t
{
    // line 4, continued
        double
    V;                     // VPrTrg
        double
    a;                     // MKg(1)
        double
    b;                     // MKg(2) 
        double
    c;                     // MKg(3)
        double
    T_max; // Tmaxg
};
    struct
data_mineral_t
    : detail::data_base_t
{
    // line 4, continued
        double
    V;                          // VPrTrm
    // line(s) 5 (with transition(s))
    // line 5 (no transitions) or line 6 (with transition(s))
    // line 6 (no transitions) or line 7 (with transition(s))
        std::array <double, 4>
    a;                          // MK[1-4](1)
        std::array <double, 4>
    b;                          // MK[1-4](2)
        std::array <double, 4>
    c;                          // MK[1-4](3)
        std::array <double, 4>
    T;                          // Ttran
        std::array <double, 3>
    DHt;                        // Htran
        std::array <double, 3>
    DVt;                        // Vtran
        std::array <double, 3>
    dP_dT;                      // dPdTtr
    // Deduced
        int
    max_phase_transition_count; // ntran
};
    struct
data_aqueous_species_t
    : detail::data_base_t
{
    // line 5
        double
    a_1;                     // a(1)
        double
    a_2;                     // a(2)
        double
    a_3;                     // a(3)
        double
    a_4;                     // a(4)
    // line 6
        double
    c_1;                     // c(1)
        double
    c_2;                     // c(2)
        double
    omega;                   // wref
        double
    charge;                  // chg
};

    class
database_t
{
public:
    // We return copies (and not refs) because the data might need to be 
    // filtered.
        virtual data_mineral_t
    get_mineral (std::string_view name) const = 0;
        virtual data_gas_t
    get_gas (std::string_view name) const = 0;
        virtual data_aqueous_species_t
    get_aqueous_species (std::string_view name) const = 0;
};
} // namespace calculisto::thermodynamics::hkf
