#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

const int MOD = 998244353;

void solve(int test_ind){
	int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for (long long &i: a) scanf("%lld", &i);

    vector<vector<int> > g(n);
    vector<int> rg(n);
    for (int i=0;i<m;++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;--y;
        g[x].push_back(y);
        rg[y]++;
    }

    vector<bool> visited(n, false);

    vector<int> order;

    function<void(int)> dfs = [&](int v){
        visited[v] = true;
        for (int u: g[v]){
            if (visited[u]) continue;
            dfs(u);
        }
        order.push_back(v);
    };

    for (int i=0;i<n;++i) if (rg[i] == 0) dfs(i);

    for (int i=0;i<n;++i) {
        bool ok = true;
        for (int v: order) {
            if (a[v]) {
                ok = false;
                a[v]--;
                for (int to: g[v]) a[to]++;
            }
        }
        if (ok) {
            cout << i << endl;
            return;
        }
    }

    int ans = n;
    // a[i] = 0 -> it will be zero forever
    vector<int> rorder = order;
    reverse(rorder.begin(), rorder.end());
    for (int v: rorder) {
        for (int to: g[v]) {
            (a[to] += a[v]) %= MOD;
        }
    }
    cout << (a[order.front()] + ans) % MOD << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}