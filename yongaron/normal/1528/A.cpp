#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#define ll long long

using namespace std;

int t, n;

ll dp[123456][2];

ll l[123456], r[123456];

vector<int> graf[123456];

void dfs(int v, int f)
{
    for(auto u : graf[v])
    {
        if(u != f)
        {
            dfs(u, v);
            dp[v][0] += max(dp[u][0] + abs(l[v]-l[u]), dp[u][1] + abs(l[v]-r[u]));
            dp[v][1] += max(dp[u][0] + abs(r[v]-l[u]), dp[u][1] + abs(r[v]-r[u]));
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> l[i] >> r[i];
        int a, b;
        for(int i = 0; i < n-1; i++)
        {
            cin >> a >> b;
            graf[a].push_back(b);
            graf[b].push_back(a);
        }
        dfs(1, 0);
        cout << max(dp[1][0], dp[1][1]) << endl;
        for(int i = 0; i <= n; i++)
        {
            graf[i].clear();
            dp[i][0] = dp[i][1] = 0;
        }
    }
    return 0;
}