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
	vector<int> a(n);
	for (int i=0;i<n;++i){
		scanf("%d", &a[i]);
	}
	map<int, int> mp;
	for (int i: a) mp[i]++;
	map<int, set<int> > c; // count -> -numbers
	for (auto &it: mp){
		c[it.second].insert(-it.first);
	}

	map<int, set<int> > dis;
	for (int i=0;i<m;++i){
		int x, y;
		scanf("%d%d", &x, &y);
		dis[x].insert(y);
		dis[y].insert(x);
	}

	long long ans = 0;
	for (auto &it: mp){
		int i = it.first;
		dis[i].insert(i);
		int cnt = it.second;
		for (auto &it2: c){
			// best in it2.second
			for (int j: it2.second){
				j = -j;
				if (dis[i].find(j) == dis[i].end()){
					long long cans = (cnt + it2.first) * 1ll * (i + j);
					// cout << i << " " << j << " " << cans << endl;
					ans = max(ans, cans);
					break;
				}
			}
		}
	}

	cout << ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}