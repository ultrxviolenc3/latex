#include <stdio.h>

int main(void)
{
    FILE *f = fopen("points.txt", "w");
    if (!f) return 1;

    double x, y, z;

    for (x = -5; x <= 5; x += 0.4)
    {
        for (y = -5; y <= 5; y += 0.4)
        {
            z = x * x - y * y;
            fprintf(f, "%lf %lf %lf\n", x, y, z);
        }
        fprintf(f, "\n");
    }
    fclose(f);

    FILE *plt = fopen("anim.plt", "w");
    if (!plt)
    {
        return 1;
    }

    fprintf(plt, "set encoding utf8\n");
    fprintf(plt, "set title 'Гиперболический параболоид'\n");
    fprintf(plt, "set xlabel 'X'\n");
    fprintf(plt, "set ylabel 'Y'\n");
    fprintf(plt, "set zlabel 'Z'\n");
    fprintf(plt, "set hidden3d\n");
    fprintf(plt, "set key below center\n");
    fprintf(plt, "set xrange [-5:5]\n");
    fprintf(plt, "set yrange [-5:5]\n");
    fprintf(plt, "set zrange [-25:25]\n");
    fprintf(plt, "do for [i=0:360:20] {\n");
    fprintf(plt, "    set view 60,i\n");
    fprintf(plt, "    splot 'points.txt' with lines title 'z = x^2 - y^2'\n");
    fprintf(plt, "    pause 1\n");
    fprintf(plt, "}\n");
    fprintf(plt, "pause -1\n");

    fclose(plt);

    FILE *plt2 = fopen("lplot.plt", "w");
    if (!plt2)
    {
        return 1;
    }

    fprintf(plt2, "set encoding utf8\n");
    fprintf(plt2, "set terminal pdfcairo\n");
    fprintf(plt2, "set output './ris/pr1.pdf'\n");
    fprintf(plt2, "set title 'Гиперболический параболоид'\n");
    fprintf(plt2, "set xlabel 'X'\n");
    fprintf(plt2, "set ylabel 'Y'\n");
    fprintf(plt2, "set zlabel 'Z'\n");
    fprintf(plt2, "set hidden3d\n");
    fprintf(plt2, "set key below center\n");
    fprintf(plt2, "set xrange [-5:5]\n");
    fprintf(plt2, "set yrange [-5:5]\n");
    fprintf(plt2, "set zrange [-25:25]\n");
    fprintf(plt2, "set view 72,318\n");
    fprintf(plt2, "splot 'points.txt' with lines title 'z = x^2 - y^2'\n");

    fclose(plt2);

    return 0;
}
