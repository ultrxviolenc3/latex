set encoding utf8
set title 'Гиперболический параболоид'
set xlabel 'X'
set ylabel 'Y'
set zlabel 'Z'
set hidden3d
set key below center
set xrange [-5:5]
set yrange [-5:5]
set zrange [-25:25]
do for [i=0:360:20] {
    set view 60,i
    splot 'points.txt' with lines title 'z = x^2 - y^2'
    pause 1
}
pause -1
