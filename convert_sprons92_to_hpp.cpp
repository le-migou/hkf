#include <vector>
#include <fstream>
#include <cassert>
#include <fmt/ranges.h>
    using fmt::print;

    void
dump (std::string_view s, bool last = false)
{
    print ("\"{}\"{}", s, last ? "" : ", ");
}
    void
dump (double x, bool last = false)
{
    print ("{}{}", x, last ? "" : ", ");
}
    void
dump (std::array <double, 3> s, bool last = false)
{
    print ("{{ {} }}{}", fmt::join (s, ", "), last ? "" : ", ");
}

    auto
ltrim (std::string& s) 
{
    s.erase (s.begin (), std::find_if (
          s.begin ()
        , s.end ()
        , [](unsigned char ch) 
          {
            return !std::isspace (ch);
          }
    ));
}
    auto
rtrim (std::string& s) 
{
    s.erase(std::find_if(
          s.rbegin()
        , s.rend()
        , [](unsigned char ch) 
          {
            return !std::isspace(ch);
          }
    ).base(), s.end());
}
    auto
trim (std::string& s)
{
    ltrim (s);
    rtrim (s);
}

    struct
data_base_t
{
        std::string
    name;
        std::string
    chemical_formula_structural;
        std::string
    abbreviation;
        std::string
    chemical_formula_elemental;
        std::string
    reference;
        std::string
    date;
        double
    DG;
        double
    DH;
        double
    S;
};
    constexpr auto
dump_base (data_base_t const& d)
{
    print ("{{ ");
    dump (d.name);
    dump (d.chemical_formula_structural);
    dump (d.abbreviation);
    dump (d.chemical_formula_elemental);
    dump (d.reference);
    dump (d.date);
    dump (d.DG);
    dump (d.DH);
    dump (d.S, true);
    print (" }}, ");
}
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
    constexpr auto
dump (gas_t const& d)
{
    print ("{{ ");
    dump_base (d);
    dump (d.V);
    dump (d.a);
    dump (d.b);
    dump (d.c);
    dump (d.T_max, true);
    print (" }}");
}
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

    constexpr auto
dump (mineral_t const& d)
{
    print ("{{ ");
    dump_base (d);
    dump (d.V);
    dump (d.a);
    dump (d.b);
    dump (d.c);
    dump (d.T);
    dump (d.DHt);
    dump (d.DVt);
    dump (d.dP_dT);
    dump (d.a_n);
    dump (d.b_n);
    dump (d.c_n);
    dump (d.T_max);
    dump (d.phase_transition_count, true);
    print (" }}");
}
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
    constexpr auto
dump (aqueous_species_t const& d)
{
    print ("{{ ");
    dump_base (d);
    dump (d.a_1);
    dump (d.a_2);
    dump (d.a_3);
    dump (d.a_4);
    dump (d.c_1);
    dump (d.c_2);
    dump (d.omega);
    dump (d.charge, true);
    print (" }}");
}

    auto
read_data_base (std::ifstream& in, data_base_t& out)
{
    if (in.peek () != ' ') return false;
    in  
        >> out.name >> out.chemical_formula_structural >> out.abbreviation 
        >> out.chemical_formula_elemental >> out.reference >> out.date
        >> out.DG >> out.DH >> out.S 
    ;
    return true;
}

    auto
read_gas (std::ifstream& in, gas_t& out)
{
    if (!read_data_base (in, out)) return false;
    in >> out.V >> out.a >> out.b >> out.c >> out.T_max;
    // ---  WARNING: for gases, the names and formulas are swapped. 
    swap (out.name, out.chemical_formula_structural);
    swap (out.abbreviation, out.chemical_formula_elemental);
    // ---
    out.b *= 1e-3;
    out.c *= 1e5;
    in.ignore (10, '\n');
    return true;
}

    auto
read_mineral_phase_transition (
      std::ifstream& in
    , mineral_t& out
    , int phase_transition_count
){
    if (!read_data_base (in, out)) return false;
    in >> out.V;
    for (auto i = 0; i < phase_transition_count; ++i)
    {
        in
            >> out.a[i] >> out.b[i] >> out.c[i] >> out.T[i]
            >> out.DHt[i] >> out.DVt[i] >> out.dP_dT[i]
        ;
        out.b[i] *= 1e-3;
        out.c[i] *= 1e5;
    }
    in >> out.a_n >> out.b_n >> out.c_n >> out.T_max;
    out.b_n *= 1e-3;
    out.c_n *= 1e5;
    out.phase_transition_count = phase_transition_count;
    in.ignore (10, '\n');
    return true;
}

    auto
read_mineral_no_phase_transition (std::ifstream& in, mineral_t& out)
{
    if (!read_data_base (in, out)) return false;
    in >> out.V >> out.a[0] >> out.b[0] >> out.c[0] >> out.T_max;
    out.b[0] *= 1e-3;
    out.c[0] *= 1e5;
    out.phase_transition_count = 0;
    in.ignore (10, '\n');
    return true;
}

    auto
read_aqueous_species (std::ifstream& in, aqueous_species_t& out)
{
    if (!read_data_base (in, out)) return false;
    in 
        >> out.a_1 >> out.a_2 >> out.a_3
        >> out.a_4 >> out.c_1 >> out.c_2
        >> out.omega >> out.charge
    ;
    out.a_1 *= 1e-1;
    out.a_2 *= 1e2;
    out.a_4 *= 1e4;
    out.c_2 *= 1e4;
    out.omega *= 1e5;
    in.ignore (10, '\n');
    return true;
}

    auto
minerals = std::vector <mineral_t> {};
    auto
gases = std::vector <gas_t> {};
    auto
aqueous_species = std::vector <aqueous_species_t> {};
    auto
mineral_names = std::vector <std::string> {};
    auto
gas_names = std::vector <std::string> {};
    auto
aqueous_species_names = std::vector <std::string> {};

    int
main ()
{
        auto
    in = std::ifstream { "sprons92.dat" };
        auto
    line = std::string {};
        auto
    mineral_count = 0;
        auto
    gases_count = 0;
        auto
    aqueous_species_count = 0;
    while (std::getline (in, line))
    {
        trim (line);
        if (line.empty ()) continue;
        if (line[0] == '*') continue;
        if (line == "minerals that do not undergo phase transitions")
        {
            std::getline (in, line);
                auto
            data = mineral_t {};
            while (read_mineral_no_phase_transition (in, data))
            {
                mineral_names.push_back (data.name);
                minerals.push_back (std::move (data));
            }
            continue;
        }
        if (line == "minerals that undergo one phase transition")
        {
            std::getline (in, line);
                auto
            data = mineral_t {};
            while (read_mineral_phase_transition (in, data, 1))
            {
                mineral_names.push_back (data.name);
                minerals.push_back (std::move (data));
            }
            continue;
        }
        if (line == "minerals that undergo two phase transitions")
        {
            std::getline (in, line);
                auto
            data = mineral_t {};
            while (read_mineral_phase_transition (in, data, 2))
            {
                mineral_names.push_back (data.name);
                minerals.push_back (std::move (data));
            }
            continue;
        }
        if (line == "minerals that undergo three phase transitions")
        {
            std::getline (in, line);
                auto
            data = mineral_t {};
            while (read_mineral_phase_transition (in, data, 3))
            {
                mineral_names.push_back (data.name);
                minerals.push_back (std::move (data));
            }
            continue;
        }
        if (line == "gases")
        {
            std::getline (in, line);
                auto
            data = gas_t {};
            while (read_gas (in, data))
            {
                gas_names.push_back (data.name);
                gases.push_back (std::move (data));
            }
            continue;
        }
        if (line == "aqueous species")
        {
            std::getline (in, line);
                auto
            data = aqueous_species_t {};
            while (read_aqueous_species (in, data))
            {
                aqueous_species_names.push_back (data.name);
                aqueous_species.push_back (std::move (data));
                if (in.peek () != ' ') break;
            }
        }
        // Summary
        std::getline (in, line);
        std::getline (in, line);
            unsigned
        n0;
        in >> n0;
        in.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
            unsigned
        n1;
        in >> n1;
        in.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
            unsigned
        n2;
        in >> n2;
        in.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
            unsigned
        n3;
        in >> n3;
        in.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        mineral_count = n0 + n1 + n2 + n3;
        assert (ssize (minerals) == mineral_count);
        in >> gases_count;
        in.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        assert (ssize (gases) == gases_count);
        in >> aqueous_species_count;
        in.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        assert (ssize (aqueous_species) == aqueous_species_count);
        break;
    }

    puts(R"(#pragma once
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
)");
    puts ("    enum class\ntype { mineral = 0, gas, aqueous_species };");
    puts ("    const auto\nname_to_type = std::unordered_map <std::string_view, type>\n{");
        bool
    first = true;
    for (auto const& d: minerals)
    {
        print ("    {} {{ \"{}\", type::mineral }}\n", first ? ' ' : ',', d.name);
        first = false;
    }
    for (auto const& d: gases)
    {
        print ("    {} {{ \"{}\", type::gas }}\n", first ? ' ' : ',', d.name);
    }
    for (auto const& d: aqueous_species)
    {
        print ("    {} {{ \"{}\", type::aqueous_species }}\n", first ? ' ' : ',', d.name);
    }
    puts ("};");

    print ("    const auto\nminerals = std::array <mineral_t, {}>\n{{{{\n", mineral_count);
    first = true;
    for (auto const& d: minerals)
    {
        print ("    {} ", first ? ' ' : ',');
        dump (d);
        puts ("");
        first = false;
    }
    puts ("}};");

    puts ("    const auto\nmineral_name_to_index = std::unordered_map <std::string_view, int>\n{\n");
    first = true;
        int
    i = 0;
    for (auto const& d: minerals)
    {
        print ("    {} {{ \"{}\", {} }}\n", first ? ' ' : ',', d.name, i);
        first = false;
        ++i;
    }
    puts ("};");
    
    print ("    const auto\ngases = std::array <gas_t, {}>\n{{{{\n", gases_count);
    first = true;
    for (auto const& d: gases)
    {
        print ("    {} ", first ? ' ' : ',');
        dump (d);
        puts ("");
        first = false;
    }
    puts ("}};");

    puts ("    const auto\ngas_name_to_index = std::unordered_map <std::string_view, int>\n{\n");
    first = true;
    i = 0;
    for (auto const& d: gases)
    {
        print ("    {} {{ \"{}\", {} }}\n", first ? ' ' : ',', d.name, i);
        first = false;
        ++i;
    }
    puts ("};");

    print ("    const auto\naqueous_species = std::array <aqueous_species_t, {}>\n{{{{\n", aqueous_species_count);
    first = true;
    for (auto const& d: aqueous_species)
    {
        print ("    {} ", first ? ' ' : ',');
        dump (d);
        puts ("");
        first = false;
    }
    puts ("}};");

    puts ("    const auto\naqueous_species_name_to_index = std::unordered_map <std::string_view, int>\n{\n");
    first = true;
    i = 0;
    for (auto const& d: aqueous_species)
    {
        print ("    {} {{ \"{}\", {} }}\n", first ? ' ' : ',', d.name, i);
        first = false;
        ++i;
    }
    puts ("};");
    puts ("} // namespace sprons92");
}
