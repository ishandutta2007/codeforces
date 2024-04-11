#include <iostream>
#include <vector>

using namespace std;

const int Q = 1e9 + 7;

long long modpow(long long x, int y)
{
    long long ans = 1;
    for(int i = 0; i < y; ++i)
        ans = (ans * x) % Q;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<int> g[n];

    for(int i = 0; i < n - 1; ++i)
    {
        int u, v, x; cin >> u >> v >> x;
        --u; --v;
        if(!x){g[u].push_back(v); g[v].push_back(u);}
    }

    bool visited[n]{};///
    int qq[n + 5]; int chc = 0;///
    long long ans = modpow(n, k);
    for(int i = 0; i < n; ++i)
    {
        if(visited[i]) continue;

        int cnt = 0;
        qq[chc++] = i;

        while(chc)
        {
            int x = qq[--chc];
            if(visited[x]) continue;
            visited[x] = true;
            ++cnt;
            for(int &j : g[x])
                qq[chc++] = j;
        }

        ans -= modpow(cnt, k);
        if(ans < 0) ans += Q;
    }

    cout << ans;
    return 0;
}