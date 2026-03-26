set encoding utf8
set terminal pdfcairo
set output './ris/pr1.pdf'
set title 'Гиперболический параболоид'
set xlabel 'X'
set ylabel 'Y'
set zlabel 'Z'
set hidden3d
set key below center
set xrange [-5:5]
set yrange [-5:5]
set zrange [-25:25]
set view 72,318
splot 'points.txt' with lines title 'z = x^2 - y^2'
