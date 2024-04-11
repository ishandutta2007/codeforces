#include <cstdio>
#include <cassert>
#include <set>
using namespace std;

const int N = 100500;

int A[N];
int B[N];
int iA[N];
int iB[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &B[i]);
    for (int i = 1; i <= n; i++)
        iA[A[i]] = i, iB[B[i]] = i;
    set<pair<int, int> > L, R;
    for (int i = 1; i <= n; i++)
        if (iA[i] < iB[i])
            R.insert(make_pair(iB[i] - iA[i], i));
        else
            L.insert(make_pair(iA[i] - iB[i], i));
    int rk = 0;
    int lk = 0;
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
    #define mp make_pair
    for (int d = 0; d < n; d++)
    {
        //eprintf("%d\n", lk);
        /*for (auto it : L)
            eprintf("(%d %d) ", it.second, it.first + lk);
        eprintf("\n");
        for (auto it : R)
            eprintf("(%d %d) ", it.second, it.first - rk);
        eprintf("\n");*/
        int cur = 1e9;
        if (!R.empty())
            cur = min(cur, R.begin()->first - rk);
        if (!L.empty())
            cur = min(cur, L.begin()->first + lk);
        printf("%d\n", cur);
        while (!R.empty() && R.begin()->first == rk + 1)
        {
            int q = R.begin()->second;
            R.erase(R.begin());
            L.insert(make_pair(-lk-1, q));
        }
        int rg = B[d + 1];
        assert(L.find(mp(iA[rg] - 1 - lk, rg)) != L.end());
        L.erase(L.find(mp(iA[rg] - 1 - lk, rg)));
        if (iA[rg] != n)
            R.insert(mp(n - iA[rg] + rk + 1, rg));
        else
            L.insert(mp(-lk - 1, rg));
        rk++;
        lk++;
    }
}