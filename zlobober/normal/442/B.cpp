#include <cstdio>
#include <algorithm>
using namespace std;

const double eps = 1e-10;

const int N = 105;
double P[N];


int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lf", &P[i]);
    sort(P, P + n);
    reverse(P, P + n);
    double ans = 0;
    for (int l = 1; l <= n; l++)
    {
        double cur = 0;
        for (int i = 0; i < l; i++)
        {
            double x = 1;
            for (int j = 0; j < l; j++)
                x *= (i == j) ? P[j] : (1 - P[j]);
            cur += x;
        }
        ans = max(ans, cur);
    }
    printf("%.10lf\n", ans);
}