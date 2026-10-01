#pragma once
#include <cmath>

// https://doi.org/10.2475/ajs.291.6.541
// James W. Johnson, Denis Norton, 1991
// https://doi.org/10.1063/1.555632
// M. Uematsu; E. U. Franck, 1980

    namespace
calculisto::thermodynamics::dielectric_constant::uematsu_1980
{
    constexpr auto 
reference_temperature = 273.15 + 25.; // K
    constexpr auto
reference_density = 1000.; // kg/m3

    namespace
detail
{
        constexpr auto
    k_0 (const auto& /*reduced_temperature*/)
    {
        return 1.;
    }
        constexpr auto
    k_1 (const auto& reduced_temperature)
    {
        return 0.1470333593e2 / reduced_temperature;
    }
        constexpr auto
    k_2 (const auto& reduced_temperature)
    {
        return 
              0.2128462733e3 / reduced_temperature
            - 0.1154445173e3
            + 0.1955210925e2 * reduced_temperature
        ;
    }
        constexpr auto
    k_3 (const auto& reduced_temperature)
    {
        return 
            - 0.8330347980e2 / reduced_temperature
            + 0.3213240048e2 * reduced_temperature
            - 0.6694098645e1 * pow (reduced_temperature, 2)
        ;
    }
        constexpr auto
    k_4 (const auto& reduced_temperature)
    {
        return 
            - 0.3786202045e2 * pow (reduced_temperature, -2)
            + 0.6887359646e2 / reduced_temperature
            - 0.2729401652e2
        ;
    }
        constexpr auto
    d_k_1 (const auto& reduced_temperature)
    {
        return - 0.1470333593e2 * pow (reduced_temperature, -2);
    }
        constexpr auto
    d_k_2 (const auto& reduced_temperature)
    {
        return
            - 0.2128462733e3 * pow (reduced_temperature, -2)
            + 0.1955210925e2
        ;
    }
        constexpr auto
    d_k_3 (const auto& reduced_temperature)
    {
        return
              0.8330347980e2 * pow (reduced_temperature, -2)
            + 0.3213240048e2
            - 2 * 0.6694098645e1 * reduced_temperature
        ;
    }
        constexpr auto
    d_k_4 (const auto& reduced_temperature)
    {
        return
            + 2 * 0.3786202045e2 * pow (reduced_temperature, -3)
            - 0.6887359646e2 * pow (reduced_temperature, -2)
        ;
    }
        constexpr auto
    d2_k_1 (const auto& reduced_temperature)
    {
        return 2 * 0.1470333593e2 * pow (reduced_temperature, -3);
    }
        constexpr auto
    d2_k_2 (const auto& reduced_temperature)
    {
        return + 2 * 0.2128462733e3 * pow (reduced_temperature, -3);
    }
        constexpr auto
    d2_k_3 (const auto& reduced_temperature)
    {
        return
            - 2 * 0.8330347980e2 * pow (reduced_temperature, -3)
            - 2 * 0.6694098645e1
        ;
    }
        constexpr auto
    d2_k_4 (const auto& reduced_temperature)
    {
        return
            - 6 * 0.3786202045e2 * pow (reduced_temperature, -4)
            + 2 * 0.6887359646e2 * pow (reduced_temperature, -3)
        ;
    }
} // namespace detail                        

    constexpr auto
dielectric_constant_dt (const auto& density, const auto& temperature)
{
        using namespace detail;
        const auto
    reduced_temperature = temperature / reference_temperature;
        const auto
    reduced_density = density / reference_density;
    return
          k_0 (reduced_temperature)
        + k_1 (reduced_temperature) * reduced_density
        + k_2 (reduced_temperature) * pow (reduced_density, 2)
        + k_3 (reduced_temperature) * pow (reduced_density, 3)
        + k_4 (reduced_temperature) * pow (reduced_density, 4)
    ;
}
    auto
d_dielectric_constant_d_density_at_temperature_dt (
      auto const& density
    , auto const& temperature
){
        using namespace detail;
        const auto
    reduced_temperature = temperature / reference_temperature;
        const auto
    reduced_density = density / reference_density;
    return (
        + k_1 (reduced_temperature)
        + 2 * k_2 (reduced_temperature) * reduced_density
        + 3 * k_3 (reduced_temperature) * pow (reduced_density, 2)
        + 4 * k_4 (reduced_temperature) * pow (reduced_density, 3)
    ) / reference_density;
}
    auto
d_dielectric_constant_d2_density_at_temperature_dt (
      auto const& density
    , auto const& temperature
){
        using namespace detail;
        const auto
    reduced_temperature = temperature / reference_temperature;
        const auto
    reduced_density = density / reference_density;
    return (
          2  * k_2 (reduced_temperature)
        + 6  * k_3 (reduced_temperature) * reduced_density
        + 12 * k_4 (reduced_temperature) * pow (reduced_density, 2)
    ) / pow (reference_density, 2);
}
    auto
d_dielectric_constant_d_temperature_at_density_dt (
      auto const& density
    , auto const& temperature
){
        using namespace detail;
        const auto
    reduced_temperature = temperature / reference_temperature;
        const auto
    reduced_density = density / reference_density;
    return (
        + d_k_1 (reduced_temperature) * reduced_density
        + d_k_2 (reduced_temperature) * pow (reduced_density, 2)
        + d_k_3 (reduced_temperature) * pow (reduced_density, 3)
        + d_k_4 (reduced_temperature) * pow (reduced_density, 4)
    ) / reference_temperature;
}
    auto
d_dielectric_constant_d2_temperature_at_density_dt (
      auto const& density
    , auto const& temperature
){
        using namespace detail;
        const auto
    reduced_temperature = temperature / reference_temperature;
        const auto
    reduced_density = density / reference_density;
    return (
        + d2_k_1 (reduced_temperature) * reduced_density
        + d2_k_2 (reduced_temperature) * pow (reduced_density, 2)
        + d2_k_3 (reduced_temperature) * pow (reduced_density, 3)
        + d2_k_4 (reduced_temperature) * pow (reduced_density, 4)
    ) / pow (reference_temperature, 2);
}
    auto
d_dielectric_constant_d_density_temperature_at_temperature_density_dt (
      auto const& density
    , auto const& temperature
){
        using namespace detail;
        const auto
    reduced_temperature = temperature / reference_temperature;
        const auto
    reduced_density = density / reference_density;
    return (
        + d_k_1 (reduced_temperature)
        + 2 * d_k_2 (reduced_temperature) * reduced_density
        + 3 * d_k_3 (reduced_temperature) * pow (reduced_density, 2)
        + 4 * d_k_4 (reduced_temperature) * pow (reduced_density, 3)
    ) / reference_temperature / reference_density;
}
    auto
d_dielectric_constant_d_pressure_at_temperature_dt (
      auto const& density
    , auto const& temperature
    , auto const& d_density_d_pressure_at_temperature
){
    return 
          d_density_d_pressure_at_temperature 
        * d_dielectric_constant_d_density_at_temperature_dt (density, temperature);
}

    auto
d_dielectric_constant_d_temperature_at_pressure_dt (
      const auto& density
    , const auto& temperature
    , const auto& d_density_d_temperature_at_pressure
){
    return 
          d_dielectric_constant_d_temperature_at_density_dt (density, temperature)
        + d_dielectric_constant_d_density_at_temperature_dt (density, temperature)
        * d_density_d_temperature_at_pressure
    ;
}
    auto
d_dielectric_constant_d2_temperature_at_pressure_dt (
      auto const& density
    , auto const& temperature
    , auto const& d_density_d_temperature_at_pressure
    , auto const& d_density_d2_temperature_at_pressure_density
    , auto const& d_density_d_temperature_density_at_pressure_temperature
){
    return
          d_dielectric_constant_d2_temperature_at_density_dt (density, temperature)
        + 2 * d_density_d_temperature_at_pressure * d_dielectric_constant_d_density_temperature_at_temperature_density_dt (density, temperature)
        + d_dielectric_constant_d_density_at_temperature_dt (density, temperature) * d_density_d2_temperature_at_pressure_density
        + pow (d_density_d_temperature_at_pressure, 2) * d_dielectric_constant_d2_density_at_temperature_dt (density, temperature)
        + d_density_d_temperature_at_pressure * d_dielectric_constant_d_density_at_temperature_dt (density, temperature) * d_density_d_temperature_density_at_pressure_temperature
    ;
}
} // namespace calculisto::thermodynamics::dielectric_constant::uematsu_1980
