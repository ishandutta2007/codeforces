// https://codeforces.com/problemset/problem/101/D

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

void solve(int test_ind){
    int n;
    cin >> n;
    vector<vector<pair<int, int> > > g(n);
    for (int i=1;i<n;++i){
        int u, v, t;
        scanf("%d%d%d", &u, &v, &t);
        u--;v--;
        g[u].emplace_back(v, t);
        g[v].emplace_back(u, t);
    }

    vector<long double> ans(n);
    vector<int> dsum(n), c(n);
    function<void(int, int)> dfs = [&](int u, int par){
        for (auto &e: g[u]){
            if (e.first == par) continue;
            dfs(e.first, u);
            c[u] += c[e.first];
            dsum[u] += dsum[e.first] + e.second;
        }
        c[u]++;
        vector<pair<long double, pair<long double, long double> > > v;
        for (auto &e: g[u]){
            if (e.first == par) continue;
            long double prob = c[e.first];
            prob /= c[u];
            ans[u] += (ans[e.first] + e.second) * prob;
            v.push_back({prob / (dsum[e.first] + e.second), {2*(dsum[e.first] + e.second), prob}});
        }
        sort(v.begin(), v.end());
        long double pr = 0;
        for (auto &p: v){
            ans[u] += p.second.first * pr;
            pr += p.second.second;
        }

        // ans[u1] * c1 / (c-1) + (dsum[u1] + ans[u2]) * c2 / (c - 1) + ... + (dsum[u1..uk-1] + ans[uk]) * ck / (c-1)
        // ans[ui] * ci / (c-1) + 2(dsum[u1] * (c2+..+ck)/(c-1) + dsum[u2] * (c3+..+ck)/(c-1) + ... + dsum[uk] * (ck+..+ck)/(c-1))
    };

    dfs(0, -1);
    printf("%.13Lf", ans[0] * n / (n-1));
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}