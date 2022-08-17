#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cassert>
using namespace std;

const int N = 1000500;
int E[N];

int n, k;
int L[N], R[N];
    
void init()
{
    for (int i = 0; i < n; i++)
        //E[i] = abs((rand() << 16) + rand()) % 1000000 + 1;
        scanf("%d", &E[i]);
    sort(E, E + n);
    n = unique(E, E + n) - E;
    for (int v = 1; v < N; v++)
    {
        int mn = v, mx = v + k;
        L[v] = lower_bound(E, E + n, mn) - E;
        R[v] = upper_bound(E, E + n, mx) - E;
    }
}

int main()
{
    //srand(23);
    scanf("%d %d", &n, &k);
    //n = 300000;
    //k = 1000000;
    init();
    int ans = 0;
    for (int g = 1; g < N; g++)
    {
        int lst = 0;
        bool bad = false;
        for (int v = g; v < N; v += g)
        {
            int l = L[v], r = R[v];
            if (l > lst)
            {
                bad = true;
                break;
            }
            lst = r;
        }
        if (lst != n)
            bad = true;
        if (!bad)
            ans = g;
    }
    assert(ans);
    printf("%d\n", ans);
    return 0;
}