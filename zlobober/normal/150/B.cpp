#include <iostream>
using namespace std;

typedef long long llong;

const int N = 2050;

bool A[N][N];
int n, k;

bool was[N];

const llong MOD = 1000*1000*1000+7;

void DFS(int x)
{
    was[x] = 1;
    for (int i = 0; i < n; i++)
        if (A[x][i] && !was[i])
            DFS(i);
}

int main()
{
    llong m;
    cin >> n >> m >> k;
    for (int i = 0; i < n - k + 1; i++)
    {
        for (int j = 0; j < k; j++)
            A[i + j][i + k - 1 - j] = 1;
    }
    int a = 0;
    for (int i = 0; i < n; i++)
        if (!was[i])
            DFS(i), a++;
    llong ans = 1;
    for (int i = 0; i < a; i++)
        ans = (ans * m) % MOD;
    cout << ans;
}