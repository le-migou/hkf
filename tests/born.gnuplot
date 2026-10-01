reset
set xlabel "T (K)"

set multiplot layout 4,1
set style data line
plot "born.csv" u 1:3 title "iapws", "" u 1:8 t "sverjensky"
plot "" u 1:4 title "iapws", "" u 1:9 t "sverjensky"
plot "" u 1:5 title "iapws", "" u 1:10 t "sverjensky"
plot "" u 1:6 title "iapws", "" u 1:11 t "sverjensky"
unset multiplot
