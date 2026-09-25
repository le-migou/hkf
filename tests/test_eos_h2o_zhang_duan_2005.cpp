#include <doctest/doctest.h>
    using doctest::Approx;
#include "../include/calculisto/hkf/eos_h2o_zhang_duan_2005.hpp"
#include <vector>
    using namespace calculisto::thermodynamics::eos::water::zhang_2005;
#include <calculisto/finite_difference/finite_difference.hpp>
    using calculisto::finite_difference::central_finite_difference;


    struct
table_6_entry_t
{
        double
      temperature        // K
    , pressure           // MPa
    , molar_volume       // cm3/mol
    , delta_molar_volume // cm3/mol
    ;
};

// https://doi.org/10.1016/j.pepi.2004.11.003
    const auto
table_6 = std::vector <table_6_entry_t> // {{{
{
      {523.15, 5000, 12.08, 0.01 }
    , {773.15, 1500, 16.37, 0.04 }
    , {773.15, 2000, 15.38, 0.03 }
    , {773.15, 2500, 14.72, 0.04 }
    , {773.15, 3000, 14.14, 0.03 }
    , {773.15, 3500, 13.71, 0.03 }
    , {773.15, 4000, 13.33, 0.02 }
    , {773.15, 4500, 13.02, 0.02 }
    , {773.15, 5000, 12.73, 0.01 }
    , {773.15, 5500, 12.5, 0.02 }
    , {773.15, 6000, 12.27, 0.02 }
    , {773.15, 6500, 12.07, 0.02 }
    , {773.15, 7000, 11.88, 0.02 }
    , {873.15, 1500, 17.03, 0.07 }
    , {873.15, 2000, 15.91, 0.03 }
    , {873.15, 2500, 15.11, 0.04 }
    , {873.15, 3000, 14.51, 0.01 }
    , {873.15, 3500, 14.04, 0.03 }
    , {873.15, 4000, 13.63, 0.02 }
    , {873.15, 4500, 13.29, 0.03 }
    , {873.15, 5000, 13, 0.01 }
    , {873.15, 5500, 12.73, 0.03 }
    , {873.15, 6000, 12.51, 0.01 }
    , {873.15, 6500, 12.28, 0.02 }
    , {873.15, 7000, 12.1, 0.01 }
    , {873.15, 7500, 11.91, 0.03 }
    , {873.15, 8000, 11.75, 0.01 }
    , {973.15, 1000, 19.68, 0.08 }
    , {973.15, 1500, 17.67, 0.08 }
    , {973.15, 2000, 16.4, 0.04 }
    , {973.15, 2500, 15.55, 0.05 }
    , {973.15, 3000, 14.89, 0.04 }
    , {973.15, 3500, 14.36, 0.04 }
    , {973.15, 4000, 13.94, 0.02 }
    , {973.15, 4500, 13.56, 0.01 }
    , {973.15, 5000, 13.25, 0.03 }
    , {973.15, 5500, 12.97, 0.02 }
    , {973.15, 6000, 12.71, 0.02 }
    , {973.15, 6500, 12.49, 0.02 }
    , {973.15, 7000, 12.29, 0.02 }
    , {973.15, 7500, 12.11, 0.01 }
    , {973.15, 8000, 11.93, 0.01 }
    , {973.15, 8500, 11.78, 0.02 }
    , {1073.15, 2500, 15.98, 0.04 }
    , {1073.15, 3000, 15.28, 0.03 }
    , {1073.15, 3500, 14.7, 0.04 }
    , {1073.15, 4000, 14.24, 0.03 }
    , {1073.15, 4500, 13.83, 0.03 }
    , {1073.15, 5000, 13.49, 0.02 }
    , {1073.15, 5500, 13.2, 0.03 }
    , {1073.15, 6000, 12.93, 0.01 }
    , {1073.15, 6500, 12.7, 0.02 }
    , {1073.15, 7000, 12.48, 0.02 }
    , {1073.15, 7500, 12.27, 0.01 }
    , {1073.15, 8000, 12.11, 0.01 }
    , {1073.15, 8500, 11.95, 0.02 }
    , {1073.15, 9000, 11.78, 0.02 }
    , {1073.15, 9500, 11.65, 0.02 }
    , {1073.15, 10000, 11.52, 0.01 }
    , {1173.15, 1000, 21.65, 0.14 }
    , {1173.15, 1500, 18.97, 0.08 }
    , {1173.15, 2500, 16.41, 0.07 }
    , {1173.15, 4000, 14.53, 0.04 }
    , {1173.15, 4500, 14.12, 0.02 }
    , {1173.15, 5000, 13.74, 0.02 }
    , {1173.15, 5500, 13.43, 0.02 }
    , {1173.15, 6000, 13.15, 0.02 }
    , {1173.15, 6500, 12.89, 0.02 }
    , {1173.15, 7000, 12.66, 0.02 }
    , {1173.15, 7500, 12.47, 0.02 }
    , {1173.15, 8000, 12.28, 0.02 }
    , {1173.15, 8500, 12.1, 0.01 }
    , {1173.15, 9000, 11.95, 0.02 }
    , {1173.15, 9500, 11.8, 0.02 }
    , {1173.15, 10000, 11.66, 0.01 }
    , {1173.15, 11000, 11.41, 0.02 }
    , {1273.15, 1500, 19.7, 0.1 }
    , {1273.15, 2000, 17.97, 0.03 }
    , {1273.15, 2500, 16.89, 0.05 }
    , {1273.15, 3500, 15.34, 0.03 }
    , {1273.15, 4000, 14.82, 0.04 }
    , {1273.15, 4500, 14.37, 0.03 }
    , {1273.15, 5000, 13.98, 0.01 }
    , {1273.15, 5500, 13.67, 0.02 }
    , {1273.15, 6000, 13.36, 0.03 }
    , {1273.15, 6500, 13.1, 0.02 }
    , {1273.15, 7000, 12.87, 0.03 }
    , {1273.15, 7500, 12.64, 0.02 }
    , {1273.15, 8000, 12.46, 0.02 }
    , {1273.15, 8500, 12.27, 0.02 }
    , {1273.15, 9000, 12.11, 0.02 }
    , {1273.15, 9500, 11.95, 0.02 }
    , {1273.15, 10000, 11.8, 0.01 }
    , {1273.15, 11000, 11.54, 0.01 }
    , {1273.15, 12000, 11.31, 0.01 }
    , {1373.15, 1000, 23.71, 0.16 }
    , {1373.15, 1500, 20.43, 0.1 }
    , {1373.15, 2000, 18.56, 0.08 }
    , {1373.15, 4500, 14.64, 0.04 }
    , {1373.15, 5000, 14.23, 0.03 }
    , {1373.15, 5500, 13.87, 0.02 }
    , {1373.15, 6000, 13.57, 0.02 }
    , {1373.15, 6500, 13.29, 0.02 }
    , {1373.15, 7000, 13.05, 0.01 }
    , {1373.15, 7500, 12.82, 0.02 }
    , {1373.15, 8000, 12.62, 0.02 }
    , {1373.15, 8500, 12.42, 0.02 }
    , {1373.15, 9000, 12.26, 0.02 }
    , {1373.15, 9500, 12.1, 0.01 }
    , {1373.15, 10000, 11.95, 0.01 }
    , {1373.15, 11000, 11.68, 0.02 }
    , {1373.15, 12000, 11.45, 0.01 }
    , {1373.15, 13000, 11.21, 0.01 }
    , {1773.15, 100, 153.69, 3.52 }
    , {1773.15, 200, 81.57, 0.72 }
    , {1773.15, 500, 41.08, 0.23 }
    , {1773.15, 1000, 27.85, 0.16 }
    , {1773.15, 2000, 20.65, 0.05 }
    , {1773.15, 5000, 15.18, 0.02 }
    , {1773.15, 10000, 12.49, 0.01 }
    , {1873.15, 1000, 28.83, 0.15 }
    , {1873.15, 1500, 23.85, 0.14 }
    , {1873.15, 2000, 21.2, 0.07 }
    , {1873.15, 3000, 18.22, 0.07 }
    , {1873.15, 3500, 17.29, 0.06 }
    , {1873.15, 4000, 16.53, 0.05 }
    , {1873.15, 4500, 15.94, 0.03 }
    , {1873.15, 5000, 15.42, 0.03 }
    , {1873.15, 5500, 14.97, 0.04 }
    , {1873.15, 6000, 14.58, 0.05 }
    , {1873.15, 6500, 14.24, 0.03 }
    , {1873.15, 7000, 13.96, 0.03 }
    , {1873.15, 7500, 13.67, 0.02 }
    , {1873.15, 8000, 13.43, 0.03 }
    , {1873.15, 8500, 13.19, 0.02 }
    , {1873.15, 9000, 12.99, 0.03 }
    , {1873.15, 9500, 12.79, 0.02 }
    , {1873.15, 10000, 12.62, 0.02 }
    , {1873.15, 11000, 12.31, 0.01 }
    , {1873.15, 12000, 12.02, 0.01 }
    , {1873.15, 13000, 11.77, 0.02 }
    , {1873.15, 14000, 11.54, 0.01 }
    , {1873.15, 15000, 11.34, 0.02 }
    , {1873.15, 16000, 11.15, 0.01 }
    , {1873.15, 17000, 10.99, 0.01 }
    , {1873.15, 18000, 10.82, 0.01 }
    , {1873.15, 19000, 10.69, 0.01 }
    , {2273.15, 100, 200.45, 4.29 }
    , {2273.15, 200, 107.17, 2.25 }
    , {2273.15, 500, 51.05, 0.68 }
    , {2273.15, 1000, 32.9, 0.27 }
    , {2273.15, 2000, 23.28, 0.12 }
    , {2273.15, 5000, 16.32, 0.03 }
    , {2273.15, 10000, 13.13, 0.02 }
    , {2273.15, 20000, 10.85, 0.01 }
    , {2373.15, 1000, 33.95, 0.33 }
    , {2373.15, 1500, 27.36, 0.16 }
    , {2373.15, 2000, 23.72, 0.16 }
    , {2373.15, 2500, 21.5, 0.09 }
    , {2373.15, 3000, 20.02, 0.14 }
    , {2373.15, 3500, 18.84, 0.06 }
    , {2373.15, 4000, 17.91, 0.06 }
    , {2373.15, 4500, 17.18, 0.05 }
    , {2373.15, 5000, 16.52, 0.05 }
    , {2373.15, 5500, 15.98, 0.06 }
    , {2373.15, 6000, 15.57, 0.06 }
    , {2373.15, 6500, 15.16, 0.04 }
    , {2373.15, 7000, 14.77, 0.03 }
    , {2373.15, 7500, 14.47, 0.03 }
    , {2373.15, 8000, 14.19, 0.03 }
    , {2373.15, 8500, 13.9, 0.03 }
    , {2373.15, 9000, 13.68, 0.02 }
    , {2373.15, 9500, 13.46, 0.03 }
    , {2373.15, 10000, 13.26, 0.02 }
    , {2373.15, 11000, 12.9, 0.02 }
    , {2373.15, 12000, 12.57, 0.02 }
    , {2373.15, 13000, 12.29, 0.01 }
    , {2373.15, 14000, 12.03, 0.02 }
    , {2373.15, 15000, 11.81, 0.01 }
    , {2373.15, 16000, 11.6, 0.02 }
    , {2373.15, 17000, 11.41, 0.01 }
    , {2373.15, 18000, 11.22, 0.01 }
    , {2373.15, 19000, 11.07, 0.01 }
    , {2373.15, 20000, 10.92, 0.01 }
    , {2873.15, 1000, 38.68, 0.44 }
    , {2873.15, 1500, 30.46, 0.21 }
    , {2873.15, 2000, 26.22, 0.19 }
    , {2873.15, 2500, 23.6, 0.21 }
    , {2873.15, 3000, 21.69, 0.13 }
    , {2873.15, 3500, 20.3, 0.11 }
    , {2873.15, 4000, 19.19, 0.08 }
    , {2873.15, 4500, 18.35, 0.05 }
    , {2873.15, 5000, 17.66, 0.05 }
    , {2873.15, 5500, 17.02, 0.07 }
    , {2873.15, 6000, 16.46, 0.05 }
    , {2873.15, 6500, 16, 0.04 }
    , {2873.15, 7000, 15.62, 0.04 }
    , {2873.15, 7500, 15.23, 0.05 }
    , {2873.15, 8000, 14.9, 0.05 }
    , {2873.15, 8500, 14.62, 0.04 }
    , {2873.15, 9000, 14.35, 0.04 }
    , {2873.15, 9500, 14.09, 0.04 }
    , {2873.15, 10000, 13.87, 0.03 }
    , {2873.15, 11000, 13.45, 0.03 }
    , {2873.15, 12000, 13.1, 0.02 }
    , {2873.15, 13000, 12.78, 0.03 }
    , {2873.15, 14000, 12.5, 0.01 }
    , {2873.15, 15000, 12.23, 0.01 }
    , {2873.15, 16000, 12.02, 0.01 }
    , {2873.15, 17000, 11.81, 0.01 }
    , {2873.15, 18000, 11.6, 0.03 }
    , {2873.15, 19000, 11.43, 0.02 }
    , {2873.15, 20000, 11.27, 0.01 }
    , {3273.15, 200, 153.27, 2.09 }
    , {3273.15, 500, 70.02, 0.8 }
    , {3273.15, 1000, 42.23, 0.32 }
    , {3273.15, 2000, 28.08, 0.17 }
    , {3273.15, 5000, 18.46, 0.04 }
    , {3273.15, 10000, 14.3, 0.02 }
    , {3273.15, 20000, 11.52, 0.01 }
    , {3373.15, 1000, 43.31, 0.42 }
    , {3373.15, 1500, 33.62, 0.2 }
    , {3373.15, 2000, 28.68, 0.23 }
    , {3373.15, 2500, 25.54, 0.18 }
    , {3373.15, 3000, 23.21, 0.12 }
    , {3373.15, 3500, 21.74, 0.2 }
    , {3373.15, 4000, 20.46, 0.15 }
    , {3373.15, 4500, 19.48, 0.04 }
    , {3373.15, 5000, 18.71, 0.11 }
    , {3373.15, 5500, 17.95, 0.1 }
    , {3373.15, 6000, 17.38, 0.06 }
    , {3373.15, 6500, 16.8, 0.08 }
    , {3373.15, 7000, 16.37, 0.06 }
    , {3373.15, 7500, 15.96, 0.04 }
    , {3373.15, 8000, 15.61, 0.03 }
    , {3373.15, 8500, 15.28, 0.03 }
    , {3373.15, 9000, 14.99, 0.03 }
    , {3373.15, 9500, 14.69, 0.03 }
    , {3373.15, 10000, 14.43, 0.04 }
    , {3373.15, 11000, 13.99, 0.04 }
    , {3373.15, 12000, 13.57, 0.04 }
    , {3373.15, 13000, 13.23, 0.02 }
    , {3373.15, 14000, 12.93, 0.02 }
    , {3373.15, 15000, 12.65, 0.02 }
    , {3373.15, 16000, 12.41, 0.02 }
    , {3373.15, 17000, 12.18, 0.02 }
    , {3373.15, 18000, 11.96, 0.02 }
    , {3373.15, 19000, 11.79, 0.02 }
    , {3373.15, 20000, 11.6, 0.01 }
    , {4273.15, 100, 372.84, 6.59 }
    , {4273.15, 200, 194.09, 2.79 }
    , {4273.15, 500, 86.55, 1.37 }
    , {4273.15, 1000, 51.14, 0.54 }
    , {4273.15, 2000, 32.56, 0.22 }
    , {4273.15, 5000, 20.41, 0.06 }
    , {4273.15, 10000, 15.39, 0.02 }
    , {4273.15, 20000, 12.15, 0.01 }
    , {4273.15, 50000, 9.28, 0.01 }
}; // }}}

TEST_CASE("zhang_duan_2005")
{
        using namespace calculisto::thermodynamics::eos::water::zhang_2005::detail;
    for (const auto [temperature, pressure, molar_volume, delta_V]: table_6)
    {
            const auto
        reduced_molar_volume = molar_volume / critical_molar_volume;
            const auto
        density_is_g_per_cm3 = molar_mass / molar_volume;
            const auto
        expected_density = density_is_g_per_cm3 * 1e3;
            const auto
        reduced_density = density_is_g_per_cm3 / critical_density;
            const auto
        pressure_in_bar = pressure * 1e6 / 1e5;
            const auto
        reduced_temperature = critical_temperature / temperature;
        INFO("T= ", temperature, " K, P= ", pressure, " MPa, expected D= ", expected_density, " kg/m3");
        CHECK(
            d_z_d_tr_vr_tr ( reduced_molar_volume, reduced_temperature)
            == Approx { central_finite_difference <1> (
                z_vr_tr <double, double>
                , 1e-6
                , reduced_molar_volume
                , reduced_temperature
            ) }
        );
        CHECK(
            d_z_d_vr_vr_tr ( reduced_molar_volume, reduced_temperature)
            == Approx { central_finite_difference <0> (
                z_vr_tr <double, double>
                , 1e-6
                , reduced_molar_volume
                , reduced_temperature
            ) }
        );
        CHECK(
            d_z_d_tr_dr_tr ( reduced_density, reduced_temperature)
            == Approx { central_finite_difference <1> (
                z_dr_tr <double, double>
                , 1e-6
                , reduced_density
                , reduced_temperature
            ) }
        );
        CHECK(
            d_z_d_dr_dr_tr ( reduced_density, reduced_temperature)
            == Approx { central_finite_difference <0> (
                z_dr_tr <double, double>
                , 1e-6
                , reduced_density
                , reduced_temperature
            ) }
        );
        CHECK(
            d_z_d2_tr_dr_tr ( reduced_density, reduced_temperature)
            == Approx { central_finite_difference <1> (
                d_z_d_tr_dr_tr <double, double>
                , 1e-6
                , reduced_density
                , reduced_temperature
            ) }
        );
        CHECK(
            d_z_d_dr_tr_dr_tr ( reduced_density, reduced_temperature)
            == Approx { central_finite_difference <1> (
                d_z_d_dr_dr_tr <double, double>
                , 1e-6
                , reduced_density
                , reduced_temperature
            ) }
        );
        CHECK(
            d_z_d2_dr_dr_tr ( reduced_density, reduced_temperature)
            == Approx { central_finite_difference <0> (
                d_z_d_dr_dr_tr <double, double>
                , 1e-6
                , reduced_density
                , reduced_temperature
            ) }
        );
        CHECK(
            d_F_molar_volume_d_tr_vr_tr (reduced_molar_volume, reduced_temperature)
            == Approx { central_finite_difference (
                [=](auto Tr)
                {
                    return F_molar_volume_vr_tr_p (
                        reduced_molar_volume
                        , Tr
                        , pressure_in_bar
                    );
                }
                , 1e-6
                , reduced_temperature

            ) }
        );
        CHECK(
            d_F_molar_volume_d_vr_vr_tr (reduced_molar_volume, reduced_temperature)
            == Approx { central_finite_difference (
                [=](auto Vr)
                {
                    return F_molar_volume_vr_tr_p (
                        Vr
                        , reduced_temperature
                        , pressure_in_bar
                    );
                }
                , 1e-6
                , reduced_molar_volume
            ) }
        );
        CHECK(
            d_F_density_d_tr_dr_tr (reduced_density, reduced_temperature)
            == Approx { central_finite_difference (
                [=](auto Tr)
                {
                    return F_density_dr_tr_p (
                        reduced_density
                        , Tr
                        , pressure_in_bar
                    );
                }
                , 1e-6
                , reduced_temperature
            ) }
        );
        CHECK(
            d_F_density_d_dr_dr_tr (reduced_density, reduced_temperature)
            == Approx { central_finite_difference (
                [=](auto Dr)
                {
                    return F_density_dr_tr_p (
                        Dr
                        , reduced_temperature
                        , pressure_in_bar
                    );
                }
                , 1e-6
                , reduced_density
            ) }
        );
        CHECK(
            d_F_density_d2_tr_dr_tr (reduced_density, reduced_temperature)
            == Approx { central_finite_difference <1> (
                d_F_density_d_tr_dr_tr <double, double>
                , 1e-6
                , reduced_density
                , reduced_temperature
            ) }
        );
        CHECK(
            d_F_density_d_dr_tr_dr_tr (reduced_density, reduced_temperature)
            == Approx { central_finite_difference <1> (
                d_F_density_d_dr_dr_tr <double, double>
                , 1e-6
                , reduced_density
                , reduced_temperature
            ) }
        );
        CHECK(
            d_F_density_d2_dr_dr_tr (reduced_density, reduced_temperature)
            == Approx { central_finite_difference <0> (
                d_F_density_d_dr_dr_tr <double, double>
                , 1e-6
                , reduced_density
                , reduced_temperature
            ) }
        );
        /*
        Regarding the low epsilon here, a quote form the paper: 

        > Compared with the simulated data listed in Table 6, the calculated 
        > volumes from our EOS show remarkable accuracy with an average 
        > relative error of 0.27% and maximum error of 1.75%.

        */
        {
                const auto
            [density, info] = density_pt (
                  pressure * 1e6 // S.I.
                , temperature
                , 1800.
                , info::convergence
            );
            CHECK(info.converged == true);
            CHECK(info.function_threw == false);
            CHECK(info.derivative_threw == false);
            CHECK(info.zero_derivative == false);
            CHECK(
                density 
                == 
                Approx { expected_density }
                    .scale (expected_density)
                    .epsilon (1e-2) // WARNING: low
            );
        }
            const auto
        density = density_pt (
                pressure * 1e6 // S.I.
            , temperature
        );
        CHECK(
            density 
            == 
            Approx { expected_density }
                .scale (expected_density)
                .epsilon (1e-2) // WARNING: low
        );
        CHECK(
            d_density_d_pressure_at_temperature_dt (density, temperature)
            == Approx { central_finite_difference (
                [=](auto P)
                {
                    return density_pt (P, temperature);
                }
                , 1e-6
                , pressure * 1e6
            ) }
        );
        CHECK(
            d_density_d_temperature_at_pressure_dt (density, temperature)
            == Approx { central_finite_difference (
                [=](auto T)
                {
                    return density_pt (pressure * 1e6, T);
                }
                , 1e-6
                , temperature
            ) }
        );
        CHECK(
            d_density_d2_temperature_at_pressure_density_dt (density, temperature)
            == Approx { central_finite_difference <1> (
                d_density_d_temperature_at_pressure_dt <double, double>
                , 1e-6
                , density
                , temperature
            ) }
        );
        CHECK(
            d_density_d_temperature_density_at_pressure_temperature_dt (density, temperature)
            == Approx { central_finite_difference <0> (
                d_density_d_temperature_at_pressure_dt <double, double>
                , 1e-6
                , density
                , temperature
            ) }
        );
    }
}
// vim: foldmethod=marker
