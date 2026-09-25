#include <doctest/doctest.h>
    using doctest::Approx;
#include "../include/calculisto/hkf/dielectric_constant_sverjensky_2014.hpp"
#include "../include/calculisto/hkf/eos_h2o_zhang_duan_2005.hpp"
#include <vector>
#include <calculisto/finite_difference/finite_difference.hpp>
    using calculisto::finite_difference::central_finite_difference;

//  https://doi.org/10.1002/bbpc.19900940219
//  (Franck et al., 1990)
    struct
table_2_entry_t
{
        double
      temperature         // °C
    , density             // g/cm3
    , dielectric_constant //
    ;
        
};
    const auto
table_2 = std::vector <table_2_entry_t> // {{{
{
      { 400., 0.10, 2.04 }
    , { 400., 0.20, 3.51 }
    , { 400., 0.30, 5.41 }
    , { 400., 0.40, 7.73 }
    , { 400., 0.50, 10.45 }
    , { 400., 0.60, 13.5 }
    , { 400., 0.70, 16.9 }
    , { 400., 0.80, 20.5 }
    , { 400., 0.90, 24.3 }
    , { 400., 1.00, 29.4 }
    , { 500., 0.10, 1.88 }
    , { 500., 0.20, 3.09 }
    , { 500., 0.30, 4.63 }
    , { 500., 0.40, 6.48 }
    , { 500., 0.50, 8.65 }
    , { 500., 0.60, 11.1 }
    , { 500., 0.70, 13.8 }
    , { 500., 0.80, 16.66 }
    , { 500., 0.90, 19.6 }
    , { 500., 1.00, 22.5 }
    , { 600., 0.10, 1.76 }
    , { 600., 0.20, 2.79 }
    , { 600., 0.30, 4.06 }
    , { 600., 0.40, 5.59 }
    , { 600., 0.50, 7.37 }
    , { 600., 0.60, 9.39 }
    , { 600., 0.70, 11.6 }
    , { 600., 0.80, 13.96 }
    , { 600., 0.90, 16.37 }
    , { 600., 1.00, 18.7 }
    , { 800., 0.10, 1.60 }
    , { 800., 0.20, 2.38 }
    , { 800., 0.30, 3.32 }
    , { 800., 0.40, 4.03 }
    , { 800., 0.50, 5.15 }
    , { 800., 0.60, 6.4 }
    , { 800., 0.70, 7.77 }
    , { 800., 0.80, 9.26 }
    , { 800., 0.90, 10.8 }
    , { 800., 1.00, 12.36 }
    , { 1000., 0.10, 1.50 }
    , { 1000., 0.20, 2.11 }
    , { 1000., 0.30, 2.85 }
    , { 1000., 0.40, 3.71 }
    , { 1000., 0.50, 4.69 }
    , { 1000., 0.60, 5.79 }
    , { 1000., 0.70, 7.0 }
    , { 1000., 0.80, 8.3 }
    , { 1000., 0.90, 9.67 }
    , { 1000., 1.00, 11.06 }
}; // }}}

// https://doi.org/10.1016/j.gca.2013.12.019, Supplementary material
// (Sverjensky et al., 2014)
    struct
table_2a_entry_t
{
        double
      temperature // °C
    , pressure    // kbar
    , density     // g/cm3
    ;
};
    const auto 
table_2a = std::vector <table_2a_entry_t> // {{{
{
      { 100, 1, 0.998 }
    , { 150, 1, 0.963 }
    , { 200, 1, 0.922 }
    , { 250, 1, 0.875 }
    , { 300, 1, 0.823 }
    , { 350, 1, 0.763 }
    , { 400, 1, 0.696 }
    , { 450, 1, 0.619 }
    , { 500, 1, 0.530 }
    , { 550, 1, 0.439 }
    , { 600, 1, 0.365 }
    , { 650, 1, 0.313 }
    , { 700, 1, 0.277 }
    , { 750, 1, 0.250 }
    , { 800, 1, 0.229 }
    , { 850, 1, 0.212 }
    , { 900, 1, 0.198 }
    , { 100, 2, 1.032 }
    , { 150, 2, 1.001 }
    , { 200, 2, 0.965 }
    , { 250, 2, 0.926 }
    , { 300, 2, 0.883 }
    , { 350, 2, 0.839 }
    , { 400, 2, 0.791 }
    , { 450, 2, 0.742 }
    , { 500, 2, 0.692 }
    , { 550, 2, 0.641 }
    , { 600, 2, 0.591 }
    , { 650, 2, 0.544 }
    , { 700, 2, 0.500 }
    , { 750, 2, 0.462 }
    , { 800, 2, 0.428 }
    , { 850, 2, 0.399 }
    , { 900, 2, 0.373 }
    , { 950, 2, 0.351 }
    , { 1000, 2, 0.332 }
    , { 1050, 2, 0.315 }
    , { 1100, 2, 0.300 }
    , { 1150, 2, 0.286 }
    , { 1200, 2, 0.274 }
    , { 100, 3, 1.061 }
    , { 150, 3, 1.031 }
    , { 200, 3, 0.999 }
    , { 250, 3, 0.964 }
    , { 300, 3, 0.928 }
    , { 350, 3, 0.889 }
    , { 400, 3, 0.850 }
    , { 450, 3, 0.810 }
    , { 500, 3, 0.769 }
    , { 550, 3, 0.729 }
    , { 600, 3, 0.690 }
    , { 650, 3, 0.652 }
    , { 700, 3, 0.615 }
    , { 750, 3, 0.581 }
    , { 800, 3, 0.549 }
    , { 850, 3, 0.520 }
    , { 900, 3, 0.493 }
    , { 950, 3, 0.469 }
    , { 1000, 3, 0.447 }
    , { 1050, 3, 0.427 }
    , { 1100, 3, 0.409 }
    , { 1150, 3, 0.392 }
    , { 1200, 3, 0.377 }
    , { 100, 4, 1.086 }
    , { 150, 4, 1.058 }
    , { 200, 4, 1.028 }
    , { 250, 4, 0.996 }
    , { 300, 4, 0.963 }
    , { 350, 4, 0.929 }
    , { 400, 4, 0.894 }
    , { 450, 4, 0.859 }
    , { 500, 4, 0.824 }
    , { 550, 4, 0.789 }
    , { 600, 4, 0.755 }
    , { 650, 4, 0.722 }
    , { 700, 4, 0.690 }
    , { 750, 4, 0.659 }
    , { 800, 4, 0.630 }
    , { 850, 4, 0.603 }
    , { 900, 4, 0.578 }
    , { 950, 4, 0.554 }
    , { 1000, 4, 0.532 }
    , { 1050, 4, 0.512 }
    , { 1100, 4, 0.493 }
    , { 1150, 4, 0.475 }
    , { 1200, 4, 0.459 }
    , { 100, 5, 1.108 }
    , { 150, 5, 1.082 }
    , { 200, 5, 1.053 }
    , { 250, 5, 1.024 }
    , { 300, 5, 0.993 }
    , { 350, 5, 0.962 }
    , { 400, 5, 0.930 }
    , { 450, 5, 0.898 }
    , { 500, 5, 0.867 }
    , { 550, 5, 0.835 }
    , { 600, 5, 0.804 }
    , { 650, 5, 0.774 }
    , { 700, 5, 0.745 }
    , { 750, 5, 0.718 }
    , { 800, 5, 0.691 }
    , { 850, 5, 0.666 }
    , { 900, 5, 0.642 }
    , { 950, 5, 0.619 }
    , { 1000, 5, 0.598 }
    , { 1050, 5, 0.578 }
    , { 1100, 5, 0.559 }
    , { 1150, 5, 0.541 }
    , { 1200, 5, 0.524 }
    , { 100, 10, 1.197 }
    , { 150, 10, 1.173 }
    , { 200, 10, 1.150 }
    , { 250, 10, 1.126 }
    , { 300, 10, 1.103 }
    , { 350, 10, 1.079 }
    , { 400, 10, 1.055 }
    , { 450, 10, 1.031 }
    , { 500, 10, 1.007 }
    , { 550, 10, 0.984 }
    , { 600, 10, 0.961 }
    , { 650, 10, 0.938 }
    , { 700, 10, 0.916 }
    , { 750, 10, 0.895 }
    , { 800, 10, 0.874 }
    , { 850, 10, 0.854 }
    , { 900, 10, 0.835 }
    , { 950, 10, 0.816 }
    , { 1000, 10, 0.798 }
    , { 1050, 10, 0.781 }
    , { 1100, 10, 0.764 }
    , { 1150, 10, 0.748 }
    , { 1200, 10, 0.733 }
    , { 100, 15, 1.264 }
    , { 150, 15, 1.242 }
    , { 200, 15, 1.220 }
    , { 250, 15, 1.200 }
    , { 300, 15, 1.179 }
    , { 350, 15, 1.158 }
    , { 400, 15, 1.138 }
    , { 450, 15, 1.117 }
    , { 500, 15, 1.097 }
    , { 550, 15, 1.077 }
    , { 600, 15, 1.057 }
    , { 650, 15, 1.038 }
    , { 700, 15, 1.019 }
    , { 750, 15, 1.001 }
    , { 800, 15, 0.983 }
    , { 850, 15, 0.965 }
    , { 900, 15, 0.948 }
    , { 950, 15, 0.932 }
    , { 1000, 15, 0.916 }
    , { 1050, 15, 0.900 }
    , { 1100, 15, 0.885 }
    , { 1150, 15, 0.871 }
    , { 1200, 15, 0.857 }
    , { 100, 20, 1.321 }
    , { 150, 20, 1.298 }
    , { 200, 20, 1.278 }
    , { 250, 20, 1.258 }
    , { 300, 20, 1.239 }
    , { 350, 20, 1.221 }
    , { 400, 20, 1.202 }
    , { 450, 20, 1.184 }
    , { 500, 20, 1.165 }
    , { 550, 20, 1.147 }
    , { 600, 20, 1.130 }
    , { 650, 20, 1.112 }
    , { 700, 20, 1.095 }
    , { 750, 20, 1.078 }
    , { 800, 20, 1.062 }
    , { 850, 20, 1.046 }
    , { 900, 20, 1.031 }
    , { 950, 20, 1.015 }
    , { 1000, 20, 1.001 }
    , { 1050, 20, 0.986 }
    , { 1100, 20, 0.972 }
    , { 1150, 20, 0.959 }
    , { 1200, 20, 0.946 }
    , { 100, 25, 1.371 }
    , { 150, 25, 1.347 }
    , { 200, 25, 1.327 }
    , { 250, 25, 1.308 }
    , { 300, 25, 1.290 }
    , { 350, 25, 1.273 }
    , { 400, 25, 1.255 }
    , { 450, 25, 1.238 }
    , { 500, 25, 1.222 }
    , { 550, 25, 1.205 }
    , { 600, 25, 1.188 }
    , { 650, 25, 1.172 }
    , { 700, 25, 1.156 }
    , { 750, 25, 1.141 }
    , { 800, 25, 1.125 }
    , { 850, 25, 1.111 }
    , { 900, 25, 1.096 }
    , { 950, 25, 1.082 }
    , { 1000, 25, 1.068 }
    , { 1050, 25, 1.054 }
    , { 1100, 25, 1.041 }
    , { 1150, 25, 1.028 }
    , { 1200, 25, 1.016 }
    , { 100, 30, 1.417 }
    , { 150, 30, 1.391 }
    , { 200, 30, 1.370 }
    , { 250, 30, 1.352 }
    , { 300, 30, 1.334 }
    , { 350, 30, 1.318 }
    , { 400, 30, 1.301 }
    , { 450, 30, 1.285 }
    , { 500, 30, 1.269 }
    , { 550, 30, 1.254 }
    , { 600, 30, 1.238 }
    , { 650, 30, 1.223 }
    , { 700, 30, 1.208 }
    , { 750, 30, 1.193 }
    , { 800, 30, 1.179 }
    , { 850, 30, 1.165 }
    , { 900, 30, 1.151 }
    , { 950, 30, 1.137 }
    , { 1000, 30, 1.124 }
    , { 1050, 30, 1.111 }
    , { 1100, 30, 1.099 }
    , { 1150, 30, 1.086 }
    , { 1200, 30, 1.074 }
    , { 100, 40, 1.500 }
    , { 150, 40, 1.468 }
    , { 200, 40, 1.445 }
    , { 250, 40, 1.427 }
    , { 300, 40, 1.410 }
    , { 350, 40, 1.394 }
    , { 400, 40, 1.379 }
    , { 450, 40, 1.364 }
    , { 500, 40, 1.349 }
    , { 550, 40, 1.335 }
    , { 600, 40, 1.320 }
    , { 650, 40, 1.306 }
    , { 700, 40, 1.292 }
    , { 750, 40, 1.279 }
    , { 800, 40, 1.266 }
    , { 850, 40, 1.252 }
    , { 900, 40, 1.240 }
    , { 950, 40, 1.227 }
    , { 1000, 40, 1.215 }
    , { 1050, 40, 1.203 }
    , { 1100, 40, 1.191 }
    , { 1150, 40, 1.180 }
    , { 1200, 40, 1.168 }
    , { 100, 50, 1.578 }
    , { 150, 50, 1.536 }
    , { 200, 50, 1.510 }
    , { 250, 50, 1.490 }
    , { 300, 50, 1.473 }
    , { 350, 50, 1.458 }
    , { 400, 50, 1.443 }
    , { 450, 50, 1.429 }
    , { 500, 50, 1.415 }
    , { 550, 50, 1.401 }
    , { 600, 50, 1.388 }
    , { 650, 50, 1.374 }
    , { 700, 50, 1.361 }
    , { 750, 50, 1.348 }
    , { 800, 50, 1.336 }
    , { 850, 50, 1.323 }
    , { 900, 50, 1.311 }
    , { 950, 50, 1.299 }
    , { 1000, 50, 1.288 }
    , { 1050, 50, 1.276 }
    , { 1100, 50, 1.265 }
    , { 1150, 50, 1.254 }
    , { 1200, 50, 1.244 }
    , { 100, 60, 1.656 }
    , { 150, 60, 1.599 }
    , { 200, 60, 1.568 }
    , { 250, 60, 1.547 }
    , { 300, 60, 1.529 }
    , { 350, 60, 1.513 }
    , { 400, 60, 1.499 }
    , { 450, 60, 1.485 }
    , { 500, 60, 1.471 }
    , { 550, 60, 1.458 }
    , { 600, 60, 1.445 }
    , { 650, 60, 1.432 }
    , { 700, 60, 1.420 }
    , { 750, 60, 1.407 }
    , { 800, 60, 1.395 }
    , { 850, 60, 1.383 }
    , { 900, 60, 1.372 }
    , { 950, 60, 1.360 }
    , { 1000, 60, 1.349 }
    , { 1050, 60, 1.338 }
    , { 1100, 60, 1.327 }
    , { 1150, 60, 1.317 }
    , { 1200, 60, 1.306 }
}; // }}}

    struct
table_2b_entry_t
{
        double
      temperature         // °C
    , pressure            // kbar
    , dielectric_constant //
    ;
};
    const auto 
table_2b = std::vector <table_2b_entry_t> // {{{
{
      { 100., 1., 57.44 }
    , { 150., 1., 46.69 }
    , { 200., 1., 38.32 }
    , { 250., 1., 31.49 }
    , { 300., 1., 25.75 }
    , { 350., 1., 20.81 }
    , { 400., 1., 16.50 }
    , { 450., 1., 12.67 }
    , { 500., 1., 9.27 }
    , { 550., 1., 6.49 }
    , { 600., 1., 4.60 }
    , { 650., 1., 3.46 }
    , { 700., 1., 2.74 }
    , { 100., 2., 59.96 }
    , { 150., 2., 49.16 }
    , { 200., 2., 40.85 }
    , { 250., 2., 34.14 }
    , { 300., 2., 28.58 }
    , { 350., 2., 23.91 }
    , { 400., 2., 19.96 }
    , { 450., 2., 16.61 }
    , { 500., 2., 13.76 }
    , { 550., 2., 11.37 }
    , { 600., 2., 9.39 }
    , { 650., 2., 7.77 }
    , { 700., 2., 6.47 }
    , { 750., 2., 5.45 }
    , { 800., 2., 4.64 }
    , { 850., 2., 4.01 }
    , { 900., 2., 3.51 }
    , { 100., 3., 62.08 }
    , { 150., 3., 51.23 }
    , { 200., 3., 42.90 }
    , { 250., 3., 36.21 }
    , { 300., 3., 30.69 }
    , { 350., 3., 26.08 }
    , { 400., 3., 22.20 }
    , { 450., 3., 18.91 }
    , { 500., 3., 16.13 }
    , { 550., 3., 13.78 }
    , { 600., 3., 11.80 }
    , { 650., 3., 10.13 }
    , { 700., 3., 8.74 }
    , { 750., 3., 7.58 }
    , { 800., 3., 6.62 }
    , { 850., 3., 5.82 }
    , { 900., 3., 5.16 }
    , { 950., 3., 4.61 }
    , { 1000., 3., 4.15 }
    , { 1050., 3., 3.77 }
    , { 1100., 3., 3.44 }
    , { 100., 4., 63.95 }
    , { 150., 4., 53.02 }
    , { 200., 4., 44.65 }
    , { 250., 4., 37.94 }
    , { 300., 4., 32.42 }
    , { 350., 4., 27.82 }
    , { 400., 4., 23.93 }
    , { 450., 4., 20.65 }
    , { 500., 4., 17.86 }
    , { 550., 4., 15.49 }
    , { 600., 4., 13.48 }
    , { 650., 4., 11.77 }
    , { 700., 4., 10.32 }
    , { 750., 4., 9.09 }
    , { 800., 4., 8.05 }
    , { 850., 4., 7.16 }
    , { 900., 4., 6.41 }
    , { 950., 4., 5.77 }
    , { 1000., 4., 5.23 }
    , { 1050., 4., 4.77 }
    , { 1100., 4., 4.37 }
    , { 1150., 4., 4.03 }
    , { 1200., 4., 3.74 }
    , { 100., 5., 65.64 }
    , { 150., 5., 54.62 }
    , { 200., 5., 46.21 }
    , { 250., 5., 39.46 }
    , { 300., 5., 33.92 }
    , { 350., 5., 29.29 }
    , { 400., 5., 25.39 }
    , { 450., 5., 22.08 }
    , { 500., 5., 19.26 }
    , { 550., 5., 16.86 }
    , { 600., 5., 14.81 }
    , { 650., 5., 13.05 }
    , { 700., 5., 11.55 }
    , { 750., 5., 10.27 }
    , { 800., 5., 9.17 }
    , { 850., 5., 8.22 }
    , { 900., 5., 7.41 }
    , { 950., 5., 6.71 }
    , { 1000., 5., 6.10 }
    , { 1050., 5., 5.58 }
    , { 1100., 5., 5.13 }
    , { 1150., 5., 4.74 }
    , { 1200., 5., 4.40 }
    , { 100., 10., 72.40 }
    , { 150., 10., 60.97 }
    , { 200., 10., 52.25 }
    , { 250., 10., 45.27 }
    , { 300., 10., 39.51 }
    , { 350., 10., 34.68 }
    , { 400., 10., 30.59 }
    , { 450., 10., 27.10 }
    , { 500., 10., 24.09 }
    , { 550., 10., 21.50 }
    , { 600., 10., 19.25 }
    , { 650., 10., 17.29 }
    , { 700., 10., 15.59 }
    , { 750., 10., 14.10 }
    , { 800., 10., 12.80 }
    , { 850., 10., 11.66 }
    , { 900., 10., 10.65 }
    , { 950., 10., 9.76 }
    , { 1000., 10., 8.98 }
    , { 1050., 10., 8.28 }
    , { 1100., 10., 7.67 }
    , { 1150., 10., 7.12 }
    , { 1200., 10., 6.63 }
    , { 100., 15., 77.67 }
    , { 150., 15., 65.82 }
    , { 200., 15., 56.80 }
    , { 250., 15., 49.55 }
    , { 300., 15., 43.57 }
    , { 350., 15., 38.53 }
    , { 400., 15., 34.24 }
    , { 450., 15., 30.56 }
    , { 500., 15., 27.37 }
    , { 550., 15., 24.60 }
    , { 600., 15., 22.18 }
    , { 650., 15., 20.06 }
    , { 700., 15., 18.20 }
    , { 750., 15., 16.56 }
    , { 800., 15., 15.11 }
    , { 850., 15., 13.83 }
    , { 900., 15., 12.69 }
    , { 950., 15., 11.68 }
    , { 1000., 15., 10.78 }
    , { 1050., 15., 9.97 }
    , { 1100., 15., 9.25 }
    , { 1150., 15., 8.60 }
    , { 1200., 15., 8.02 }
    , { 100., 20., 82.16 }
    , { 150., 20., 69.90 }
    , { 200., 20., 60.57 }
    , { 250., 20., 53.07 }
    , { 300., 20., 46.87 }
    , { 350., 20., 41.63 }
    , { 400., 20., 37.16 }
    , { 450., 20., 33.30 }
    , { 500., 20., 29.95 }
    , { 550., 20., 27.02 }
    , { 600., 20., 24.46 }
    , { 650., 20., 22.20 }
    , { 700., 20., 20.21 }
    , { 750., 20., 18.44 }
    , { 800., 20., 16.88 }
    , { 850., 20., 15.48 }
    , { 900., 20., 14.24 }
    , { 950., 20., 13.13 }
    , { 1000., 20., 12.13 }
    , { 1050., 20., 11.24 }
    , { 1100., 20., 10.43 }
    , { 1150., 20., 9.71 }
    , { 1200., 20., 9.05 }
    , { 100., 25., 86.17 }
    , { 150., 25., 73.48 }
    , { 200., 25., 63.85 }
    , { 250., 25., 56.11 }
    , { 300., 25., 49.70 }
    , { 350., 25., 44.28 }
    , { 400., 25., 39.64 }
    , { 450., 25., 35.62 }
    , { 500., 25., 32.12 }
    , { 550., 25., 29.05 }
    , { 600., 25., 26.35 }
    , { 650., 25., 23.97 }
    , { 700., 25., 21.86 }
    , { 750., 25., 19.99 }
    , { 800., 25., 18.32 }
    , { 850., 25., 16.83 }
    , { 900., 25., 15.50 }
    , { 950., 25., 14.30 }
    , { 1000., 25., 13.23 }
    , { 1050., 25., 12.26 }
    , { 1100., 25., 11.39 }
    , { 1150., 25., 10.60 }
    , { 1200., 25., 9.88 }
    , { 100., 30., 89.87 }
    , { 150., 30., 76.73 }
    , { 200., 30., 66.80 }
    , { 250., 30., 58.83 }
    , { 300., 30., 52.21 }
    , { 350., 30., 46.62 }
    , { 400., 30., 41.81 }
    , { 450., 30., 37.65 }
    , { 500., 30., 34.01 }
    , { 550., 30., 30.82 }
    , { 600., 30., 28.00 }
    , { 650., 30., 25.51 }
    , { 700., 30., 23.29 }
    , { 750., 30., 21.32 }
    , { 800., 30., 19.56 }
    , { 850., 30., 17.99 }
    , { 900., 30., 16.58 }
    , { 950., 30., 15.31 }
    , { 1000., 30., 14.16 }
    , { 1050., 30., 13.13 }
    , { 1100., 30., 12.19 }
    , { 1150., 30., 11.35 }
    , { 1200., 30., 10.58 }
    , { 100., 40., 96.67 }
    , { 150., 40., 82.54 }
    , { 200., 40., 72.00 }
    , { 250., 40., 63.57 }
    , { 300., 40., 56.58 }
    , { 350., 40., 50.65 }
    , { 400., 40., 45.56 }
    , { 450., 40., 41.12 }
    , { 500., 40., 37.24 }
    , { 550., 40., 33.82 }
    , { 600., 40., 30.79 }
    , { 650., 40., 28.10 }
    , { 700., 40., 25.70 }
    , { 750., 40., 23.56 }
    , { 800., 40., 21.64 }
    , { 850., 40., 19.92 }
    , { 900., 40., 18.37 }
    , { 950., 40., 16.97 }
    , { 1000., 40., 15.71 }
    , { 1050., 40., 14.56 }
    , { 1100., 40., 13.52 }
    , { 1150., 40., 12.58 }
    , { 1200., 40., 11.72 }
    , { 100., 50., 103.13 }
    , { 150., 50., 87.77 }
    , { 200., 50., 76.58 }
    , { 250., 50., 67.70 }
    , { 300., 50., 60.35 }
    , { 350., 50., 54.12 }
    , { 400., 50., 48.75 }
    , { 450., 50., 44.07 }
    , { 500., 50., 39.97 }
    , { 550., 50., 36.35 }
    , { 600., 50., 33.13 }
    , { 650., 50., 30.27 }
    , { 700., 50., 27.71 }
    , { 750., 50., 25.42 }
    , { 800., 50., 23.37 }
    , { 850., 50., 21.52 }
    , { 900., 50., 19.85 }
    , { 950., 50., 18.34 }
    , { 1000., 50., 16.97 }
    , { 1050., 50., 15.73 }
    , { 1100., 50., 14.61 }
    , { 1150., 50., 13.59 }
    , { 1200., 50., 12.65 }
    , { 100., 60., 109.66 }
    , { 150., 60., 92.65 }
    , { 200., 60., 80.75 }
    , { 250., 60., 71.41 }
    , { 300., 60., 63.71 }
    , { 350., 60., 57.19 }
    , { 400., 60., 51.57 }
    , { 450., 60., 46.67 }
    , { 500., 60., 42.36 }
    , { 550., 60., 38.56 }
    , { 600., 60., 35.17 }
    , { 650., 60., 32.16 }
    , { 700., 60., 29.46 }
    , { 750., 60., 27.03 }
    , { 800., 60., 24.86 }
    , { 850., 60., 22.89 }
    , { 900., 60., 21.12 }
    , { 950., 60., 19.51 }
    , { 1000., 60., 18.06 }
    , { 1050., 60., 16.74 }
    , { 1100., 60., 15.53 }
    , { 1150., 60., 14.44 }
    , { 1200., 60., 13.44 }
}; // }}}

    using namespace calculisto::thermodynamics::dielectric_constant;
    using namespace calculisto::thermodynamics::eos::water;

TEST_CASE("dielectric_constant_sverjensky_2014")
{
    SUBCASE("density, Zhang and Duan, 2005 vs. Sverjensky, 2014")
    {
            using namespace calculisto::thermodynamics::eos::water::zhang_2005;
        for (const auto& [T, P, D]: table_2a)
        {
                const auto
            temperature = T + 273.15;
                const auto
            pressure = P * 1e8;
                const auto
            expected_molar_volume =  molar_mass / D * 1e-6;
                const auto
            expected_density = D * 1e3;
            INFO(
                "temperature ", temperature
                , " K, pressure ", pressure
                , " Pa, expected molar volume ", expected_molar_volume
                , " m3/mol, expected density = ", expected_density
                , "kg/m3"
            );

                const auto
            molar_volume = molar_volume_pt (pressure, temperature);
            // Epsilon here is low because the Sverjensky, 2014 calculations were
            // made to a precision of two decimals only
            CHECK(molar_volume == doctest::Approx { expected_molar_volume }.scale (expected_molar_volume).epsilon (1e-3));

                const auto
            density = density_pt (pressure, temperature);
            CHECK(density == doctest::Approx { expected_density }.scale (expected_density).epsilon (1e-3));
        }
    }

    SUBCASE("dielectric constant, Franck et al., 1990 vs. Svejensky et al., 2014")
    {
        for (const auto& [T, D, e_expected]: table_2)
        {
                const auto
            temperature = T + 273.15;
                const auto
            density = D * 1000;
                const auto
            e = franck_1990::dielectric_constant_dt (density, temperature);
            INFO("temperature ", temperature, " K, density ", density, " kg/cm3");
            CHECK(e == doctest::Approx { e_expected }.scale (e_expected).epsilon (1e-1));
        }
    }
    SUBCASE("dielectric constant, Franck et al., 1990 (new fit) vs. Svejensky et al., 2014")
    {
        for (const auto& [T, D, e_expected]: table_2)
        {
                const auto
            temperature = T + 273.15;
                const auto
            density = D * 1000;
                const auto
            e = franck_1990::dielectric_constant_sverjensky_fit_dt (density, temperature);
            INFO("temperature ", temperature, " K, density ", density, " kg/cm3");
            CHECK(e == doctest::Approx { e_expected }.scale (e_expected).epsilon (1e-0));
        }
    }
    SUBCASE("dielectric constant, Johnson et al., 1991 vs. Svejensky et al., 2014")
    {
        for (const auto& [T, D, e_expected]: table_2)
        {
                const auto
            temperature = T + 273.15;
                const auto
            density = D * 1000;
                const auto
            e = johnson_1991::dielectric_constant_dt (density, temperature);
            INFO("temperature ", temperature, " K, density ", density, " kg/cm3");
            CHECK(e == doctest::Approx { e_expected }.scale (e_expected).epsilon (1e-0));
        }
    }
    SUBCASE("dielectric constant, Svejensky et al., 2014")
    {
            using namespace calculisto::thermodynamics::eos::water::zhang_2005;
        for (const auto& [T, P, e_expected]: table_2b)
        {
                const auto
            temperature = T + 273.15;
                const auto
            pressure = P * 1e8;
                const auto
            density = density_pt (pressure, temperature);
                const auto
            e = sverjensky_2014::dielectric_constant_dt (density, temperature);
            INFO(
                "pressure ", pressure
                , " Pa, temperature " , temperature
                , " K, density ", density
                , " kg/cm3"
            );
            CHECK(e == doctest::Approx { e_expected }.scale (e_expected).epsilon (1e-3));
        }
    }
    SUBCASE("dielectric constant, derivatives, Svejensky et al., 2014")
    {
            using namespace sverjensky_2014;
        for (const auto& [T, P, e_expected]: table_2b)
        {
                const auto
            temperature = T + 273.15;
                const auto
            pressure = P * 1e8;
                const auto
            density = zhang_2005::density_pt (pressure, temperature);
            {
                    const auto
                d_dielectric_constant_d_density_at_temperature = 
                    d_dielectric_constant_d_density_at_temperature_dt (
                        density
                        , temperature
                    )
                ;
                    const auto
                d_dielectric_constant_d_density_at_temperature_fd = 
                    central_finite_difference <0> (
                        dielectric_constant_dt <double, double>
                        , 1e-6
                        , density
                        , temperature
                    )
                ;
                CHECK(
                    d_dielectric_constant_d_density_at_temperature 
                    == 
                    Approx { d_dielectric_constant_d_density_at_temperature_fd }
                );
            }
            {
                    const auto
                d_dielectric_constant_d2_density_at_temperature = 
                    d_dielectric_constant_d2_density_at_temperature_dt (
                        density
                        , temperature
                    )
                ;
                    const auto
                d_dielectric_constant_d2_density_at_temperature_fd = 
                    central_finite_difference <0> (
                        d_dielectric_constant_d_density_at_temperature_dt <double, double>
                        , 1e-6
                        , density
                        , temperature
                    )
                ;
                CHECK(
                    d_dielectric_constant_d2_density_at_temperature 
                    == 
                    Approx { d_dielectric_constant_d2_density_at_temperature_fd }
                );
            }
            {
                    const auto
                d_dielectric_constant_d_temperature_at_density =
                    d_dielectric_constant_d_temperature_at_density_dt (
                        density
                        , temperature
                    )
                ;
                    const auto
                d_dielectric_constant_d_temperature_at_density_fd = 
                    central_finite_difference <1> (
                        dielectric_constant_dt <double, double>
                        , 1e-6
                        , density
                        , temperature
                    )
                ;
                CHECK(
                    d_dielectric_constant_d_temperature_at_density 
                    == 
                    Approx { d_dielectric_constant_d_temperature_at_density_fd }
                );
            }
            {
                    const auto
                d_dielectric_constant_d2_temperature_at_density =
                    d_dielectric_constant_d2_temperature_at_density_dt (
                        density
                        , temperature
                    )
                ;
                    const auto
                d_dielectric_constant_d2_temperature_at_density_fd = 
                    central_finite_difference <1> (
                        d_dielectric_constant_d_temperature_at_density_dt <double, double>
                        , 1e-6
                        , density
                        , temperature
                    )
                ;
                CHECK(
                    d_dielectric_constant_d2_temperature_at_density 
                    == 
                    Approx { d_dielectric_constant_d2_temperature_at_density_fd }
                );
            }
            {
                    const auto
                d_dielectric_constant_d_density_temperature_at_temperature_density =
                    d_dielectric_constant_d_density_temperature_at_temperature_density_dt (
                        density
                        , temperature
                    )
                ;
                    const auto
                d_dielectric_constant_d_density_temperature_at_temperature_density_fd = 
                    central_finite_difference <0> (
                        d_dielectric_constant_d_temperature_at_density_dt <double, double>
                        , 1e-6
                        , density
                        , temperature
                    )
                ;
                CHECK(
                    d_dielectric_constant_d_density_temperature_at_temperature_density 
                    == 
                    Approx { d_dielectric_constant_d_density_temperature_at_temperature_density_fd }
                );
            }
                const auto
            d_density_d_pressure = zhang_2005::d_density_d_pressure_at_temperature_dt (density, temperature);
            {
                    const auto
                d_dielectric_constant_d_pressure_at_temperature = 
                    d_dielectric_constant_d_pressure_at_temperature_dt (
                        density
                        , temperature
                        , d_density_d_pressure
                    )
                ;
                    const auto
                d_dielectric_constant_d_pressure_at_temperature_fd = 
                    central_finite_difference <0> (
                        [=](auto p, auto t)
                        {
                                const auto
                            d = zhang_2005::density_pt (p, t);
                            return dielectric_constant_dt (d, t);
                        }
                        , 1e-6
                        , pressure
                        , temperature
                    )
                ;
                CHECK(
                    d_dielectric_constant_d_pressure_at_temperature 
                    == 
                    Approx { d_dielectric_constant_d_pressure_at_temperature_fd }
                );
            }
                const auto
            d_density_d_temperature_at_pressure = 
                zhang_2005::d_density_d_temperature_at_pressure_dt (
                    density
                    , temperature
                )
            ;
            {
                    const auto
                d_dielectric_constant_d_temperature_at_pressure = 
                    d_dielectric_constant_d_temperature_at_pressure_dt (
                        density
                        , temperature
                        , d_density_d_temperature_at_pressure
                    )
                ;
                    const auto
                d_dielectric_constant_d_temperature_at_pressure_fd = 
                    central_finite_difference <1> (
                        [=](auto p, auto t)
                        {
                                const auto
                            d = zhang_2005::density_pt (p, t);
                            return dielectric_constant_dt (d, t);
                        }
                        , 1e-6
                        , pressure
                        , temperature
                    )
                ;
                CHECK(
                    d_dielectric_constant_d_temperature_at_pressure 
                    == 
                    Approx { d_dielectric_constant_d_temperature_at_pressure_fd }
                );
            }
                const auto
            d_density_d2_temperature_at_pressure_density = 
                zhang_2005::d_density_d2_temperature_at_pressure_density_dt (
                    density
                    , temperature
                )
            ;
                const auto
            d_density_d_temperature_density_at_pressure_temperature =
                zhang_2005::d_density_d_temperature_density_at_pressure_temperature_dt (
                    density
                    , temperature
                )
            ;
            {
                    const auto
                d_dielectric_constant_d2_temperature_at_pressure = 
                    d_dielectric_constant_d2_temperature_at_pressure_dt (
                        density
                        , temperature
                        , d_density_d_temperature_at_pressure
                        , d_density_d2_temperature_at_pressure_density
                        , d_density_d_temperature_density_at_pressure_temperature
                    );
                    const auto
                d_dielectric_constant_d2_temperature_at_pressure_fd = 
                    central_finite_difference <1, 2> (
                        [=](auto p, auto t)
                        {
                                const auto
                            d = zhang_2005::density_pt (p, t);
                            return dielectric_constant_dt (d, t);
                        }
                        , 1e-2
                        , pressure
                        , temperature
                    )
                ;
                CHECK(
                    d_dielectric_constant_d2_temperature_at_pressure 
                    == 
                    Approx { d_dielectric_constant_d2_temperature_at_pressure_fd }
                );
            }
        }
    }
}
// vim: foldmethod=marker
