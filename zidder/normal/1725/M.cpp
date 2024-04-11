#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int> > > g(2 * n);
    for (int i=0;i<n;++i) g[2*i].emplace_back(2*i+1, 0);
    for (int i=0;i<m;++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        u--;v--;
        g[u * 2].emplace_back(v * 2, w);
        g[v * 2+1].emplace_back(u * 2+1, w);
    }

    vector<long long> dist(2*n, -1);
    dist[0] = 0;
    set<pair<long long, int> > st;
    st.emplace(0, 0);
    while (!st.empty()) {
        auto it = st.begin();
        auto p = *it;
        st.erase(it);
        long long d = p.first;
        int v = p.second;
        for (auto &p2: g[v]) {
            if (dist[p2.first] == -1 || dist[p2.first] > p2.second + d) {
                st.erase({dist[p2.first], p2.first});
                dist[p2.first] = p2.second + d;
                st.emplace(dist[p2.first], p2.first);
            }
        }
    }

    for (int i=1;i<n;++i) {
        printf("%lld ", dist[2*i+1]);
    }
    cout << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}