#include <iostream>
#include <list>
using namespace std;

const int N = 50500, K = 550;
typedef long long llong;
llong D[N][K];
llong OV[N];
list<int> E[N];

int n, k;

llong ans = 0;

void DFS(int x, int p)
{
    D[x][0] = 1;
    for (auto y : E[x])
    {
        if (y == p)
            continue;
        DFS(y, x);
    }
    for (auto y : E[x])
    {
        if (y == p)
            continue;
        for (int d = 1; d <= k; d++)
            D[x][d] += D[y][d - 1];
    }
    //cerr << x << endl;
    //for (int d = 0; d <= k; d++)
    //    cerr << D[x][d] << ' ';
    //cerr << endl;
    llong add = 0;
    for (int d = 0; d <= k; d++)
        add += D[x][d] * D[x][k - d];
    for (auto y : E[x])
    {
        if (p == y)
            continue;
        for (int d = 1; d <= k - 1; d++)
            add -= D[y][d - 1] * D[y][k - d - 1];
    }
    //cerr << add << endl;
    ans += add;
}

int main()
{
    cin >> n >> k;
    if (k == 1)
    {
        cout << n - 1;
        return 0;
    }
    int a, b;
    for (int i = 0; i < n - 1; i++)
        cin >> a >> b, E[a].push_back(b), E[b].push_back(a);
    DFS(1, -1);
    cout << ans / 2;
}