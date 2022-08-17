#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const int N = 53;

int n, p;

typedef long long llong;

int A[N];
double F[N];

llong D[N][N][N][N];

void init()
{
    for (int l = 0; l < n; l++)
        D[0][0][0][l] = 1;
    for (int i = 1; i <= n; i++)
        for (int l = 0; l < n; l++)
            for (int k = 0; k <= n; k++)
                for (int v = 0; v <= p; v++)
                {
                    if (k == 0)
                        D[i][k][v][l] = !v;
                    else
                        D[i][k][v][l] = D[i - 1][k][v][l] + ((v >= A[i - 1] && i - 1 != l) ? (D[i - 1][k - 1][v - A[i - 1]][l]) : 0);
                }
    F[0] = 1;
    for (int i = 1; i < N; i++)
        F[i] = i * F[i - 1];
}


double way(int k)
{
    assert(0 <= k && k < n);
    double ans = 0;
    for (int l = 0; l < n; l++)
    {
        int w = max(p - A[l] + 1, 0);
        double prf = 0;
        for (int v = w; v <= p; v++)
            prf += D[n][k][v][l];
        prf *= F[k] * F[n - k - 1];
        ans += prf * k;
    }
    return ans;
}

double rans()
{
    sort(A, A + n);
    int ans = 0;
    int it = 0;
    do
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += A[i];
            if (sum > p)
            {
                ans += i;
                break;
            }
        }
        it++;
    } while (next_permutation(A, A + n));
    return ans / (double)it;
}

int main()
{
    scanf("%d", &n);
    int s = 0;
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]), s += A[i];
    scanf("%d", &p);
    if (s <= p)
    {
        printf("%d\n", n);
        return 0;
    }
    init();

    double ans = 0;
    for (int i = 0; i < n; i++)
        ans += way(i);
    ans /= F[n];
    //double sans = rans();
    printf("%.10lf\n", ans);
    //eprintf("%.10lf\n", sans);
}