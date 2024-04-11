#include <cstdio>
#include <cmath>
using namespace std;

char buf[20];

int main()
{
    gets(buf);
    int n, h;
    double ans;
    scanf("%d %d", &n, &h);
    ans = n;
    if (buf[0] == 'A')
    {
        for (int y = 1; y <= h; y++)
        {
            double u = 1;
            double v = 1 - 1.0 / (1LL << y);
            for (int l = 1; l < n; l++)
            {
                double q = u * (n - l);
                double r = (1 - (l - 1) * 1.0 / ((1LL << y) - 1)) / (1LL << (y + 1));
                ans += q * r;
                u *= v;
            }
        }
    }
    printf("%.10lf\n", ans);
}