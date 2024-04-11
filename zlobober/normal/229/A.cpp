#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

const int N = 105, M = 10500;
int A[N][M];
set<int> S[N];

int n, m;

int dist(int x, int y)
{
    return min(abs(x - y), m - abs(x - y));
}

int mnn(int y, int x)
{
    int res = M;
    #define RELAX(t) if (res > (dist(x, (t)))) res = dist(x, (t))
    set<int>::iterator it = S[y].lower_bound(x);
    if (it != S[y].end())
    {
        RELAX(*it);
    }
    if (it != S[y].begin())
    {
        --it;
        RELAX(*it);
    }
    RELAX(*S[y].begin());
    RELAX(*S[y].rbegin());
    return res;
}


int main()
{
    scanf("%d %d ", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char t;
            scanf(" %c ", &t);
            A[i][j] = t - '0';
            if (A[i][j])
                S[i].insert(j);
        }
        if (S[i].empty())
        {
            printf("-1\n");
            return 0;
        }
    }
    int gans = N * M;
    for (int j = 0; j < m; j++)
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += mnn(i, j);
        }
        gans = min(gans, ans);
    }
    printf("%d\n", gans);
    return 0;
}