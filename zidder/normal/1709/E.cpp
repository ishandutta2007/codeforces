#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

set<int> st[200005];
int       x[200005];

void solve(int test_ind){
	int n;
    cin >> n;
    vector<int> a(n);
    for (int &i: a) scanf("%d", &i);
    vector<vector<int> > g(n);
    for (int i=1;i<n;++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x;--y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int ans = 0;

    function<int(int, int)> dfs = [&](int v, int p) -> int {
        vector<int> children;
        for (int u: g[v]) {
            if (u == p) continue;
            children.push_back(dfs(u, v));
        }
        if (children.empty()) {
            x[v] = 0;
            st[v] = {a[v]};
            // cout << "leaf " << v + 1 << endl;
            return v;
        }
        for (int i: children) {
            // cout << "ch: " <<  v + 1 << " " << i + 1 << endl;
            if (st[i].find(a[v]^x[i]) != st[i].end()) {
                st[v] = {};
                x[v] = 0;
                ans++;
                return v;
            }
        }
        int mx = children[0];
        for (int i=0;i<children.size();++i) if (st[children[i]].size() > st[mx].size()) mx = children[i];
        for (int i: children) {
            if (i != mx) {
                for (int j: st[i]) {
                    int num = j ^ x[i];
                    num ^= x[mx];
                    if (st[mx].find(num ^ a[v]) != st[mx].end()) {
                        st[v] = {};
                        x[v] = 0;
                        ans++;
                        return v;
                    }
                }
                for (int j: st[i]) {
                    int num = j ^ x[i];
                    num ^= x[mx];
                    st[mx].insert(num);
                }
            }
        }
        st[mx].insert(x[mx]);
        x[mx] ^= a[v];
        // cout << v + 1 << " " << mx + 1 << endl;
        // for (int i: st[mx]) {
        //     cout << i <<" ";
        // }
        // cout << endl;
        return mx;
    };

    dfs(0, -1);

    cout << ans << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}