#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		vector<vector<int>> v(n);
		map<int,int> m;
		for(int i=0;i<n;i++) {
			int k;
			cin >> k;
			v[i] = vector<int>(k);
			for(int &x:v[i])
				cin >> x, m[x] = 0;
		}
		{
			int cnt = 0;
			for(auto &it:m)
				it.second = cnt++;
		}
		for(int i=0;i<n;i++)
			for(int &x:v[i])
				x = m[x];
		vector<int> idx(n);
		iota(idx.begin(), idx.end(), 0);
		sort(idx.begin(), idx.end(), [&](const int& a, const int& b) {
			return v[a].size() > v[b].size();
		});
		int th = sqrt(n);
		bool ok = false;
		vector<int> vis(m.size());
		for(int i=0;!ok&&i<idx.size();i++) {
			if(v[idx[i]].size() < th)	break;
			for(int x:v[idx[i]])
				vis[x] = true;
			for(int j=i+1;j<idx.size();j++) {
				int cnt = 0;
				for(int x:v[idx[j]])
					cnt += vis[x];
				if(cnt > 1) {
					ok = true;
					cout << idx[i] + 1 << ' ' << idx[j] + 1 << '\n';
					break;
				}
			}
			for(int x:v[idx[i]])
				vis[x] = false;
		}
		if(ok)	continue;
		vector<vector<pair<int,int>>> arr(m.size());
		for(int i=0;i<idx.size();i++) {
			if(v[idx[i]].size() >= th)	continue;
			auto &cur = v[idx[i]];
			for(int j=0;j<cur.size();j++)
				for(int k=j+1;k<cur.size();k++)
					if(cur[j] < cur[k])
						arr[cur[j]].emplace_back(cur[k], idx[i]);
					else
						arr[cur[k]].emplace_back(cur[j], idx[i]);
		}
		for(int i=0;!ok&&i<m.size();i++) {
			for(auto it:arr[i]) {
				if(vis[it.first]) {
					ok = true;
					cout << vis[it.first] << ' ' << it.second + 1 << '\n';
					break;
				}
				vis[it.first] = it.second + 1;
			}
			for(auto it:arr[i])
				vis[it.first] = 0;
		}
		if(ok)	continue;
		cout << -1 << '\n';
	}
}