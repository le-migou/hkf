#pragma once
#include "../include/calculisto/hkf/hkf.hpp"
#include "../include/calculisto/hkf/born.hpp"
#include <calculisto/iapws/r6_inverse.hpp>
#include <calculisto/iapws/r8.hpp>
    using namespace calculisto::thermodynamics;

    template <class Number>
    class
iapws_eos_t
    : public hkf::equation_of_state_h2o_t <Number>
{
public:
        hkf::molal_properties_h2o_t <Number>
    compute_properties (Number const& T, Number const& P) const override
    {
            const auto
        D = iapws::r6_inverse::density_pt (P, T);
            const auto
        dDdP = 1 / iapws::r6::d_pressure_d_density_at_temperature_dt (D, T);
            const auto
        dEdD = iapws::r8::d_relative_permittivity_d_density_at_temperature_dt (D, T);
            const auto
        dDdTaP = iapws::r6::d_density_d_temperature_at_pressure_dt (D, T);
            const auto
        dDd2TaP = iapws::r6::d_density_d2_temperature_at_pressure_density_dt (D, T);
            const auto
        dDdTDaPT = iapws::r6::d_density_d_temperature_density_at_pressure_temperature_dt (D, T);
            const auto
        dEdT = iapws::r8::d_relative_permittivity_d_temperature_at_density_dt (D, T);
            const auto
        d2EdT = iapws::r8::d_relative_permittivity_d2_temperature_at_pressure_dt (
              D
            , T
            , dDdTaP
            , dDd2TaP
            , dDdTDaPT
        );
            const auto
        E = iapws::r8::relative_permittivity_dt (D, T);
            const auto
        Q = born::q (E, dDdP, dEdD);
            const auto
        Z = born::z (E);
            const auto
        Y = born::y (E, dEdT, dEdD, dDdTaP);
            const auto
        X = born::x (E, d2EdT, Y);

        // /!\ The followings are molal
            const auto
        V = 1 / D * iapws::molar_mass;
            const auto
        Cp = iapws::r6::massic_isobaric_heat_capacity_dt (D, T) * iapws::molar_mass;;

        //
        // If you want to understand what is going on below, you need to read 
        // the appendix A of the technical report of the software
        //
        //   H2OI95: A Stand-Alone Fortran Code for Evaluating the IAPWS-95 
        //   Equation-of-State Model for Water
        // 
        // by Wolery, Thomas J. (2020), https://doi.org/10.11578/dc.20190408.2
        //
        // Available here:
        //   https://github.com/llnl/H2OI95
        //
            const auto
        S_iapws = iapws::r6::massic_entropy_dt (D, T);
            const auto
        H_iapws = iapws::r6::massic_enthalpy_dt (D, T);
            const auto
        S = (S_iapws + 3.5156150e3) * iapws::molar_mass;
            const auto
        H = (H_iapws - 0.000611782e3 - 15970.89538e3) * iapws::molar_mass;
            const auto
        G = (H_iapws - T * (S_iapws + 3.51562e3) - 12110.528e3) * iapws::molar_mass;
            
        return hkf::molal_properties_h2o_t <double> {
            .volume = V
            , .isobaric_heat_capacity = Cp
            , .entropy = S
            , .enthalpy = H
            , .gibbs_energy = G
            , .density = D
            , .born_q = Q
            , .born_z = Z
            , .born_y = Y
            , .born_x = X
        };
    }
};

    inline const auto
iapws_eos = iapws_eos_t <double> {};

