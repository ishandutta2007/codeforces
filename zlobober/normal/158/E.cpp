#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

const int N = 4050;

pair<int, int> P[N];

int n, k;
int D[N][N];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> P[i].first >> P[i].second;
    P[0] = make_pair(0, 1);
    P[n + 1] = make_pair(86401, 42);
    int ans = 0;
    D[0][0] = 1;
    for (int i = 1; i <= n + 1; i++)
    {
        for (int j = 0; j <= min(i - 1, k); j++)
            ans = max(ans, P[i].first - D[i - 1][j]);
        for (int j = 0; j <= min(i, k); j++)
        {
            if (j == 0)
                D[i][j] = max(D[i - 1][j] + P[i].second, P[i].first + P[i].second);
            else
                D[i][j] = min(max(D[i - 1][j] + P[i].second, P[i].first + P[i].second),
                              D[i - 1][j - 1]);
        }
    }
    cout << ans;
}