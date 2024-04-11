#include <cstdio>
using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    double ans = -1;
    if (n == 1 && m == 1)
    {
        ans = 1.0;
    }
    else
    {
        ans = 1.0 / n + (n - 1) * 1.0 * (m - 1) / 1.0 / n / 1.0 / (n * m - 1);
    }
    printf("%.10lf\n", ans);

}