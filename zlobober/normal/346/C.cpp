#include <cstdio>
#include <set>
#include <cassert>
#include <memory.h>
#include <algorithm>
using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const int N = 1 << 17;
int X[N];

int val[N];

bool cmp(int a, int b)
{
    return val[a] == val[b] ? a < b : val[a] < val[b];
}

int MX[2 * N];
int MN[2 * N];

void sset(int x, int mn, int mx)
{
    x += N;
    MX[x] = mx;
    MN[x] = mn;
    while (x /= 2)
        MX[x] = max(MX[2 * x], MX[2 * x + 1]), MN[x] = min(MN[2 * x], MN[2 * x + 1]);
}

int findmx()
{
    int x = 1;
    while (x < N)
        if (MX[2 * x] > MX[2 * x + 1])
            x = 2 * x;
        else
            x = 2 * x + 1;
    return x - N;
}

int findmn()
{
    int x = 1;
    while (x < N)
        if (MN[2 * x] < MN[2 * x + 1])
            x = 2 * x;
        else
            x = 2 * x + 1;
    return x - N;
}

void sset(int x, int mn)
{
    sset(x, mn, mn);
}


int main()
{
    int n;
    scanf("%d", &n);
    //n = 100000;
    for (int i = 0; i < n; i++)
        scanf("%d", &X[i]);
        //X[i] = i + 1;
    sort(X, X + n);
    n = unique(X, X + n) - X;
    set<int, function<bool(int, int)> > S(cmp);
    int a, b;
    scanf("%d %d", &b, &a);
    //a = (int)1e9 - 1000000, b = (int)1e9;
    for (int i = 0; i < n; i++)
        sset(i, val[i] = b % X[i]);
    for (int i = n; i < N; i++)
        sset(i, 1e9 + 42, -1e9 - 42);
    int cur = 0;
    int ans = 0;
    int cnt = n;
    while (true)
    {
        if (b == a)
            break;
        //if (ans % 1000 == 0)
        //eprintf("b = %d, cur = %d, ans = %d\n", b, cur, ans);
        /*while (!S.empty() && val[*S.begin()] < cur)
        {
            int q = *S.begin();
            S.erase(S.begin());
            val[q] += X[q];
            S.insert(q);
        }*/
        if (cnt)
        {
            while (true)
            {
                int q = findmn();
                if (val[q] < cur)
                    val[q] = (cur - val[q] + (X[q] - 1)) / X[q] * X[q] + val[q], sset(q, val[q]);
                else
                    break;
            }
        }
        while (cnt)
        {
            int q = findmx();
            if (b - (val[q] - cur) < a)
                sset(q, 1e9 + 42, -1e9 - 42), cnt--;
            else
                break;
        }
        if (!cnt)
            b--, cur++;
        else
        {
            int r = max(1, val[findmx()] - cur);
            b -= r, cur += r;
        }
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}