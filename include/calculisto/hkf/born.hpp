#pragma once
#include <cmath>

    namespace
calculisto::thermodynamics::born
{
    constexpr auto
z (const auto& dielectric_constant) 
{
    return - 1 / dielectric_constant;
}
    constexpr auto
q (
      auto const& dielectric_constant
    , auto const& d_density_d_presure_at_temperature
    , auto const& d_dielectric_constant_d_density_at_temperature
){
    return 
          d_dielectric_constant_d_density_at_temperature
        * d_density_d_presure_at_temperature
        / dielectric_constant
        / dielectric_constant
    ;
}
    constexpr auto
y (
      auto const& dielectric_constant
    , auto const& d_dielectric_constant_d_temperature_at_pressure
){
    return 
          d_dielectric_constant_d_temperature_at_pressure
        / dielectric_constant 
        / dielectric_constant
    ;
}
    constexpr auto
y (
      auto const& dielectric_constant
    , auto const& d_dielectric_constant_d_temperature_at_density
    , auto const& d_dielectric_constant_d_density_at_temperature
    , auto const& d_density_d_temperature_at_pressure
){
    return (
          d_dielectric_constant_d_temperature_at_density
        + d_density_d_temperature_at_pressure
        * d_dielectric_constant_d_density_at_temperature
    ) / dielectric_constant / dielectric_constant;
}
    constexpr auto
x (
      auto const& dielectric_constant
    , auto const& d2_dielectric_constant_d2_temperature_at_pressure
    , auto const& y
){
    return
          d2_dielectric_constant_d2_temperature_at_pressure
        / dielectric_constant
        / dielectric_constant
        - 2
        * dielectric_constant
        * y
        * y
    ;
}
    constexpr auto
x (
      auto const& dielectric_constant
    , auto const& d_dielectric_constant_d2_temperature_at_density
    , auto const& d_dielectric_constant_d_density_temperature_at_temperature_density
    , auto const& d_dielectric_constant_d_density_at_temperature 
    , auto const& d_dielectric_constant_d2_density_at_temperature
    , auto const& d_density_d_temperature_at_pressure
    , auto const& d_density_d2_temperature_at_pressure_density
    , auto const& d_density_d_temperature_density_at_pressure_temperature
    , auto const& y
){
    return 
        (
            d_dielectric_constant_d2_temperature_at_density
            + 2 * d_density_d_temperature_at_pressure * d_dielectric_constant_d_density_temperature_at_temperature_density
            + d_dielectric_constant_d_density_at_temperature * d_density_d2_temperature_at_pressure_density
            + pow (d_density_d_temperature_at_pressure, 2) * d_dielectric_constant_d2_density_at_temperature
            + d_density_d_temperature_at_pressure * d_dielectric_constant_d_density_at_temperature * d_density_d_temperature_density_at_pressure_temperature
        )
        / dielectric_constant
        / dielectric_constant
        - 2
        * dielectric_constant
        * y
        * y
    ;
}
} // namespace calculisto::thermodynamics::born
