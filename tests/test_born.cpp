#include <doctest/doctest.h>
    using doctest::Approx;
#include "../include/calculisto/hkf/born.hpp"
#include "../include/calculisto/hkf/dielectric_constant_sverjensky_2014.hpp"
#include "../include/calculisto/hkf/dielectric_constant_uematsu_1980.hpp"
#include "../include/calculisto/hkf/eos_h2o_zhang_duan_2005.hpp"
#include <calculisto/iapws/r6_inverse.hpp>
#include <calculisto/iapws/r8.hpp>
#include <fstream>
#include "supcrt_results.hpp"

    using namespace calculisto::thermodynamics;
    using namespace calculisto::thermodynamics::dielectric_constant;
    using namespace calculisto::thermodynamics::eos::water;

TEST_CASE("Born function")
{
        auto
    o = std::ofstream { "born.csv" };
    SUBCASE ("Comparison with SUPCRT92")
    {
        for (auto const& [temperature, map]: supcrt_data_isotherms)
        {
            o << "# T = " << temperature << " K\n";
            for (auto const& [pressure_in_bar, data]: map)
            {
                    const auto
                density = data.D * 1e3;
                    const auto
                pressure = pressure_in_bar * 1e5;
                INFO(
                    "P= ", pressure
                    , " Pa, T= ", temperature
                    , " K, D= ", density, " kg/m3"
                );
                    const auto
                pressure_zhang = zhang_2005::pressure_dt (density, temperature);
                    const auto
                dielectric_constant_iapws = iapws::r8::relative_permittivity_dt (density, temperature);
                    const auto
                z_iapws = born::z (dielectric_constant_iapws);
                    const auto
                dielectric_constant_sverj = sverjensky_2014::dielectric_constant_dt (density, temperature);
                    const auto
                z_sverj = born::z (dielectric_constant_sverj);
                    const auto
                dielectric_constant_uemat = uematsu_1980::dielectric_constant_dt (density, temperature);
                    const auto
                z_uemat = born::z (dielectric_constant_uemat);
                    const auto
                d_density_d_presure_at_temperature_iapws = 1 / iapws::r6::d_pressure_d_density_at_temperature_dt (density, temperature);
                    const auto
                d_dielectric_constant_d_density_at_temperature_iapws = iapws::r8::d_relative_permittivity_d_density_at_temperature_dt (density, temperature);
                    const auto
                q_iapws = born::q (
                    dielectric_constant_iapws
                    , d_density_d_presure_at_temperature_iapws
                    , d_dielectric_constant_d_density_at_temperature_iapws
                );
                    const auto
                d_density_d_pressure_at_temperature_zhang = zhang_2005::d_density_d_pressure_at_temperature_dt (density, temperature);
                    const auto
                d_dielectric_constant_d_density_at_temperature_sverj = sverjensky_2014::d_dielectric_constant_d_density_at_temperature_dt (density, temperature);
                    const auto
                q_sverj = born::q (
                    dielectric_constant_sverj
                    , d_density_d_pressure_at_temperature_zhang
                    , d_dielectric_constant_d_density_at_temperature_sverj
                );
                    const auto
                d_dielectric_constant_d_temperature_at_density_iapws = iapws::r8::d_relative_permittivity_d_temperature_at_density_dt (density, temperature);
                    const auto
                d_density_d_temperature_at_pressure_iapws = iapws::r6::d_density_d_temperature_at_pressure_dt (density, temperature);
                    const auto
                y_iapws = born::y (
                    dielectric_constant_iapws
                    , d_dielectric_constant_d_temperature_at_density_iapws
                    , d_dielectric_constant_d_density_at_temperature_iapws
                    , d_density_d_temperature_at_pressure_iapws
                );
                    const auto
                d_dielectric_constant_d_temperature_at_density_sverj = sverjensky_2014::d_dielectric_constant_d_temperature_at_density_dt (density, temperature);
                    const auto
                y_sverj = born::y (
                    dielectric_constant_sverj
                    , d_dielectric_constant_d_temperature_at_density_sverj
                    , d_dielectric_constant_d_density_at_temperature_iapws
                    , d_density_d_temperature_at_pressure_iapws
                );
                    const auto
                d_dielectric_constant_d2_temperature_at_density_iapws = iapws::r8::d_relative_permittivity_d2_temperature_at_density_dt (density, temperature);
                    const auto
                d_dielectric_constant_d_density_temperature_at_temperature_density_iapws = iapws::r8::d_relative_permittivity_d_density_temperature_at_temperature_density_dt (density, temperature);
                    const auto
                d_dielectric_constant_d2_density_at_temperature_iapws = iapws::r8::d_relative_permittivity_d2_density_at_temperature_dt (density, temperature);
                    const auto
                d_density_d2_temperature_at_pressure_density_iapws = iapws::r6::d_density_d2_temperature_at_pressure_density_dt (density, temperature);
                    const auto
                d_density_d_temperature_density_at_pressure_temperature_iapws = iapws::r6::d_density_d_temperature_density_at_pressure_temperature_dt (density, temperature);
                    const auto
                x_iapws = born::x (
                    dielectric_constant_iapws
                    , d_dielectric_constant_d2_temperature_at_density_iapws
                    , d_dielectric_constant_d_density_temperature_at_temperature_density_iapws
                    , d_dielectric_constant_d_density_at_temperature_iapws
                    , d_dielectric_constant_d2_density_at_temperature_iapws
                    , d_density_d_temperature_at_pressure_iapws
                    , d_density_d2_temperature_at_pressure_density_iapws
                    , d_density_d_temperature_density_at_pressure_temperature_iapws
                    , y_iapws
                );
                    const auto
                d_dielectric_constant_d2_temperature_at_density_sverj = sverjensky_2014::d_dielectric_constant_d2_temperature_at_density_dt (density, temperature);
                    const auto
                d_dielectric_constant_d_density_temperature_at_temperature_density_sverj = sverjensky_2014::d_dielectric_constant_d_density_temperature_at_temperature_density_dt (density, temperature);
                    const auto
                d_dielectric_constant_d2_density_at_temperature_sverj = sverjensky_2014::d_dielectric_constant_d2_density_at_temperature_dt (density, temperature);
                    const auto
                d_density_d_temperature_at_pressure_zhang = zhang_2005::d_density_d_temperature_at_pressure_dt (density, temperature);
                    const auto
                d_density_d2_temperature_at_pressure_density_zhang = zhang_2005::d_density_d2_temperature_at_pressure_density_dt (density, temperature);
                    const auto
                d_density_d_temperature_density_at_pressure_temperature_zhang = zhang_2005::d_density_d_temperature_density_at_pressure_temperature_dt (density, temperature);
                    const auto
                x_sverj = born::x (
                    dielectric_constant_sverj
                    , d_dielectric_constant_d2_temperature_at_density_sverj
                    , d_dielectric_constant_d_density_temperature_at_temperature_density_sverj
                    , d_dielectric_constant_d_density_at_temperature_sverj
                    , d_dielectric_constant_d2_density_at_temperature_sverj
                    , d_density_d_temperature_at_pressure_zhang
                    , d_density_d2_temperature_at_pressure_density_zhang
                    , d_density_d_temperature_density_at_pressure_temperature_zhang
                    , y_sverj
                );
                    const auto
                is_zhang_valid = pressure_zhang >= 100e6;
                    const auto
                is_sverjensky_valid = 
                        is_zhang_valid
                    and temperature >= 100 + 273.15 
                    and temperature <= 1200 + 273.15 
                    and pressure >= 1e3 * 1e5
                ;
                // WARNING: very high epsilon. We basically only check that the
                // orders of magnitude match.
                CHECK(z_iapws == Approx { data.Z }.scale (fabs (data.Z)).epsilon (1e-0));
                CHECK(q_iapws == Approx { data.Q }.scale (fabs (data.Q)).epsilon (1e-0));
                CHECK(y_iapws == Approx { data.Y }.scale (fabs (data.Y)).epsilon (1e-0));
                CHECK(x_iapws == Approx { data.X }.scale (fabs (data.X)).epsilon (1e-0));
                CHECK(z_uemat == Approx { data.Z });
                // CHECK(q_uemat == Approx { e.Q });
                // CHECK(y_uemat == Approx { e.Y });
                // CHECK(x_uemat == Approx { e.X });
                o
                    << pressure_in_bar
                    << ' ' << dielectric_constant_iapws
                    << ' ' << z_iapws
                    << ' ' << q_iapws
                    << ' ' << y_iapws
                    << ' ' << x_iapws
                ;
                if (is_sverjensky_valid)
                {
                    CHECK(z_sverj == Approx { data.Z }.scale (fabs (data.Z)).epsilon (1e-0));
                    CHECK(q_sverj == Approx { data.Q }.scale (fabs (data.Q)).epsilon (1e-0));
                    CHECK(y_sverj == Approx { data.Y }.scale (fabs (data.Y)).epsilon (1e-0));
                    CHECK(x_sverj == Approx { data.X }.scale (fabs (data.X)).epsilon (1e-0));
                    o
                        << ' ' << dielectric_constant_sverj
                        << ' ' << z_sverj
                        << ' ' << q_sverj
                        << ' ' << y_sverj
                        << ' ' << x_sverj
                    ;
                }
                o << '\n';
            }
            o << "\n";
        }
    } // SUBCASE ("Comparison with SUPCRT92")
}

// vim: foldmethod=marker
