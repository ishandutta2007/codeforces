#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1 << 17;

vector<int> C[N];

int T[2 * N], S[2 * N];

int in = 0;

const int inf = 1.42e9;

void add(int x, int u, int v)
{
    x += N;
    T[x] += u;
    in += u;
    S[x] += v;
    while (x /= 2)
        T[x] = T[2 * x] + T[2 * x + 1], S[x] = S[2 * x] + S[2 * x + 1];
}
vector<int> U[N];

int get(int cnt, int v = 1)
{
    assert(T[v] >= cnt);
    if (v >= N)
        return cnt * (v - N);
    else if (T[2 * v] >= cnt)
        return get(cnt, 2 * v);
    else
        return S[2 * v] + get(cnt - T[2 * v], 2 * v + 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    int init = 0;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a == 0)
            init++;
        else
            C[a].push_back(b);
    }
    for (int i = 0; i < N; i++)
    {
        sort(C[i].rbegin(), C[i].rend());
        //sort(C[i].begin(), C[i].end());
        for (int j = 0; j < C[i].size(); j++)
            add(C[i][j], 1, C[i][j]), U[j].push_back(C[i][j]);
    }
    int alr = 0;
    int ans = inf;
    for (int g = in + init; g >= 1; g--)
    {
        for (int i = 0; i < U[g - 1].size(); i++)
            add(U[g - 1][i], -1, -U[g - 1][i]), alr += U[g - 1][i], init++;
        int cost = alr;
        if (init < g)
        {
            int nd = g - init;
            assert(nd <= in);
            cost += get(nd);
        }
        ans = min(ans, cost);
    }
    printf("%d\n", ans);
    return 0;
}