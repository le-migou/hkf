#include <doctest/doctest.h>
    using doctest::Approx;
#include "../include/calculisto/hkf/dielectric_constant_uematsu_1980.hpp"
#include <calculisto/finite_difference/finite_difference.hpp>
    using calculisto::finite_difference::central_finite_difference;


    using namespace calculisto::thermodynamics::dielectric_constant::uematsu_1980;

TEST_CASE("dielectric_constant_uematsu_1980")
{
        const auto
    density = 999.;
        const auto
    temperature = 25 + 273.15;
        const auto
    reduced_density = density / reference_density;
        const auto
    reduced_temperature = temperature / reference_temperature;
    SUBCASE("detail")
    {
            using namespace detail;
        CHECK(d_k_1 (reduced_temperature) == Approx { 
            central_finite_difference (
                  k_1 <double>
                , 1e-6
                , reduced_temperature
            ) 
        });
        CHECK(d_k_2 (reduced_temperature) == Approx { 
            central_finite_difference (
                  k_2 <double>
                , 1e-6
                , reduced_temperature
            ) 
        });
        CHECK(d_k_3 (reduced_temperature) == Approx { 
            central_finite_difference (
                  k_3 <double>
                , 1e-6
                , reduced_temperature
            ) 
        });
        CHECK(d_k_4 (reduced_temperature) == Approx { 
            central_finite_difference (
                  k_4 <double>
                , 1e-6
                , reduced_temperature
            ) 
        });
            using namespace detail;
        CHECK(d2_k_1 (reduced_temperature) == Approx { 
            central_finite_difference (
                  d_k_1 <double>
                , 1e-6
                , reduced_temperature
            ) 
        });
        CHECK(d2_k_2 (reduced_temperature) == Approx { 
            central_finite_difference (
                  d_k_2 <double>
                , 1e-6
                , reduced_temperature
            ) 
        });
        CHECK(d2_k_3 (reduced_temperature) == Approx { 
            central_finite_difference (
                  d_k_3 <double>
                , 1e-6
                , reduced_temperature
            ) 
        });
        CHECK(d2_k_4 (reduced_temperature) == Approx { 
            central_finite_difference (
                  d_k_4 <double>
                , 1e-6
                , reduced_temperature
            ) 
        });
    }
    CHECK(
        d_dielectric_constant_d_density_at_temperature_dt (
              density
            , temperature
        )
        ==
        Approx { central_finite_difference <0> (
            dielectric_constant_dt <double, double>
            , 1e-6
            , density
            , temperature
        ) }
    );
    CHECK(
        d_dielectric_constant_d2_density_at_temperature_dt (
              density
            , temperature
        )
        ==
        Approx { central_finite_difference <0> (
            d_dielectric_constant_d_density_at_temperature_dt <double, double>
            , 1e-6
            , density
            , temperature
        ) }
    );
    CHECK(
        d_dielectric_constant_d_temperature_at_density_dt (
              density
            , temperature
        )
        ==
        Approx { central_finite_difference <1> (
            dielectric_constant_dt <double, double>
            , 1e-6
            , density
            , temperature
        ) }
    );
    CHECK(
        d_dielectric_constant_d2_temperature_at_density_dt (
              density
            , temperature
        )
        ==
        Approx { central_finite_difference <1> (
            d_dielectric_constant_d_temperature_at_density_dt <double, double>
            , 1e-6
            , density
            , temperature
        ) }
    );
}
// vim: foldmethod=marker
