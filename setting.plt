set macros
max = "1.0"
pass = "0.2"
sty1 = "with lines lw 2"

set multiplot layout 2,2
set size 0.5, 0.5
set datafile separator ","

set size square
set polar
set grid polar
set xlabel "Real"
set ylabel "Imaginary"
set xrange [-1:1]
set yrange [-1:1]
set xtics 1
set mxtics 5
set ytics 1
set mytics 5
set format r ""
plot "out.dat" index 0 using 4:2 notitle @sty1
unset polar
unset grid

set xlabel "Normalized Frequency (×π rad/sample)"
set ylabel "Magnitude (dB)"
set xtics 0.5
set mxtics 5
set ytics 10
set mytics 1
set xrange [0:@max]
set yrange [-50:0]
plot "out.dat" index 0 using 1:3 ti "Gain" @sty1

set ylabel "Phrase (rad)"
set ytics 5
set mytics 5
set autoscale y
plot "out.dat" index 0 using 1:4 ti "Phase" @sty1

set ylabel "Group Delay (samples)"
set xtics 0.5
set mxtics 5
set ytics 5
set mytics 5
set xrange [0:@max]
plot "out.dat" index 0 using 1:5 ti "Group Delay" @sty1

unset autoscale
unset multiplot
