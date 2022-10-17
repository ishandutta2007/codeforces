#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss

using namespace std;

vector<int> gph[303030];
int val[303030];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, m; cin >> n >> m;
        for(int i = 0; i < m; ++i)
        {
            int x, y; cin >> x >> y; --x; --y;
            gph[x].push_back(y);
            gph[y].push_back(x);
        }

        queue<int> Q;
        Q.push(0);
        vector<int> ans;
        while(Q.size())
        {
            int x = Q.front(); Q.pop();
            if(val[x]) continue;
            val[x] = 1;
            ans.push_back(x);
            for(auto y : gph[x])
            {
                if(!val[y])
                {
                    val[y] = 2;
                    for(auto z : gph[y])
                    {
                        if(!val[z]) Q.push(z);
                    }
                }
            }
        }

        bool flag = true;
        for(int i = 0; i < n; ++i) if(!val[i]) { flag = false; cout << "NO\n"; break; }
        if(flag)
        {
            cout << "YES\n";
            cout << ans.size() << '\n';
            for(auto i : ans) cout << i + 1 << ' ';
            cout << '\n';
        }

        for(int i = 0; i < n; ++i) vector<int>().swap(gph[i]);
        for(int i = 0; i < n; ++i) val[i] = 0;
    }
}