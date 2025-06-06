#pragma once
#include <array>
#include <string_view>
#include <unordered_map>

    namespace
sprons92
{
        struct
    data_base_t
    {
            std::string_view
        name;
            std::string_view
        chemical_formula_structural;
            std::string_view
        abbreviation;
            std::string_view
        chemical_formula_elemental;
            std::string_view
        reference;
            std::string_view
        date;
            double
        DG;
            double
        DH;
            double
        S;
    };
        struct
    gas_t
        : data_base_t
    {
            double
        V;
            double
        a;
            double
        b;
            double
        c;
            double
        T_max;
    };
        struct
    mineral_t
        : data_base_t
    {
            double
        V;
            std::array <double, 3>
        a;
            std::array <double, 3>
        b;
            std::array <double, 3>
        c;
            std::array <double, 3>
        T;
            std::array <double, 3>
        DHt;
            std::array <double, 3>
        DVt;
            std::array <double, 3>
        dP_dT;
            double
        a_n;
            double
        b_n;
            double
        c_n;
            double
        T_max;
            int
        phase_transition_count;
    };
        struct
    aqueous_species_t
        :data_base_t
    {
            double
        a_1;
            double
        a_2;
            double
        a_3;
            double
        a_4;
            double
        c_1;
            double
        c_2;
            double
        omega;
            double
        charge;
    };

    enum class
type { mineral = 0, gas, aqueous_species };
    const auto
name_to_type = std::unordered_map <std::string_view, type>
{
      { "AKERMANITE", type::mineral }
    , { "ALABANDITE", type::mineral }
    , { "ALBITE,LOW", type::mineral }
    , { "ALUNITE", type::mineral }
    , { "AMESITE,7A", type::mineral }
    , { "AMORPHOUS-SILICA", type::mineral }
    , { "ANALCIME", type::mineral }
    , { "ANALCIME,DEHYDRATED", type::mineral }
    , { "ANDALUSITE", type::mineral }
    , { "ANDRADITE", type::mineral }
    , { "ANGLESITE", type::mineral }
    , { "ANHYDRITE", type::mineral }
    , { "ANNITE", type::mineral }
    , { "ANORTHITE", type::mineral }
    , { "ARAGONITE", type::mineral }
    , { "ARTINITE", type::mineral }
    , { "AZURITE", type::mineral }
    , { "BARITE", type::mineral }
    , { "BERNDTITE", type::mineral }
    , { "BOEHMITE", type::mineral }
    , { "BROMELLITE", type::mineral }
    , { "BRUCITE", type::mineral }
    , { "CA-AL-PYROXENE", type::mineral }
    , { "CALCITE", type::mineral }
    , { "CASSITERITE", type::mineral }
    , { "CELADONITE", type::mineral }
    , { "CELESTITE", type::mineral }
    , { "CERUSSITE", type::mineral }
    , { "CHABAZITE", type::mineral }
    , { "CHALCEDONY", type::mineral }
    , { "CHAMOSITE,7A", type::mineral }
    , { "CHLORARGYRITE", type::mineral }
    , { "CHLORITOID", type::mineral }
    , { "CHRYSOTILE", type::mineral }
    , { "CINNABAR", type::mineral }
    , { "CLINOCHLORE,14A", type::mineral }
    , { "CLINOZOISITE", type::mineral }
    , { "COPPER,NATIVE", type::mineral }
    , { "CORDIERITE", type::mineral }
    , { "CORDIERITE,HYDROUS", type::mineral }
    , { "CORUNDUM", type::mineral }
    , { "COVELLITE", type::mineral }
    , { "CRISTOBALITE,ALPHA", type::mineral }
    , { "CRISTOBALITE,BETA", type::mineral }
    , { "CUMMINGTONITE", type::mineral }
    , { "CUPRITE", type::mineral }
    , { "DAPHNITE,14A", type::mineral }
    , { "DIASPORE", type::mineral }
    , { "DICKITE", type::mineral }
    , { "DIOPSIDE", type::mineral }
    , { "DOLOMITE", type::mineral }
    , { "DOLOMITE,DISORDERED", type::mineral }
    , { "DOLOMITE,ORDERED", type::mineral }
    , { "EPIDOTE", type::mineral }
    , { "EPIDOTE,ORDERED", type::mineral }
    , { "FAYALITE", type::mineral }
    , { "FERROPARGASITE", type::mineral }
    , { "FERROTREMOLITE", type::mineral }
    , { "FERROUS-OXIDE", type::mineral }
    , { "FLUORITE", type::mineral }
    , { "FLUORPHLOGOPITE", type::mineral }
    , { "FLUORTREMOLITE", type::mineral }
    , { "FORSTERITE", type::mineral }
    , { "GALENA", type::mineral }
    , { "GEHLENITE", type::mineral }
    , { "GIBBSITE", type::mineral }
    , { "GLAUCOPHANE", type::mineral }
    , { "GOLD,NATIVE", type::mineral }
    , { "GRAPHITE", type::mineral }
    , { "GREENALITE", type::mineral }
    , { "GROSSULAR", type::mineral }
    , { "GRUNERITE", type::mineral }
    , { "HALITE", type::mineral }
    , { "HALLOYSITE", type::mineral }
    , { "HEDENBERGITE", type::mineral }
    , { "HUNTITE", type::mineral }
    , { "HYDROMAGNESITE", type::mineral }
    , { "JADEITE", type::mineral }
    , { "K-FELDSPAR", type::mineral }
    , { "KAOLINITE", type::mineral }
    , { "KYANITE", type::mineral }
    , { "LAUMONTITE", type::mineral }
    , { "LEONHARDITE", type::mineral }
    , { "LIME", type::mineral }
    , { "MAGNESITE", type::mineral }
    , { "MALACHITE", type::mineral }
    , { "MANGANOSITE", type::mineral }
    , { "MERWINITE", type::mineral }
    , { "METACINNABAR", type::mineral }
    , { "MICROCLINE,MAXIMUM", type::mineral }
    , { "MINNESOTAITE", type::mineral }
    , { "MONTICELLITE", type::mineral }
    , { "MUSCOVITE", type::mineral }
    , { "NEPHELINE", type::mineral }
    , { "PARAGONITE", type::mineral }
    , { "PARGASITE", type::mineral }
    , { "PERICLASE", type::mineral }
    , { "PHLOGOPITE", type::mineral }
    , { "POTASSIUM-OXIDE", type::mineral }
    , { "PYRITE", type::mineral }
    , { "PYROPHYLLITE", type::mineral }
    , { "RHODOCHROSITE", type::mineral }
    , { "RICHTERITE", type::mineral }
    , { "ROMARCHITE", type::mineral }
    , { "RUTILE", type::mineral }
    , { "SANIDINE,HIGH", type::mineral }
    , { "SEPIOLITE", type::mineral }
    , { "SIDERITE", type::mineral }
    , { "SILLIMANITE", type::mineral }
    , { "SILVER,NATIVE", type::mineral }
    , { "SMITHSONITE", type::mineral }
    , { "SODIUM-OXIDE", type::mineral }
    , { "SPHALERITE", type::mineral }
    , { "SPINEL", type::mineral }
    , { "STAUROLITE", type::mineral }
    , { "STRONTIANITE", type::mineral }
    , { "SYLVITE", type::mineral }
    , { "TALC", type::mineral }
    , { "TENORITE", type::mineral }
    , { "TITANITE", type::mineral }
    , { "TREMOLITE", type::mineral }
    , { "WAIRAKITE", type::mineral }
    , { "WITHERITE", type::mineral }
    , { "WOLLASTONITE", type::mineral }
    , { "WURTZITE", type::mineral }
    , { "ZINCITE", type::mineral }
    , { "ZOISITE", type::mineral }
    , { "ALBITE", type::mineral }
    , { "ALBITE,HIGH", type::mineral }
    , { "ALMANDINE", type::mineral }
    , { "AMESITE,14A", type::mineral }
    , { "ANTIGORITE", type::mineral }
    , { "CLINOCHLORE,7A", type::mineral }
    , { "COESITE", type::mineral }
    , { "CRISTOBALITE", type::mineral }
    , { "DAPHNITE,7A", type::mineral }
    , { "EDENITE", type::mineral }
    , { "EPISTILBITE", type::mineral }
    , { "FERROEDENITE", type::mineral }
    , { "FERROSILITE", type::mineral }
    , { "FLUOREDENITE", type::mineral }
    , { "HERZENBERGITE", type::mineral }
    , { "HEULANDITE", type::mineral }
    , { "KALSILITE", type::mineral }
    , { "LAWSONITE", type::mineral }
    , { "MAGNETITE", type::mineral }
    , { "MARGARITE", type::mineral }
    , { "NATROLITE", type::mineral }
    , { "NESQUEHONITE", type::mineral }
    , { "NICKEL", type::mineral }
    , { "PHILLIPSITE,CA", type::mineral }
    , { "PHILLIPSITE,K", type::mineral }
    , { "PHILLIPSITE,NA", type::mineral }
    , { "PREHNITE", type::mineral }
    , { "PYROPE", type::mineral }
    , { "QUARTZ", type::mineral }
    , { "QUICKSILVER", type::mineral }
    , { "SPESSARTINE", type::mineral }
    , { "STILBITE", type::mineral }
    , { "TIN,NATIVE", type::mineral }
    , { "ACANTHITE", type::mineral }
    , { "AEGERINE", type::mineral }
    , { "ANTHOPHYLLITE", type::mineral }
    , { "BORNITE", type::mineral }
    , { "BUNSENITE", type::mineral }
    , { "CHALCOCITE", type::mineral }
    , { "CHALCOPYRITE", type::mineral }
    , { "CRONSTEDTITE,7A", type::mineral }
    , { "ENSTATITE", type::mineral }
    , { "FERROGEDRITE", type::mineral }
    , { "HASTINGSITE", type::mineral }
    , { "HEMATITE", type::mineral }
    , { "LARNITE", type::mineral }
    , { "MAGNESIOHASTINGSITE", type::mineral }
    , { "MAGNESIORIEBECKITE", type::mineral }
    , { "PYRRHOTITE", type::mineral }
    , { "RIEBECKITE", type::mineral }
    , { "IRON", type::mineral }
    , { "PD-OXYANNITE", type::mineral }
    , { "ARGON", type::gas }
    , { "METHANE", type::gas }
    , { "CARBON-DIOXIDE", type::gas }
    , { "HYDROGEN", type::gas }
    , { "STEAM", type::gas }
    , { "HYDROGEN-SULFIDE", type::gas }
    , { "HELIUM", type::gas }
    , { "KRYPTON", type::gas }
    , { "NITROGEN", type::gas }
    , { "AMMONIA", type::gas }
    , { "NEON", type::gas }
    , { "OXYGEN", type::gas }
    , { "RADON", type::gas }
    , { "SULFUR", type::gas }
    , { "SULFUR-DIOXIDE", type::gas }
    , { "XENON", type::gas }
    , { "1-BUTANAMINE,AQ", type::aqueous_species }
    , { "1-BUTANOL,AQ", type::aqueous_species }
    , { "1-BUTENE,AQ", type::aqueous_species }
    , { "1-BUTYNE,AQ", type::aqueous_species }
    , { "1-HEPTANAMINE,AQ", type::aqueous_species }
    , { "1-HEPTANOL,AQ", type::aqueous_species }
    , { "1-HEPTENE,AQ", type::aqueous_species }
    , { "1-HEPTYNE,AQ", type::aqueous_species }
    , { "1-HEXANAMINE,AQ", type::aqueous_species }
    , { "1-HEXANOL,AQ", type::aqueous_species }
    , { "1-HEXENE,AQ", type::aqueous_species }
    , { "1-HEXYNE,AQ", type::aqueous_species }
    , { "1-OCTANAMINE,AQ", type::aqueous_species }
    , { "1-OCTANOL,AQ", type::aqueous_species }
    , { "1-OCTENE,AQ", type::aqueous_species }
    , { "1-OCTYNE,AQ", type::aqueous_species }
    , { "1-PENTANAMINE,AQ", type::aqueous_species }
    , { "1-PENTANOL,AQ", type::aqueous_species }
    , { "1-PENTENE,AQ", type::aqueous_species }
    , { "1-PENTYNE,AQ", type::aqueous_species }
    , { "1-PROPANAMINE,AQ", type::aqueous_species }
    , { "1-PROPANOL,AQ", type::aqueous_species }
    , { "1-PROPENE,AQ", type::aqueous_species }
    , { "1-PROPYNE,AQ", type::aqueous_species }
    , { "2-BUTANONE,AQ", type::aqueous_species }
    , { "2-HEPTANONE,AQ", type::aqueous_species }
    , { "2-HEXANONE,AQ", type::aqueous_species }
    , { "2-OCTANONE,AQ", type::aqueous_species }
    , { "2-PENTANONE,AQ", type::aqueous_species }
    , { "A-AMINOBUTYRIC,AQ", type::aqueous_species }
    , { "ACETATE,AQ", type::aqueous_species }
    , { "ACETIC-ACID,AQ", type::aqueous_species }
    , { "ACETONE,AQ", type::aqueous_species }
    , { "ALANINE,AQ", type::aqueous_species }
    , { "ASPARAGINE,AQ", type::aqueous_species }
    , { "ASPARTIC-ACID,AQ", type::aqueous_species }
    , { "Ag(CO3)-", type::aqueous_species }
    , { "Ag(CO3)2-3", type::aqueous_species }
    , { "Ag+", type::aqueous_species }
    , { "Ag+2", type::aqueous_species }
    , { "AgCl,aq", type::aqueous_species }
    , { "AgCl2-", type::aqueous_species }
    , { "AgCl3-2", type::aqueous_species }
    , { "AgCl4-3", type::aqueous_species }
    , { "AgNO3,aq", type::aqueous_species }
    , { "Al(OH)+2", type::aqueous_species }
    , { "Al+3", type::aqueous_species }
    , { "Ar,aq", type::aqueous_species }
    , { "Au+", type::aqueous_species }
    , { "Au+3", type::aqueous_species }
    , { "B(OH)3,aq", type::aqueous_species }
    , { "BENZENE,AQ", type::aqueous_species }
    , { "BF4-", type::aqueous_species }
    , { "BO2-", type::aqueous_species }
    , { "BUTANOATE,AQ", type::aqueous_species }
    , { "BUTANOIC-ACID,AQ", type::aqueous_species }
    , { "Ba(CO3),aq", type::aqueous_species }
    , { "Ba+2", type::aqueous_species }
    , { "BaCl+", type::aqueous_species }
    , { "BaF+", type::aqueous_species }
    , { "Be+2", type::aqueous_species }
    , { "BeO2-2", type::aqueous_species }
    , { "Br-", type::aqueous_species }
    , { "Br3-", type::aqueous_species }
    , { "BrO-", type::aqueous_species }
    , { "BrO3-", type::aqueous_species }
    , { "BrO4-", type::aqueous_species }
    , { "CN-", type::aqueous_species }
    , { "CO2,aq", type::aqueous_species }
    , { "CO3-2", type::aqueous_species }
    , { "Ca(CO3),aq", type::aqueous_species }
    , { "Ca(HCO3)+", type::aqueous_species }
    , { "Ca+2", type::aqueous_species }
    , { "CaCl+", type::aqueous_species }
    , { "CaCl2,aq", type::aqueous_species }
    , { "CaF+", type::aqueous_species }
    , { "CaSO4,aq", type::aqueous_species }
    , { "Cd+2", type::aqueous_species }
    , { "Ce+3", type::aqueous_species }
    , { "Cl-", type::aqueous_species }
    , { "ClO-", type::aqueous_species }
    , { "ClO2-", type::aqueous_species }
    , { "ClO3-", type::aqueous_species }
    , { "ClO4-", type::aqueous_species }
    , { "Co+2", type::aqueous_species }
    , { "Co+3", type::aqueous_species }
    , { "Cr2O7-2", type::aqueous_species }
    , { "CrO4-2", type::aqueous_species }
    , { "Cs+", type::aqueous_species }
    , { "CsBr,aq", type::aqueous_species }
    , { "CsCl,aq", type::aqueous_species }
    , { "CsI,aq", type::aqueous_species }
    , { "Cu+", type::aqueous_species }
    , { "Cu+2", type::aqueous_species }
    , { "Dy+3", type::aqueous_species }
    , { "ETHANAMINE,AQ", type::aqueous_species }
    , { "ETHANE,AQ", type::aqueous_species }
    , { "ETHANOL,AQ", type::aqueous_species }
    , { "ETHYLBENZENE,AQ", type::aqueous_species }
    , { "ETHYLENE,AQ", type::aqueous_species }
    , { "ETHYNE,AQ", type::aqueous_species }
    , { "Er+3", type::aqueous_species }
    , { "Eu+2", type::aqueous_species }
    , { "Eu+3", type::aqueous_species }
    , { "F-", type::aqueous_species }
    , { "FORMATE,AQ", type::aqueous_species }
    , { "FORMIC-ACID,AQ", type::aqueous_species }
    , { "Fe(CH3COO)+", type::aqueous_species }
    , { "Fe(CH3COO)2,aq", type::aqueous_species }
    , { "Fe+2", type::aqueous_species }
    , { "Fe+3", type::aqueous_species }
    , { "FeCl+", type::aqueous_species }
    , { "FeCl2,aq", type::aqueous_species }
    , { "GLUTAMIC-ACID,AQ", type::aqueous_species }
    , { "GLUTAMINE,AQ", type::aqueous_species }
    , { "GLYCINE,AQ", type::aqueous_species }
    , { "Ga+3", type::aqueous_species }
    , { "Gd+3", type::aqueous_species }
    , { "H+", type::aqueous_species }
    , { "H2,aq", type::aqueous_species }
    , { "H2AsO3-", type::aqueous_species }
    , { "H2AsO4-", type::aqueous_species }
    , { "H2P2O7-2", type::aqueous_species }
    , { "H2PO4-", type::aqueous_species }
    , { "H2S,aq", type::aqueous_species }
    , { "H2VO4-", type::aqueous_species }
    , { "H3P2O7-", type::aqueous_species }
    , { "H3PO4,aq", type::aqueous_species }
    , { "HAsO4-2", type::aqueous_species }
    , { "HCO3-", type::aqueous_species }
    , { "HCrO4-", type::aqueous_species }
    , { "HEPTANOATE,AQ", type::aqueous_species }
    , { "HEPTANOIC-ACID,AQ", type::aqueous_species }
    , { "HEXANOATE,AQ", type::aqueous_species }
    , { "HEXANOIC-ACID,AQ", type::aqueous_species }
    , { "HF,aq", type::aqueous_species }
    , { "HF2-", type::aqueous_species }
    , { "HNO3,aq", type::aqueous_species }
    , { "HO2-", type::aqueous_species }
    , { "HPO4-2", type::aqueous_species }
    , { "HS-", type::aqueous_species }
    , { "HSO3-", type::aqueous_species }
    , { "HSO4-", type::aqueous_species }
    , { "HSO5-", type::aqueous_species }
    , { "HSe-", type::aqueous_species }
    , { "HSeO3-", type::aqueous_species }
    , { "HSeO4-", type::aqueous_species }
    , { "HSiO3-", type::aqueous_species }
    , { "HVO4-2", type::aqueous_species }
    , { "He,aq", type::aqueous_species }
    , { "Hg+2", type::aqueous_species }
    , { "Hg2+2", type::aqueous_species }
    , { "Ho+3", type::aqueous_species }
    , { "I-", type::aqueous_species }
    , { "I3-", type::aqueous_species }
    , { "IO-", type::aqueous_species }
    , { "IO3-", type::aqueous_species }
    , { "IO4-", type::aqueous_species }
    , { "ISOLEUCINE,AQ", type::aqueous_species }
    , { "In+3", type::aqueous_species }
    , { "K+", type::aqueous_species }
    , { "KBr,aq", type::aqueous_species }
    , { "KCl,aq", type::aqueous_species }
    , { "KHSO4,aq", type::aqueous_species }
    , { "KI,aq", type::aqueous_species }
    , { "KSO4-", type::aqueous_species }
    , { "Kr,aq", type::aqueous_species }
    , { "LEUCINE,AQ", type::aqueous_species }
    , { "La+3", type::aqueous_species }
    , { "Li+", type::aqueous_species }
    , { "LiCl,aq", type::aqueous_species }
    , { "Lu+3", type::aqueous_species }
    , { "METHANAMINE,AQ", type::aqueous_species }
    , { "METHANE,AQ", type::aqueous_species }
    , { "METHANOL,AQ", type::aqueous_species }
    , { "METHIONINE,AQ", type::aqueous_species }
    , { "Mg(CO3),aq", type::aqueous_species }
    , { "Mg(HCO3)+", type::aqueous_species }
    , { "Mg+2", type::aqueous_species }
    , { "MgCl+", type::aqueous_species }
    , { "MgF+", type::aqueous_species }
    , { "Mn+2", type::aqueous_species }
    , { "MnCl+", type::aqueous_species }
    , { "MnO4-", type::aqueous_species }
    , { "MnO4-2", type::aqueous_species }
    , { "MnSO4,aq", type::aqueous_species }
    , { "MoO4-2", type::aqueous_species }
    , { "N-BUTANE,AQ", type::aqueous_species }
    , { "N-BUTYLBENZENE,AQ", type::aqueous_species }
    , { "N-HEPTANE,AQ", type::aqueous_species }
    , { "N-HEPTYLBENZENE,AQ", type::aqueous_species }
    , { "N-HEXANE,AQ", type::aqueous_species }
    , { "N-HEXYLBENZENE,AQ", type::aqueous_species }
    , { "N-OCTANE,AQ", type::aqueous_species }
    , { "N-OCTYLBENZENE,AQ", type::aqueous_species }
    , { "N-PENTANE,AQ", type::aqueous_species }
    , { "N-PENTYLBENZENE,AQ", type::aqueous_species }
    , { "N-PROPYLBENZENE,AQ", type::aqueous_species }
    , { "N2,aq", type::aqueous_species }
    , { "NH3,aq", type::aqueous_species }
    , { "NH4+", type::aqueous_species }
    , { "NO2-", type::aqueous_species }
    , { "NO3-", type::aqueous_species }
    , { "Na+", type::aqueous_species }
    , { "NaBr,aq", type::aqueous_species }
    , { "NaCl,aq", type::aqueous_species }
    , { "NaF,aq", type::aqueous_species }
    , { "NaHSiO3,aq", type::aqueous_species }
    , { "NaI,aq", type::aqueous_species }
    , { "Nd+3", type::aqueous_species }
    , { "Ne,aq", type::aqueous_species }
    , { "Ni+2", type::aqueous_species }
    , { "NiCl+", type::aqueous_species }
    , { "O2,aq", type::aqueous_species }
    , { "OCTANOATE,AQ", type::aqueous_species }
    , { "OCTANOIC-ACID,AQ", type::aqueous_species }
    , { "OH-", type::aqueous_species }
    , { "PENTANOATE,AQ", type::aqueous_species }
    , { "PENTANOIC-ACID,AQ", type::aqueous_species }
    , { "PHENOL,AQ", type::aqueous_species }
    , { "PHENYLALANINE,AQ", type::aqueous_species }
    , { "PO4-3", type::aqueous_species }
    , { "PROPANE,AQ", type::aqueous_species }
    , { "PROPANOATE,AQ", type::aqueous_species }
    , { "PROPANOIC-ACID,AQ", type::aqueous_species }
    , { "Pb(CH3COO)+", type::aqueous_species }
    , { "Pb(CH3COO)2,aq", type::aqueous_species }
    , { "Pb+2", type::aqueous_species }
    , { "PbCl+", type::aqueous_species }
    , { "PbCl2,aq", type::aqueous_species }
    , { "PbCl3-", type::aqueous_species }
    , { "PbCl4-2", type::aqueous_species }
    , { "Pd+2", type::aqueous_species }
    , { "Pr+3", type::aqueous_species }
    , { "Ra+2", type::aqueous_species }
    , { "Rb+", type::aqueous_species }
    , { "RbBr,aq", type::aqueous_species }
    , { "RbCl,aq", type::aqueous_species }
    , { "RbF,aq", type::aqueous_species }
    , { "RbI,aq", type::aqueous_species }
    , { "ReO4-", type::aqueous_species }
    , { "Rn,aq", type::aqueous_species }
    , { "S2-2", type::aqueous_species }
    , { "S2O3-2", type::aqueous_species }
    , { "S2O4-2", type::aqueous_species }
    , { "S2O5-2", type::aqueous_species }
    , { "S2O6-2", type::aqueous_species }
    , { "S2O8-2", type::aqueous_species }
    , { "S3-2", type::aqueous_species }
    , { "S3O6-2", type::aqueous_species }
    , { "S4-2", type::aqueous_species }
    , { "S4O6-2", type::aqueous_species }
    , { "S5-2", type::aqueous_species }
    , { "S5O6-2", type::aqueous_species }
    , { "SERINE,AQ", type::aqueous_species }
    , { "SO2,aq", type::aqueous_species }
    , { "SO3-2", type::aqueous_species }
    , { "SO4-2", type::aqueous_species }
    , { "Sc+3", type::aqueous_species }
    , { "SeO3-2", type::aqueous_species }
    , { "SeO4-2", type::aqueous_species }
    , { "SiF6-2", type::aqueous_species }
    , { "SiO2,aq", type::aqueous_species }
    , { "Sm+2", type::aqueous_species }
    , { "Sm+3", type::aqueous_species }
    , { "Sn+2", type::aqueous_species }
    , { "Sr(CO3),aq", type::aqueous_species }
    , { "Sr+2", type::aqueous_species }
    , { "SrCl+", type::aqueous_species }
    , { "SrF+", type::aqueous_species }
    , { "THREONINE,AQ", type::aqueous_species }
    , { "TOLUENE,AQ", type::aqueous_species }
    , { "TRYPTOPHAN,AQ", type::aqueous_species }
    , { "TYROSINE,AQ", type::aqueous_species }
    , { "Tb+3", type::aqueous_species }
    , { "Tl+", type::aqueous_species }
    , { "Tl+3", type::aqueous_species }
    , { "Tm+3", type::aqueous_species }
    , { "VALINE,AQ", type::aqueous_species }
    , { "VO+2", type::aqueous_species }
    , { "VO2+", type::aqueous_species }
    , { "WO4-2", type::aqueous_species }
    , { "Xe,aq", type::aqueous_species }
    , { "Y+3", type::aqueous_species }
    , { "Yb+2", type::aqueous_species }
    , { "Yb+3", type::aqueous_species }
    , { "Zn(CH3COO)+", type::aqueous_species }
    , { "Zn(CH3COO)2,aq", type::aqueous_species }
    , { "Zn(CH3COO)3-", type::aqueous_species }
    , { "Zn+2", type::aqueous_species }
    , { "ZnCl+", type::aqueous_species }
    , { "ZnCl2,aq", type::aqueous_species }
    , { "ZnCl3-", type::aqueous_species }
    , { "ZnCl4-2", type::aqueous_species }
};
    const auto
minerals = std::array <mineral_t, 179>
{{
      { { "AKERMANITE", "Ca2MgSi2O7", "Ak", "Ca(2)Mg(1)Si(2)O(7)", "ref:1,19", "15.Mar.90", -879362, -926497, 50.03 }, 92.81, { 60.09, 0, 0 }, { 0.0114, 0, 0 }, { -1140000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1700, 0 }
    , { { "ALABANDITE", "MnS", "Alb", "Mn(1)S(1)", "ref:1", "5.May.78", -52178, -51000, 19.2 }, 21.46, { 11.4, 0, 0 }, { 0.0018000000000000002, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1803, 0 }
    , { { "ALBITE,LOW", "Na(AlSi3)O8", "Lo-Ab", "Na(1)Al(1)Si(3)O(8)", "ref:1", "5.May.78", -886308, -939680, 49.51 }, 100.07, { 61.7, 0, 0 }, { 0.013900000000000001, 0, 0 }, { -1501000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1400, 0 }
    , { { "ALUNITE", "KAl3(OH)6(SO4)2", "Alu", "K(1)Al(3)S(2)O(14)H(6)", "ref:1", "5.May.78", -1113600, -1235600, 78.4 }, 293.6, { 153.45, 0, 0 }, { 0, 0, 0 }, { -5495000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 650, 0 }
    , { { "AMESITE,7A", "Mg2Al(AlSi)O5(OH)4", "Ams-7A", "Mg(2)Al(2)Si(1)O(9)H(4)", "ref:1", "5.May.78", 999999, 999999, 52 }, 103, { 81.03, 0, 0 }, { 0.024738, 0, 0 }, { -2023000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "AMORPHOUS-SILICA", "SiO2*NH2O", "Amor-Sl", "Si(1)O(2)H(2N)O(N)", "ref:1", "5.May.78", -202892, -214568, 14.34 }, 29, { 5.93, 0, 0 }, { 0.047200000000000006, 0, 0 }, { -2278000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 622, 0 }
    , { { "ANALCIME", "NaAlSi2O6*H2O", "Anl", "Na(1)Al(1)Si(2)O(7)H(2)", "ref:1", "5.May.78", -738098, -790193, 56 }, 97.1, { 53.49, 0, 0 }, { 0.02414, 0, 0 }, { -888000.0000000001, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "ANALCIME,DEHYDRATED", "NaAlSi2O6", "Dhyd-Anl", "Na(1)Al(1)Si(2)O(6)", "ref:1", "5.May.78", -674989, -714678, 41.9 }, 89.1, { 42.09, 0, 0 }, { 0.02414, 0, 0 }, { -888000.0000000001, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "ANDALUSITE", "Al2SiO5", "And", "Al(2)Si(1)O(5)", "ref:1", "5.May.78", -580587, -615866, 22.2 }, 51.53, { 41.310833, 0, 0 }, { 0.006292556, 0, 0 }, { -1239206.3, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1043, 0 }
    , { { "ANDRADITE", "Ca3Fe2Si3O12", "Adr", "Ca(3)Fe(2)Si(3)O(12)", "ref:1,19", "15.Mar.90", -1296819, -1380345, 70.13 }, 131.85, { 113.532, 0, 0 }, { 0.015636, 0, 0 }, { -3088900, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1100, 0 }
    , { { "ANGLESITE", "PbSO4", "Ang", "Pb(1)S(1)O(4)", "ref:1", "5.May.78", -194353, -219870, 35.51 }, 47.95, { 10.96, 0, 0 }, { 0.031, 0, 0 }, { 420000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1100, 0 }
    , { { "ANHYDRITE", "CaSO4", "Anh", "Ca(1)S(1)O(4)", "ref:1", "5.May.78", -315925, -342760, 25.5 }, 45.94, { 16.78, 0, 0 }, { 0.023600000000000003, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1453, 0 }
    , { { "ANNITE", "KFe3(AlSi3)O10(OH)2", "Ann", "K(1)Fe(3)Al(1)Si(3)O(12)H(2)", "ref:1", "5.May.78", -1147156, -1232195, 95.2 }, 154.32, { 106.43, 0, 0 }, { 0.02977, 0, 0 }, { -1930999.9999999998, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "ANORTHITE", "Ca(Al2Si2)O8", "An", "Ca(1)Al(2)Si(2)O(8)", "ref:1,19", "15.Mar.90", -954078, -1007552, 49.1 }, 100.79, { 63.311, 0, 0 }, { 0.014794000000000002, 0, 0 }, { -1544000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1700, 0 }
    , { { "ARAGONITE", "CaCO3", "Arg", "Ca(1)C(1)O(3)", "ref:1,18", "9.Mar.90", -269683, -288531, 21.56 }, 34.15, { 20.13, 0, 0 }, { 0.01024, 0, 0 }, { -334000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 600, 0 }
    , { { "ARTINITE", "Mg2(OH)2(CO3)*3H2O", "Art", "Mg(2)C(1))O(8)H(8)", "ref:1", "5.May.78", -613915, -698043, 55.67 }, 96.9, { 70.87, 0, 0 }, { 0.02766, 0, 0 }, { -743000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "AZURITE", "Cu3(OH)2(CO3)2", "Azr", "Cu(3)C(2)O(8)H(2)", "ref:1", "5.May.78", -334417, -390100, 66.97 }, 91.01, { 36.88, 0, 0 }, { 0.07744, 0, 0 }, { -92000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 780, 0 }
    , { { "BARITE", "BaSO4", "Brt", "Ba(1)S(1)O(4)", "ref:1", "5.May.78", -325563, -352100, 31.6 }, 52.1, { 33.8, 0, 0 }, { 0, 0, 0 }, { -843000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1422, 0 }
    , { { "BERNDTITE", "SnS2", "Brn", "Sn(1)S(2)", "ref:12", "5.May.78", -34750, -36700, 20.9 }, 40.96, { 15.51, 0, 0 }, { 0.004200000000000001, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "BOEHMITE", "AlO(OH)", "Bhm", "Al(1)O(2)H(1)", "ref:1", "5.May.78", -217250, -235078, 11.58 }, 19.535, { 14.435, 0, 0 }, { 0.004200000000000001, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 500, 0 }
    , { { "BROMELLITE", "BeO", "Brm", "Be(1)O(1)", "ref:1", "5.May.78", 999999, 999999, 3.38 }, 8.309, { 8.45, 0, 0 }, { 0.004, 0, 0 }, { -317000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1200, 0 }
    , { { "BRUCITE", "Mg(OH)2", "Brc", "Mg(1)O(2)H(2)", "ref:1", "5.May.78", -199646, -221390, 15.09 }, 24.63, { 24.147, 0, 0 }, { 0.0040124, 0, 0 }, { -611000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 900, 0 }
    , { { "CA-AL-PYROXENE", "CaAl(AlSi)O6", "Ca-Al-Px", "Ca(1)Al(2)Si(1)O(6)", "ref:1,19", "15.Mar.90", -742067, -783793, 35 }, 63.5, { 54.13, 0, 0 }, { 0.00642, 0, 0 }, { -1490000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1400, 0 }
    , { { "CALCITE", "CaCO3", "Cal", "Ca(1)C(1)O(3)", "ref:1,18", "9.Mar.90", -269880, -288552, 22.15 }, 36.934, { 24.98, 0, 0 }, { 0.005240000000000001, 0, 0 }, { -620000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1200, 0 }
    , { { "CASSITERITE", "SnO2", "Cst", "Sn(1)O(2)", "ref:12", "5.May.78", -124260, -138800, 12.5 }, 21.55, { 17.246, 0, 0 }, { 0.0028026, 0, 0 }, { -490010, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1500, 0 }
    , { { "CELADONITE", "K(MgAl)Si4O10(OH)2", "Cln", "K(1)Mg(1)Al(1)Si(4)O(12)H(2)", "ref:1", "5.May.78", 999999, 999999, 74.9 }, 157.1, { 80.25, 0, 0 }, { 0.0253, 0, 0 }, { -1854000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "CELESTITE", "SrSO4", "Cls", "Sr(1)S(1)O(4)", "ref:1", "5.May.78", -320435, -347300, 28 }, 46.25, { 21.8, 0, 0 }, { 0.013300000000000001, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1500, 0 }
    , { { "CERUSSITE", "PbCO3", "Cer", "Pb(1)C(1)O(3)", "ref:1", "5.May.78", -150370, -168000, 31.3 }, 40.59, { 12.39, 0, 0 }, { 0.0286, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 800, 0 }
    , { { "CHABAZITE", "Ca(Al2Si4)O12*6H2O", "Cbz", "Ca(1)Al(2)Si(4)O(18)H(12)", "ref:1", "5.May.78", 999999, 999999, 152.9 }, 247.76, { 146, 0, 0 }, { 0.04447, 0, 0 }, { -1643000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "CHALCEDONY", "SiO2", "Cha", "Si(1)O(2)", "ref:1", "5.May.78", -204276, -217282, 9.88 }, 22.688, { 11.22, 0, 0 }, { 0.008199999999999999, 0, 0 }, { -270000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 848, 0 }
    , { { "CHAMOSITE,7A", "Fe2Al(AlSi)O5(OH)4", "Chm-7A", "Fe(2)Al(2)Si(1)O(9)H(4)", "ref:1", "5.May.78", 999999, 999999, 64.7 }, 106.2, { 84.91, 0, 0 }, { 0.0254, 0, 0 }, { -1877000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "CHLORARGYRITE", "AgCl", "Crg", "Ag(1)Cl(1)", "ref:7,15", "5.May.78", -26247, -30370, 23 }, 25.727, { 14.33, 0, 0 }, { 0.001821, 0, 0 }, { -243000.00000000003, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 728, 0 }
    , { { "CHLORITOID", "FeAl2SiO5(OH)2", "Cld", "Fe(1)Al(2)Si(1)O(7)H(2)", "ref:1", "5.May.78", 999999, 999999, 42.1 }, 69.8, { 60.63, 0, 0 }, { 0.01713, 0, 0 }, { -1363000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "CHRYSOTILE", "Mg3Si2O5(OH)4", "Ctl", "Mg(3)Si(2)O(9)H(4)", "ref:1", "5.May.78", -964871, -1043123, 52.9 }, 108.5, { 75.82, 0, 0 }, { 0.0316, 0, 0 }, { -1757999.9999999998, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "CINNABAR", "HgS", "Cin", "Hg(1)S(1)", "ref:1", "5.May.78", -10940, -12750, 19.7 }, 28.416, { 10.46, 0, 0 }, { 0.00372, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 618, 0 }
    , { { "CLINOCHLORE,14A", "Mg5Al(AlSi3)O10(OH)8", "14A-Cnc", "Mg(5)Al(2)Si(3)O(18)H(8)", "ref:1", "5.May.78", -1961703, -2116964, 111.2 }, 207.11, { 166.5, 0, 0 }, { 0.042100000000000005, 0, 0 }, { -3747000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 900, 0 }
    , { { "CLINOZOISITE", "Ca2Al3Si3O12(OH)", "Czo", "Ca(2)Al(3)Si(3)O(13)H(1)", "ref:1,19", "15.Mar.90", -1549240, -1643781, 70.64 }, 136.2, { 106.118, 0, 0 }, { 0.025214, 0, 0 }, { -2714500, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 700, 0 }
    , { { "COPPER,NATIVE", "Cu", "Cu", "Cu(1)", "ref:1", "5.May.78", 0, 0, 7.923 }, 7.113, { 5.41, 0, 0 }, { 0.0015, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1357, 0 }
    , { { "CORDIERITE", "Mg2Al3(AlSi5)O18", "Crd", "Mg(2)Al(4)Si(5)O(18)", "ref:1", "5.May.78", -2061279, -2183199, 97.33 }, 233.22, { 143.83, 0, 0 }, { 0.0258, 0, 0 }, { -3860000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1700, 0 }
    , { { "CORDIERITE,HYDROUS", "Mg2Al3(AlSi5)O18*H20", "Hyd-Crd", "Mg(2)Al(4)Si(5)O(19)H(2)", "ref:1", "5.May.78", -2121350, -2255676, 111.43 }, 241.22, { 155.23, 0, 0 }, { 0.0258, 0, 0 }, { -3860000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1700, 0 }
    , { { "CORUNDUM", "Al2O3", "Crn", "Al(2)O(3)", "ref:1", "5.May.78", -374824, -397145, 12.18 }, 25.575, { 27.49, 0, 0 }, { 0.00282, 0, 0 }, { -838000.0000000001, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1800, 0 }
    , { { "COVELLITE", "CuS", "Cv", "Cu(1)S(1)", "ref:1", "5.May.78", -12612, -12500, 15.9 }, 20.42, { 10.6, 0, 0 }, { 0.00264, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1273, 0 }
    , { { "CRISTOBALITE,ALPHA", "SiO2", "A-Crs", "Si(1)O(2)", "ref:1", "5.May.78", -203895, -216755, 10.372 }, 25.74, { 13.98, 0, 0 }, { 0.00334, 0, 0 }, { -381000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "CRISTOBALITE,BETA", "SiO2", "B-Crs", "Si(1)O(2)", "ref:1", "5.May.78", -203290, -215675, 11.963 }, 27.38, { 17.39, 0, 0 }, { 0.00031, 0, 0 }, { -989000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 2000, 0 }
    , { { "CUMMINGTONITE", "Mg7Si8O22(OH)2", "Cum", "Mg(7)Si(8)O(24)H(2)", "ref:1", "5.May.78", 999999, 999999, 127.5 }, 271.9, { 185.24, 0, 0 }, { 0.05861, 0, 0 }, { -4466000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 800, 0 }
    , { { "CUPRITE", "Cu2O", "Cpr", "Cu(2)O(1)", "ref:1", "5.May.78", -35384, -40830, 22.08 }, 23.437, { 14.08, 0, 0 }, { 0.00588, 0, 0 }, { -76000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1515, 0 }
    , { { "DAPHNITE,14A", "Fe5Al(AlSi3)O10(OH)8", "Dph-14A", "Fe(5)Al(2)Si(3)O(18)H(8)", "ref:1", "5.May.78", 999999, 999999, 142.5 }, 213.42, { 176.21, 0, 0 }, { 0.04376, 0, 0 }, { -3382000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "DIASPORE", "AlO(OH)", "Dsp", "Al(1)O(2)H(1)", "ref:1", "5.May.78", -218402, -237170, 8.43 }, 17.76, { 14.435, 0, 0 }, { 0.004200000000000001, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 500, 0 }
    , { { "DICKITE", "Al2Si2O5(OH)4", "Dck", "Al(2)Si(2)O(9)H(4)", "ref:1,7", "5.May.78", 999999, 999999, 47.1 }, 99.3, { 72.77, 0, 0 }, { 0.0292, 0, 0 }, { -2152000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "DIOPSIDE", "CaMg(SiO3)2", "Di", "Ca(1)Mg(1)Si(2)O(6)", "ref:1,19", "15.Mar.90", -723780, -765378, 34.2 }, 66.09, { 52.87, 0, 0 }, { 0.00784, 0, 0 }, { -1574000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1600, 0 }
    , { { "DOLOMITE", "CaMg(CO3)2", "Dol", "Ca(1)Mg(1)C(2)O(6)", "ref:1,19", "15.Mar.90", -517760, -556631, 37.09 }, 64.365, { 41.557, 0, 0 }, { 0.023952, 0, 0 }, { -988400, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "DOLOMITE,DISORDERED", "CaMg(CO3)2", "Dis-Dol", "Ca(1)Mg(1)C(2)O(6)", "ref:1,19", "15.Mar.90", -515653, -553704, 39.84 }, 64.39, { 44.711, 0, 0 }, { 0.017779, 0, 0 }, { -1094800, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "DOLOMITE,ORDERED", "CaMg(CO3)2", "Ord-Dol", "Ca(1)Mg(1)C(2)O(6)", "ref:1,19", "15.Mar.90", -517760, -556631, 37.09 }, 64.34, { 44.711, 0, 0 }, { 0.017779, 0, 0 }, { -1094800, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "EPIDOTE", "Ca2FeAl2Si3O12(OH)", "Ep", "Ca(2)Fe(1)Al(2)Si(3)O(13)H(1)", "ref:1,19", "15.Mar.90", -1450906, -1543992, 75.28 }, 139.2, { 117.622, 0, 0 }, { 0.012816000000000001, 0, 0 }, { -3186400, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1100, 0 }
    , { { "EPIDOTE,ORDERED", "Ca2FeAl2Si3O12(OH)", "Ord-Ep", "Ca(2)Fe(1)Al(2)Si(3)O(13)H(1)", "ref:1,19", "15.Mar.90", -1450906, -1544016, 75.2 }, 139.2, { 113.78, 0, 0 }, { 0.01469, 0, 0 }, { -2892000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1100, 0 }
    , { { "FAYALITE", "Fe2SiO4", "Fa", "Fe(2)Si(1)O(4)", "ref:1", "5.May.78", -330233, -354119, 35.45 }, 46.39, { 36.51, 0, 0 }, { 0.00936, 0, 0 }, { -670000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1490, 0 }
    , { { "FERROPARGASITE", "Na(Ca2Fe4Al)(Al2Si6)O22(OH)2", "Fe-Prg", "Na(1)Ca(2)Fe(4)Al(3)Si(6)O(24)H(2)", "ref:1", "5.May.78", 999999, 999999, 185.5 }, 279.89, { 213.57, 0, 0 }, { 0.04299, 0, 0 }, { -4729000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "FERROTREMOLITE", "(Ca2Fe5)Si8O22(OH)2", "Fe-Tr", "Ca(2)Fe(5)Si(8)O(24)H(2)", "ref:1", "5.May.78", 999999, 999999, 163.5 }, 282.8, { 197.93, 0, 0 }, { 0.05895, 0, 0 }, { -4117000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 800, 0 }
    , { { "FERROUS-OXIDE", "FeO", "Frs-Ox", "Fe(1)O(1)", "ref:1", "5.May.78", -60097, -65020, 14.52 }, 12, { 12.122, 0, 0 }, { 0.002072, 0, 0 }, { -75000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1600, 0 }
    , { { "FLUORITE", "CaF2", "Fl", "Ca(1)F(2)", "ref:1", "5.May.78", -280493, -293000, 16.39 }, 24.542, { 14.3, 0, 0 }, { 0.00728, 0, 0 }, { 47000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1424, 0 }
    , { { "FLUORPHLOGOPITE", "KMg3(AlSi3)O10(F)2", "F-Phl", "K(1)Mg(3)Al(1)Si(3)O(10)F(2)", "ref:1,7", "5.May.78", 999999, 999999, 80.38 }, 146.37, { 96.13, 0, 0 }, { 0.02674, 0, 0 }, { -2041000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "FLUORTREMOLITE", "(Ca2Mg5)Si8O22(F)2", "F-Tr", "Ca(2)Mg(5)Si(8)O(22)F(2)", "ref:1", "5.May.78", 999999, 999999, 129.4 }, 270.45, { 183.74, 0, 0 }, { 0.05525, 0, 0 }, { -4373000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 800, 0 }
    , { { "FORSTERITE", "Mg2SiO4", "Fo", "Mg(2)Si(1)O(4)", "ref:1", "5.May.78", -491564, -520000, 22.75 }, 43.79, { 35.81, 0, 0 }, { 0.00654, 0, 0 }, { -852000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1800, 0 }
    , { { "GALENA", "PbS", "Gn", "Pb(1)S(1)", "ref:1", "5.May.78", -23115, -23500, 21.8 }, 31.49, { 11.17, 0, 0 }, { 0.0022, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1388, 0 }
    , { { "GEHLENITE", "Ca2(Al2Si)O7", "Gh", "Ca(2)Al(2)Si(1)O(7)", "ref:1,19", "15.Mar.90", -903148, -951225, 48.1 }, 90.24, { 63.74, 0, 0 }, { 0.008, 0, 0 }, { -1512000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1800, 0 }
    , { { "GIBBSITE", "Al(OH)3", "Gbs", "Al(1)O(3)H(3)", "ref:1", "5.May.78", -276168, -309065, 16.75 }, 31.956, { 8.65, 0, 0 }, { 0.0456, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 425, 0 }
    , { { "GLAUCOPHANE", "Na2(Mg3Al2)Si8O22(OH)2", "Gln", "Na(2)Mg(3)Al(2)Si(8)O(24)H(2)", "ref:1", "5.May.78", 999999, 999999, 130 }, 269.7, { 190.26, 0, 0 }, { 0.05936, 0, 0 }, { -5001000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 800, 0 }
    , { { "GOLD,NATIVE", "Au", "Au", "Au(1)", "ref:1", "5.May.78", 0, 0, 11.33 }, 10.215, { 5.66, 0, 0 }, { 0.00124, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1336, 0 }
    , { { "GRAPHITE", "C", "Gr", "C(1)", "ref:1", "5.May.78", 0, 0, 1.372 }, 5.298, { 4.03, 0, 0 }, { 0.00114, 0, 0 }, { -204000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 2500, 0 }
    , { { "GREENALITE", "Fe3Si2O5(OH)4", "Grn", "Fe(3)Si(2)O(9)H(4)", "ref:1", "5.May.78", 999999, 999999, 72.6 }, 115, { 81.65, 0, 0 }, { 0.032600000000000004, 0, 0 }, { -1539000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "GROSSULAR", "Ca3Al2Si3O12", "Grs", "Ca(3)Al(2)Si(3)O(12)", "ref:1,19", "15.Mar.90", -1496307, -1582737, 60.87 }, 125.3, { 104.017, 0, 0 }, { 0.017013, 0, 0 }, { -2731800, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "GRUNERITE", "Fe7Si8O22(OH)2", "Gru", "Fe(7)Si(8)O(24)H(2)", "ref:1", "5.May.78", 999999, 999999, 163.3 }, 256.67, { 198.83, 0, 0 }, { 0.06093, 0, 0 }, { -3954999.9999999995, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 800, 0 }
    , { { "HALITE", "NaCl", "Hl", "Na(1)Cl(1)", "ref:1", "5.May.78", -91807, -98260, 17.24 }, 27.015, { 10.98, 0, 0 }, { 0.0039, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1073, 0 }
    , { { "HALLOYSITE", "Al2Si2O5(OH)4", "Hal", "Al(2)Si(2)O(9)H(4)", "ref:1,7", "5.May.78", 999999, 999999, 48.52 }, 99.3, { 72.77, 0, 0 }, { 0.0292, 0, 0 }, { -2152000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "HEDENBERGITE", "CaFe(SiO3)2", "Hd", "Ca(1)Fe(1)Si(2)O(6)", "ref:1,19", "5.Mar.90", -638998, -678276, 40.7 }, 68.27, { 54.81, 0, 0 }, { 0.00817, 0, 0 }, { -1501000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1600, 0 }
    , { { "HUNTITE", "CaMg3(CO3)4", "Hun", "Ca(1)Mg(3)C(4)O(12)", "ref:1", "5.May.78", -1004710, -1082600, 71.59 }, 122.9, { 84.17, 0, 0 }, { 0.04286, 0, 0 }, { -2044000.0000000002, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "HYDROMAGNESITE", "Mg5(OH)2(CO3)4*4H20", "Hydro-Mgs", "Mg(5)C(4)O(18)H(10)", "ref:1", "5.May.78", -1401687, -1557090, 129.38 }, 208.8, { 141.46, 0, 0 }, { 0.06528, 0, 0 }, { -2167000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "JADEITE", "NaAl(SiO3)2", "Jd", "Na(1)Al(1)Si(2)O(6)", "ref:1", "5.May.78", -679445, -722116, 31.9 }, 60.4, { 48.16, 0, 0 }, { 0.01142, 0, 0 }, { -1187000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1400, 0 }
    , { { "K-FELDSPAR", "K(AlSi3)O8", "K-Fs", "K(1)Al(1)Si(3)O(8)", "ref:1", "5.May.78", -895374, -949188, 51.13 }, 108.87, { 76.617, 0, 0 }, { 0.004311, 0, 0 }, { -2994500, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1400, 0 }
    , { { "KAOLINITE", "Al2Si2O5(OH)4", "Kln", "Al(2)Si(2)O(9)H(4)", "ref:1", "5.May.78", -905614, -982221, 48.53 }, 99.52, { 72.77, 0, 0 }, { 0.0292, 0, 0 }, { -2152000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "KYANITE", "Al2SiO5", "Ky", "Al(2)Si(1)O(5)", "ref:1", "5.May.78", -580956, -616897, 20 }, 44.09, { 41.393132, 0, 0 }, { 0.006816463, 0, 0 }, { -1288210.4, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 466, 0 }
    , { { "LAUMONTITE", "Ca(Al2Si4)O12*4H2O", "Lmt", "Ca(1)Al(2)Si(4)O(16)H(8)", "ref:1,19", "15.Mar.90", -1596823, -1728664, 116.1 }, 207.55, { 123.2, 0, 0 }, { 0.04447, 0, 0 }, { -1643000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "LEONHARDITE", "Ca2(Al4Si8)O24*7H2O", "Lnr", "Ca(2)Al(4)Si(8)O(31)H(14)", "ref:1", "5.May.78", 999999, 999999, 220.4 }, 407.86, { 235, 0, 0 }, { 0.08894, 0, 0 }, { -3286000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "LIME", "CaO", "Lim", "Ca(1)O(1)", "ref:1", "5.May.78", -144366, -151790, 9.5 }, 16.764, { 11.67, 0, 0 }, { 0.00108, 0, 0 }, { -156000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 2000, 0 }
    , { { "MAGNESITE", "MgCO3", "Mgs", "Mg(1)C(1)O(3)", "ref:1", "5.May.78", -245658, -265630, 15.7 }, 28.018, { 19.731, 0, 0 }, { 0.012539, 0, 0 }, { -474800, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "MALACHITE", "Cu2(OH)2(CO3)", "Mal", "Cu(2)C(1)O(5)H(2)", "ref:1", "5.May.78", -214204, -251900, 44.5 }, 54.86, { 27.76, 0, 0 }, { 0.04378, 0, 0 }, { -134000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 780, 0 }
    , { { "MANGANOSITE", "MnO", "Mng", "Mn(1)O(1)", "ref:1,6", "5.May.78", -86735, -92070, 14.27 }, 13.221, { 11.11, 0, 0 }, { 0.0019399999999999999, 0, 0 }, { -88000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1800, 0 }
    , { { "MERWINITE", "Ca3Mg(SiO4)2", "Mer", "Ca(3)Mg(1)Si(2)O(8)", "ref:1,19", "15.Mar.90", -1036526, -1090796, 60.5 }, 104.4, { 72.97, 0, 0 }, { 0.011960000000000002, 0, 0 }, { -1444000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1700, 0 }
    , { { "METACINNABAR", "HgS", "Met-Cin", "Hg(1)S(1)", "ref:1", "5.May.78", -10437, -11800, 21.2 }, 30.169, { 10.52, 0, 0 }, { 0.00363, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "MICROCLINE,MAXIMUM", "K(AlSi3)O8", "Max-Mc", "K(1)Al(1)Si(3)O(8)", "ref:1", "5.May.78", -895374, -949188, 51.13 }, 108.741, { 63.83, 0, 0 }, { 0.0129, 0, 0 }, { -1705000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1400, 0 }
    , { { "MINNESOTAITE", "Fe3Si4O10(OH)2", "Mnn", "Fe(3)Si(4)O(12)H(2)", "ref:1", "5.May.78", 999999, 999999, 83.5 }, 147.86, { 88.31, 0, 0 }, { 0.04261, 0, 0 }, { -1115000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 800, 0 }
    , { { "MONTICELLITE", "CaMgSiO4", "Mtc", "Ca(1)Mg(1)Si(1)O(4)", "ref:1", "5.May.78", -512829, -540800, 26.4 }, 51.47, { 36.82, 0, 0 }, { 0.00534, 0, 0 }, { -800000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1400, 0 }
    , { { "MUSCOVITE", "KAl2(AlSi3)O10(OH)2", "Ms", "K(1)Al(3)Si(3)O(12)H(2)", "ref:1", "5.May.78", -1336301, -1427408, 68.8 }, 140.71, { 97.56, 0, 0 }, { 0.02638, 0, 0 }, { -2544000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "NEPHELINE", "Na(AlSi)O4", "Ne", "Na(1)Al(1)Si(1)O(4)", "ref:1", "5.May.78", -472872, -500241, 29.72 }, 54.16, { 35.908062, 0, 0 }, { 0.006457918, 0, 0 }, { -732796.5, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1500, 0 }
    , { { "PARAGONITE", "NaAl2(AlSi3)O10(OH)2", "Pg", "Na(1)Al(3)Si(3)O(12)H(2)", "ref:1", "5.May.78", -1326012, -1416963, 66.4 }, 132.53, { 97.43, 0, 0 }, { 0.0245, 0, 0 }, { -2644000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "PARGASITE", "Na(Ca2Mg4Al)(Al2Si6)O22(OH)2", "Prg", "Na(1)Ca(2)Mg(4)Al(3)Si(6)O(24)H(2)", "ref:1,19", "15.Mar.90", -2846728, -3016624, 160 }, 273.5, { 205.8, 0, 0 }, { 0.041659999999999996, 0, 0 }, { -5021000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "PERICLASE", "MgO", "Per", "Mg(1)O(1)", "ref:1", "5.May.78", -136086, -143800, 6.44 }, 11.248, { 10.18, 0, 0 }, { 0.00174, 0, 0 }, { -148000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 2100, 0 }
    , { { "PHLOGOPITE", "KMg3(AlSi3)O10(OH)2", "Phl", "K(1)Mg(3)Al(1)Si(3)O(12)H(2)", "ref:1", "5.May.78", -1396187, -1488067, 76.1 }, 149.66, { 100.61, 0, 0 }, { 0.02878, 0, 0 }, { -2150000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "POTASSIUM-OXIDE", "K2O", "K-Ox", "K(2)O(1)", "ref:1", "5.May.78", -77056, -86800, 22.5 }, 40.38, { 18.51, 0, 0 }, { 0.00865, 0, 0 }, { -88000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1100, 0 }
    , { { "PYRITE", "FeS2", "Py", "Fe(1)S(2)", "ref:1", "5.May.78", -38293, -41000, 12.65 }, 23.94, { 17.88, 0, 0 }, { 0.00132, 0, 0 }, { -305000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "PYROPHYLLITE", "Al2Si4O10(OH)2", "Prl", "Al(2)Si(4)O(12)H(2)", "ref:1", "5.May.78", -1255997, -1345313, 57.2 }, 126.6, { 79.432, 0, 0 }, { 0.039214, 0, 0 }, { -1728200, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 800, 0 }
    , { { "RHODOCHROSITE", "MnCO3", "Rds", "Mn(1)C(1)O(3)", "ref:1", "5.May.78", -195045, -212521, 23.9 }, 31.075, { 21.99, 0, 0 }, { 0.009300000000000001, 0, 0 }, { -469000.00000000006, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 700, 0 }
    , { { "RICHTERITE", "Na2(CaMg5)Si8O22(OH)2", "Rct", "Na(2)Ca(1)Mg(5)Si(8)O(24)H(2)", "ref:1", "5.May.78", 999999, 999999, 137.6 }, 272.8, { 194.8, 0, 0 }, { 0.0611, 0, 0 }, { -4615000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 800, 0 }
    , { { "ROMARCHITE", "SnO", "Sn-Ox", "Sn(1)O(1)", "ref:12", "5.May.78", -61459, -68340, 13.66 }, 20.895, { 9.55, 0, 0 }, { 0.0035, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1237, 0 }
    , { { "RUTILE", "TiO2", "Ru", "Ti(1)O(2)", "ref:7,9", "Mar.83", -212883, -226101, 12.02 }, 18.82, { 15.01442, 0, 0 }, { 0.002720501, 0, 0 }, { -236536.4, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1800, 0 }
    , { { "SANIDINE,HIGH", "K(AlSi3)O8", "Hi-Sa", "K(1)Al(1)Si(3)O(8)", "ref:1", "5.May.78", -893738, -946538, 54.53 }, 109.008, { 63.83, 0, 0 }, { 0.0129, 0, 0 }, { -1705000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1400, 0 }
    , { { "SEPIOLITE", "Mg4Si6O15(OH)2(H2O)2*4H2O", "Sep", "Mg(4)Si(6)O(23)H(14)", "ref:1", "5.May.78", -2211192, -2418000, 146.6 }, 285.6, { 157.92, 0, 0 }, { 0.1043, 0, 0 }, { -1868000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 800, 0 }
    , { { "SIDERITE", "FeCO3", "Sd", "Fe(1)C(1)O(3)", "ref:1,13", "5.May.78", -162414, -179173, 25.1 }, 29.378, { 11.63, 0, 0 }, { 0.0268, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 885, 0 }
    , { { "SILLIMANITE", "Al2SiO5", "Sil", "Al(2)Si(1)O(5)", "ref:1", "5.May.78", -580091, -615099, 23.13 }, 49.9, { 40.023988, 0, 0 }, { 0.007390511, 0, 0 }, { -1167405.3, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1200, 0 }
    , { { "SILVER,NATIVE", "Ag", "Ag", "Ag(1)", "ref:1", "5.May.78", 0, 0, 10.17 }, 10.272, { 5.09, 0, 0 }, { 0.00204, 0, 0 }, { 36000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1234, 0 }
    , { { "SMITHSONITE", "ZnCO3", "Smt", "Zn(1)C(1)O(3)", "ref:1", "5.May.78", -174850, -194260, 19.7 }, 28.275, { 9.3, 0, 0 }, { 0.033, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 780, 0 }
    , { { "SODIUM-OXIDE", "Na2O", "Na-Ox", "Na(2)O(1)", "ref:1", "5.May.78", -89883, -99140, 17.935 }, 25, { 18.25, 0, 0 }, { 0.004889999999999999, 0, 0 }, { -289000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "SPHALERITE", "ZnS", "Sp", "Zn(1)S(1)", "ref:1", "5.May.78", -47947, -49000, 14.019 }, 23.83, { 11.77, 0, 0 }, { 0.00126, 0, 0 }, { -115999.99999999999, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1300, 0 }
    , { { "SPINEL", "MgAl2O4", "Spn", "Mg(1)Al(2)O(4)", "ref:1", "5.May.78", -517006, -546847, 19.27 }, 39.71, { 36.772808, 0, 0 }, { 0.006415456, 0, 0 }, { -970879.2000000001, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 2000, 0 }
    , { { "STAUROLITE", "Fe2Al9Si4O23(OH)", "St", "Fe(2)Al(9)Si(4)O(24)H(1)", "ref:1", "5.May.78", 999999, 999999, 117.1 }, 224.4, { 207.12, 0, 0 }, { 0.03694, 0, 0 }, { -5722000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "STRONTIANITE", "SrCO3", "Str", "Sr(1)C(1)O(3)", "ref:1", "5.May.78", -275470, -294600, 23.2 }, 39.01, { 23.52, 0, 0 }, { 0.00632, 0, 0 }, { -508000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1197, 0 }
    , { { "SYLVITE", "KCl", "Sy", "K(1)Cl(1)", "ref:1", "5.May.78", -97735, -104370, 19.73 }, 37.524, { 9.89, 0, 0 }, { 0.005200000000000001, 0, 0 }, { 77000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1043, 0 }
    , { { "TALC", "Mg3Si4O10(OH)2", "Tcl", "Mg(3)Si(4)O(12)H(2)", "ref:1", "5.May.78", -1320188, -1410920, 62.34 }, 136.25, { 82.482, 0, 0 }, { 0.041614, 0, 0 }, { -1334200, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 800, 0 }
    , { { "TENORITE", "CuO", "Tn", "Cu(1)O(1)", "ref:1", "5.May.78", -30568, -37200, 10.18 }, 12.22, { 11.53, 0, 0 }, { 0.00188, 0, 0 }, { -176000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1600, 0 }
    , { { "TITANITE", "CaTiSiO5", "Ti", "Ca(1)Ti(1)Si(1)O(5)", "ref:7,9,19", "Mar.90", -587129, -620960, 30.88 }, 55.65, { 42.23422, 0, 0 }, { 0.0057039510000000005, 0, 0 }, { -952503.8, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1670, 0 }
    , { { "TREMOLITE", "(Ca2Mg5)Si8O22(OH)2", "Tr", "Ca(2)Mg(5)Si(8)O(24)H(2)", "ref:1,19", "15.Mar.90", -2770245, -2944038, 131.19 }, 272.92, { 188.222, 0, 0 }, { 0.057294, 0, 0 }, { -4482200, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 800, 0 }
    , { { "WAIRAKITE", "Ca(Al2Si4)O12*2H2O", "Wai", "Ca(1)Al(2)Si(4)O(14)H(4)", "ref:1,19", "15.Mar.90", -1477432, -1579333, 105.1 }, 186.87, { 100.4, 0, 0 }, { 0.04447, 0, 0 }, { -1643000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1000, 0 }
    , { { "WITHERITE", "BaCO3", "Wth", "Ba(1)C(1)O(3)", "ref:1", "5.May.78", -278400, -297500, 26.8 }, 45.81, { 21.5, 0, 0 }, { 0.01106, 0, 0 }, { -391000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1079, 0 }
    , { { "WOLLASTONITE", "CaSiO3", "Wo", "Ca(1)Si(1)O(3)", "ref:1,19", "15.Mar.90", -369225, -389590, 19.6 }, 39.93, { 26.64, 0, 0 }, { 0.0036000000000000003, 0, 0 }, { -652000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1400, 0 }
    , { { "WURTZITE", "ZnS", "Wur", "Zn(1)S(1)", "ref:1", "5.May.78", -44810, -45850, 14.064 }, 23.846, { 11.82, 0, 0 }, { 0.00116, 0, 0 }, { -104000, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 1300, 0 }
    , { { "ZINCITE", "ZnO", "Znc", "Zn(1)O(1)", "ref:1", "5.May.78", 999999, 999999, 10.43 }, 14.338, { 11.71, 0, 0 }, { 0.00122, 0, 0 }, { -218000.00000000003, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 2000, 0 }
    , { { "ZOISITE", "Ca2Al3Si3O12(OH)", "Zo", "Ca(2)Al(3)Si(3)O(13)H(1)", "ref:1,19", "15.Mar.90", -1549179, -1643691, 70.74 }, 135.9, { 106.118, 0, 0 }, { 0.025214, 0, 0 }, { -2714500, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 }, 0, 0, 0, 700, 0 }
    , { { "ALBITE", "Na(AlSi3)O8", "Ab", "Na(1)Al(1)Si(3))O(8)", "ref:1", "5.May.78", -886308, -939680, 49.51 }, 100.25, { 61.7, 0, 0 }, { 0.013900000000000001, 0, 0 }, { -1501000, 0, 0 }, { 473, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 81.88, 0.003554, -5015400, 1200, 1 }
    , { { "ALBITE,HIGH", "NaAlSi3O8", "Hi-Ab", "Na(1)Al(1)Si(3)O(8)", "ref:1", "5.May.78", -884509, -937050, 52.3 }, 100.43, { 61.7, 0, 0 }, { 0.013900000000000001, 0, 0 }, { -1501000, 0, 0 }, { 623, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 64.17, 0.013900000000000001, -1501000, 1400, 1 }
    , { { "ALMANDINE", "Fe3Al2Si3O12", "Alm", "Fe(3)Al(2)Si(3)O(12)", "ref:1", "5.May.78", 999999, 999999, 75.6 }, 115.28, { 97.52, 0, 0 }, { 0.03364, 0, 0 }, { -1873000, 0, 0 }, { 848, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 107.09, 0.01486, -1063000, 1600, 1 }
    , { { "AMESITE,14A", "Mg4Al2(Al2Si2)O10(OH)8", "14A-Am", "Mg(4)Al(4)Si(2)O(18)H(8)", "ref:1", "5.May.78", 999999, 999999, 108.9 }, 205.4, { 172.59, 0, 0 }, { 0.03498, 0, 0 }, { -4167000, 0, 0 }, { 848, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 169.4, 0.041240000000000006, -4437000, 1000, 1 }
    , { { "ANTIGORITE", "Mg48Si34O85(OH)62", "Atg", "Mg(48)Si(34)O(147)H(62)", "ref:1", "5.May.78", -15808020, -17070891, 861.36 }, 1749.13, { 1228.45, 0, 0 }, { 0.51376, 0, 0 }, { -28668000, 0, 0 }, { 848, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 1234.83, 0.50124, -28127999.999999996, 1000, 1 }
    , { { "CLINOCHLORE,7A", "Mg5Al(AlSi3)O10(OH)8", "7A-Cnc", "Mg(5)Al(2)Si(3)O(18)H(8)", "ref:1", "5.May.78", -1957101, -2113197, 106.5 }, 211.5, { 162.82, 0, 0 }, { 0.05062, 0, 0 }, { -4088000.0000000005, 0, 0 }, { 848, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 166.01, 0.044360000000000004, -3818000, 900, 1 }
    , { { "COESITE", "SiO2", "Cos", "Si(1)O(2)", "ref:1", "5.May.78", -203541, -216614, 9.65 }, 20.641, { 11, 0, 0 }, { 0.008199999999999999, 0, 0 }, { -270000, 0, 0 }, { 848, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 14.19, 0.0019399999999999999, 0, 2000, 1 }
    , { { "CRISTOBALITE", "SiO2", "Crs", "Si(1)O(2)", "ref:1", "5.May.78", -203895, -216755, 10.372 }, 25.74, { 13.98, 0, 0 }, { 0.00334, 0, 0 }, { -381000, 0, 0 }, { 543, 0, 0 }, { 321, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 17.39, 0.00031, -989000, 2000, 1 }
    , { { "DAPHNITE,7A", "Fe5Al(AlSi3)O10(OH)8", "7A-Dph", "Fe(5)Al(2)Si(3)O(18)H(8)", "ref:1", "5.May.78", 999999, 999999, 138.9 }, 221.2, { 172.53, 0, 0 }, { 0.05228, 0, 0 }, { -3722999.9999999995, 0, 0 }, { 848, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 175.72, 0.046020000000000005, -3463000.0000000005, 1000, 1 }
    , { { "EDENITE", "Na(Ca2Mg5)(AlSi7)O22(OH2)", "Ed", "Na(1)Ca(2)Mg(5)Al(1)Si(7)O(24)H(2)", "ref:1", "5.May.78", 999999, 999999, 161 }, 271, { 199.71, 0, 0 }, { 0.048780000000000004, 0, 0 }, { -4601000, 0, 0 }, { 848, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 202.9, 0.04252, -4331000, 1000, 1 }
    , { { "EPISTILBITE", "Ca(Al2Si6)O16*5H2O", "Eps", "Ca(1)Al(2)Si(6)O(21)H(10)", "ref:1", "5.May.78", 999999, 999999, 152.9 }, 267.56, { 157.04, 0, 0 }, { 0.06087, 0, 0 }, { -2183000, 0, 0 }, { 848, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 163.42, 0.048350000000000004, -1643000, 1000, 1 }
    , { { "FERROEDENITE", "Na(Ca2Fe5)(AlSi7)O22(OH)2", "Fe-Ed", "Na(1)Ca(2)Fe(5)Al(1)Si(7)O(24)H(2)", "ref:1", "5.May.78", 999999, 999999, 193.7 }, 280.9, { 209.42, 0, 0 }, { 0.05044, 0, 0 }, { -4236000, 0, 0 }, { 848, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 212.61, 0.044180000000000004, -3965999.9999999995, 1000, 1 }
    , { { "FERROSILITE", "FeSiO3", "Fs", "Fe(1)Si(1)O(3)", "ref:1,13", "5.May.78", -267588, -285658, 21.63 }, 32.952, { 26.49, 0, 0 }, { 0.005070000000000001, 0, 0 }, { -555000, 0, 0 }, { 413, 0, 0 }, { 37, 0, 0 }, { 0.056, 0, 0 }, { 67, 0, 0 }, 23.865, 0.00878, -470000, 1400, 1 }
    , { { "FLUOREDENITE", "Na(Ca2Mg5)(AlSi7)O22(F)2", "Fl-Ed", "Na(1)Ca(2)Mg(5)Al(1)Si(7)O(22)F(2)", "ref:1", "5.May.78", 999999, 999999, 146.7 }, 272.5, { 195.23, 0, 0 }, { 0.046740000000000004, 0, 0 }, { -4492000, 0, 0 }, { 848, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 198.42, 0.040479999999999995, -4222000, 1000, 1 }
    , { { "HERZENBERGITE", "SnS", "Hrz", "Sn(1)S(1)", "ref:12", "5.May.78", -25023, -25464, 18.36 }, 29.01, { 8.53, 0, 0 }, { 0.0074800000000000005, 0, 0 }, { 90000, 0, 0 }, { 875, 0, 0 }, { 160, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 9.78, 0.0037400000000000003, 0, 1153, 1 }
    , { { "HEULANDITE", "Ca(Al2Si7)O18*6H2O", "Hul", "Ca(1)Al(2)Si(7)O(24)H(12)", "ref:1", "5.May.78", 999999, 999999, 182.4 }, 316.37, { 179.66, 0, 0 }, { 0.06906999999999999, 0, 0 }, { -2453000, 0, 0 }, { 848, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 189.23, 0.05029, -1643000, 1000, 1 }
    , { { "KALSILITE", "K(AlSi)O4", "Kls", "K(1)Al(1)Si(1)O(4)", "ref:1", "5.May.78", -481750, -509408, 31.85 }, 59.89, { 29.43, 0, 0 }, { 0.01736, 0, 0 }, { -532000, 0, 0 }, { 810, 0, 0 }, { 160, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 42.5, 0, 0, 1800, 1 }
    , { { "LAWSONITE", "CaAl2Si2O7(OH)2*H2O", "Lws", "Ca(1)Al(2)Si(2)O(10)H(4)", "ref:1,19", "15.Mar.90", -1073408, -1158104, 55.8 }, 101.32, { 81.8, 0, 0 }, { 0.02336, 0, 0 }, { -1626000.0000000002, 0, 0 }, { 848, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 84.99, 0.0171, -1356000, 1000, 1 }
    , { { "MAGNETITE", "Fe3O4", "Mag", "Fe(3)O(4)", "ref:1", "5.May.78", -242574, -267250, 34.83 }, 44.524, { 21.88, 0, 0 }, { 0.04820000000000001, 0, 0 }, { 0, 0, 0 }, { 900, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 48, 0, 0, 1800, 1 }
    , { { "MARGARITE", "CaAl2(Al2Si2)O10(OH)2", "Mrg", "Ca(1)Al(4)Si(2)O(12)H(2)", "ref:1,19", "15.Mar.90", -1394150, -1485803, 63.8 }, 129.4, { 102.5, 0, 0 }, { 0.016350000000000003, 0, 0 }, { -2805000, 0, 0 }, { 848, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 99.31, 0.02261, -3075000, 1000, 1 }
    , { { "NATROLITE", "Na2(Al2Si3)O10*2H2O", "Ntr", "Na(2)Al(2)Si(3)O(12)H(4)", "ref:1", "5.May.78", 999999, 999999, 101.6 }, 169.72, { 95.76, 0, 0 }, { 0.04008, 0, 0 }, { -1506000, 0, 0 }, { 848, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 92.57, 0.046340000000000006, -1776000.0000000002, 1000, 1 }
    , { { "NESQUEHONITE", "MgCO3*3H2O", "Nsh", "Mg(1)C(1)O(6)H(6)", "ref:1", "5.May.78", -412035, -472576, 46.76 }, 74.79, { -1574.804, 0, 0 }, { 3.899173, 0, 0 }, { -41732500, 0, 0 }, { 306.5, 0, 0 }, { 184, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 25.246, 0.09128900000000001, -422200.00000000006, 340, 1 }
    , { { "NICKEL", "Ni", "Ni", "Ni(1)", "ref:1", "5.May.78", 0, 0, 7.14 }, 6.588, { 4.06, 0, 0 }, { 0.00704, 0, 0 }, { 0, 0, 0 }, { 633, 0, 0 }, { 0, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 6, 0.0018000000000000002, 0, 1725, 1 }
    , { { "PHILLIPSITE,CA", "Ca(Al2Si5)O14*5H2O", "Ca-Php", "Ca(1)Al(2)Si(5)O(19)H(10)", "ref:1", "5.May.78", 999999, 999999, 166.6 }, 265, { 145.82, 0, 0 }, { 0.05267, 0, 0 }, { -1913000, 0, 0 }, { 848, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 149.01, 0.04641, -1643000, 1000, 1 }
    , { { "PHILLIPSITE,K", "K2(Al2Si5)O14*5H2O", "K-Php", "K(2)Al(2)Si(5)O(19)H(10)", "ref:1", "5.May.78", 999999, 999999, 172.1 }, 265, { 152.66, 0, 0 }, { 0.06024, 0, 0 }, { -1845000, 0, 0 }, { 848, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 155.85, 0.05398, -1575000, 1000, 1 }
    , { { "PHILLIPSITE,NA", "Na2(Al2Si5)O14*5H2O", "Na-Php", "Na(2)Al(2)Si(5)O(19)H(10)", "ref:1", "5.May.78", 999999, 999999, 172.4 }, 265, { 152.4, 0, 0 }, { 0.056479999999999995, 0, 0 }, { -2046000, 0, 0 }, { 848, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 155.59, 0.05022, -1776000.0000000002, 1000, 1 }
    , { { "PREHNITE", "Ca2Al2Si3O10(OH)2", "Prh", "Ca(2)Al(2)Si(3)O(12)H(2)", "ref:1,19", "15.Mar.90", -1390097, -1481649, 65 }, 140.33, { 91.6, 0, 0 }, { 0.03782, 0, 0 }, { -1960000.0000000002, 0, 0 }, { 848, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 101.17, 0.019039999999999998, -1150000, 1000, 1 }
    , { { "PYROPE", "Mg3Al2Si3O12", "Prp", "Mg(3)Al(2)Si(3)O(12)", "ref:1,7", "5.May.78", 999999, 999999, 62.3 }, 113.27, { 91.69, 0, 0 }, { 0.03264, 0, 0 }, { -2092000.0000000002, 0, 0 }, { 848, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 101.26, 0.013859999999999999, -1282000, 1800, 1 }
    , { { "QUARTZ", "SiO2", "Qtz", "Si(1)O(2)", "ref:1", "5.May.78", -204646, -217650, 9.88 }, 22.688, { 11.22, 0, 0 }, { 0.008199999999999999, 0, 0 }, { -270000, 0, 0 }, { 848, 0, 0 }, { 290, 0, 0 }, { 0.372, 0, 0 }, { 38.5, 0, 0 }, 14.41, 0.0019399999999999999, 0, 2000, 1 }
    , { { "QUICKSILVER", "Hg", "Hg", "Hg(1)", "ref:1", "5.May.78", 0, 0, 18.17 }, 14.822, { 6.44, 0, 0 }, { 0, 0, 0 }, { 19000, 0, 0 }, { 629, 0, 0 }, { 14140, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 4.97, 0, 0, 3000, 1 }
    , { { "SPESSARTINE", "Mn3Al2Si3O12", "Sps", "Mn(3)Al(2)Si(3)O(12)", "ref:1", "5.May.78", 999999, 999999, 74.5 }, 117.9, { 94.48, 0, 0 }, { 0.033240000000000006, 0, 0 }, { -1912000, 0, 0 }, { 848, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 104.05, 0.01446, -1102000, 1800, 1 }
    , { { "STILBITE", "NaCa2(Al5Si13)O36*14H2O", "Stb", "Na(1)Ca(2)Al(5)Si(13)O(50)H(28)", "ref:1", "5.May.78", 999999, 999999, 399.3 }, 649.91, { 390.55, 0, 0 }, { 0.13768, 0, 0 }, { -4984000, 0, 0 }, { 848, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 400.12, 0.1189, -4174000, 1000, 1 }
    , { { "TIN,NATIVE", "Sn", "Sn", "Sn(1)", "ref:12", "Aug.85", 0, 0, 12.24 }, 16.289, { 4.42, 0, 0 }, { 0.0063, 0, 0 }, { 0, 0, 0 }, { 505.06, 0, 0 }, { 1680, 0, 0 }, { 999999, 0, 0 }, { 999999, 0, 0 }, 7.3, 0, 0, 3000, 1 }
    , { { "ACANTHITE", "Ag2S", "Acn", "Ag(2)S(1)", "ref:1", "5.May.78", -9446, -7550, 34.3 }, 34.2, { 15.63, 1.819, 0 }, { 0.0086, 0.053, 0 }, { 0, 0, 0 }, { 450, 620, 0 }, { 950, 600, 0 }, { 999999, 999999, 0 }, { 999999, 999999, 0 }, 21.6, 0, 0, 1000, 2 }
    , { { "AEGERINE", "NaFe(SiO3)2", "Agt", "Na(1)Fe(1)Si(2)O(6)", "ref:1", "5.May.78", 999999, 999999, 36.7 }, 64.37, { 46.16, 52.42, 0 }, { 0.01931, 0.01001, 0 }, { -946000.0000000001, -768000, 0 }, { 950, 1050, 0 }, { 999999, 999999, 0 }, { 999999, 999999, 0 }, { 999999, 999999, 0 }, 50.27, 0.01089, -768000, 1400, 2 }
    , { { "ANTHOPHYLLITE", "Mg7Si8O22(OH)2", "Ath", "Mg(7)Si(8)O(24)H(2)", "ref:1", "5.May.78", -2715430, -2888749, 128.6 }, 264.4, { 180.682, 197.542, 0 }, { 0.060573999999999996, 0.041614, 0 }, { -3846200.0000000005, -1334200, 0 }, { 903, 1258, 0 }, { 999999, 999999, 0 }, { 999999, 999999, 0 }, { 999999, 999999, 0 }, 199.522, 0.041614, -1334200, 1800, 2 }
    , { { "BORNITE", "Cu5FeS4", "Bn", "Cu(5)Fe(1)S(4)", "ref:1,16", "5.May.78", -86704, -79922, 99.29 }, 98.6, { 49.76, -34.31, 0 }, { 0.03508, 0.247, 0 }, { -135000, 0, 0 }, { 485, 540, 0 }, { 1430, 0, 0 }, { 999999, 999999, 0 }, { 999999, 999999, 0 }, 80.33, -0.00204, 0, 1200, 2 }
    , { { "BUNSENITE", "NiO", "Bsn", "Ni(1)O(1)", "ref:1", "5.May.78", -50573, -57300, 9.08 }, 10.97, { -4.99, 13.88, 0 }, { 0.03758, 0, 0 }, { 389000, 0, 0 }, { 525, 565, 0 }, { 0, 0, 0 }, { 999999, 999999, 0 }, { 999999, 999999, 0 }, 11.18, 0.00202, 0, 2000, 2 }
    , { { "CHALCOCITE", "Cu2S", "Cc", "Cu(2)S(1)", "ref:1", "5.May.78", -20626, -19000, 28.9 }, 27.48, { 12.63, 26.78, 0 }, { 0.01882, -0.00735, 0 }, { 0, 0, 0 }, { 376, 717, 0 }, { 920, 287, 0 }, { 999999, 999999, 0 }, { 999999, 999999, 0 }, 20.32, 0, 0, 1400, 2 }
    , { { "CHALCOPYRITE", "CuFeS2", "Ccp", "Cu(1)Fe(1)S(2)", "ref:1,16", "5.May.78", -44900, -44453, 31.15 }, 42.83, { 20.79, -141.4, 0 }, { 0.0128, 0.21, 0 }, { -134000, 0, 0 }, { 830, 930, 0 }, { 2405, 0, 0 }, { 999999, 999999, 0 }, { 999999, 999999, 0 }, 41.22, 0, 0, 1200, 2 }
    , { { "CRONSTEDTITE,7A", "Fe2Fe(FeSi)O5(OH)4", "7A-Csd", "Fe(4)Si(1)O(9)H(4)", "ref:1", "5.May.78", 999999, 999999, 73.5 }, 110.9, { 84.79, 97.3, 0 }, { 0.04184, 0.02324, 0 }, { -1247600, -893000, 0 }, { 950, 1050, 0 }, { 999999, 999999, 0 }, { 999999, 999999, 0 }, { 999999, 999999, 0 }, 93.01, 0.025, -893000, 1500, 2 }
    , { { "ENSTATITE", "MgSiO3", "En", "Mg(1)Si(1)O(3)", "ref:1", "5.May.78", -348930, -369686, 16.2 }, 31.276, { 24.55, 28.765, 0 }, { 0.00474, 0, 0 }, { -628000, 0, 0 }, { 903, 1258, 0 }, { 166, 390, 0 }, { 0.02, 1.09, 0 }, { 384.615, 11.9, 0 }, 29.26, 0, 0, 1800, 2 }
    , { { "FERROGEDRITE", "(Fe5Al2)(Al2Si6)O22(OH)2", "Fe-Ged", "Fe(5)Al(4)Si(6)O(24)H(2)", "ref:1", "5.May.78", 999999, 999999, 153.5 }, 265.9, { 196.27, 204.7, 0 }, { 0.058390000000000004, 0.048909999999999995, 0 }, { -3901000, -2645000, 0 }, { 903, 1258, 0 }, { 999999, 999999, 0 }, { 999999, 999999, 0 }, { 999999, 999999, 0 }, 205.69, 0.048909999999999995, -2645000, 1500, 2 }
    , { { "HASTINGSITE", "Na(Ca2Fe4Fe)(Al2Si6)O22(OH)2", "Hs", "Na(1)Ca(2)Fe(5)Al(2)Si(6)O(24)H(2)", "ref:1", "5.May.78", 999999, 999999, 189.2 }, 280.3, { 211.57, 217.82, 0 }, { 0.05088, 0.04158, 0 }, { -4488000, -4310000, 0 }, { 950, 1050, 0 }, { 999999, 999999, 0 }, { 999999, 999999, 0 }, { 999999, 999999, 0 }, 215.68, 0.042460000000000005, -4310000, 1500, 2 }
    , { { "HEMATITE", "Fe2O3", "Hem", "Fe(2)O(3)", "ref:1", "5.May.78", -178155, -197720, 20.94 }, 30.274, { 23.49, 36, 0 }, { 0.018600000000000002, 0, 0 }, { -355000, 0, 0 }, { 950, 1050, 0 }, { 160, 0, 0 }, { 999999, 999999, 0 }, { 999999, 999999, 0 }, 31.71, 0.00176, 0, 1800, 2 }
    , { { "LARNITE", "Ca2SiO4", "Lrn", "Ca(2)Si(1)O(4)", "ref:1,8", "5.May.78", 999999, 999999, 30.5 }, 51.6, { 34.87, 32.16, 0 }, { 0.00974, 0.01102, 0 }, { -626000, 0, 0 }, { 970, 1710, 0 }, { 440, 3390, 0 }, { 999999, 999999, 0 }, { 999999, 999999, 0 }, 49, 0, 0, 2000, 2 }
    , { { "MAGNESIOHASTINGSITE", "Na(Ca2Mg4Fe)(Al2Si6)O22(OH)2", "Mg-Hs", "Na(1)Ca(2)Mg(4)Fe(1)Al(2)Si(6)O(24)H(2)", "ref:1", "5.May.78", 999999, 999999, 163.8 }, 273.8, { 203.8, 210.06, 0 }, { 0.04955, 0.04025, 0 }, { -4780000, -4602000, 0 }, { 950, 1050, 0 }, { 999999, 999999, 0 }, { 999999, 999999, 0 }, { 999999, 999999, 0 }, 207.91, 0.04113000000000001, -4602000, 1500, 2 }
    , { { "MAGNESIORIEBECKITE", "Na2(Mg3Fe2)Si8O22(OH)2", "Mg-Rbk", "Na(2)Mg(3)Fe(2)Si(8)O(24)H(2)", "ref:1", "5.May.78", 999999, 999999, 138 }, 271.3, { 186.26, 198.77, 0 }, { 0.07514, 0.05654, 0 }, { -4518000, -4163000.0000000005, 0 }, { 950, 1050, 0 }, { 999999, 999999, 0 }, { 999999, 999999, 0 }, { 999999, 999999, 0 }, 194.48, 0.0583, -4163000.0000000005, 1500, 2 }
    , { { "PYRRHOTITE", "FeS", "Po", "Fe(1)S(1)", "ref:1", "5.May.78", -24084, -24000, 14.41 }, 18.2, { 5.19, 17.4, 0 }, { 0.0264, 0, 0 }, { 0, 0, 0 }, { 411, 598, 0 }, { 570, 120, 0 }, { 999999, 999999, 0 }, { 999999, 999999, 0 }, 12.2, 0.0023799999999999997, 0, 1468, 2 }
    , { { "RIEBECKITE", "Na2(Fe3Fe2)Si8O22(OH)2", "Rbk", "Na(2)Fe(5)Si(8)O(24)H(2)", "ref:1", "5.May.78", 999999, 999999, 156.6 }, 274.9, { 192.09, 204.6, 0 }, { 0.07614, 0.05754, 0 }, { -4299000, -3944000, 0 }, { 950, 1050, 0 }, { 999999, 999999, 0 }, { 999999, 999999, 0 }, { 999999, 999999, 0 }, 200.31, 0.0593, -3944000, 1500, 2 }
    , { { "IRON", "Fe", "Fe", "Fe(1)", "ref:7,8", "5.May.78", 0, 0, 6.52 }, 7.092, { 3.04, 11.13, 5.8 }, { 0.00758, 0, 0.00198 }, { 60000, 0, 0 }, { 1033, 1183, 1673 }, { 326, 215, 165 }, { 999999, 999999, 999999 }, { 999999, 999999, 999999 }, 6.74, 0.0016, 0, 1812, 3 }
    , { { "PD-OXYANNITE", "KFe3(AlSi3)O10(OH)O-", "Pd-Oxn", "K(1)Fe(3)Al(1)Si(3)O(12)H(1)", "ref:1", "5.May.78", 999999, 999999, 68.5 }, 143.2, { 88.34, 97.91, 116.68 }, { 0.05412, 0.03534, 0.00744 }, { -1805999.9999999998, -996000.0000000001, -463000 }, { 848, 950, 1050 }, { 999999, 999999, 999999 }, { 999999, 999999, 999999 }, { 999999, 999999, 999999 }, 110.24, 0.01008, -463000, 1100, 3 }
}};
    const auto
mineral_name_to_index = std::unordered_map <std::string_view, int>
{

      { "AKERMANITE", 0 }
    , { "ALABANDITE", 1 }
    , { "ALBITE,LOW", 2 }
    , { "ALUNITE", 3 }
    , { "AMESITE,7A", 4 }
    , { "AMORPHOUS-SILICA", 5 }
    , { "ANALCIME", 6 }
    , { "ANALCIME,DEHYDRATED", 7 }
    , { "ANDALUSITE", 8 }
    , { "ANDRADITE", 9 }
    , { "ANGLESITE", 10 }
    , { "ANHYDRITE", 11 }
    , { "ANNITE", 12 }
    , { "ANORTHITE", 13 }
    , { "ARAGONITE", 14 }
    , { "ARTINITE", 15 }
    , { "AZURITE", 16 }
    , { "BARITE", 17 }
    , { "BERNDTITE", 18 }
    , { "BOEHMITE", 19 }
    , { "BROMELLITE", 20 }
    , { "BRUCITE", 21 }
    , { "CA-AL-PYROXENE", 22 }
    , { "CALCITE", 23 }
    , { "CASSITERITE", 24 }
    , { "CELADONITE", 25 }
    , { "CELESTITE", 26 }
    , { "CERUSSITE", 27 }
    , { "CHABAZITE", 28 }
    , { "CHALCEDONY", 29 }
    , { "CHAMOSITE,7A", 30 }
    , { "CHLORARGYRITE", 31 }
    , { "CHLORITOID", 32 }
    , { "CHRYSOTILE", 33 }
    , { "CINNABAR", 34 }
    , { "CLINOCHLORE,14A", 35 }
    , { "CLINOZOISITE", 36 }
    , { "COPPER,NATIVE", 37 }
    , { "CORDIERITE", 38 }
    , { "CORDIERITE,HYDROUS", 39 }
    , { "CORUNDUM", 40 }
    , { "COVELLITE", 41 }
    , { "CRISTOBALITE,ALPHA", 42 }
    , { "CRISTOBALITE,BETA", 43 }
    , { "CUMMINGTONITE", 44 }
    , { "CUPRITE", 45 }
    , { "DAPHNITE,14A", 46 }
    , { "DIASPORE", 47 }
    , { "DICKITE", 48 }
    , { "DIOPSIDE", 49 }
    , { "DOLOMITE", 50 }
    , { "DOLOMITE,DISORDERED", 51 }
    , { "DOLOMITE,ORDERED", 52 }
    , { "EPIDOTE", 53 }
    , { "EPIDOTE,ORDERED", 54 }
    , { "FAYALITE", 55 }
    , { "FERROPARGASITE", 56 }
    , { "FERROTREMOLITE", 57 }
    , { "FERROUS-OXIDE", 58 }
    , { "FLUORITE", 59 }
    , { "FLUORPHLOGOPITE", 60 }
    , { "FLUORTREMOLITE", 61 }
    , { "FORSTERITE", 62 }
    , { "GALENA", 63 }
    , { "GEHLENITE", 64 }
    , { "GIBBSITE", 65 }
    , { "GLAUCOPHANE", 66 }
    , { "GOLD,NATIVE", 67 }
    , { "GRAPHITE", 68 }
    , { "GREENALITE", 69 }
    , { "GROSSULAR", 70 }
    , { "GRUNERITE", 71 }
    , { "HALITE", 72 }
    , { "HALLOYSITE", 73 }
    , { "HEDENBERGITE", 74 }
    , { "HUNTITE", 75 }
    , { "HYDROMAGNESITE", 76 }
    , { "JADEITE", 77 }
    , { "K-FELDSPAR", 78 }
    , { "KAOLINITE", 79 }
    , { "KYANITE", 80 }
    , { "LAUMONTITE", 81 }
    , { "LEONHARDITE", 82 }
    , { "LIME", 83 }
    , { "MAGNESITE", 84 }
    , { "MALACHITE", 85 }
    , { "MANGANOSITE", 86 }
    , { "MERWINITE", 87 }
    , { "METACINNABAR", 88 }
    , { "MICROCLINE,MAXIMUM", 89 }
    , { "MINNESOTAITE", 90 }
    , { "MONTICELLITE", 91 }
    , { "MUSCOVITE", 92 }
    , { "NEPHELINE", 93 }
    , { "PARAGONITE", 94 }
    , { "PARGASITE", 95 }
    , { "PERICLASE", 96 }
    , { "PHLOGOPITE", 97 }
    , { "POTASSIUM-OXIDE", 98 }
    , { "PYRITE", 99 }
    , { "PYROPHYLLITE", 100 }
    , { "RHODOCHROSITE", 101 }
    , { "RICHTERITE", 102 }
    , { "ROMARCHITE", 103 }
    , { "RUTILE", 104 }
    , { "SANIDINE,HIGH", 105 }
    , { "SEPIOLITE", 106 }
    , { "SIDERITE", 107 }
    , { "SILLIMANITE", 108 }
    , { "SILVER,NATIVE", 109 }
    , { "SMITHSONITE", 110 }
    , { "SODIUM-OXIDE", 111 }
    , { "SPHALERITE", 112 }
    , { "SPINEL", 113 }
    , { "STAUROLITE", 114 }
    , { "STRONTIANITE", 115 }
    , { "SYLVITE", 116 }
    , { "TALC", 117 }
    , { "TENORITE", 118 }
    , { "TITANITE", 119 }
    , { "TREMOLITE", 120 }
    , { "WAIRAKITE", 121 }
    , { "WITHERITE", 122 }
    , { "WOLLASTONITE", 123 }
    , { "WURTZITE", 124 }
    , { "ZINCITE", 125 }
    , { "ZOISITE", 126 }
    , { "ALBITE", 127 }
    , { "ALBITE,HIGH", 128 }
    , { "ALMANDINE", 129 }
    , { "AMESITE,14A", 130 }
    , { "ANTIGORITE", 131 }
    , { "CLINOCHLORE,7A", 132 }
    , { "COESITE", 133 }
    , { "CRISTOBALITE", 134 }
    , { "DAPHNITE,7A", 135 }
    , { "EDENITE", 136 }
    , { "EPISTILBITE", 137 }
    , { "FERROEDENITE", 138 }
    , { "FERROSILITE", 139 }
    , { "FLUOREDENITE", 140 }
    , { "HERZENBERGITE", 141 }
    , { "HEULANDITE", 142 }
    , { "KALSILITE", 143 }
    , { "LAWSONITE", 144 }
    , { "MAGNETITE", 145 }
    , { "MARGARITE", 146 }
    , { "NATROLITE", 147 }
    , { "NESQUEHONITE", 148 }
    , { "NICKEL", 149 }
    , { "PHILLIPSITE,CA", 150 }
    , { "PHILLIPSITE,K", 151 }
    , { "PHILLIPSITE,NA", 152 }
    , { "PREHNITE", 153 }
    , { "PYROPE", 154 }
    , { "QUARTZ", 155 }
    , { "QUICKSILVER", 156 }
    , { "SPESSARTINE", 157 }
    , { "STILBITE", 158 }
    , { "TIN,NATIVE", 159 }
    , { "ACANTHITE", 160 }
    , { "AEGERINE", 161 }
    , { "ANTHOPHYLLITE", 162 }
    , { "BORNITE", 163 }
    , { "BUNSENITE", 164 }
    , { "CHALCOCITE", 165 }
    , { "CHALCOPYRITE", 166 }
    , { "CRONSTEDTITE,7A", 167 }
    , { "ENSTATITE", 168 }
    , { "FERROGEDRITE", 169 }
    , { "HASTINGSITE", 170 }
    , { "HEMATITE", 171 }
    , { "LARNITE", 172 }
    , { "MAGNESIOHASTINGSITE", 173 }
    , { "MAGNESIORIEBECKITE", 174 }
    , { "PYRRHOTITE", 175 }
    , { "RIEBECKITE", 176 }
    , { "IRON", 177 }
    , { "PD-OXYANNITE", 178 }
};
    const auto
gases = std::array <gas_t, 16>
{{
      { { "ARGON", "Ar,g", "Ar(1)", "Ar(g)", "ref:6,8", "27.Dec.89", 0, 0, 37.008 }, 0, 4.968, 0, 0, 8000 }
    , { { "METHANE", "CH4,g", "C(1)H(4)", "CH4(g)", "ref:6,8", "15.Dec.87", -12122.4, -17880, 44.518 }, 0, 5.65, 0.01144, -46000, 1500 }
    , { { "CARBON-DIOXIDE", "CO2,g", "C(1)O(2)", "CO2(g)", "ref:6,8", "27.Dec.89", -94254, -94051, 51.085 }, 0, 10.57, 0.0021000000000000003, -206000, 2500 }
    , { { "HYDROGEN", "H2,g", "H(2)", "H2(g)", "ref:6,8", "27.Dec.89", 0, 0, 31.234 }, 0, 6.52, 0.0007800000000000001, 12000, 3000 }
    , { { "STEAM", "H2O,g", "H(2)O", "H2O(g)", "ref:17", "24.Mar.90", -54524.8, -57935.1, 44.763 }, 0, 12.6647, -0.0104041, 1307.8, 2523.15 }
    , { { "HYDROGEN-SULFIDE", "H2S,g", "H(2)S(1)", "H2S(g)", "ref:6,8", "27.Dec.89", -8021, -4931, 49.185 }, 0, 7.81, 0.00296, -46000, 2300 }
    , { { "HELIUM", "He,g", "He(1)", "He(g)", "ref:6,8", "27.Dec.89", 0, 0, 30.151 }, 0, 4.968, 0, 0, 8000 }
    , { { "KRYPTON", "Kr,g", "Kr(1)", "Kr(g)", "ref:6,8", "27.Dec.89", 0, 0, 39.217 }, 0, 4.968, 0, 0, 8000 }
    , { { "NITROGEN", "N2,g", "N(2)", "N2(g)", "ref:6,8", "27.Dec.89", 0, 0, 45.796 }, 0, 6.83, 0.0009000000000000001, -12000, 3000 }
    , { { "AMMONIA", "NH3,g", "N(1)H(3)", "NH3(g)", "ref:6,8", "26.Jul.89", -3932, -11021, 46 }, 0, 7.11, 0.006, -37000, 1800 }
    , { { "NEON", "Ne,g", "Ne(1)", "Ne(g)", "ref:6,8", "27.Dec.89", 0, 0, 34.973 }, 0, 4.968, 0, 0, 8000 }
    , { { "OXYGEN", "O2,g", "O(2)", "O2(g)", "ref:6,8", "27.Dec.89", 0, 0, 49.029 }, 0, 7.16, 0.001, -40000, 3000 }
    , { { "RADON", "Rn,g", "Rn(1)", "Rn(g)", "ref:6,8", "27.Dec.89", 0, 0, 42.12 }, 0, 4.968, 0, 0, 3000 }
    , { { "SULFUR", "S2,g", "S(2)", "S2(g)", "ref:6,8", "27.Dec.89", 18953, 30681, 54.54 }, 0, 8.72, 0.00016, -90000, 3000 }
    , { { "SULFUR-DIOXIDE", "SO2,g", "S(1)O(2)", "SO2(g)", "ref:6,8", "27.Dec.89", -71748, -70944, 59.33 }, 0, 11.04, 0.00188, -184000, 2000 }
    , { { "XENON", "Xe,g", "Xe(1)", "Xe(g)", "ref:6,8", "27.Dec.89", 0, 0, 40.555 }, 0, 4.968, 0, 0, 8000 }
}};
    const auto
gas_name_to_index = std::unordered_map <std::string_view, int>
{

      { "ARGON", 0 }
    , { "METHANE", 1 }
    , { "CARBON-DIOXIDE", 2 }
    , { "HYDROGEN", 3 }
    , { "STEAM", 4 }
    , { "HYDROGEN-SULFIDE", 5 }
    , { "HELIUM", 6 }
    , { "KRYPTON", 7 }
    , { "NITROGEN", 8 }
    , { "AMMONIA", 9 }
    , { "NEON", 10 }
    , { "OXYGEN", 11 }
    , { "RADON", 12 }
    , { "SULFUR", 13 }
    , { "SULFUR-DIOXIDE", 14 }
    , { "XENON", 15 }
};
    const auto
aqueous_species = std::array <aqueous_species_t, 294>
{{
      { { "1-BUTANAMINE,AQ", "C4H9NH2", "1-BUAM(aq)", "C(4)H(11)N(1)+(0)", "ref:4", "4.Sep.87", 9410, -36110, 47.2 }, 1.3926600000000002, 1972.0500000000002, 11.9476, -35941, 91.9109, 27736, -37480, 0 }
    , { { "1-BUTANOL,AQ", "C4H9OH", "l-BUOL(aq)", "C(4)H(10)O(1)+(0)", "ref:4", "2.Sep.87", -38840, -80320, 46.9 }, 1.34902, 1794.0000000000002, 14.1816, -35205, 94.8858, 30034, -37020, 0 }
    , { { "1-BUTENE,AQ", "C4H8", "l-BUTE(aq)", "C(4)H(8)+(0)", "ref:4", "4.Sep.87", 20310, -5635, 43.4 }, 1.20932, 2174.7599999999998, -2.7991, -36779, 61.5894, 183335, -65720, 0 }
    , { { "1-BUTYNE,AQ", "C4H6", "l-BUTY(aq)", "C(4)H(6)+(0)", "ref:4", "4.Sep.87", 50030, 33400, 43.4 }, 1.2613200000000002, 2301.85, -3.3011, -37305, 56.0218, 163984, -65720, 0 }
    , { { "1-HEPTANAMINE,AQ", "C7H15NH2", "1-HPAM(aq)", "C(7)H(17)N(1)+(0)", "ref:4", "4.Sep.87", 16910, -51990, 66.9 }, 2.0366700000000004, 3259.21, 13.0098, -41262.99999999999, 142.4729, 69513, -67310, 0 }
    , { { "1-HEPTANOL,AQ", "C7H15OH", "l-HPOL(aq)", "C(7)H(16)O(1)+(0)", "ref:4", "2.Sep.87", -32000, -97270, 72.1 }, 1.9769500000000002, 3139.77, 12.9129, -40769, 151.5815, 77219, -75190, 0 }
    , { { "1-HEPTENE,AQ", "C7H14", "l-HEPTE(aq)", "C(7)H(14)+(0)", "ref:4", "4.Sep.87", 26450, -22670, 63.5 }, 1.8476600000000003, 3733.42, -8.926, -43223, 96.0586, 312889, -96160, 0 }
    , { { "1-HEPTYNE,AQ", "C7H12", "l-HEPTY(aq)", "C(7)H(12)+(0)", "ref:4", "4.Sep.87", 56730, 16980, 63.7 }, 1.8995600000000001, 3860.15, -9.4245, -43747, 90.4632, 293537, -96470, 0 }
    , { { "1-HEXANAMINE,AQ", "C6H13NH2", "1-HXAM(aq)", "C(6)H(15)N(1)+(0)", "ref:4", "4.Sep.87", 14860, -46320, 60.2 }, 1.8211500000000003, 2828.22, 12.6611, -39481, 127.1903, 56804, -57170, 0 }
    , { { "1-HEXANOL,AQ", "C6H13OH", "l-HXOL(aq)", "C(6)H(14)O(1)+(0)", "ref:4", "2.Sep.87", -35490, -92690, 64.8 }, 1.7784300000000002, 2742.89, 12.589, -39128, 126.8936, 57074, -64130, 0 }
    , { { "1-HEXENE,AQ", "C6H12", "l-HEXE(aq)", "C(6)H(12)+(0)", "ref:4", "4.Sep.87", 24370, -17025, 56.8 }, 1.63488, 3213.87, -6.8838, -41075, 84.5689, 269704, -86020, 0 }
    , { { "1-HEXYNE,AQ", "C6H10", "l-HEXY(aq)", "C(6)H(10)+(0)", "ref:4", "4.Sep.87", 54420, 22340, 56.8 }, 1.6868800000000002, 3340.9599999999996, -7.3857, -41601, 79.0012, 250353, -86020, 0 }
    , { { "1-OCTANAMINE,AQ", "C8H17NH2", "1-OCAM(aq)", "C(8)H(19)N(1)+(0)", "ref:4", "4.Sep.87", 18960, -57660, 73.6 }, 2.2467099999999998, 3678.96, 13.3574, -42998, 159.8259, 83844, -77460, 0 }
    , { { "1-OCTANOL,AQ", "C8H17OH", "l-OCOL(aq)", "C(8)H(18)O(1)+(0)", "ref:4", "2.Sep.87", -30250, -103060, 72.3 }, 2.1926400000000004, 3570.93, 13.267, -42551, 169.4962, 91280, -75490, 0 }
    , { { "1-OCTENE,AQ", "C8H16", "l-OCTE(aq)", "C(8)H(16)+(0)", "ref:4", "4.Sep.87", 28720, -28120, 70.2 }, 2.06044, 4252.97, -10.9682, -45371, 107.5483, 356073, -106310, 0 }
    , { { "1-OCTYNE,AQ", "C8H14", "l-OCTY(aq)", "C(8)H(14)+(0)", "ref:4", "4.Sep.87", 58860, 11330, 70.2 }, 2.1124400000000003, 4380.06, -11.4705, -45896, 101.9808, 336721, -106310, 0 }
    , { { "1-PENTANAMINE,AQ", "C5H11NH2", "l-PEAM(aq)", "C(5)H(13)N(1)+(0)", "ref:4", "1.OCT.87", 12800, -40650, 53.5 }, 1.60701, 2400.48, 12.301, -37713, 110.0099, 42608, -47020, 0 }
    , { { "1-PENTANOL,AQ", "C5H11OH", "l-PEOL(aq)", "C(5)H(12)O(1)+(0)", "ref:4", "2.Sep.87", -38470, -87730, 53.4 }, 1.56573, 2262.3, 13.6464, -37141, 111.9216, 44095.00000000001, -46870, 0 }
    , { { "1-PENTENE,AQ", "C5H10", "l-PENTE(aq)", "C(5)H(10)+(0)", "ref:4", "4.Sep.87", 22470, -11200, 50.1 }, 1.4221000000000001, 2694.31, -4.8413, -38927, 73.0791, 226520, -75870, 0 }
    , { { "1-PENTYNE,AQ", "C5H8", "l-PENTY(aq)", "C(5)H(8)+(0)", "ref:4", "4.Sep.87", 52160, 27800, 50.1 }, 1.4741, 2821.3999999999996, -5.3433, -39453, 67.5117, 207168, -75870, 0 }
    , { { "1-PROPANAMINE,AQ", "C3H7NH2", "1-PRAM(aq)", "C(3)H(9)N(1)+(0)", "ref:4", "4.Sep.87", 7010, -30680, 40.8 }, 1.18178, 1550.13, 11.6113, -34197, 72.9633, 12188.000000000002, -27789.999999999996, 0 }
    , { { "1-PROPANOL,AQ", "C3H7OH", "l-PROL(aq)", "C(3)H(8)O(1)+(0)", "ref:4", "2.Sep.87", -41910, -75320, 41.4 }, 1.13426, 1432.52, 12.1079, -33711, 78.3142, 16447, -28690, 0 }
    , { { "1-PROPENE,AQ", "C3H6", "l-PROP(aq)", "C(3)H(6)+(0)", "ref:4", "4.Sep.87", 17910, -290, 36.7 }, 0.99655, 1655.18, -0.7564, -34632, 50.0997, 140151, -55579.99999999999, 0 }
    , { { "1-PROPYNE,AQ", "C3H4", "l-PRPY(aq)", "C(3)H(4)+(0)", "ref:4", "4.Sep.87", 47880, 38970, 36.7 }, 1.04855, 1782.2700000000002, -1.2588, -35157, 44.5321, 120799, -55579.99999999999, 0 }
    , { { "2-BUTANONE,AQ", "C4H8O", "2-BUON(aq)", "C(4)H(8)O(1)+(0)", "ref:4", "2.Sep.87", -36730, -67880, 50.3 }, 1.2914500000000002, 1769.67, 11.7839, -35105, 73.7083, 13810, -42170, 0 }
    , { { "2-HEPTANONE,AQ", "C7H14O", "2-HPON(aq)", "C(7)H(14)O(1)+(0)", "ref:4", "2.Sep.87", -30430, -84890, 70.1 }, 1.9241900000000003, 3033.92, 12.8366, -40331, 125.8091, 56804, -72160, 0 }
    , { { "2-HEXANONE,AQ", "C6H12O", "2-HXON(aq)", "C(6)H(12)O(1)+(0)", "ref:4", "2.Sep.87", -32480, -79220, 63.4 }, 1.71141, 2608.86, 12.4806, -38574, 108.456, 42473, -62010, 0 }
    , { { "2-OCTANONE,AQ", "C8H16O", "2-OCON(aq)", "C(8)H(16)O(1)+(0)", "ref:4", "2.Sep.87", -28380, -90560, 76.8 }, 2.1369700000000003, 3459.5999999999995, 13.1769, -42091, 143.162, 71135, -82310, 0 }
    , { { "2-PENTANONE,AQ", "C5H10O", "2-PEON(aq)", "C(5)H(10)O(1)+(0)", "ref:4", "2.Sep.87", -34390, -73460, 56.3 }, 1.50021, 2186.53, 12.1372, -36828, 91.1588, 28142, -51259.99999999999, 0 }
    , { { "A-AMINOBUTYRIC,AQ", "C4H9NO2", "ABA(aq)", "C(4)H(9)O(2)N(1)+(0)", "ref:4", "4.Sep.87", -87120, -138180, 46.7 }, 1.21092, 1608.6200000000001, 11.6529, -34439, 50.6605, -4643, -36720, 0 }
    , { { "ACETATE,AQ", "CH3COO-", "ACTA(aq)", "C(2)H(3)O(2)-(1)", "ref:4", "11.Jan.89", -88270, -116180, 20.6 }, 0.7752500000000001, 869.96, 7.5825, -31385, 26.3, -38600, 131820, -1 }
    , { { "ACETIC-ACID,AQ", "CH3COOH", "ACAC(aq)", "C(2)H(4)O(2)+(0)", "ref:4", "11.Jan.89", -94760, -116100, 42.7 }, 0.8803100000000001, 1245.72, 3.5477, -32939, 40.8037, -9218, -23370, 0 }
    , { { "ACETONE,AQ", "C3H6O", "ACON(aq)", "C(3)H(6)O(1)+(0)", "ref:4", "2.Sep.87", -38500, -61720, 44.4 }, 1.0810000000000002, 1349.12, 11.435, -33366, 54.9496, -1534, -33240, 0 }
    , { { "ALANINE,AQ", "C3H7NO2", "ALA(aq)", "C(3)H(7)O(2)N(1)+(0)", "ref:4", "4.Sep.87", -88800, -132130, 40 }, 0.99472, 1176.29, 11.3023, -32652, 34.9465, -17690, -26579.999999999996, 0 }
    , { { "ASPARAGINE,AQ", "C4H8N2O3", "ASN(aq)", "C(4)H(8)O(3)N(2)+(0)", "ref:4", "4.Sep.87", -128650, -186660, 55.2 }, 1.21587, 1618.1200000000001, 11.6715, -34478, 29.4616, -20327, -49590, 0 }
    , { { "ASPARTIC-ACID,AQ", "C4H7NO4", "ASP(aq)", "C(4)H(7)O(4)N(1)+(0)", "ref:4", "4.Sep.87", -172400, -226370, 54.8 }, 1.14232, 1471.24, 11.547, -33871, 29.9488, -19989, -48990, 0 }
    , { { "Ag(CO3)-", "Ag(CO3)(-)", "Ag(CO3)-", "Ag(1)C(1)O(3)-(1)", "ref:5", "JAN.91", -111430, -141600, 3 }, 0.23711000000000004, -199.18, 6.5329, -26967, 15.1234, -49901, 158290, -1 }
    , { { "Ag(CO3)2-3", "Ag(CO3)2(-3)", "Ag(CO3)2-3", "Ag(1)C(2)O(6)-(3)", "ref:5", "JAN.91", -236890, -304200, -19 }, 0.37401, 135.1, 5.219, -28348, 37.2623, -85549, 509920, -3 }
    , { { "Ag+", "Ag(+)", "Ag+", "Ag(1)+(1)", "ref:2", "1.Jul.87", 18427, 25275, 17.54 }, 0.17285, -356.08, 7.1496, -26318, 12.7862, -14254, 21600, 1 }
    , { { "Ag+2", "Ag(+2)", "Ag+2", "Ag(1)+(2)", "ref:2", "16.Feb.88", 64300, 64200, -21 }, -0.04299, -883.0999999999999, 9.221, -24139, 15.2224, -41142, 132010, 2 }
    , { { "AgCl,aq", "AgCl(0)", "AgCl(aq)", "Ag(1)Cl(1)+(0)", "ref:5", "JAN.91", -17450, -18270, 34.1 }, 0.52032, 492.34999999999997, 3.8149, -29825, 9.8168, -16698, -3000, 0 }
    , { { "AgCl2-", "AgCl2(-)", "AgCl2-", "Ag(1)Cl(2)-(1)", "ref:5", "JAN.91", -51560, -61130, 47 }, 0.96024, 1566.52, -0.4071, -34266, 19.1265, -14661, 91690, -1 }
    , { { "AgCl3-2", "AgCl3(-2)", "AgCl3-2", "Ag(1)Cl(3)-(2)", "ref:5", "JAN.91", -82710, -105940, 43.4 }, 1.48201, 2840.52, -5.4145, -39533, 38.1349, -1095, 255650.00000000003, -2 }
    , { { "AgCl4-3", "AgCl4(-3)", "AgCl4-3", "Ag(1)Cl(4)-(3)", "ref:5", "JAN.91", -112280, -142220, 27.5 }, 2.07599, 4290.87, -11.1149, -45528.00000000001, 107.0545, 179628, 439350.00000000006, -3 }
    , { { "AgNO3,aq", "AgNO3(0)", "AgNO3(aq)", "Ag(1)N(1)O(3)+(0)", "ref:5", "JAN.91", -7810, -23090, 50 }, 0.6620900000000001, 838.5, 2.4543, -31256, 19.1352, 15690, -3000, 0 }
    , { { "Al(OH)+2", "Al(OH)(+2)", "Al(OH)+2", "Al(1)O(1)H(1)+(2)", "ref:5", "AUG.89", -165228, -181868, -40 }, -0.14649, -1135.82, 10.2143, -23095, 8.5593, -75404, 166680, 2 }
    , { { "Al+3", "Al(+3)", "Al+3", "Al(1)+(3)", "ref:2", "1.Jul.87", -115377, -126012, -75.6 }, -0.33404, -1711.0800000000002, 14.9917, -20716, 10.7, -80600, 287110, 3 }
    , { { "Ar,aq", "Ar(0)", "Ar(aq)", "Ar(1)+(0)", "ref:3", "26.Jun.87", 3900, -2870, 14.3 }, 0.6000300000000001, 686.98, 3.0499, -30630, 35.6471, 73160, -30730, 0 }
    , { { "Au+", "Au(+)", "Au+", "Au(1)+(1)", "ref:2", "1.Jul.87", 39000, 47580, 24.5 }, 0.33448000000000006, 38.56, 5.5985, -27949, 8.1768, -29124, 18000, 1 }
    , { { "Au+3", "Au(+3)", "Au+3", "Au(1)+(3)", "ref:2", "13.Jul.87", 103600, 96930, -57.9 }, -0.30567000000000005, -1524.5, 11.7419, -21488, 7.5724, -104085, 245540, 3 }
    , { { "B(OH)3,aq", "B(OH)3(0)", "B(OH)3(aq)", "B(1)O(3)H(3)+(0)", "ref:3", "13.Jul.87", -231540, -256820, 37 }, 0.7064300000000001, 885.4699999999999, 3.5844, -31450.999999999996, 11.3568, -5901.999999999999, -20000, 0 }
    , { { "BENZENE,AQ", "C6H6", "BEN(aq)", "C(6)H(6)+(0)", "ref:4", "4.Sep.87", 32000, 12230, 35.5 }, 1.31244, 1811.43, 11.8225, -35277, 80.8626, 17799, -19760, 0 }
    , { { "BF4-", "BF4(-)", "BF4-", "B(1)F(4)-(1)", "ref:2", "16.Feb.88", -355400, -376400, 43 }, 0.79796, 1170.27, 1.1504, -32628, 11.8941, -41753, 97790, -1 }
    , { { "BO2-", "BO2(-)", "BO2-", "B(1)O(2)-(1)", "ref:2", "3.Jul.87", -162240, -184600, -8.9 }, -0.22428, -620.65, -6.3216, -25224.000000000004, -1.6521, -113863, 175950, -1 }
    , { { "BUTANOATE,AQ", "C3H7COO-", "BUTAT(aq)", "C(4)H(7)O(2)-(1)", "ref:4", "4.Sep.87", -84610, -127930, 31.8 }, 1.17724, 2096.5699999999997, -2.4947, -36456, 42.8123, 60300, 114690, -1 }
    , { { "BUTANOIC-ACID,AQ", "C3H7COOH", "BUAC(aq)", "C(4)H(8)O(2)+(0)", "ref:4", "2.Sep.87", -91190, -127950, 56.1 }, 1.31708, 1820.4999999999998, 11.8362, -35315, 72.9853, 13878, -50960.00000000001, 0 }
    , { { "Ba(CO3),aq", "Ba(CO3)(0)", "Ba(CO3)(aq)", "Ba(1)C(1)O(3)+(0)", "ref:5", "JAN.91", -263830, -285850, 16 }, 0.029070000000000002, -707.17, 8.5295, -24867, -12.7465, -95123, -3000, 0 }
    , { { "Ba+2", "Ba(+2)", "Ba+2", "Ba(1)+(2)", "ref:2", "1.Jul.87", -134030, -128500, 2.3 }, 0.27383, -1005.65, -0.047, -23633, 3.8, -34500, 98500, 2 }
    , { { "BaCl+", "BaCl(+)", "BaCl+", "Ba(1)Cl(1)+(1)", "ref:5", "JAN.91", -164730, -165770, 22.5 }, 0.33818000000000004, 47.589999999999996, 5.563, -27987.000000000004, 11.6588, -18063, 21260, 1 }
    , { { "BaF+", "BaF(+)", "BaF+", "Ba(1)F(1)+(1)", "ref:5", "JAN.91", -201120, -206510, 5.5 }, 0.15809, -392.13, 7.2913, -26168.999999999996, 16.2348, -10322, 46750, 1 }
    , { { "Be+2", "Be(+2)", "Be+2", "Be(1)+(2)", "ref:2", "3.Jul.87", -83500, -91500, -55.7 }, -0.10684, -1039.01, 9.8338, -23495, 22.9152, -32994, 190070, 2 }
    , { { "BeO2-2", "BeO2(-2)", "BeO2-2", "Be(1)O(2)-(2)", "ref:2", "3.Jul.87", -153000, -189000, -38 }, -0.032100000000000004, -856.5300000000001, 9.1166, -24249, -18.0684, -235879, 378800, -2 }
    , { { "Br-", "Br(-)", "Br-", "Br(1)-(1)", "ref:2", "1.Jul.87", -24870, -29040, 19.8 }, 0.5269, 659.4, 4.745, -31429.999999999996, -3.8, -68110, 138580, -1 }
    , { { "Br3-", "Br3(-)", "Br3-", "Br(3)-(1)", "ref:2", "12.Jul.87", -25590, -31170, 51.5 }, 0.9099200000000001, 1443.64, 0.0759, -33758, 17.2705, -18939, 84900, -1 }
    , { { "BrO-", "BrO(-)", "BrO-", "Br(1)O(1)-(1)", "ref:2", "12.Jul.87", -8000, -22500, 10 }, 0.36325, 108.81, 5.3224, -28240, -9.063, -130566, 147670, -1 }
    , { { "BrO3-", "BrO3(-)", "BrO3-", "Br(1)O(3)-(1)", "ref:2", "12.Jul.87", 4450, -16030, 38.65 }, 0.6961700000000001, 921.73, 2.1272, -31600, 3.7059, -72308, 104329.99999999999, -1 }
    , { { "BrO4-", "BrO4(-)", "BrO4-", "Br(1)O(4)-(1)", "ref:2", "12.Jul.87", 28200, 3100, 47.7 }, 0.8598699999999999, 1321.44, 0.5562, -33253, 14.8727, -29124, 90680, -1 }
    , { { "CN-", "CN(-)", "CN-", "C(1)N(1)-(1)", "ref:2", "13.Jul.87", 41200, 36000, 22.5 }, 0.55125, 567.86, 3.5181, -30137.999999999996, -1.1135, -96956, 129000, -1 }
    , { { "CO2,aq", "CO2(0)", "CO2(aq)", "C(1)O(2)+(0)", "ref:3", "26.Jun.87", -92250, -98900, 28.1 }, 0.62466, 747.11, 2.8136, -30879, 40.0325, 88004, -2000, 0 }
    , { { "CO3-2", "CO3(-2)", "CO3-2", "C(1)O(3)-(2)", "ref:2", "1.Jul.87", -126191, -161385, -11.95 }, 0.28524, -398.44, 6.4142, -26143, -3.3206, -171917, 339140, -2 }
    , { { "Ca(CO3),aq", "Ca(CO3)(0)", "Ca(CO3)(aq)", "Ca(1)C(1)O(3)+(0)", "ref:5", "JAN.91", -262850, -287390, 2.5 }, -0.024300000000000002, -837.48, 9.0417, -24328, -9.951, -85406, -3000, 0 }
    , { { "Ca(HCO3)+", "Ca(HCO3)(+)", "Ca(HCO3)+", "Ca(1)H(1)C(1)O(3)+(1)", "ref:5", "JAN.91", -273830, -294350, 16 }, 0.31911, 1.04, 5.7459, -27794, 42.3545, 85559, 30840, 1 }
    , { { "Ca+2", "Ca(+2)", "Ca+2", "Ca(1)+(2)", "ref:2", "3.Jun.87", -132120, -129800, -13.5 }, -0.01947, -725.1999999999999, 5.2966, -24792, 9, -25219.999999999996, 123659.99999999999, 2 }
    , { { "CaCl+", "CaCl(+)", "CaCl+", "Ca(1)Cl(1)+(1)", "ref:5", "JAN.91", -162550, -169250, -1.5 }, 0.2667, -126.94000000000001, 6.2489, -27265, 23.6652, 12044, 57560, 1 }
    , { { "CaCl2,aq", "CaCl2(0)", "CaCl2(aq)", "Ca(1)Cl(2)+(0)", "ref:5", "JAN.91", -194000, -211060, 6 }, 0.61187, 715.88, 2.9363, -30749, 26.6309, 41743, -3000, 0 }
    , { { "CaF+", "CaF(+)", "CaF+", "Ca(1)F(1)+(1)", "ref:5", "JAN.91", -200390, -208600, -9 }, 0.09846, -537.73, 7.8635, -25567.000000000004, 30.1157, 30764, 69110, 1 }
    , { { "CaSO4,aq", "CaSO4(0)", "CaSO4(aq)", "Ca(1)S(1)O(4)+(0)", "ref:5", "JAN.91", -312930, -345900, 5 }, 0.2791, -96.66, 6.13, -27390, -8.4941, -81271, -100, 0 }
    , { { "Cd+2", "Cd(+2)", "Cd+2", "Cd(1)+(2)", "ref:2", "1.Jul.87", -18560, -18140, -17.4 }, 0.00537, -1070.8, 16.5176, -23363, 15.6573, -37476, 125279.99999999999, 2 }
    , { { "Ce+3", "Ce(+3)", "Ce+3", "Ce(1)+(3)", "ref:2", "13.Jul.87", -161600, -167400, -49 }, -0.29292, -1493.3799999999999, 11.6196, -21616, 4.0445, -108974, 222510, 3 }
    , { { "Cl-", "Cl(-)", "Cl-", "Cl(1)-(1)", "ref:2", "3.Jun.87", -31379, -39933, 13.56 }, 0.4032, 480.1, 5.563, -28470, -4.4, -57140.00000000001, 145600, -1 }
    , { { "ClO-", "ClO(-)", "ClO-", "Cl(1)O(1)-(1)", "ref:2", "12.Jul.87", -8800, -25600, 10 }, 0.36325, 108.81, 5.3224, -28240, -9.063, -130566, 147670, -1 }
    , { { "ClO2-", "ClO2(-)", "ClO2-", "Cl(1)O(2)-(1)", "ref:2", "12.Jul.87", 4100, -15900, 24.2 }, 0.55036, 565.69, 3.5266, -30129, -0.0659, -92474.00000000001, 126370, -1 }
    , { { "ClO3-", "ClO3(-)", "ClO3-", "Cl(1)O(3)-(1)", "ref:2", "12.Jul.87", -1900, -24850, 38.8 }, 0.71665, 971.72, 1.9307, -31807, 8.5561, -55401, 104180, -1 }
    , { { "ClO4-", "ClO4(-)", "ClO4-", "Cl(1)O(4)-(1)", "ref:2", "12.Jul.87", -2040, -30910, 43.5 }, 0.81411, 1730.5900000000001, -12.2254, -34944, 22.3, -89000, 96990, -1 }
    , { { "Co+2", "Co(+2)", "Co+2", "Co(1)+(2)", "ref:2", "1.Jul.87", -13000, -13900, -27 }, -0.10748, -1299.48, 16.4112, -22418, 15.2014, -46235, 147690, 2 }
    , { { "Co+3", "Co(+3)", "Co+3", "Co(1)+(3)", "ref:2", "1.Jul.87", 32000, 22000, -73 }, -0.33247000000000004, -1589.94, 11.9992, -21217, 12.25, -96141, 271500, 3 }
    , { { "Cr2O7-2", "Cr2O7(-2)", "Cr2O7-2", "Cr(2)O(7)-(2)", "ref:2", "12.Jul.87", -311000, -356200, 62.6 }, 1.252, 2278.8900000000003, -3.207, -37211, 15.082, -71901, 226540, -2 }
    , { { "CrO4-2", "CrO4(-2)", "CrO4-2", "Cr(1)O(4)-(2)", "ref:2", "12.Jul.87", -173940, -210600, 12 }, 0.55808, 584.54, 3.4525, -30206, -1.0175, -152362, 303070, -2 }
    , { { "Cs+", "Cs(+)", "Cs+", "Cs(1)+(1)", "ref:2", "1.Jul.87", -69710, -61670, 31.75 }, 0.61475, -13.089999999999998, 4.2094, -27736, 6.27, -57360, 9740, 1 }
    , { { "CsBr,aq", "CsBr(0)", "CsBr(aq)", "Cs(1)Br(1)+(0)", "ref:5", "JAN.91", -94210, -88090, 58.8 }, 0.9838200000000001, 1624.09, -0.6333, -34504, -9.4143, -84469, -100, 0 }
    , { { "CsCl,aq", "CsCl(0)", "CsCl(aq)", "Cs(1)Cl(1)+(0)", "ref:5", "JAN.91", -100900, -100950, 52.58 }, 0.86067, 1323.3700000000001, 0.5486, -33261, -8.2011, -80252, -100, 0 }
    , { { "CsI,aq", "CsI(0)", "CsI(aq)", "Cs(1)I(1)+(0)", "ref:5", "JAN.91", -82480, -76840, 61.3 }, 1.16171, 2058.45, -2.3406, -36300, -8.1425, -80048.99999999999, -100, 0 }
    , { { "Cu+", "Cu(+)", "Cu+", "Cu(1)+(1)", "ref:2", "1.Jul.87", 11950, 17132, 9.7 }, 0.07835, -586.8199999999999, 8.0565, -25364, 17.2831, -2439, 33510, 1 }
    , { { "Cu+2", "Cu(+2)", "Cu+2", "Cu(1)+(2)", "ref:2", "1.Jul.87", 15675, 15700, -23.2 }, -0.11021000000000002, -1047.26, 9.8662, -23461, 20.3, -43900, 147690, 2 }
    , { { "Dy+3", "Dy(+3)", "Dy+3", "Dy(1)+(3)", "ref:2", "13.Jul.87", -158700, -166500, -55.2 }, -0.30003, -1510.74, 11.6879, -21545, 9.5076, -94919, 237920, 3 }
    , { { "ETHANAMINE,AQ", "C2H5NH2", "ETAM(aq)", "C(2)H(7)N(1)+(0)", "ref:4", "1.OCT.87", 6300, -23830, 33.6 }, 0.97281, 1132.57, 11.2651, -32471, 55.6799, -2142, -16880, 0 }
    , { { "ETHANE,AQ", "C2H6", "ETH(aq)", "C(2)H(6)+(0)", "ref:4", "31.Aug.87", -3886, -24650, 26.81 }, 0.8634000000000001, 1330.11, 0.5205, -33288, 54.1755, 149521, -40600, 0 }
    , { { "ETHANOL,AQ", "C2H5OH", "ETOL(aq)", "C(2)H(6)O(1)+(0)", "ref:4", "2.Sep.87", -43330, -68650, 35.9 }, 0.92333, 995.81, 12.1445, -31906, 60.0175, 1507, -20370, 0 }
    , { { "ETHYLBENZENE,AQ", "C6H5C2H5", "ETBN(aq)", "C(8)H(10)+(0)", "ref:4", "4.Sep.87", 32440, -2500, 49.8 }, 1.7197399999999998, 2625.7400000000002, 12.4885, -38644, 108.3695, 40918, -41420, 0 }
    , { { "ETHYLENE,AQ", "C2H4", "ETHLE(aq)", "C(2)H(4)+(0)", "ref:4", "4.Sep.87", 19450, 8570, 28.7 }, 0.7856000000000001, 1263.9099999999999, -1.8737, -33014, 39.1, 97000, -40000, 0 }
    , { { "ETHYNE,AQ", "C2H2", "ETHY(aq)", "C(2)H(2)+(0)", "ref:4", "31.Aug.87", 51890, 50700, 30 }, 0.83577, 1262.72, 0.7833, -33009, 33.0423, 77615, -45430, 0 }
    , { { "Er+3", "Er(+3)", "Er+3", "Er(1)+(3)", "ref:2", "13.Jul.87", -159900, -168500, -58.3 }, -0.33041000000000004, -1584.92, 11.9794, -21238, 8.2815, -100215, 241150.00000000003, 3 }
    , { { "Eu+2", "Eu(+2)", "Eu+2", "Eu(1)+(2)", "ref:2", "13.Jul.87", -129100, -126100, -2.4 }, 0.18333, -330.5, 7.049, -26424, 19.7516, -18124, 109290, 2 }
    , { { "Eu+3", "Eu(+3)", "Eu+3", "Eu(1)+(3)", "ref:2", "13.Jul.87", -137300, -144700, -53 }, -0.31037000000000003, -1535.99, 11.7871, -21440, 6.0548, -104900, 231610, 3 }
    , { { "F-", "F(-)", "F-", "F(1)-(1)", "ref:2", "1.Jul.87", -67340, -80150, -3.15 }, 0.06870000000000001, 135.88, 7.6033, -28352, 4.46, -74880, 178700, -1 }
    , { { "FORMATE,AQ", "HCOO-", "FORMT(aq)", "C(1)H(1)O(2)-(1)", "ref:4", "2.Sep.87", -83862, -101680, 21.7 }, 0.57842, 634.05, 3.2606, -30410, 17, -124000, 130030, -1 }
    , { { "FORMIC-ACID,AQ", "HCOOH", "FOAC(aq)", "C(1)H(2)O(2)+(0)", "ref:4", "2.Sep.87", -88982, -101680, 38.9 }, 0.63957, 466.3, 10.7209, -29716.999999999996, 22.1924, -31196, -34420, 0 }
    , { { "Fe(CH3COO)+", "Fe(CH3COO)(+)", "Fe(CH3COO)+", "Fe(1)C(2)H(3)O(2)+(1)", "ref:5", "JAN.91", -111900, -139060, -1.5 }, 0.39314000000000004, 181.8, 5.0355, -28542, 59.0575, 135058, 57560, 1 }
    , { { "Fe(CH3COO)2,aq", "Fe(CH3COO)2(0)", "Fe(CH3COO)2(aq)", "Fe(1)C(4)H(6)O(4)+(0)", "ref:5", "JAN.91", -201800, -259100, 11.53 }, 1.09505, 1895.68, -1.7008, -35627, 113.8428, 344869, -3000, 0 }
    , { { "Fe+2", "Fe(+2)", "Fe+2", "Fe(1)+(2)", "ref:2,13,14", "1.Jul.87", -21870, -22050, -25.3 }, -0.07803, -968.67, 9.5573, -23786, 14.9632, -46438, 145740, 2 }
    , { { "Fe+3", "Fe(+3)", "Fe+3", "Fe(1)+(3)", "ref:2,14", "1.Jul.87", -4120, -11850, -66.3 }, -0.31784, -1554.22, 11.8588, -21365, 11.0798, -99808, 270250, 3 }
    , { { "FeCl+", "FeCl(+)", "FeCl+", "Fe(1)Cl(1)+(1)", "ref:5", "JAN.91", -53030, -61260, -10.06 }, 0.20756000000000002, -271.34000000000003, 6.8165, -26668, 24.6737, 11555, 70030, 1 }
    , { { "FeCl2,aq", "FeCl2(0)", "FeCl2(aq)", "Fe(1)Cl(2)+(0)", "ref:5", "JAN.91", -81280, -100370, -4.22 }, 0.54085, 542.4699999999999, 3.6179, -30033, 25.1189, 36488, -3000, 0 }
    , { { "GLUTAMIC-ACID,AQ", "C5H9NO4", "GLU(aq)", "C(5)H(9)O(4)N(1)+(0)", "ref:4", "4.Sep.87", -173000, -232000, 70.5 }, 1.37471, 1936.0600000000002, 11.9216, -35793, 38.0235, -11943.999999999998, -72760, 0 }
    , { { "GLUTAMINE,AQ", "C5H10N2O3", "GLN(aq)", "C(5)H(10)O(3)N(2)+(0)", "ref:4", "4.Sep.87", -126600, -192330, 61.9 }, 1.4475300000000002, 2081.73, 12.0386, -36395, 41.2938, -10322, -59740.00000000001, 0 }
    , { { "GLYCINE,AQ", "C2H5NO2", "GLY(aq)", "C(2)H(5)O(2)N(1)+(0)", "ref:4", "4.Sep.87", -88618, -122846, 37.84 }, 0.76046, 708.25, 10.9119, -30717, 14.1998, -34185, -23300, 0 }
    , { { "Ga+3", "Ga(+3)", "Ga+3", "Ga(1)+(3)", "ref:2", "3.Jul.87", -38000, -50600, -79 }, -0.34573000000000004, -1622.32, 12.1264, -21083, 13.2451, -93086, 272760, 3 }
    , { { "Gd+3", "Gd(+3)", "Gd+3", "Gd(1)+(3)", "ref:2", "13.Jul.87", -158600, -164200, -49.2 }, -0.29771000000000003, -1505.06, 11.6656, -21568, 6.5606, -103474, 232649.99999999997, 3 }
    , { { "H+", "H(+)", "H+", "H(1)+(1)", "ref:2", "17.Jul.89", 0, 0, 0 }, 0, 0, 0, 0, 0, 0, 0, 1 }
    , { { "H2,aq", "H2(0)", "H2(aq)", "H(2)+(0)", "ref:3", "13.Jul.87", 4236, -1000, 13.8 }, 0.51427, 477.58000000000004, 3.8729, -29764, 27.6251, 50930, -20900, 0 }
    , { { "H2AsO3-", "H2AsO3(-)", "H2AsO3-", "H(2)As(1)O(3)-(1)", "ref:2", "3.Jul.87", -140330, -170840, 26.4 }, 0.5793400000000001, 636.46, 3.2485, -30421, 15.8032, -36253, 123049.99999999999, -1 }
    , { { "H2AsO4-", "H2AsO4(-)", "H2AsO4-", "H(2)As(1)O(4)-(1)", "ref:2", "3.Jul.87", -180010, -217390, 28 }, 0.6975500000000001, 925.0899999999999, 2.114, -31614, 16.8622, -31772, 120550, -1 }
    , { { "H2P2O7-2", "H2P2O7(-2)", "H2P2O7-2", "H(2)P(2)O(7)-(2)", "ref:2", "3.Jul.87", -480400, -544600, 39 }, 0.9821500000000001, 1620, -0.6173, -34487, 18.4241, -71697, 262180, -2 }
    , { { "H2PO4-", "H2PO4(-)", "H2PO4-", "H(2)P(1)O(4)-(1)", "ref:2", "3.Jul.87", -270140, -309820, 21.6 }, 0.64875, 805.94, 2.5823, -31122, 14.0435, -44605, 130030, -1 }
    , { { "H2S,aq", "H2S(0)", "H2S(aq)", "H(2)S(1)+(0)", "ref:3", "26.Jun.87", -6673, -9001, 30 }, 0.65097, 677.24, 5.9646, -30590, 32.3, 47300.00000000001, -10000, 0 }
    , { { "H2VO4-", "H2VO4(-)", "H2VO4-", "H(2)V(1)O(4)-(1)", "ref:2", "12.Jul.87", -244000, -280600, 29 }, 0.61355, 719.97, 2.9202, -30766, 17.4795, -29124, 118980, -1 }
    , { { "H3P2O7-", "H3P2O7(-)", "H3P2O7-", "H(3)P(2)O(7)-(1)", "ref:2", "3.Jul.87", -483600, -544100, 51 }, 0.90334, 1427.5700000000002, 0.1391, -33692, 31.4072, 29949, 85680, -1 }
    , { { "H3PO4,aq", "H3PO4(0)", "H3PO4(aq)", "H(3)P(1)O(4)+(0)", "ref:3", "11.Jul.87", -273100, -307920, 38 }, 0.8272700000000001, 1241.8200000000002, 0.8691, -32924, 17.9708, 17727, -22000, 0 }
    , { { "HAsO4-2", "HAsO4(-2)", "HAsO4-2", "H(1)As(1)O(4)-(2)", "ref:2", "3.Jul.87", -170790, -216620, -0.4 }, 0.46321000000000007, 352.88, 4.363, -29249, 5.471, -135863, 321970, -2 }
    , { { "HCO3-", "HCO3(-)", "HCO3-", "H(1)C(1)O(3)-(1)", "ref:2", "1.Jul.87", -140282, -164898, 23.53 }, 0.75621, 115.05000000000001, 1.2346, -28266, 12.9395, -47579, 127330.00000000001, -1 }
    , { { "HCrO4-", "HCrO4(-)", "HCrO4-", "H(1)Cr(1)O(4)-(1)", "ref:2", "12.Jul.87", -182800, -209900, 44 }, 0.8111200000000001, 1202.3899999999999, 1.0241, -32761, 26.9872, 11209, 96220, -1 }
    , { { "HEPTANOATE,AQ", "C6H13COO-", "HPAN(aq)", "C(7)H(13)O(2)-(1)", "ref:4", "4.Sep.87", -78390, -145560, 52 }, 1.82787, 3684.7999999999997, -8.7285, -43022, 79.677, 198205, 84170, -1 }
    , { { "HEPTANOIC-ACID,AQ", "C6H13COOH", "HPAC(aq)", "C(7)H(14)O(2)+(0)", "ref:4", "2.Sep.87", -85150, -145080, 76.2 }, 1.9593800000000003, 3104.65, 12.8851, -40624, 127.0284, 58426, -81400, 0 }
    , { { "HEXANOATE,AQ", "C5H11COO-", "HXAN(aq)", "C(6)H(11)O(2)-(1)", "ref:4", "4.Sep.87", -80450, -139890, 45.3 }, 1.6070000000000002, 3145.89, -6.6186, -40794, 73.4573, 173354, 94270, -1 }
    , { { "HEXANOIC-ACID,AQ", "C5H11COOH", "HXAC(aq)", "C(6)H(12)O(2)+(0)", "ref:4", "2.Sep.87", -87080, -139290, 69.5 }, 1.74729, 2680.9, 12.5312, -38872, 109.6753, 44095.00000000001, -71250, 0 }
    , { { "HF,aq", "HF(0)", "HF(aq)", "H(1)F(1)+(0)", "ref:3", "7.Feb.89", -71662, -76835, 22.5 }, 0.34753, 70.42, 5.4732, -28081, 14.3647, -1828, -70, 0 }
    , { { "HF2-", "HF2(-)", "HF2-", "H(1)F(2)-(1)", "ref:2", "12.Jul.87", -138160, -155340, 22.1 }, 0.52263, 497.97, 3.7928, -29849, -1.3751, -97974, 129340.00000000001, -1 }
    , { { "HNO3,aq", "HNO3(0)", "HNO3(aq)", "H(1)N(1)O(3)+(0)", "ref:3", "22.Feb.87", -24730, -45410, 42.7 }, 99.9, 99900, 999, 9990000, 15.2159, 12635, -36000, 0 }
    , { { "HO2-", "HO2(-)", "HO2-", "H(1)O(2)-(1)", "ref:2", "3.Jul.87", -16100, -38320, 5.7 }, 0.30671000000000004, -29.24, 5.8649, -27669, 2.7007, -91862.99999999999, 154490, -1 }
    , { { "HPO4-2", "HPO4(-2)", "HPO4-2", "H(1)P(1)O(4)-(2)", "ref:2", "3.Jul.87", -260310, -308815, -8 }, 0.36315000000000003, 108.57000000000001, 5.3233, -28239, 2.7357, -149103, 333630, -2 }
    , { { "HS-", "HS(-)", "HS-", "H(1)S(1)-(1)", "ref:2", "1.Jul.87", 2860, -3850, 16.3 }, 0.50119, 497.98999999999995, 3.4765, -29849, 3.42, -62699.99999999999, 144100, -1 }
    , { { "HSO3-", "HSO3(-)", "HSO3-", "H(1)S(1)O(3)-(1)", "ref:2", "3.Jul.87", -126130, -149670, 33.4 }, 0.67014, 858.16, 2.3771, -31338, 15.6949, -33198, 112330, -1 }
    , { { "HSO4-", "HSO4(-)", "HSO4-", "H(1)S(1)O(4)-(1)", "ref:2", "3.Jul.87", -180630, -212500, 30 }, 0.6978800000000001, 925.9000000000001, 2.1108, -31618, 20.0961, -19550, 117480, -1 }
    , { { "HSO5-", "HSO5(-)", "HSO5-", "H(1)S(1)O(5)-(1)", "ref:2", "3.Jul.87", -152370, -185380, 50.7 }, 0.8993800000000001, 1417.9, 0.1771, -33652, 31.2126, 29134.000000000004, 86110, -1 }
    , { { "HSe-", "HSe(-)", "HSe-", "H(1)Se(1)-(1)", "ref:2", "3.Jul.87", 10500, 3800, 19 }, 0.48181000000000007, 398.31, 4.1845, -29437.000000000004, 11.1345, -56012.00000000001, 134080, -1 }
    , { { "HSeO3-", "HSeO3(-)", "HSeO3-", "H(1)Se(1)O(3)-(1)", "ref:2", "3.Jul.87", -98340, -122980, 32.3 }, 0.65703, 826.15, 2.5029, -31205, 19.5432, -20365.000000000004, 114020.00000000001, -1 }
    , { { "HSeO4-", "HSeO4(-)", "HSeO4-", "H(1)Se(1)O(4)-(1)", "ref:2", "3.Jul.87", -108100, -139000, 35.7 }, 0.6374900000000001, 778.4399999999999, 2.6904, -31008, -8.3616, -115696, 108850, -1 }
    , { { "HSiO3-", "HSiO3(-)", "HSiO3-", "H(1)Si(1)O(3)-(1)", "ref:5", "JAN.91", -242300, -271880, 10 }, 0.36325, 108.81, 5.3224, -28240, 0.4312, -97567, 147670, -1 }
    , { { "HVO4-2", "HVO4(-2)", "HVO4-2", "H(1)V(1)O(4)-(2)", "ref:2", "12.Jul.87", -233000, -277000, 4 }, 0.52115, 494.37, 3.8069, -29834, 6.9055, -128733, 315270, -2 }
    , { { "He,aq", "He(0)", "He(aq)", "He(1)+(0)", "ref:3", "13.Jul.87", 4658, -150, 14.02 }, 0.34722000000000003, 69.67, 5.4762, -28078, 26.0707, 45634, -21230, 0 }
    , { { "Hg+2", "Hg(+2)", "Hg+2", "Hg(1)+(2)", "ref:2", "1.Jul.87", 39360, 40670, -8.68 }, -0.05280000000000001, -907.07, 9.3152, -24040, 18.0613, -25865, 115120, 2 }
    , { { "Hg2+2", "Hg2(+2)", "Hg2+2", "Hg(2)+(2)", "ref:2", "13.Jul.87", 36710, 39870, -15.66 }, 0.40126, 201.64, 4.9575, -28624, 23.7433, 4487, 82010, 2 }
    , { { "Ho+3", "Ho(+3)", "Ho+3", "Ho(1)+(3)", "ref:2", "13.Jul.87", -161400, -169000, -54.3 }, -0.31198000000000004, -1539.92, 11.8026, -21424, 8.6686, -98178, 238990, 3 }
    , { { "I-", "I(-)", "I-", "I(1)-(1)", "ref:2", "1.Jul.87", -12410, -13600, 25.5 }, 0.77623, 827.6199999999999, 1.4609, -31211.000000000004, -6.27, -49440, 129340.00000000001, -1 }
    , { { "I3-", "I3(-)", "I3-", "I(3)-(1)", "ref:2", "12.Jul.87", -12300, -12300, 57.2 }, 0.985, 1626.97, -0.6447, -34516, 20.8712, -3661, 76280, -1 }
    , { { "IO-", "IO(-)", "IO-", "I(1)O(1)-(1)", "ref:2", "16.Feb.88", -9200, -25700, -1.3 }, 0.21432000000000004, -254.82, 6.7516, -26737.000000000004, -16.2398, -160918, 164550, -1 }
    , { { "IO3-", "IO3(-)", "IO3-", "I(1)O(3)-(1)", "ref:2", "12.Jul.87", -30600, -52900, 28.3 }, 0.5714800000000001, 617.25, 3.324, -30341.999999999996, 7.7293, -63345, 120020, -1 }
    , { { "IO4-", "IO4(-)", "IO4-", "I(1)O(4)-(1)", "ref:2", "12.Jul.87", -14000, -36200, 53 }, 0.92968, 1491.89, -0.1138, -33957, 18.2345, -14865, 82640, -1 }
    , { { "ISOLEUCINE,AQ", "C6H13NO2", "ILE(aq)", "C(6)H(13)O(2)N(1)+(0)", "ref:4", "4.Sep.87", -82200, -150900, 52.8 }, 1.6039500000000002, 2394.1400000000003, 12.301, -37686, 83.0208, 21382, -45960, 0 }
    , { { "In+3", "In(+3)", "In+3", "In(1)+(3)", "ref:2", "3.Jul.87", -23400, -25000, -63 }, -0.31646, -1550.86, 11.8456, -21379, 8.7476, -101437.00000000001, 250030.00000000003, 3 }
    , { { "K+", "K(+)", "K+", "K(1)+(1)", "ref:2", "3.Jun.87", -67510, -60270, 24.15 }, 0.35590000000000005, -147.3, 5.435, -27120.000000000004, 7.4, -17910, 19270, 1 }
    , { { "KBr,aq", "KBr(0)", "KBr(aq)", "K(1)Br(1)+(0)", "ref:5", "JAN.91", -90010, -86320, 47.5 }, 0.7784300000000001, 1122.57, 1.3378, -32431, 1.4496, -46581, -500, 0 }
    , { { "KCl,aq", "KCl(0)", "KCl(aq)", "K(1)Cl(1)+(0)", "ref:5", "JAN.91", -96850, -96810, 42.25 }, 0.6811200000000001, 884.97, 2.2717, -31448, -2.4989, -58864, -5000, 0 }
    , { { "KHSO4,aq", "KHSO4(0)", "KHSO4(aq)", "K(1)H(1)S(1)O(4)+(0)", "ref:5", "JAN.91", -246550, -270540, 56.31 }, 0.90596, 1433.97, 0.1139, -33718, 28.4277, 47060.00000000001, -100, 0 }
    , { { "KI,aq", "KI(0)", "KI(aq)", "K(1)I(1)+(0)", "ref:5", "JAN.91", -77740, -71680, 49.7 }, 0.9426399999999999, 1523.52, -0.2381, -34088, 2.7214, -42161, -500, 0 }
    , { { "KSO4-", "KSO4(-)", "KSO4-", "K(1)S(1)O(4)-(1)", "ref:5", "JAN.91", -246640, -276980, 35 }, 0.6077600000000001, 705.85, 2.9757, -30708.000000000004, 9.8504, -52753, 109959.99999999999, -1 }
    , { { "Kr,aq", "Kr(0)", "Kr(aq)", "Kr(1)+(0)", "ref:3", "13.Jul.87", 3554, -3650, 15.06 }, 0.62721, 753.3299999999999, 2.7891, -30903.999999999996, 37.8226, 86984.99999999999, -22810, 0 }
    , { { "LEUCINE,AQ", "C6H13NO2", "LEU(aq)", "C(6)H(13)O(2)N(1)+(0)", "ref:4", "4.Sep.87", -82000, -151070, 51.5 }, 1.6336200000000003, 2453.12, 12.3587, -37930, 86.2214, 23748, -43990, 0 }
    , { { "La+3", "La(+3)", "La+3", "La(1)+(3)", "ref:2", "13.Jul.87", -164000, -169600, -52 }, -0.2788, -1438.24, 10.9602, -21844, 4.2394, -106122, 215720, 3 }
    , { { "Li+", "Li(+)", "Li+", "Li(1)+(1)", "ref:2", "2.Jun.87", -69933, -66552, 2.7 }, -0.00237, -6.9, 11.58, -27761, 19.2, -2400, 48620, 1 }
    , { { "LiCl,aq", "LiCl(0)", "LiCl(aq)", "Li(1)Cl(1)+(0)", "ref:5", "JAN.91", -99250, -105680, 13.14 }, 0.55458, 576, 3.4861, -30171, 16.6817, 11005, -15000, 0 }
    , { { "Lu+3", "Lu(+3)", "Lu+3", "Lu(1)+(3)", "ref:2", "13.Jul.87", -159400, -167900, -63.1 }, -0.35630000000000006, -1648.1200000000001, 12.2279, -20977, 9.565, -97160, 245540, 3 }
    , { { "METHANAMINE,AQ", "CH3NH2", "MEAM(aq)", "C(1)H(5)N(1)+(0)", "ref:4", "4.Sep.87", 5040, -16320, 30.5 }, 0.7454700000000001, 678.24, 10.8884, -30593, 39.0324, -15527, -12190, 0 }
    , { { "METHANE,AQ", "CH4", "METH(aq)", "C(1)H(4)+(0)", "ref:4", "31.Aug.87", -8234, -21010, 20.99 }, 0.67617, 872.79, 2.3212, -31397, 42.0941, 104707.00000000001, -31790, 0 }
    , { { "METHANOL,AQ", "CH3OH", "MEOL(aq)", "C(1)H(4)O(1)+(0)", "ref:4", "2.Sep.87", -42050, -58870, 32.2 }, 0.6938300000000001, 551.4599999999999, 11.4018, -30069, 39.4852, -14986, -14760, 0 }
    , { { "METHIONINE,AQ", "C5H11NO2S", "MET(aq)", "C(5)H(11)O(2)N(1)S(1)+(0)", "ref:4", "4.Sep.87", -120200, -177600, 65.7 }, 1.59529, 2376.88, 12.2862, -37615, 62.5883, 6780.000000000001, -65500, 0 }
    , { { "Mg(CO3),aq", "Mg(CO3)(0)", "Mg(CO3)(aq)", "Mg(1)C(1)O(3)+(0)", "ref:5", "JAN.91", -238760, -270570, -24 }, -0.058370000000000005, -920.67, 9.3687, -23984, -8.6676, -80945, -3000, 0 }
    , { { "Mg(HCO3)+", "Mg(HCO3)(+)", "Mg(HCO3)+", "Mg(1)H(1)C(1)O(3)+(1)", "ref:5", "JAN.91", -250200, -275750, -3 }, 0.27171, -114.69, 6.2008, -27315.999999999996, 49.0065, 99391, 59850, 1 }
    , { { "Mg+2", "Mg(+2)", "Mg+2", "Mg(1)+(2)", "ref:2", "1.Jul.87", -108505, -111367, -33 }, -0.08217, -859.9, 8.39, -23900, 20.8, -58920, 153720, 2 }
    , { { "MgCl+", "MgCl(+)", "MgCl+", "Mg(1)Cl(1)+(1)", "ref:5", "JAN.91", -139700, -151440, -20.5 }, 0.22269000000000003, -234.39999999999998, 6.6713, -26821, 39.0235, 56430, 85650, 1 }
    , { { "MgF+", "MgF(+)", "MgF+", "Mg(1)F(1)+(1)", "ref:5", "JAN.91", -177690, -190950, -28.07 }, 0.06494, -619.58, 8.1852, -25229, 37.9653, 49097, 97060, 1 }
    , { { "Mn+2", "Mn(+2)", "Mn+2", "Mn(1)+(2)", "ref:2", "1.Jul.87", -54500, -52724, -17.6 }, -0.01016, -802.95, 8.906, -24471, 16.6674, -38698, 140060, 2 }
    , { { "MnCl+", "MnCl(+)", "MnCl+", "Mn(1)Cl(1)+(1)", "ref:5", "JAN.91", -86290, -88280, 12 }, 0.27448, -107.92999999999999, 6.1743, -27344, 27.9936, 33718, 36860, 1 }
    , { { "MnO4-", "MnO4(-)", "MnO4-", "Mn(1)O(4)-(1)", "ref:2", "12.Jul.87", -106900, -129400, 45.7 }, 0.7828900000000001, 1133.46, 1.295, -32476, 13.7427, -34013, 93680, -1 }
    , { { "MnO4-2", "MnO4(-2)", "MnO4-2", "Mn(1)O(4)-(2)", "ref:2", "12.Jul.87", -119700, -156000, 14 }, 0.65291, 816.09, 2.5424, -31164, -0.9267, -151140, 300240, -2 }
    , { { "MnSO4,aq", "MnSO4(0)", "MnSO4(aq)", "Mn(1)S(1)O(4)+(0)", "ref:5", "JAN.91", -235640, -266750, 5 }, 0.24377000000000001, -182.92, 6.469, -27033.999999999996, -6.6984, -74101, -3000, 0 }
    , { { "MoO4-2", "MoO4(-2)", "MoO4-2", "Mo(1)O(4)-(2)", "ref:2", "12.Jul.87", -199900, -238500, 6.5 }, 0.6977500000000001, 925.59, 2.1121, -31616, 7.0224, -127103, 311450, -2 }
    , { { "N-BUTANE,AQ", "C4H10", "n-BUT(aq)", "C(4)H(10)+(0)", "ref:4", "31.Aug.87", 36, -36230, 40.02 }, 1.28905, 2369.6000000000004, -3.5683, -37585, 79.0569, 242408, -60610, 0 }
    , { { "N-BUTYLBENZENE,AQ", "C6H5C4H9", "n-BUBN(aq)", "C(10)H(14)+(0)", "ref:4", "31.Aug.87", 36110, -14430, 62.8 }, 2.1454999999999997, 3476.58, 13.1931, -42162, 145.8054, 71676, -61100, 0 }
    , { { "N-HEPTANE,AQ", "C7H16", "n-HEPT(aq)", "C(7)H(16)+(0)", "ref:4", "31.Aug.87", 6470, -52950, 60 }, 1.92745, 3928.1, -9.6879, -44028, 112.898, 369721, -90860, 0 }
    , { { "N-HEPTYLBENZENE,AQ", "C6H5C7H15", "n-HPBN(aq)", "C(13)H(20)+(0)", "ref:4", "2.Sep.87", 42640, -31090, 82.9 }, 2.78384, 4752.38, 14.2453, -47435, 197.8642, 114670, -91540, 0 }
    , { { "N-HEXANE,AQ", "C6H14", "n-HEX(aq)", "C(6)H(14)+(0)", "ref:4", "31.Aug.87", 4420, -47400, 52.9 }, 1.7148700000000003, 3409.27, -7.653, -41883, 101.4642, 326536, -80110, 0 }
    , { { "N-HEXYLBENZENE,AQ", "C6H5C6H13", "n-HXBN(aq)", "C(12)H(18)+(0)", "ref:4", "2.Sep.87", 40390, -25590, 76.2 }, 2.57106, 4327.320000000001, 13.8894, -45678, 180.5115, 100338, -81400, 0 }
    , { { "N-OCTANE,AQ", "C8H18", "n-OCT(aq)", "C(8)H(18)+(0)", "ref:4", "31.Aug.87", 8580, -59410, 63.8 }, 2.1417100000000002, 4451.26, -11.7437, -46191.00000000001, 124.7924, 412905, -96620, 0 }
    , { { "N-OCTYLBENZENE,AQ", "C6H5C8H17", "n-OCBN(aq)", "C(14)H(22)+(0)", "ref:4", "2.Sep.87", 44690, -36760, 89.6 }, 2.99662, 5177.44, 14.6016, -49193, 215.2173, 129001, -101689.99999999999, 0 }
    , { { "N-PENTANE,AQ", "C5H12", "n-PENT(aq)", "C(5)H(12)+(0)", "ref:4", "31.Aug.87", 2130, -41560, 47.5 }, 1.50143, 2887.71, -5.5949, -39727, 89.207, 281315, -71930, 0 }
    , { { "N-PENTYLBENZENE,AQ", "C6H5C5H11", "n-PEBN(aq)", "C(11)H(16)+(0)", "ref:4", "2.Sep.87", 38210, -19750, 69.5 }, 2.35828, 3901.64, 13.549, -43918, 163.1584, 86007, -71250, 0 }
    , { { "N-PROPYLBENZENE,AQ", "C6H5C3H7", "n-PRBN(aq)", "C(9)H(12)+(0)", "ref:4", "31.Aug.87", 34170, -8630, 56.1 }, 1.9327200000000002, 3051.52, 12.8372, -40404, 128.4523, 57345, -50960.00000000001, 0 }
    , { { "N2,aq", "N2(0)", "N2(aq)", "N(2)+(0)", "ref:3", "7.Feb.89", 4347, -2495, 22.9 }, 0.62046, 736.85, 2.8539, -30836, 35.7911, 83726, -34680, 0 }
    , { { "NH3,aq", "NH3(0)", "NH3(aq)", "N(1)H(3)+(0)", "ref:3", "13.Jul.87", -6383, -19440, 25.77 }, 0.5091100000000001, 279.7, 8.6248, -28946, 20.3, -11700, -5000, 0 }
    , { { "NH4+", "NH4(+)", "NH4+", "N(1)H(4)+(1)", "ref:2", "1.Jul.87", -18990, -31850, 26.57 }, 0.38763000000000003, 234.48000000000002, 8.5605, -28759, 17.45, -210, 15020, 1 }
    , { { "NO2-", "NO2(-)", "NO2-", "N(1)O(2)-(1)", "ref:2", "3.Jul.87", -7700, -25000, 29.4 }, 0.55864, 585.9, 3.4472, -30212, 3.426, -77808, 118470.00000000001, -1 }
    , { { "NO3-", "NO3(-)", "NO3-", "N(1)O(3)-(1)", "ref:2", "1.Jul.87", -26507, -49429, 35.12 }, 0.73161, 678.24, -4.6838, -30594, 7.7, -67250, 109769.99999999999, -1 }
    , { { "Na+", "Na(+)", "Na+", "Na(1)+(1)", "ref:2", "3.Jun.87", -62591, -57433, 13.96 }, 0.1839, -228.5, 3.256, -27260, 18.18, -29810, 33060, 1 }
    , { { "NaBr,aq", "NaBr(0)", "NaBr(aq)", "Na(1)Br(1)+(0)", "ref:5", "JAN.91", -85610, -84830, 34.1 }, 0.6105400000000001, 712.64, 2.9491, -30736, 9.6398, -14111, -13000, 0 }
    , { { "NaCl,aq", "NaCl(0)", "NaCl(aq)", "Na(1)Cl(1)+(0)", "ref:10,11", "OCT.89", -92910, -96120, 28 }, 0.50363, 473.65000000000003, 3.4154, -29748, 10.8, -13000, -3800, 0 }
    , { { "NaF,aq", "NaF(0)", "NaF(aq)", "Na(1)F(1)+(0)", "ref:5", "JAN.91", -128570, -135860, 12 }, 0.27483, -107.08, 6.1709, -27347, 12.4307, -7613, -3000, 0 }
    , { { "NaHSiO3,aq", "NaHSiO3(0)", "NaHSiO3(aq)", "Na(1)H(1)Si(1)O(3)+(0)", "ref:5", "JAN.91", -307140, -332740, 20 }, 0.41742, 241.08, 4.8025, -28786.999999999996, 8.6095, -20894, -3000, 0 }
    , { { "NaI,aq", "NaI(0)", "NaI(aq)", "Na(1)I(1)+(0)", "ref:5", "JAN.91", -72900, -69280, 38.3 }, 0.76488, 1089.48, 1.4679, -32294, 12.1001, -9691, -100, 0 }
    , { { "Nd+3", "Nd(+3)", "Nd+3", "Nd(1)+(3)", "ref:2", "13.Jul.87", -160600, -166500, -49.5 }, -0.33707, -1454.52, 8.3211, -21777.000000000004, 1.6236, -118344, 225500, 3 }
    , { { "Ne,aq", "Ne(0)", "Ne(aq)", "Ne(1)+(0)", "ref:3", "13.Jul.87", 4565, -870, 16.74 }, 0.44709000000000004, 313.52000000000004, 4.5177, -29086, 27.0977, 50523, -25350, 0 }
    , { { "Ni+2", "Ni(+2)", "Ni+2", "Ni(1)+(2)", "ref:2", "1.Jul.87", -10900, -12900, -30.8 }, -0.16942000000000002, -1191.8100000000002, 10.4344, -22863.000000000004, 13.1905, -54179.00000000001, 150670, 2 }
    , { { "NiCl+", "NiCl(+)", "NiCl+", "Ni(1)Cl(1)+(1)", "ref:5", "JAN.91", -40920, -51400, -17 }, 0.10703000000000001, -516.8000000000001, 7.7813, -25654, 18.3277, -14050, 81110, 1 }
    , { { "O2,aq", "O2(0)", "O2(aq)", "O(2)+(0)", "ref:3", "26.Jun.87", 3954, -2900, 26.04 }, 0.57889, 635.36, 3.2528, -30417, 35.353, 83726, -39430, 0 }
    , { { "OCTANOATE,AQ", "C7H15COO-", "OCTAN(aq)", "C(8)H(15)O(2)-(1)", "ref:4", "4.Sep.87", -76340, -151230, 58.7 }, 2.0406500000000003, 4204.36, -10.7711, -45170, 91.1664, 241390, 74020, -1 }
    , { { "OCTANOIC-ACID,AQ", "C7H15COOH", "OCAC(aq)", "C(8)H(16)O(2)+(0)", "ref:4", "1.OCT.87", -83400, -151050, 82.9 }, 2.17216, 3529.71, 13.241, -42381, 144.3812, 72758, -91540, 0 }
    , { { "OH-", "OH(-)", "OH-", "O(1)H(1)-(1)", "ref:2", "9.Jun.87", -37595, -54977, -2.56 }, 0.12527, 7.380000000000001, 1.8423, -27820.999999999996, 4.15, -103460, 172460, -1 }
    , { { "PENTANOATE,AQ", "C4H9COO-", "PNTAT(aq)", "C(5)H(9)O(2)-(1)", "ref:4", "4.Sep.87", -82600, -134410, 38.3 }, 1.39304, 2623.19, -4.5589, -38633, 62.0175, 130170, 104960.00000000001, -1 }
    , { { "PENTANOIC-ACID,AQ", "C4H9COOH", "PEAC(aq)", "C(5)H(10)O(2)+(0)", "ref:4", "2.Sep.87", -89210, -133690, 62.8 }, 1.53109, 2248.58, 12.1803, -37085, 91.7185, 29291, -61100, 0 }
    , { { "PHENOL,AQ", "C6H5OH", "PHOL(aq)", "C(6)H(6)O(1)+(0)", "ref:4", "2.Sep.87", -12585, -36640, 45.8 }, 1.3437000000000001, 1873.73, 11.8793, -35535, 69.9366, 10363, -35360, 0 }
    , { { "PHENYLALANINE,AQ", "C9H11NO2", "PHE(aq)", "C(9)H(11)O(2)N(1)+(0)", "ref:4", "4.Sep.87", -49500, -110080, 52.9 }, 1.8292700000000002, 2844.4, 12.6752, -39548, 83.1794, 21517, -46110, 0 }
    , { { "PO4-3", "PO4(-3)", "PO4-3", "P(1)O(4)-(3)", "ref:2", "9.Jun.87", -243500, -305300, -53 }, -0.052590000000000005, -906.5400000000001, 9.3131, -24042, -9.475, -264397, 561140, -3 }
    , { { "PROPANE,AQ", "C3H8", "PRP(aq)", "C(3)H(8)+(0)", "ref:4", "31.Aug.87", -1963, -30490, 33.37 }, 1.07625, 1849.4800000000002, -1.5133, -35435, 66.3294, 194945.99999999997, -50530, 0 }
    , { { "PROPANOATE,AQ", "C2H5COO-", "PRPAT(aq)", "C(3)H(5)O(2)-(1)", "ref:4", "4.Sep.87", -86770, -122630, 26.5 }, 0.96992, 1590.17, -0.5003, -34363, 52.3, -42000, 122760, -1 }
    , { { "PROPANOIC-ACID,AQ", "C2H5COOH", "PRAC(aq)", "C(3)H(6)O(2)+(0)", "ref:4", "4.Sep.87", -93430, -122470, 49.4 }, 1.09213, 1371.1499999999999, 11.4582, -33457, 54.313, -2460, -40000, 0 }
    , { { "Pb(CH3COO)+", "Pb(CH3COO)(+)", "Pb(CH3COO)+", "Pb(1)C(2)H(3)O(2)+(1)", "ref:5", "JAN.91", -97320, -115210, 36 }, 0.49868, 439.49, 4.0226, -29607, 45.0804, 104727, 570, 1 }
    , { { "Pb(CH3COO)2,aq", "Pb(CH3COO)2(0)", "Pb(CH3COO)2(aq)", "Pb(1)C(4)H(6)O(4)+(0)", "ref:5", "JAN.91", -187020, -187020, 69.8 }, 1.26733, 2316.34, -3.3542, -37366, 97.7026, 288770, -3000, 0 }
    , { { "Pb+2", "Pb(+2)", "Pb+2", "Pb(1)+(2)", "ref:2", "1.Jul.87", -5710, 220, 4.2 }, -0.00051, -779.39, 8.8134, -24568, 8.6624, -56216, 107880, 2 }
    , { { "PbCl+", "PbCl(+)", "PbCl+", "Pb(1)Cl(1)+(1)", "ref:5", "JAN.91", -39050, -38630, 28 }, 0.28934000000000004, -71.65, 6.0316, -27494, 10.2182, -20365.000000000004, 12810, 1 }
    , { { "PbCl2,aq", "PbCl2(0)", "PbCl2(aq)", "Pb(1)Cl(2)+(0)", "ref:5", "JAN.91", -71200, -77700, 47 }, 0.65402, 818.7900000000001, 2.5318, -31175, 7.0623, -26272.000000000004, -3000, 0 }
    , { { "PbCl3-", "PbCl3(-)", "PbCl3-", "Pb(1)Cl(3)-(1)", "ref:5", "JAN.91", -102150, -117700, 59 }, 1.10396, 1917.4299999999998, -1.7863, -35717, 5.9113, -54790, 73560, -1 }
    , { { "PbCl4-2", "PbCl4(-2)", "PbCl4-2", "Pb(1)Cl(4)-(2)", "ref:5", "JAN.91", -133260, -161230, 59.5 }, 1.6415, 3229.9700000000003, -6.9452, -41143, 32.7277, -12054, 231180, -2 }
    , { { "Pd+2", "Pd(+2)", "Pd+2", "Pd(1)+(2)", "ref:2", "12.Jul.87", 42200, 42080, -22.6 }, -0.060790000000000004, -926.58, 9.3919, -23960, 15.378, -43179, 140060, 2 }
    , { { "Pr+3", "Pr(+3)", "Pr+3", "Pr(1)+(3)", "ref:2", "13.Jul.87", -162600, -168800, -50 }, -0.32406, -1419.98, 8.1257, -21920, -1.1975, -127510.99999999999, 223500, 3 }
    , { { "Ra+2", "Ra(+2)", "Ra+2", "Ra(1)+(2)", "ref:2", "3.Jul.87", -134200, -126100, 13 }, 0.06285, -624.69, 8.2053, -25208, 6.2858, -59679, 92900, 2 }
    , { { "Rb+", "Rb(+)", "Rb+", "Rb(1)+(1)", "ref:2", "29.Jun.87", -67800, -60020, 28.8 }, 0.42913, -90.41, 7.407, -27416, 5.7923, -36457, 15020, 1 }
    , { { "RbBr,aq", "RbBr(0)", "RbBr(aq)", "Rb(1)Br(1)+(0)", "ref:5", "JAN.91", -91010, -85730, 54.2 }, 0.84668, 1289.22, 0.6828, -33120, -5.172, -69436, -1000, 0 }
    , { { "RbCl,aq", "RbCl(0)", "RbCl(aq)", "Rb(1)Cl(1)+(0)", "ref:5", "JAN.91", -97870, -96800, 48.56 }, 0.79468, 1162.25, 1.1819, -32595, -5.0607, -69049, -1000, 0 }
    , { { "RbF,aq", "RbF(0)", "RbF(aq)", "Rb(1)F(1)+(0)", "ref:5", "JAN.91", -136450, -139710, 31.6 }, 0.43646000000000007, 287.58, 4.6197, -28979, -3.2196, -62938, -100, 0 }
    , { { "RbI,aq", "RbI(0)", "RbI(aq)", "Rb(1)I(1)+(0)", "ref:5", "JAN.91", -79100, -71920, 56.3 }, 1.0192700000000001, 1710.63, -0.9735, -34862, -3.8542, -65016, -500, 0 }
    , { { "ReO4-", "ReO4(-)", "ReO4-", "Re(1)O(4)-(1)", "ref:2", "12.Jul.87", -166000, -188200, 48.1 }, 0.8651300000000002, 1334.28, 0.5057, -33306, 14.3448, -30753, 90040, -1 }
    , { { "Rn,aq", "Rn(0)", "Rn(aq)", "Rn(1)+(0)", "ref:3", "13.Jul.87", 2790, -5000, 16 }, 0.90862, 1440.45, 0.0884, -33745, 52.5774, 138725, -24230, 0 }
    , { { "S2-2", "S2(-2)", "S2-2", "S(2)-(2)", "ref:2", "3.Jul.87", 19000, 7200, 6.8 }, 0.55797, 584.26, 3.4536, -30205.000000000004, -3.3496, -162955, 310830, -2 }
    , { { "S2O3-2", "S2O3(-2)", "S2O3-2", "S(2)O(3)-(2)", "ref:2", "3.Jul.87", -124900, -155000, 16 }, 0.66685, 1249.51, -7.7281, -32955, -0.0577, -147066, 296940, -2 }
    , { { "S2O4-2", "S2O4(-2)", "S2O4-2", "S(2)O(4)-(2)", "ref:2", "3.Jul.87", -143500, -180100, 22 }, 0.7581500000000001, 1073.0600000000002, 1.5324, -32226, 1.6707, -138103, 287720, -2 }
    , { { "S2O5-2", "S2O5(-2)", "S2O5-2", "S(2)O(5)-(2)", "ref:2", "3.Jul.87", -189000, -232000, 25 }, 0.7977500000000001, 1169.76, 1.1524, -32626, 2.6824, -133215, 283430, -2 }
    , { { "S2O6-2", "S2O6(-2)", "S2O6-2", "S(2)O(6)-(2)", "ref:2", "3.Jul.87", -231000, -280400, 30 }, 0.8622500000000001, 1327.24, 0.5334, -33277, 4.3301, -125066, 275870, -2 }
    , { { "S2O8-2", "S2O8(-2)", "S2O8-2", "S(2)O(8)-(2)", "ref:2", "3.Jul.87", -266500, -321400, 58.4 }, 1.33622, 2484.54, -4.0153, -38061, 12.9632, -81271, 232810, -2 }
    , { { "S3-2", "S3(-2)", "S3-2", "S(3)-(2)", "ref:2", "3.Jul.87", 17600, 6200, 15.8 }, 0.67661, 873.9599999999999, 2.315, -31403, -0.3595, -148288, 297490, -2 }
    , { { "S3O6-2", "S3O6(-2)", "S3O6-2", "S(3)O(6)-(2)", "ref:2", "3.Jul.87", -229000, -279000, 33 }, 0.90313, 1427.06, 0.141, -33689, 5.3169, -120178, 271310, -2 }
    , { { "S4-2", "S4(-2)", "S4-2", "S(4)-(2)", "ref:2", "3.Jul.87", 16500, 5500, 24.7 }, 0.7938100000000001, 1160.1200000000001, 1.1902, -32586, 2.6081, -133622, 283900, -2 }
    , { { "S4O6-2", "S4O6(-2)", "S4O6-2", "S(4)O(6)-(2)", "ref:2", "3.Jul.87", -248700, -292600, 61.5 }, 1.2785000000000002, 2343.62, -3.4614, -37479, 14.6933, -73734, 228050, -2 }
    , { { "S5-2", "S5(-2)", "S5-2", "S(5)-(2)", "ref:2", "3.Jul.87", 15700, 5100, 33.6 }, 0.91107, 1446.4499999999998, 0.0649, -33770, 5.5361, -119159, 270510, -2 }
    , { { "S5O6-2", "S5O6(-2)", "S5O6-2", "S(5)O(6)-(2)", "ref:2", "3.Jul.87", -229000, -281000, 40 }, 0.9953500000000001, 1652.24, -0.744, -34620, 7.6266, -108770, 260760, -2 }
    , { { "SERINE,AQ", "C3H7NO3", "SER(aq)", "C(3)H(7)O(3)N(1)+(0)", "ref:4", "4.Sep.87", -122100, -170800, 46.5 }, 0.9937200000000002, 1174.54, 11.2943, -32645, 29.1225, -21543, -36420, 0 }
    , { { "SO2,aq", "SO2(0)", "SO2(aq)", "S(1)O(2)+(0)", "ref:3", "13.Jul.87", -71980, -77194, 38.7 }, 0.69502, 918.9, 2.1383, -31589, 31.2101, 64578, -24610, 0 }
    , { { "SO3-2", "SO3(-2)", "SO3-2", "S(1)O(3)-(2)", "ref:2", "3.Jul.87", -116300, -151900, -7 }, 0.36537000000000003, 31.91, 7.3853, -27921.999999999996, -7.8368, -185362, 332100, -2 }
    , { { "SO4-2", "SO4(-2)", "SO4-2", "S(1)O(4)-(2)", "ref:2", "3.Jun.87", -177930, -217400, 4.5 }, 0.83014, -198.45999999999998, -6.2122, -26970, 1.64, -179980, 314630, -2 }
    , { { "Sc+3", "Sc(+3)", "Sc+3", "Sc(1)+(3)", "ref:2", "13.Jul.87", -140200, -146800, -61 }, -0.31236, -1540.8400000000001, 11.8062, -21420, 8.4546, -102456, 250030.00000000003, 3 }
    , { { "SeO3-2", "SeO3(-2)", "SeO3-2", "Se(1)O(3)-(2)", "ref:2", "3.Jul.87", -88400, -121700, 3 }, 0.5079100000000001, 462.04, 3.934, -29700.000000000004, -4.5783, -169066, 316580, -2 }
    , { { "SeO4-2", "SeO4(-2)", "SeO4-2", "Se(1)O(4)-(2)", "ref:2", "3.Jul.87", -105500, -143200, 12.9 }, 0.5618000000000001, 593.62, 3.4168, -30244, -1.2986, -152973, 301920, -2 }
    , { { "SiF6-2", "SiF6(-2)", "SiF6-2", "Si(1)F(6)-(2)", "ref:2", "16.Feb.88", -525700, -571000, 29.2 }, 0.85311, 1304.92, 0.6211, -33185, 4.097, -126289, 277160, -2 }
    , { { "SiO2,aq", "SiO2(0)", "SiO2(aq)", "Si(1)O(2)+(0)", "ref:3", "13.Jan.89", -199190, -209775, 18 }, 0.19, 170, 20, -27000, 29.1, -512000, 12910, 0 }
    , { { "Sm+2", "Sm(+2)", "Sm+2", "Sm(1)+(2)", "ref:2", "13.Jul.87", -123000, -120500, -6.2 }, 0.14002, -436.25, 7.4647, -25987, 19.6533, -22809, 122849.99999999999, 2 }
    , { { "Sm+3", "Sm(+3)", "Sm(+3)", "Sm(1)+(3)", "ref:2", "13.Jul.87", -159100, -165200, -50.7 }, -0.32065000000000005, -1561.08, 11.8857, -21337, 1.9385, -118547.99999999999, 229550, 3 }
    , { { "Sn+2", "Sn(+2)", "Sn+2", "Sn(1)+(2)", "ref:2", "1.Jul.87", -6630, -2100, -3.8 }, 0.00786, -758.95, 8.733, -24652, 11.4502, -53160, 128600, 2 }
    , { { "Sr(CO3),aq", "Sr(CO3)(0)", "Sr(CO3)(aq)", "Sr(1)C(1)O(3)+(0)", "ref:5", "JAN.91", -264860, -288620, 8.5 }, -0.01787, -821.7700000000001, 8.9799, -24392.999999999996, -11.4279, -90539, -3000, 0 }
    , { { "Sr+2", "Sr(+2)", "Sr+2", "Sr(1)+(2)", "ref:2", "1.Jul.87", -134760, -131670, -7.53 }, 0.07071, -1015.08, 7.0027, -23594, 10.7452, -50818, 113630.00000000001, 2 }
    , { { "SrCl+", "SrCl(+)", "SrCl+", "Sr(1)Cl(1)+(1)", "ref:5", "JAN.91", -165800, -169790, 11 }, 0.2702, -118.38, 6.2153, -27301.000000000004, 17.326, -3845, 38370, 1 }
    , { { "SrF+", "SrF(+)", "SrF+", "Sr(1)F(1)+(1)", "ref:5", "JAN.91", -202290, -210670, -6.2 }, 0.10491, -521.98, 7.8016, -25632, 21.9809, 3896, 64720, 1 }
    , { { "THREONINE,AQ", "C4H9NO3", "THR(aq)", "C(4)H(9)O(3)N(1)+(0)", "ref:4", "4.Sep.87", -120000, -179100, 53.2 }, 1.21251, 1611.9399999999998, 11.6532, -34453, 47.252, -6604, -46570, 0 }
    , { { "TOLUENE,AQ", "C6H5CH3", "TOL(aq)", "C(7)H(8)+(0)", "ref:4", "4.Sep.87", 30260, 3280, 43.9 }, 1.50259, 2191.5299999999997, 12.1349, -36849, 93.924, 28953.000000000004, -32479.999999999996, 0 }
    , { { "TRYPTOPHAN,AQ", "C11H12N2O2", "TRP(aq)", "C(11)H(12)O(2)N(2)+(0)", "ref:4", "4.Sep.87", -26900, -97800, 36.6 }, 2.1397500000000003, 3464.81, 13.1912, -42112.99999999999, 92.8723, 27330, -21430, 0 }
    , { { "TYROSINE,AQ", "C9H11NO3", "TYR(aq)", "C(9)H(11)O(3)N(1)+(0)", "ref:4", "4.Sep.87", -87300, -157400, 45.5 }, 1.8478400000000001, 2881.27, 12.7114, -39700, 66.7005, 7794, -34900, 0 }
    , { { "Tb+3", "Tb(+3)", "Tb+3", "Tb(1)+(3)", "ref:2", "13.Jul.87", -159500, -166900, -54 }, -0.29355000000000003, -1494.9099999999999, 11.6257, -21610, 4.2522, -112844, 236850, 3 }
    , { { "Tl+", "Tl(+)", "Tl+", "Tl(1)+(1)", "ref:2", "3.Jul.87", -7740, 1280, 30 }, 0.43063000000000007, 273.33, 4.6757, -28920, 5.089, -38901, 15020, 1 }
    , { { "Tl+3", "Tl(+3)", "Tl+3", "Tl(1)+(3)", "ref:2", "3.Jul.87", 51300, 47000, -46 }, -0.28195000000000003, -1466.5800000000002, 11.5143, -21727, 4.7607, -110399.99999999999, 234740, 3 }
    , { { "Tm+3", "Tm(+3)", "Tm+3", "Tm(1)+(3)", "ref:2", "13.Jul.87", -159900, -168500, -58.1 }, -0.32967, -1583.1200000000001, 11.9724, -21245, 8.4826, -100215, 243330, 3 }
    , { { "VALINE,AQ", "C5H11NO2", "VAL(aq)", "C(5)H(11)O(2)N(1)+(0)", "ref:4", "4.Sep.87", -85300, -147300, 42.6 }, 1.40856, 2003.4300000000003, 11.9842, -36071, 67.709, 8267, -30510, 0 }
    , { { "VO+2", "VO(+2)", "VO+2", "V(1)O(1)+(2)", "ref:2", "12.Jul.87", -106700, -116300, -32 }, -0.17351000000000003, -1201.8000000000002, 10.4736, -22822, 13.391, -54790, 154750, 2 }
    , { { "VO2+", "VO2(+)", "VO2+", "V(1)O(2)+(1)", "ref:2", "12.Jul.87", -140300, -155300, -10.1 }, -0.25825000000000004, -1408.71, 11.2869, -21966, 30.8449, 33005, 70030, 1 }
    , { { "WO4-2", "WO4(-2)", "WO4-2", "W(1)O(4)-(2)", "ref:2", "1.Jul.87", -219150, -257100, 9.7 }, 0.72074, 879.34, 4.4896, -31425, 8.3311, -120992, 306570, -2 }
    , { { "Xe,aq", "Xe(0)", "Xe(aq)", "Xe(1)+(0)", "ref:3", "13.Jul.87", 3225, -4510, 14.62 }, 0.75196, 1057.93, 1.5919, -32163, 42.1036, 101652, -22140, 0 }
    , { { "Y+3", "Y(+3)", "Y+3", "Y(1)+(3)", "ref:2", "13.Jul.87", -163800, -170900, -60 }, -0.3014, -1514.0800000000002, 11.701, -21530.999999999996, 7.1634, -103067, 237920, 3 }
    , { { "Yb+2", "Yb(+2)", "Yb+2", "Yb(1)+(2)", "ref:2", "13.Jul.87", -128500, -126800, -11.2 }, 0.07707000000000001, -589.9499999999999, 8.0688, -25351, 17.8951, -28920, 122849.99999999999, 2 }
    , { { "Yb+3", "Yb(+3)", "Yb+3", "Yb(1)+(3)", "ref:2", "13.Jul.87", -153000, -160300, -56.9 }, -0.34983000000000003, -1632.33, 12.1658, -21042, 7.3533, -104492.99999999999, 244430, 3 }
    , { { "Zn(CH3COO)+", "Zn(CH3COOH)(+)", "Zn(CH3COOH)+", "Zn(1)C(2)H(3)O(2)+(1)", "ref:5", "JAN.91", -125660, -155120, 9.4 }, 0.34786000000000006, 71.24000000000001, 5.47, -28085, 60.4333, 145142, 41000, 1 }
    , { { "Zn(CH3COO)2,aq", "Zn(CH3COOH)2(0)", "Zn(CH3COOH)2(aq", "Zn(1)C(4)H(6)O(4)+(0)", "ref:5", "JAN.91", -216450, -271500, 22.47 }, 1.04018, 1761.69, -1.1742, -35073, 119.1584, 363345, -3000, 0 }
    , { { "Zn(CH3COO)3-", "Zn(CH3COO)3(-)", "Zn(CH3COO)3-", "Zn(1)C(6)H(9)O(6)-(1)", "ref:5", "JAN.91", -305080, -378900, 73.72 }, 2.0655200000000002, 4265.31, -11.0145, -45423, 70.0818, 175391, 51259.99999999999, -1 }
    , { { "Zn+2", "Zn(+2)", "Zn+2", "Zn(1)+(2)", "ref:2", "1.Jul.87", -35200, -36660, -26.2 }, -0.10677000000000002, -1038.8400000000001, 9.8331, -23495, 15.9009, -43179, 145740, 2 }
    , { { "ZnCl+", "ZnCl(+)", "ZnCl+", "Zn(1)Cl(1)+(1)", "ref:5", "JAN.91", -66850, -66240, 23 }, 0.15844000000000003, -391.28, 7.2879, -26172, 22.4668, 19825, 20250, 1 }
    , { { "ZnCl2,aq", "ZnCl2(0)", "ZnCl2(aq)", "Zn(1)Cl(2)+(0)", "ref:5", "JAN.91", -98300, -109080, 27.03 }, 0.5057, 456.65, 3.9552, -29678, 32.0555, 59669, -100, 0 }
    , { { "ZnCl3-", "ZnCl3(-)", "ZnCl3-", "Zn(1)Cl(3)-(1)", "ref:5", "JAN.91", -129310, -151060, 25 }, 0.9541700000000001, 1551.68, -0.3487, -34205, 42.3675, 55412, 125130.00000000001, -1 }
    , { { "ZnCl4-2", "ZnCl4(-2)", "ZnCl4-2", "Zn(1)Cl(4)-(2)", "ref:5", "JAN.91", -161890, -195200, 36 }, 1.4662800000000002, 2802.13, -5.2636, -39374, 56.1061, 57855.99999999999, 266620, -2 }
}};
    const auto
aqueous_species_name_to_index = std::unordered_map <std::string_view, int>
{

      { "1-BUTANAMINE,AQ", 0 }
    , { "1-BUTANOL,AQ", 1 }
    , { "1-BUTENE,AQ", 2 }
    , { "1-BUTYNE,AQ", 3 }
    , { "1-HEPTANAMINE,AQ", 4 }
    , { "1-HEPTANOL,AQ", 5 }
    , { "1-HEPTENE,AQ", 6 }
    , { "1-HEPTYNE,AQ", 7 }
    , { "1-HEXANAMINE,AQ", 8 }
    , { "1-HEXANOL,AQ", 9 }
    , { "1-HEXENE,AQ", 10 }
    , { "1-HEXYNE,AQ", 11 }
    , { "1-OCTANAMINE,AQ", 12 }
    , { "1-OCTANOL,AQ", 13 }
    , { "1-OCTENE,AQ", 14 }
    , { "1-OCTYNE,AQ", 15 }
    , { "1-PENTANAMINE,AQ", 16 }
    , { "1-PENTANOL,AQ", 17 }
    , { "1-PENTENE,AQ", 18 }
    , { "1-PENTYNE,AQ", 19 }
    , { "1-PROPANAMINE,AQ", 20 }
    , { "1-PROPANOL,AQ", 21 }
    , { "1-PROPENE,AQ", 22 }
    , { "1-PROPYNE,AQ", 23 }
    , { "2-BUTANONE,AQ", 24 }
    , { "2-HEPTANONE,AQ", 25 }
    , { "2-HEXANONE,AQ", 26 }
    , { "2-OCTANONE,AQ", 27 }
    , { "2-PENTANONE,AQ", 28 }
    , { "A-AMINOBUTYRIC,AQ", 29 }
    , { "ACETATE,AQ", 30 }
    , { "ACETIC-ACID,AQ", 31 }
    , { "ACETONE,AQ", 32 }
    , { "ALANINE,AQ", 33 }
    , { "ASPARAGINE,AQ", 34 }
    , { "ASPARTIC-ACID,AQ", 35 }
    , { "Ag(CO3)-", 36 }
    , { "Ag(CO3)2-3", 37 }
    , { "Ag+", 38 }
    , { "Ag+2", 39 }
    , { "AgCl,aq", 40 }
    , { "AgCl2-", 41 }
    , { "AgCl3-2", 42 }
    , { "AgCl4-3", 43 }
    , { "AgNO3,aq", 44 }
    , { "Al(OH)+2", 45 }
    , { "Al+3", 46 }
    , { "Ar,aq", 47 }
    , { "Au+", 48 }
    , { "Au+3", 49 }
    , { "B(OH)3,aq", 50 }
    , { "BENZENE,AQ", 51 }
    , { "BF4-", 52 }
    , { "BO2-", 53 }
    , { "BUTANOATE,AQ", 54 }
    , { "BUTANOIC-ACID,AQ", 55 }
    , { "Ba(CO3),aq", 56 }
    , { "Ba+2", 57 }
    , { "BaCl+", 58 }
    , { "BaF+", 59 }
    , { "Be+2", 60 }
    , { "BeO2-2", 61 }
    , { "Br-", 62 }
    , { "Br3-", 63 }
    , { "BrO-", 64 }
    , { "BrO3-", 65 }
    , { "BrO4-", 66 }
    , { "CN-", 67 }
    , { "CO2,aq", 68 }
    , { "CO3-2", 69 }
    , { "Ca(CO3),aq", 70 }
    , { "Ca(HCO3)+", 71 }
    , { "Ca+2", 72 }
    , { "CaCl+", 73 }
    , { "CaCl2,aq", 74 }
    , { "CaF+", 75 }
    , { "CaSO4,aq", 76 }
    , { "Cd+2", 77 }
    , { "Ce+3", 78 }
    , { "Cl-", 79 }
    , { "ClO-", 80 }
    , { "ClO2-", 81 }
    , { "ClO3-", 82 }
    , { "ClO4-", 83 }
    , { "Co+2", 84 }
    , { "Co+3", 85 }
    , { "Cr2O7-2", 86 }
    , { "CrO4-2", 87 }
    , { "Cs+", 88 }
    , { "CsBr,aq", 89 }
    , { "CsCl,aq", 90 }
    , { "CsI,aq", 91 }
    , { "Cu+", 92 }
    , { "Cu+2", 93 }
    , { "Dy+3", 94 }
    , { "ETHANAMINE,AQ", 95 }
    , { "ETHANE,AQ", 96 }
    , { "ETHANOL,AQ", 97 }
    , { "ETHYLBENZENE,AQ", 98 }
    , { "ETHYLENE,AQ", 99 }
    , { "ETHYNE,AQ", 100 }
    , { "Er+3", 101 }
    , { "Eu+2", 102 }
    , { "Eu+3", 103 }
    , { "F-", 104 }
    , { "FORMATE,AQ", 105 }
    , { "FORMIC-ACID,AQ", 106 }
    , { "Fe(CH3COO)+", 107 }
    , { "Fe(CH3COO)2,aq", 108 }
    , { "Fe+2", 109 }
    , { "Fe+3", 110 }
    , { "FeCl+", 111 }
    , { "FeCl2,aq", 112 }
    , { "GLUTAMIC-ACID,AQ", 113 }
    , { "GLUTAMINE,AQ", 114 }
    , { "GLYCINE,AQ", 115 }
    , { "Ga+3", 116 }
    , { "Gd+3", 117 }
    , { "H+", 118 }
    , { "H2,aq", 119 }
    , { "H2AsO3-", 120 }
    , { "H2AsO4-", 121 }
    , { "H2P2O7-2", 122 }
    , { "H2PO4-", 123 }
    , { "H2S,aq", 124 }
    , { "H2VO4-", 125 }
    , { "H3P2O7-", 126 }
    , { "H3PO4,aq", 127 }
    , { "HAsO4-2", 128 }
    , { "HCO3-", 129 }
    , { "HCrO4-", 130 }
    , { "HEPTANOATE,AQ", 131 }
    , { "HEPTANOIC-ACID,AQ", 132 }
    , { "HEXANOATE,AQ", 133 }
    , { "HEXANOIC-ACID,AQ", 134 }
    , { "HF,aq", 135 }
    , { "HF2-", 136 }
    , { "HNO3,aq", 137 }
    , { "HO2-", 138 }
    , { "HPO4-2", 139 }
    , { "HS-", 140 }
    , { "HSO3-", 141 }
    , { "HSO4-", 142 }
    , { "HSO5-", 143 }
    , { "HSe-", 144 }
    , { "HSeO3-", 145 }
    , { "HSeO4-", 146 }
    , { "HSiO3-", 147 }
    , { "HVO4-2", 148 }
    , { "He,aq", 149 }
    , { "Hg+2", 150 }
    , { "Hg2+2", 151 }
    , { "Ho+3", 152 }
    , { "I-", 153 }
    , { "I3-", 154 }
    , { "IO-", 155 }
    , { "IO3-", 156 }
    , { "IO4-", 157 }
    , { "ISOLEUCINE,AQ", 158 }
    , { "In+3", 159 }
    , { "K+", 160 }
    , { "KBr,aq", 161 }
    , { "KCl,aq", 162 }
    , { "KHSO4,aq", 163 }
    , { "KI,aq", 164 }
    , { "KSO4-", 165 }
    , { "Kr,aq", 166 }
    , { "LEUCINE,AQ", 167 }
    , { "La+3", 168 }
    , { "Li+", 169 }
    , { "LiCl,aq", 170 }
    , { "Lu+3", 171 }
    , { "METHANAMINE,AQ", 172 }
    , { "METHANE,AQ", 173 }
    , { "METHANOL,AQ", 174 }
    , { "METHIONINE,AQ", 175 }
    , { "Mg(CO3),aq", 176 }
    , { "Mg(HCO3)+", 177 }
    , { "Mg+2", 178 }
    , { "MgCl+", 179 }
    , { "MgF+", 180 }
    , { "Mn+2", 181 }
    , { "MnCl+", 182 }
    , { "MnO4-", 183 }
    , { "MnO4-2", 184 }
    , { "MnSO4,aq", 185 }
    , { "MoO4-2", 186 }
    , { "N-BUTANE,AQ", 187 }
    , { "N-BUTYLBENZENE,AQ", 188 }
    , { "N-HEPTANE,AQ", 189 }
    , { "N-HEPTYLBENZENE,AQ", 190 }
    , { "N-HEXANE,AQ", 191 }
    , { "N-HEXYLBENZENE,AQ", 192 }
    , { "N-OCTANE,AQ", 193 }
    , { "N-OCTYLBENZENE,AQ", 194 }
    , { "N-PENTANE,AQ", 195 }
    , { "N-PENTYLBENZENE,AQ", 196 }
    , { "N-PROPYLBENZENE,AQ", 197 }
    , { "N2,aq", 198 }
    , { "NH3,aq", 199 }
    , { "NH4+", 200 }
    , { "NO2-", 201 }
    , { "NO3-", 202 }
    , { "Na+", 203 }
    , { "NaBr,aq", 204 }
    , { "NaCl,aq", 205 }
    , { "NaF,aq", 206 }
    , { "NaHSiO3,aq", 207 }
    , { "NaI,aq", 208 }
    , { "Nd+3", 209 }
    , { "Ne,aq", 210 }
    , { "Ni+2", 211 }
    , { "NiCl+", 212 }
    , { "O2,aq", 213 }
    , { "OCTANOATE,AQ", 214 }
    , { "OCTANOIC-ACID,AQ", 215 }
    , { "OH-", 216 }
    , { "PENTANOATE,AQ", 217 }
    , { "PENTANOIC-ACID,AQ", 218 }
    , { "PHENOL,AQ", 219 }
    , { "PHENYLALANINE,AQ", 220 }
    , { "PO4-3", 221 }
    , { "PROPANE,AQ", 222 }
    , { "PROPANOATE,AQ", 223 }
    , { "PROPANOIC-ACID,AQ", 224 }
    , { "Pb(CH3COO)+", 225 }
    , { "Pb(CH3COO)2,aq", 226 }
    , { "Pb+2", 227 }
    , { "PbCl+", 228 }
    , { "PbCl2,aq", 229 }
    , { "PbCl3-", 230 }
    , { "PbCl4-2", 231 }
    , { "Pd+2", 232 }
    , { "Pr+3", 233 }
    , { "Ra+2", 234 }
    , { "Rb+", 235 }
    , { "RbBr,aq", 236 }
    , { "RbCl,aq", 237 }
    , { "RbF,aq", 238 }
    , { "RbI,aq", 239 }
    , { "ReO4-", 240 }
    , { "Rn,aq", 241 }
    , { "S2-2", 242 }
    , { "S2O3-2", 243 }
    , { "S2O4-2", 244 }
    , { "S2O5-2", 245 }
    , { "S2O6-2", 246 }
    , { "S2O8-2", 247 }
    , { "S3-2", 248 }
    , { "S3O6-2", 249 }
    , { "S4-2", 250 }
    , { "S4O6-2", 251 }
    , { "S5-2", 252 }
    , { "S5O6-2", 253 }
    , { "SERINE,AQ", 254 }
    , { "SO2,aq", 255 }
    , { "SO3-2", 256 }
    , { "SO4-2", 257 }
    , { "Sc+3", 258 }
    , { "SeO3-2", 259 }
    , { "SeO4-2", 260 }
    , { "SiF6-2", 261 }
    , { "SiO2,aq", 262 }
    , { "Sm+2", 263 }
    , { "Sm+3", 264 }
    , { "Sn+2", 265 }
    , { "Sr(CO3),aq", 266 }
    , { "Sr+2", 267 }
    , { "SrCl+", 268 }
    , { "SrF+", 269 }
    , { "THREONINE,AQ", 270 }
    , { "TOLUENE,AQ", 271 }
    , { "TRYPTOPHAN,AQ", 272 }
    , { "TYROSINE,AQ", 273 }
    , { "Tb+3", 274 }
    , { "Tl+", 275 }
    , { "Tl+3", 276 }
    , { "Tm+3", 277 }
    , { "VALINE,AQ", 278 }
    , { "VO+2", 279 }
    , { "VO2+", 280 }
    , { "WO4-2", 281 }
    , { "Xe,aq", 282 }
    , { "Y+3", 283 }
    , { "Yb+2", 284 }
    , { "Yb+3", 285 }
    , { "Zn(CH3COO)+", 286 }
    , { "Zn(CH3COO)2,aq", 287 }
    , { "Zn(CH3COO)3-", 288 }
    , { "Zn+2", 289 }
    , { "ZnCl+", 290 }
    , { "ZnCl2,aq", 291 }
    , { "ZnCl3-", 292 }
    , { "ZnCl4-2", 293 }
};
} // namespace sprons92
