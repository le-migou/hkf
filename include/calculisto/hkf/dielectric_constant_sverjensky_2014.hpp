#pragma once
#include <cmath>
#include <numbers>
    using std::numbers::pi;

#include <fmt/format.h>
    using fmt::println;

#include <calculisto/auto_diff/dual.hpp>
    using calculisto::auto_diff::dual_t;

    namespace
calculisto::thermodynamics
{
    namespace
dielectric_constant
{
    namespace
johnson_1991
{
// https://doi.org/10.2475/ajs.291.6.541
    auto
dielectric_constant_dt (auto const& density, auto const& temperature)
{
        const auto
    T_hat = temperature / 298.15 ;
        const auto
    rho = density * 1e-3;
        const auto
    k0 = 1.;
        const auto
    k1 = 14.70333593 / T_hat;
        const auto
    k2 = 212.8462733 / T_hat - 115.4445173 + 19.55210915 * T_hat;
        const auto
    k3 = -83.3034798 / T_hat + 32.13240048 * T_hat - 6.69409865 * (T_hat * T_hat);
        const auto
    k4 = -37.86202045 / (T_hat * T_hat) + 68.87359646 / T_hat - 27.29401652;
    return k0 + k1 * rho + k2 * (rho * rho) + k3 * pow(rho, 3) + k4 * pow(rho, 4);
}


} // namespace johnsonson_1991
    namespace
franck_1990
{
// https://doi.org/10.1002/bbpc.19900940219
    auto
dielectric_constant_dt (auto const& density, auto const& temperature)
{
        const auto
    k = 1.380649e-16; // [erg/K], Boltzmann constant
        const auto
    sigma = 2.68e-8; // [cm]
         const auto
    rho = density / 1000. / 18.02; // [kg/m3] -> [mol/cm3]
        const auto
    mu = 2.33e-18; // [D (i.e. debye)], 1D = 1e-18 cm^(5/2).g^(1/2)/s
        const auto
    rho_star = rho * pow (sigma, 3) * 6.02214076e23;
    //     const auto
    // mu_star_squared = pow (mu, 2) / k / temperature * pow (sigma, 3);

    // FIXME: The paper says:
    //     const auto
    // y = 4 * pi / 9 * rho_star * mu_star_squared;
    // But this seems to somewhat work...
        const auto
    y = 4 * pi / 9 * rho * pow (mu, 2) / temperature * 6.02214076e23 / k;

        const auto
    a_1 = 0.4341 * pow (rho_star, 2);
        const auto
    a_2 = -(0.05 + 0.75 * pow (rho_star, 3));
        const auto
    a_3 = -0.026 * pow (rho_star, 2) + 0.173 * pow (rho_star, 4);
    return 3. * y / (1. - a_1 * y) * 
    (
        1. + (1 - a_1) * y + a_2 * pow (y, 2) + a_3 * pow (y, 3)
    ) + 1.;
}

// New fit in https://doi.org/10.1016/j.gca.2013.12.019
    auto
dielectric_constant_sverjensky_fit_dt (auto const& density, auto const& temperature)
{
        const auto
    k = 1.380649e-16; // [erg/K]
        const auto
    sigma = 2.34e-8; // [cm]
         const auto
    rho = density / 1000. / 18.02; // [kg/m3] -> [mol/cm3]
        const auto
    mu = 2.39e-18; // [1 D (i.e. debye) = 1e-18 cm^(5/2).g^(1/2)/s]
        const auto
    rho_star = rho * pow (sigma, 3) * 6.02214076e23;
    // Should be mu_star and rho_star...
        const auto
    y = 4. * pi / 9. * pow (mu, 2) * rho / temperature * 6.02214076e23 / k;
        const auto
    a_1 = 0.4341 * pow (rho_star, 2);
        const auto
    a_2 = -(0.05 + 0.75 * pow (rho_star, 3));
        const auto
    a_3 = -0.026 * pow (rho_star, 2) + 0.173 * pow (rho_star, 4);
    return 3. * y / (1. - a_1 * y) * 
    (
        1. + (1 - a_1) * y + a_2 * pow (y, 2) + a_3 * pow (y, 3)
    ) + 1.;
}
} // namespace franck_1990

    namespace
sverjensky_2014
{
    namespace
detail
{
        constexpr auto
    a_1 = -1.576377e-3;
        constexpr auto
    a_2 =  6.810288e-2;
        constexpr auto
    a_3 =  7.548755e-1;
        constexpr auto
    b_1 = -8.016651e-5;
        constexpr auto
    b_2 = -6.871618e-2;
        constexpr auto
    b_3 =  4.747973;
} // namespace detail

// 100°C < T < 1200°C, 0.1 kbar < P < 60 kbar
// From the paper:
// > We emphasize that Eq. (8) is completely empirical and should only be used
// > between 100 and 1200 °C when the pressure is at least 1.0 kb.
    auto 
dielectric_constant_dt (
      auto const& density
    , auto const& temperature
){
        using namespace detail;
        const auto 
    T = temperature - 273.15; // [K] -> [°C]
        const auto 
    D = density / 1e3; // [kg/m3] -> [g/cm3]
        const auto
    A = a_1 * T + a_2 * sqrt (T) + a_3;
        const auto
    B = b_1 * T + b_2 * sqrt (T) + b_3;
    return exp (B) * pow (D, A);
}

    auto
d_dielectric_constant_d_density_at_temperature_dt (
      auto const& density
    , auto const& temperature
){
        using namespace detail;
        const auto 
    T = temperature - 273.15; // [K] -> [°C]
        const auto 
    D = density / 1e3; // [kg/m3] -> [g/cm3]
        const auto
    A = a_1 * T + a_2 * sqrt (T) + a_3;
        const auto
    B = b_1 * T + b_2 * sqrt (T) + b_3;
    return exp (B) * A * pow (D, A - 1) * 1e-3;
}
    auto
d_dielectric_constant_d2_density_at_temperature_dt (
      auto const& density
    , auto const& temperature
){
        using namespace detail;
        const auto 
    T = temperature - 273.15; // [K] -> [°C]
        const auto 
    D = density / 1e3; // [kg/m3] -> [g/cm3]
        const auto
    A = a_1 * T + a_2 * sqrt (T) + a_3;
        const auto
    B = b_1 * T + b_2 * sqrt (T) + b_3;
    return A * (A - 1) * exp (B) * pow (D, A - 2) * 1e-6;
}
    auto
d_dielectric_constant_d_temperature_at_density_dt (
      auto const& density
    , auto const& temperature
){
        using namespace detail;
        const auto 
    T = temperature - 273.15; // [K] -> [°C]
        const auto 
    D = density / 1e3; // [kg/m3] -> [g/cm3]
        const auto
    A = a_1 * T + a_2 * sqrt (T) + a_3;
        const auto
    B = b_1 * T + b_2 * sqrt (T) + b_3;
        const auto
    dA = a_1 + a_2 / 2 / sqrt (T);
        const auto
    dB = b_1 + b_2 / 2 / sqrt (T);
    return exp (B) * pow (D, A) * ( dA * log (D) + dB); 
}
    auto
d_dielectric_constant_d2_temperature_at_density_dt (
      auto const& density
    , auto const& temperature
){
        using namespace detail;
        const auto 
    T = temperature - 273.15; // [K] -> [°C]
        const auto 
    D = density / 1e3; // [kg/m3] -> [g/cm3]
        const auto
    A = a_1 * T + a_2 * sqrt (T) + a_3;
        const auto
    B = b_1 * T + b_2 * sqrt (T) + b_3;
        const auto
    dA = a_1 + a_2 / 2 / sqrt (T);
        const auto
    dB = b_1 + b_2 / 2 / sqrt (T);
        const auto
    d2A = - a_2 / 4 / pow (T, 1.5);
        const auto
    d2B = - b_2 / 4 / pow (T, 1.5);
    return exp (B) * pow (D, A) * (pow (dA * log (D) + dB, 2) + d2A * log (D) + d2B); 
}
    auto
d_dielectric_constant_d_density_temperature_at_temperature_density_dt (
      auto const& density
    , auto const& temperature
){
        using namespace detail;
        const auto 
    T = temperature - 273.15; // [K] -> [°C]
        const auto 
    D = density / 1e3; // [kg/m3] -> [g/cm3]
        const auto
    A = a_1 * T + a_2 * sqrt (T) + a_3;
        const auto
    B = b_1 * T + b_2 * sqrt (T) + b_3;
        const auto
    dA = a_1 + a_2 / 2 / sqrt (T);
        const auto
    dB = b_1 + b_2 / 2 / sqrt (T);
    return exp (B) * pow (D, A) / D * (A * (dA * log (D) + dB) + dA) * 1e-3; 
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
} // namespace sverjensky_2014
} // namespace dielectric_constant
} // namespace calculisto::thermodynamics
