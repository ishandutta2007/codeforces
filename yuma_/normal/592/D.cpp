#include<stdio.h>
#include <iostream>
#include <math.h>
#include <numeric>
#include <vector>
#include <map>
#include <functional>
#include <stdio.h>
#include <array>
#include <algorithm>
#include <string>
#include <assert.h>
#include <stdio.h>
#include <queue>
#include<iomanip>
#include<bitset>
#include<stack>
#include<set>
using namespace std;
//using namespace std;
//
//int N;
//int bit[1000010];
//void add(int a,int w) {
//	for	(int x = a; x <= N; x += x &-x)
//		bit[x] += w;
//
//}
//int sum(int a) {
//	int	ret = 0;
//	for	(int x = a; x > 0; x-= x &-x)
//		ret += bit[x];
//	return ret;
//}
//
//int main() {
//	cin >> N;
//	vector<int>lengths;
//	for (int i = 0; i < N; ++i) {
//		int l; cin >> l;
//		lengths.push_back(l);
//	}
//	vector<pair<int, vector<int>>>Nodes(N);
//	Nodes[0].first = lengths[0];
//	for (int i = 1; i < N; ++i) {
//		int p; cin >> p;
//		p--;
//		Nodes[i].first = Nodes[p].first + lengths[i];
//		Nodes[p].second.push_back(i);
//	}
//	vector<int>heights;
//	for (int i = 0; i < N; ++i) {
//		heights.emplace_back(Nodes[i].first);
//	}
//	sort(heights.begin(), heights.end());
//	heights.erase( unique(heights.begin(), heights.end()),heights.end());
//	for (int i = 0; i < N; ++i) {
//		auto it = find(heights.begin(), heights.end(), Nodes[i].first);
//		Nodes[i].first = abs(distance(it, heights.begin()));
//	}
//
//	map<int, int>compress;
//	for (auto it = heights.begin(); it != heights.end();++it) {
//		compress[*it] = abs(distance(it , heights.begin()));
//	}
//	vector<int>m_h(N);
//	for (int i = N - 1; i >= 0; i--) {
//		int nmh = Nodes[i].first;
//		for (auto it : Nodes[i].second) {
//			nmh = max(nmh, m_h[it]);
//		}
//		m_h[i] = nmh;
//	}
//	for (int i = 0; i < 1000010; ++i) {
//		bit[i] = 0;
//	}
//	int q; cin >> q;
//	for (int i = 0; i < q; ++i) {
//		int h; cin >> h;
//		int ans = 0;
//		if (compress.count(h)) {
//			int ch = compress[h];
//			vector<int> nodeid (1,0);
//			while(!nodeid.empty()) {
//				int nid = nodeid.back();
//				nodeid.pop_back();
//				if (Nodes[nid].first > ch) {
//					ans++;
//				}
//				else {
//					for (auto it : Nodes[nid].second) {
//						if (m_h[it] > ch) {
//							nodeid.emplace_back(it);
//						}
//					}
//				}
//			}
//			cout << ans << endl;
//		}
//		else {
//			cout << -1 << endl;
//		}
//	}
//
//
//
//	return 0;
//}

vector<int>que(1, 0);
vector<bool>attacked(124000,false);
vector<int>used(124000);
vector<vector<int>> Edges(124000,vector<int>());

vector<pair<int, int>>outs;

bool dfs(int from,int id) {
	if (used[id]) {
		return false;
	}
	else {
		vector<int>ne;
		used[id] = true;
		bool ok = attacked[id];
		for  (int i = 0; i < Edges[id].size();++i) {
			if (Edges[id][i] != from) {

			
			bool nok = dfs(id,Edges[id][i]);
			if (!nok) {
			}
			else {
				ne.push_back(Edges[id][i]);
			}
			ok = ok | nok;
			}
		}
		if (ok&&from != -1)ne.push_back(from);

		Edges[id] = ne;
		
		if (!ok) {
			return false;
		}
	}
}
pair<int, int>getans(const int from,const int id){
	int nid = id;
	int ans = 0;
	for (int i = 0; i < Edges[id].size(); ++i) {
		
		if (Edges[id][i] != from) {
			pair<int,int>np  =getans(id,Edges[id][i]);
			if (np.second > ans||np.second==ans&&nid>np.first) {
				ans = np.second;
				nid = np.first;
			}
		}
	}
	return make_pair(nid, ans + 1);
}
int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n-1; ++i) {
		int u, v; cin >> u >> v;
		u--; v--;
		Edges[u].push_back(v);
		Edges[v].push_back(u);
	}
	int t = 0;
	for (int i = 0; i < m; ++i) {
		
		int a; cin >> a;
		t = a - 1;
		a--;
		attacked[a] = true;
	}
	dfs(-1,t);
	auto it= find_if(Edges.begin(), Edges.end(), [](const vector<int> a) {return !a.empty(); });
	if (it == Edges.end()) {
		cout << t+1 << " " << 0 << endl;
		return 0;
	}
	pair<int, int> p(getans(-1, distance(Edges.begin(), it)));
	pair<int, int> q(getans(-1,p.first));
	pair<int, int> r(getans(-1, q.first));

	int path = 0;
	for (int i = 0; i < Edges.size(); ++i) {
		path += Edges[i].size();
	}
	path /= 2;
	int ans = path * 2 - r.second+1;
	int fromid = min(r.first, q.first) + 1;
	cout << fromid << " " <<ans<< endl;
	return 0;
	
}