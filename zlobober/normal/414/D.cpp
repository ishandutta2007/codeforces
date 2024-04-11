#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 100500;
int A[N];
typedef long long llong;
llong S[N];
vector<int> E[N];
int apt = 0;
void DFS(int x, int p = -1, int d = 0)
{
    if (d)
        A[apt++] = d;
    for (int i = 0; i < E[x].size(); i++)
    {
        int y = E[x][i];
        if (y == p)
            continue;
        DFS(y, x, d + 1);
    }
}

int main()
{
    int n, k, p;
    scanf("%d %d %d", &n, &k, &p);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    DFS(1);
    sort(A, A + apt);
    for (int i = 0; i < apt; i++)
        S[i + 1] = S[i] + A[i];
    A[apt] = 1000000;
    int pt = 0;
    int ans = 0;
    for (int m = 1; m <= n; m++)
    {
        while (A[pt] <= m)
            pt++;
        int r = pt, l = -1;
        while (r - l > 1)
        {
            int q = (l + r) / 2;
            if ((pt - q) * 1LL * m - (S[pt] - S[q]) <= p)
                r = q;
            else
                l = q;
        }
        ans = max(ans, pt - r);
    }
    printf("%d\n", min(ans, k));
}