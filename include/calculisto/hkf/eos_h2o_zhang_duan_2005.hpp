#pragma once
#include <calculisto/root_finding/root_finding.hpp>
    using namespace calculisto::root_finding;

// https://doi.org/10.1016/j.pepi.2004.11.003
    namespace
calculisto::thermodynamics::eos::water::zhang_2005
{
    constexpr auto
critical_temperature = 647.25; // K
    constexpr auto
critical_molar_volume = 55.9480373; // cm3/mol
    constexpr auto
molar_gas_constant = 83.14467; // cm3.bar/K/mol
    constexpr auto
molar_mass = 18.01528; // g/mol
    constexpr auto
critical_density = molar_mass / critical_molar_volume; // g/cm3

    namespace
detail 
{
        constexpr auto
    a_1 = 3.49824207e-01;
        constexpr auto
    a_2 = -2.91046273e+00;
        constexpr auto
    a_3 = 2.00914688e+00;
        constexpr auto
    a_4 = 1.12819964e-01;
        constexpr auto
    a_5 = 7.48997714e-01;
        constexpr auto
    a_6 = -8.73207040e-01;
        constexpr auto
    a_7 = 1.70609505e-02;
        constexpr auto
    a_8 = -1.46355822e-02;
        constexpr auto
    a_9 = 5.79768283e-02;
        constexpr auto
    a_10 = -8.41246372e-04;
        constexpr auto
    a_11 = 4.95186474e-03;
        constexpr auto
    a_12 = -9.16248538e-03;
        constexpr auto
    a_13 = -1.00358152e-01;
        constexpr auto
    a_14 = -1.82674744e-03;
        constexpr auto
    gamma = 1.05999998e-02;

    auto
z_vr_tr (
      auto const& Vr // reduced_molar_volume
    , auto const& Tr // reduced_temperature
){
        using namespace detail;
        const auto
    B = a_1 + a_2 * pow (Tr, 2) + a_3 * pow (Tr, 3);
        const auto
    C = a_4 + a_5 * pow (Tr, 2) + a_6 * pow (Tr, 3);
        const auto
    D = a_7 + a_8 * pow (Tr, 2) + a_9 * pow (Tr, 3);
        const auto
    E = a_10 + a_11 * pow (Tr, 2) + a_12 * pow (Tr, 3);
        const auto
    F = a_13 * Tr;
        const auto
    G = a_14 / Tr;
    return
        1.
        + B / Vr
        + C / pow (Vr, 2)
        + D / pow (Vr, 4)
        + E / pow (Vr, 5)
        + (
              F / pow (Vr, 2)
            + G / pow (Vr, 4)
          )
        * exp (-gamma / pow (Vr, 2))
    ;
}
    auto
d_z_d_vr_vr_tr (
      auto const& Vr // reduced_molar_volume
    , auto const& Tr // reduced_temperature
){
        using namespace detail;
        const auto
    B = a_1 + a_2 * pow (Tr, 2) + a_3 * pow (Tr, 3);
        const auto
    C = a_4 + a_5 * pow (Tr, 2) + a_6 * pow (Tr, 3);
        const auto
    D = a_7 + a_8 * pow (Tr, 2) + a_9 * pow (Tr, 3);
        const auto
    E = a_10 + a_11 * pow (Tr, 2) + a_12 * pow (Tr, 3);
        const auto
    F = a_13 * Tr;
        const auto
    G = a_14 / Tr;
        const auto
    r = 
        - B / pow (Vr, 2)
        - 2 * C / pow (Vr, 3)
        - 4 * D / pow (Vr, 5)
        - 5 * E / pow (Vr, 6)
        - 2 * (
              F / pow (Vr, 3) * (1 - gamma / pow (Vr, 2))
            + G / pow (Vr, 5) * (2 - gamma / pow (Vr, 2))
          )
        * exp (-gamma / pow (Vr, 2))
    ;
    return r;
}

    auto
d_z_d_tr_vr_tr (
      auto const& Vr // reduced_molar_volume
    , auto const& Tr // reduced_temperature
){
        using namespace detail;
        const auto
    dB = 2 * a_2 * Tr + 3 * a_3 * pow (Tr, 2);
        const auto
    dC = 2 * a_5 * Tr + 3 * a_6 * pow (Tr, 2);
        const auto
    dD = 2 * a_8 * Tr + 3 * a_9 * pow (Tr, 2);
        const auto
    dE = 2 * a_11 * Tr + 3 * a_12 * pow (Tr, 2);
        const auto
    dF = a_13;
        const auto
    dG = - a_14 / pow (Tr, 2);
    return
          dB / Vr
        + dC / pow (Vr, 2)
        + dD / pow (Vr, 4)
        + dE / pow (Vr, 5)
        + (
              dF / pow (Vr, 2)
            + dG / pow (Vr, 4)
          )
        * exp (-gamma / pow (Vr, 2))
    ;
}

    auto
z_dr_tr (
      auto const& Dr // reduced_density
    , auto const& Tr // reduced_temperature
){
        using namespace detail;
        const auto
    B = a_1 + a_2 * pow (Tr, 2) + a_3 * pow (Tr, 3);
        const auto
    C = a_4 + a_5 * pow (Tr, 2) + a_6 * pow (Tr, 3);
        const auto
    D = a_7 + a_8 * pow (Tr, 2) + a_9 * pow (Tr, 3);
        const auto
    E = a_10 + a_11 * pow (Tr, 2) + a_12 * pow (Tr, 3);
        const auto
    F = a_13 * Tr;
        const auto
    G = a_14 / Tr;
    return
        1.
        + B * Dr
        + C * pow (Dr, 2)
        + D * pow (Dr, 4)
        + E * pow (Dr, 5)
        + (
              F * pow (Dr, 2)
            + G * pow (Dr, 4)
          )
        * exp (-gamma * pow (Dr, 2))
    ;
}
    auto
d_z_d_tr_dr_tr (
      auto const& Dr // reduced_density
    , auto const& Tr // reduced_temperature
){
        using namespace detail;
        const auto
    dB = 2 * a_2 * Tr + 3 * a_3 * pow (Tr, 2);
        const auto
    dC = 2 * a_5 * Tr + 3 * a_6 * pow (Tr, 2);
        const auto
    dD = 2 * a_8 * Tr + 3 * a_9 * pow (Tr, 2);
        const auto
    dE = 2 * a_11 * Tr + 3 * a_12 * pow (Tr, 2);
        const auto
    dF = a_13;
        const auto
    dG = - a_14 / pow (Tr, 2);
    return
          dB * Dr
        + dC * pow (Dr, 2)
        + dD * pow (Dr, 4)
        + dE * pow (Dr, 5)
        + pow (Dr, 2) * (
              dF
            + dG * pow (Dr, 2)
          )
        * exp (-gamma * pow (Dr, 2))
    ;
}
    auto
d_z_d_dr_dr_tr (
      auto const& Dr // reduced_density
    , auto const& Tr // reduced_temperature
){
        using namespace detail;
        const auto
    B = a_1 + a_2 * pow (Tr, 2) + a_3 * pow (Tr, 3);
        const auto
    C = a_4 + a_5 * pow (Tr, 2) + a_6 * pow (Tr, 3);
        const auto
    D = a_7 + a_8 * pow (Tr, 2) + a_9 * pow (Tr, 3);
        const auto
    E = a_10 + a_11 * pow (Tr, 2) + a_12 * pow (Tr, 3);
        const auto
    F = a_13 * Tr;
        const auto
    G = a_14 / Tr;
        const auto
    r =
          B
        + 2 * C * Dr
        + 4 * D * pow (Dr, 3)
        + 5 * E * pow (Dr, 4)
        + (
              2 * F * Dr * (1 - gamma * pow (Dr, 2))
            + 2 * G * pow (Dr, 3) * (2 - gamma * pow (Dr, 2))
          )
        * exp (-gamma * pow (Dr, 2))
    ;
    return r;
}
    auto
d_z_d2_tr_dr_tr (
      auto const& Dr // reduced_density
    , auto const& Tr // reduced_temperature
){
        using namespace detail;
        const auto
    d2B = 2 * a_2 + 6 * a_3 * Tr;
        const auto
    d2C = 2 * a_5 + 6 * a_6 * Tr;
        const auto
    d2D = 2 * a_8 + 6 * a_9 * Tr;
        const auto
    d2E = 2 * a_11 + 6 * a_12 * Tr;
        const auto
    d2F = 0.;
        const auto
    d2G = 2 * a_14 / pow (Tr, 3);
    return
          d2B * Dr
        + d2C * pow (Dr, 2)
        + d2D * pow (Dr, 4)
        + d2E * pow (Dr, 5)
        + pow (Dr, 2) * (
              d2F
            + d2G * pow (Dr, 2)
          )
        * exp (-gamma * pow (Dr, 2))
    ;
}
    auto
d_z_d_dr_tr_dr_tr (
      auto const& Dr // reduced_density
    , auto const& Tr // reduced_temperature
){
        using namespace detail;
        const auto
    dB = 2 * a_2 * Tr + 3 * a_3 * pow (Tr, 2);
        const auto
    dC = 2 * a_5 * Tr + 3 * a_6 * pow (Tr, 2);
        const auto
    dD = 2 * a_8 * Tr + 3 * a_9 * pow (Tr, 2);
        const auto
    dE = 2 * a_11 * Tr + 3 * a_12 * pow (Tr, 2);
        const auto
    dF = a_13;
        const auto
    dG = - a_14 / pow (Tr, 2);
        const auto
    r =
          dB
        + 2 * dC * Dr
        + 4 * dD * pow (Dr, 3)
        + 5 * dE * pow (Dr, 4)
        + (
              2 * dF * Dr * (1 - gamma * pow (Dr, 2))
            + 2 * dG * pow (Dr, 3) * (2 - gamma * pow (Dr, 2))
          )
        * exp (-gamma * pow (Dr, 2))
    ;
    return r;
}
    auto
d_z_d2_dr_dr_tr (
      auto const& Dr // reduced_density
    , auto const& Tr // reduced_temperature
){
        using namespace detail;
        const auto
    C = a_4 + a_5 * pow (Tr, 2) + a_6 * pow (Tr, 3);
        const auto
    D = a_7 + a_8 * pow (Tr, 2) + a_9 * pow (Tr, 3);
        const auto
    E = a_10 + a_11 * pow (Tr, 2) + a_12 * pow (Tr, 3);
        const auto
    F = a_13 * Tr;
        const auto
    G = a_14 / Tr;
        const auto
    r =
          2 * C
        + 12 * D * pow (Dr, 2)
        + 20 * E * pow (Dr, 3)
        + (
              2 * F
            + (12 * G - 10 * gamma * F) * pow (Dr, 2)
            + (4 * pow (gamma, 2) * F - 18 * gamma * G) * pow (Dr, 4)
            + 4 * pow (gamma, 2) * G * pow (Dr, 6)
          )
        * exp (-gamma * pow (Dr, 2))
    ;
    return r;
}
} // namespace detail

    namespace
detail
{
    auto
F_molar_volume_vr_tr_p (
      auto const& reduced_molar_volume
    , auto const& reduced_temperature
    , auto const& pressure_in_bar
){
    return 
          z_vr_tr (reduced_molar_volume, reduced_temperature)
        * molar_gas_constant 
        * critical_temperature 
        / reduced_temperature
        / reduced_molar_volume
        / critical_molar_volume
        - pressure_in_bar
    ;
}
    auto
d_F_molar_volume_d_tr_vr_tr (
      auto const& reduced_molar_volume
    , auto const& reduced_temperature
){
    return 
          molar_gas_constant
        * critical_temperature
        / reduced_temperature
        / critical_molar_volume
        / reduced_molar_volume
        * (
              d_z_d_tr_vr_tr (reduced_molar_volume, reduced_temperature)
            - z_vr_tr (reduced_molar_volume, reduced_temperature)
            / reduced_temperature
        )
    ;
}
    auto
d_F_molar_volume_d_vr_vr_tr (
      auto const& reduced_molar_volume
    , auto const& reduced_temperature
){
    return 
          molar_gas_constant
        * critical_temperature
        / reduced_temperature
        / critical_molar_volume
        / reduced_molar_volume
        * (
              d_z_d_vr_vr_tr (reduced_molar_volume, reduced_temperature)
            - z_vr_tr (reduced_molar_volume, reduced_temperature)
            / reduced_molar_volume
          )
    ;
}
} // namespace detail

    constexpr auto
initial_molar_volume_pt (
      [[maybe_unused]] auto const& pressure
    , [[maybe_unused]] auto const& temperature
){
    // This value has been tuned so that we pass the Sverjensky, 2014 tests.
    return 10. * 1e-6;
}

    template <info_tag_t InfoTag = info::tag::none>
    constexpr auto
molar_volume_pt (
      auto const& pressure
    , auto const& temperature
    , auto const& molar_volume_initial_guess
    , info_t <InfoTag> info = info::none
){
        const auto
    pressure_in_bar = pressure / 1e5;
        const auto
    reduced_temperature = critical_temperature / temperature;
        auto
    r = newton (
          [=](auto reduced_molar_volume)
          { 
            return detail::F_molar_volume_vr_tr_p (
                  reduced_molar_volume
                , reduced_temperature
                , pressure_in_bar
            )
            ;
          }
        , [=](auto reduced_molar_volume)
          {
            return detail::d_F_molar_volume_d_vr_vr_tr (
                  reduced_molar_volume
                , reduced_temperature
            )
            ;
          }
        , molar_volume_initial_guess * 1e6 / critical_molar_volume
          // options:
        , { 
            .converged = [](auto curr, auto prev, auto f)
            { 
                return fabs (f) < 1e-8 || fabs ((curr - prev)/curr) < 1e-8; 
            } 
          }
        , info
    );
    if constexpr (InfoTag == info::tag::none)
    {
        r *= critical_molar_volume * 1e-6; // Back to S.I.
    }
    else
    {
        r.first *= critical_molar_volume * 1e-6;
    }
    return r;
}

    template <info_tag_t InfoTag>
    constexpr auto
molar_volume_pt (
      auto const& pressure
    , auto const& temperature
    , info_t <InfoTag> info
){
    return molar_volume_pt (
          pressure
        , temperature
        , initial_molar_volume_pt (pressure, temperature)
        , info
    );
}
    constexpr auto
molar_volume_pt (
      auto const& pressure
    , auto const& temperature
){
    return molar_volume_pt (
          pressure
        , temperature
        , initial_molar_volume_pt (pressure, temperature)
        , info::none
    );
}

    namespace
detail
{
    auto
F_density_dr_tr_p (
      auto const& reduced_density
    , auto const& reduced_temperature
    , auto const& pressure_in_bar
){
    return 
          z_dr_tr (reduced_density, reduced_temperature)
        * molar_gas_constant 
        * critical_temperature
        / reduced_temperature 
        * reduced_density
        * critical_density
        - pressure_in_bar
        * molar_mass
    ;
}
    auto
d_F_density_d_tr_dr_tr (
      auto const& reduced_density
    , auto const& reduced_temperature
){
    return 
          molar_gas_constant
        * reduced_density 
        * critical_density
        * critical_temperature
        / reduced_temperature
        * (
              d_z_d_tr_dr_tr (reduced_density, reduced_temperature)
            - z_dr_tr (reduced_density, reduced_temperature)
            / reduced_temperature
          )
    ;
}
    auto
d_F_density_d_dr_dr_tr (
      auto const& reduced_density
    , auto const& reduced_temperature
){
    return 
          molar_gas_constant
        * critical_temperature
        / reduced_temperature
        * critical_density
        * (
              z_dr_tr (reduced_density, reduced_temperature)
            + reduced_density * d_z_d_dr_dr_tr (reduced_density, reduced_temperature)
        )
    ;
}
    auto
d_F_density_d2_tr_dr_tr (
      auto const& reduced_density
    , auto const& reduced_temperature
){
    return
        molar_gas_constant
        * reduced_density
        * critical_density
        * critical_temperature
        / reduced_temperature
        * (
            d_z_d2_tr_dr_tr (reduced_density, reduced_temperature)
            -
            2 / reduced_temperature * (
                  d_z_d_tr_dr_tr (reduced_density, reduced_temperature)
                - z_dr_tr (reduced_density, reduced_temperature)
                    / reduced_temperature
            )
        )
    ;
}
    auto
d_F_density_d_dr_tr_dr_tr (
      auto const& reduced_density
    , auto const& reduced_temperature
){
    return 
          molar_gas_constant
        * critical_density
        * critical_temperature
        / reduced_temperature
        * (
            - z_dr_tr (reduced_density, reduced_temperature) 
                / reduced_temperature
            + d_z_d_tr_dr_tr (reduced_density, reduced_temperature) 
            + reduced_density
                * d_z_d_dr_tr_dr_tr (reduced_density, reduced_temperature) 
            - reduced_density
                / reduced_temperature
                * d_z_d_dr_dr_tr (reduced_density, reduced_temperature) 
        )
    ;
}
    auto
d_F_density_d2_dr_dr_tr (
      auto const& reduced_density
    , auto const& reduced_temperature
){
    return 
          molar_gas_constant
        * critical_density
        * critical_temperature
        / reduced_temperature
        * (
            2 * d_z_d_dr_dr_tr (reduced_density, reduced_temperature) 
            + reduced_density * d_z_d2_dr_dr_tr (reduced_density, reduced_temperature) 
        )
    ;
}
} // namespace detail

    template <info_tag_t InfoTag = info::tag::none>
    constexpr auto
density_pt (
      auto const& pressure
    , auto const& temperature
    , auto const& density_initial_guess
    , info_t <InfoTag> info = info::none
){
        const auto
    pressure_in_bar = pressure * 1e-5;
        const auto
    reduced_temperature = critical_temperature / temperature;
        const auto
    reduced_density_initial_guess = density_initial_guess * 1e-3 / critical_density;
        auto
    r = newton (
          [=](auto reduced_density)
          { 
            return detail::F_density_dr_tr_p (
                  reduced_density
                , reduced_temperature
                , pressure_in_bar
            );
          }
        , [=](auto reduced_density)
          {
            return detail::d_F_density_d_dr_dr_tr(
                  reduced_density
                , reduced_temperature
            );
          }
        , reduced_density_initial_guess
          // options:
        , { 
            .converged = [](auto curr, auto prev, auto f)
            { 
                return fabs (f) < 1e-8 || fabs ((curr - prev)/curr) < 1e-8; 
            } 
          }
        , info
    );
    if constexpr (InfoTag == info::tag::none)
    {
        r *= critical_density * 1e3; // Back to S.I.
    }
    else
    {
        r.first *= critical_density * 1e3;
    }
    return r;
}
    constexpr auto
inital_density_pt (
      const auto& pressure [[maybe_unused]]
    , const auto& temperature [[maybe_unused]]
){
    return static_cast <decltype (pressure)> (1800.);
}
    template <info_tag_t InfoTag>
    constexpr auto
density_pt (
      auto const& pressure
    , auto const& temperature
    , info_t <InfoTag> info
){
    return density_pt (
          pressure
        , temperature
        , inital_density_pt (pressure, temperature)
        , info
    );
}
    constexpr auto
density_pt (
      auto const& pressure
    , auto const& temperature
){
    return density_pt (
          pressure
        , temperature
        , info::none
    );
}
// These require an inversion. We don't need them at the moment
/*
    template <info_tag_t InfoTag = info::tag::none>
    constexpr auto
d_density_d_temperature_at_pressure_pt (
      auto const& pressure
    , auto const& temperature
    , auto const& density_initial_guess
    , info_t <InfoTag> info = info::none
){
        auto const
    density = density_pt (pressure, temperature, density_initial_guess, info);
        auto const
    reduced_density = density * 1e-3 / critical_density;
        const auto
    reduced_temperature = critical_temperature / temperature;
    return 
          critical_temperature / temperature / temperature
        * critical_density * 1e3
        * detail::d_F_density_d_tr_dr_tr (
              reduced_density
            , reduced_temperature
          ) 
        / detail::d_F_density_d_dr_dr_tr (
              reduced_density
            , reduced_temperature
        )
    ;
}
    constexpr auto
d_density_d_temperature_at_pressure_pt (
      auto const& pressure
    , auto const& temperature
){
    return d_density_d_temperature_at_pressure_pt (
          pressure
        , temperature
        , inital_density_pt (pressure, temperature)
        , info::none
    );
}
    template <info_tag_t InfoTag = info::tag::none>
    constexpr auto
d_density_d_pressure_at_temperature_pt (
      auto const& pressure
    , auto const& temperature
    , auto const& density_initial_guess
    , info_t <InfoTag> info = info::none
){
        auto const
    density = density_pt (pressure, temperature, density_initial_guess, info);
        auto const
    reduced_density = density * 1e-3 / critical_density;
        const auto
    reduced_temperature = critical_temperature / temperature;
    // return 
    //       critical_density
    //     * molar_mass
    //     / detail::d_F_density_d_dr_dr_tr (
    //           reduced_density
    //         , reduced_temperature
    //     ) * 1e-2 // g/cm3/bar -> S.I.
    // ;
    // OR
    return 1. / (
        molar_gas_constant * temperature / molar_mass * (
              reduced_density * detail::d_z_d_dr_dr_tr (reduced_density, reduced_temperature)
            + detail::z_dr_tr (reduced_density, reduced_temperature)
        )
    ) * 1e-2; // g/cm3/bar -> S.I.
}
    constexpr auto
d_density_d_pressure_at_temperature_pt (
      auto const& pressure
    , auto const& temperature
){
    return d_density_d_pressure_at_temperature_pt (
          pressure
        , temperature
        , inital_density_pt (pressure, temperature)
        , info::none
    );
}
*/
    auto
d_density_d_pressure_at_temperature_dt (
      auto const& density
    , auto const& temperature
){
        auto const
    reduced_density = density * 1e-3 / critical_density;
        const auto
    reduced_temperature = critical_temperature / temperature;
    return 
          critical_density
        * molar_mass
        / detail::d_F_density_d_dr_dr_tr (
              reduced_density
            , reduced_temperature
        ) * 1e-2 // g/cm3/bar -> S.I.
    ;
}
    auto
d_density_d_temperature_at_pressure_dt (
      auto const& density
    , auto const& temperature
){
        auto const
    reduced_density = density * 1e-3 / critical_density;
        const auto
    reduced_temperature = critical_temperature / temperature;
        const auto
    N = detail::d_F_density_d_tr_dr_tr (reduced_density, reduced_temperature);
        const auto
    D = detail::d_F_density_d_dr_dr_tr (reduced_density, reduced_temperature);
        const auto
    d_dr_d_tr = - N / D;
    return 
        - reduced_temperature 
        * critical_density
        / temperature
        * d_dr_d_tr
        * 1e3 // g/cm3/K -> S.I.
    ;
}
    auto
d_density_d2_temperature_at_pressure_density_dt (
      auto const& density
    , auto const& temperature
){
        auto const
    reduced_density = density * 1e-3 / critical_density;
        const auto
    reduced_temperature = critical_temperature / temperature;
        const auto
    N = detail::d_F_density_d_tr_dr_tr (reduced_density, reduced_temperature);
        const auto
    D = detail::d_F_density_d_dr_dr_tr (reduced_density, reduced_temperature);
        const auto
    dN = detail::d_F_density_d2_tr_dr_tr (reduced_density, reduced_temperature);
        const auto
    dD = detail::d_F_density_d_dr_tr_dr_tr (reduced_density, reduced_temperature);
        const auto
    d_dr_d_tr = - N / D;
        const auto
    d_dr_d2_tr = - (dN * D - N * dD) / D / D;
    return
          reduced_temperature
        * critical_density
        / pow (temperature, 2)
        * (
            2 * d_dr_d_tr + reduced_temperature * d_dr_d2_tr
        ) * 1e3
    ;
}
    auto
d_density_d_temperature_density_at_pressure_temperature_dt (
      auto const& density
    , auto const& temperature
){
        auto const
    reduced_density = density * 1e-3 / critical_density;
        const auto
    reduced_temperature = critical_temperature / temperature;
        const auto
    N = detail::d_F_density_d_tr_dr_tr (reduced_density, reduced_temperature);
        const auto
    D = detail::d_F_density_d_dr_dr_tr (reduced_density, reduced_temperature);
        const auto
    dN = detail::d_F_density_d_dr_tr_dr_tr (reduced_density, reduced_temperature);
        const auto
    dD = detail::d_F_density_d2_dr_dr_tr (reduced_density, reduced_temperature);
        const auto
    d_dr_d_dr_tr =  - (dN * D - N * dD) / D / D;
    return - reduced_temperature / temperature * d_dr_d_dr_tr;
}

    auto
pressure_dt (auto const& density, auto const& temperature)
{
        auto const
    reduced_density = density * 1e-3 / critical_density;
        const auto
    reduced_temperature = critical_temperature / temperature;
    return 
          detail::z_dr_tr (reduced_density, reduced_temperature) 
        * molar_gas_constant
        * temperature
        * density * 1e-3
        / molar_mass
        * 1e5
    ;
}
} // namespace calculisto::thermodynamics::eos::water::zhang_2005
