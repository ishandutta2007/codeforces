#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

const int N = 150;

int fav[N];

char name[N][N];

int mn[N];
int mx[N];

int mxmnL[N], mxmnR[N];
int mxmxL[N], mxmxR[N];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int m, k;
    scanf("%d %d", &m, &k);
    int gnf = 0, gf = 0;
    for (int i = 0; i < k; i++)
    {
        int t;
        scanf("%d", &t);
        fav[t] = 1;
    }
    gf = k;
    gnf = m - k;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf(" %s ", name[i]);
        int d;
        scanf("%d", &d);
        int f = 0, nf = 0;
        for (int j = 0; j < d; j++)
        {
            int t;
            scanf("%d", &t);
            if (t != 0)
            {
                if (fav[t])
                    f++;
                else
                    nf++;
            }
        }
        mn[i] = max(f, d - gnf);
        mx[i] = min(d - nf, gf);
    }
    mxmnL[0] = mxmnR[n + 1] = -1;
    mxmxL[0] = mxmxR[n + 1] = -1;
    for (int i = 1; i <= n; i++)
        mxmnL[i] = max(mxmnL[i - 1], mn[i]), mxmxL[i] = max(mxmxL[i - 1], mx[i]);
    for (int i = n; i >= 1; i--)
        mxmnR[i] = max(mxmnR[i + 1], mn[i]), mxmxR[i] = max(mxmxR[i + 1], mx[i]);
    for (int i = 1; i <= n; i++)
    {
        int bstw = mx[i];
        int bsto = max(mxmnL[i - 1], mxmnR[i + 1]);
        int wstw = mn[i];
        int wsto = max(mxmxL[i - 1], mxmxR[i + 1]);
        bool bst = false, wst = false;
        if (bstw >= bsto)
            bst = true;
        if (wstw >= wsto)
            wst = true;
        assert(!(!bst && wst));
        if (bst && wst)
            printf("0\n");
        else if (bst && !wst)
            printf("2\n");
        else if (!bst && !wst)
            printf("1\n");
        else
            assert(false);
    }
    return 0;
}