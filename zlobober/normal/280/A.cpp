#include <cmath>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    double w, h, al;
    scanf("%lf %lf %lf", &w, &h, &al);
    double ans;
    al = al / 180.0 * M_PI;
    if (al > M_PI / 2)
        al = M_PI - al;
    if (w < h)
        swap(w, h);
    if (fabs(al) < 0.01)
        ans = w * h;
    else if (al < 2 * atan2(h, w))
    {
        double q = atan2(h, w);
        #define eprintf(...) fprintf(stderr, __VA_ARGS__)

        eprintf("%lf %lf\n", q, al);
        double h1 = sqrt(w * w + h * h) / 2.0 * sin(q + al) - h / 2.0;
        double s1 = h1 * h1 / sin(al) / cos(al);
        double h2 = sqrt(w * w + h * h) / 2.0 * cos(q - al) - w / 2.0;
        double s2 = h2 * h2 / sin(al) / cos(al);
        eprintf("%lf %lf\n", s1, s2);
        ans = w * h - s1 - s2;
    }
    else
    {
        ans = h * h / sin(al);
    }
    printf("%.10lf\n", ans);
    return 0;
}