#include <cstdio>
#include <set>
using namespace std;

const int N = 2000500;

int P[N];
int D[N];

multiset<int> S[N];

inline bool recalc(int x)
{
    if (x == 1)
    {
        D[x] = *S[x].rbegin() + 1;
        return false;
    }
    else
    {
        int nd;
        if (S[x].size() == 1)
            nd = *S[x].rbegin();
        else
            nd = max(*S[x].rbegin(), *(++S[x].rbegin()) + 1);

        if (nd != D[x])
        {
            S[P[x]].erase(S[P[x]].find(D[x]));
            D[x] = nd;
            S[P[x]].insert(nd);
            return true;
        }
        else
            return false;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    P[1] = -1;
    D[0] = 1;
    for (int i = 2; i < n + 2; i++)
    {
        scanf("%d", &P[i]);
        S[P[i]].insert(0);
        for (int x = P[i]; recalc(x); x = P[x]);
        printf("%d ", D[1]);
    }
    printf("\n");
}