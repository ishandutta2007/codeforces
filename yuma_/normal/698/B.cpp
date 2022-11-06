#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;


struct Dscc {
public:

	//fst:belongs , scd:newedges
	pair<vector<vector<int>>, vector<vector<int>>>get(const vector<vector<int>>&edges) {
		nums.resize(edges.size());
		fill(nums.begin(), nums.end(), -1);
		vector<vector<int>>revedges(edges.size());
		for (int i = 0; i < edges.size(); ++i) {
			for (auto j : edges[i]) {
				revedges[j].push_back(i);
			}
		}
		int num = 0;
		for (int i = 0; i < edges.size(); ++i) {
			dfs(i, num, edges);
		}
		vector<int>big(nums.size());
		for (int i = 0; i < nums.size(); ++i) {
			big[nums[i]] = i;
		}
		reverse(big.begin(), big.end());
		unis.resize(edges.size());
		fill(unis.begin(), unis.end(), -1);
		num = 0;
		for (int i = 0; i < big.size(); ++i) {

			dfs2(big[i], num, revedges);
			num++;
		}
		vector<int>nums;
		for (int i = 0; i < unis.size(); ++i) {
			nums.push_back(unis[i]);
		}
		sort(nums.begin(), nums.end());
		nums.erase(unique(nums.begin(), nums.end()), nums.end());


		map<int, int>mp;
		for (int i = 0; i < nums.size(); ++i) {
			mp[nums[i]] = i;
		}
		for (int i = 0; i < unis.size(); ++i) {
			unis[i] = mp[unis[i]];
		}

		vector<vector<int>>belongs(nums.size());
		for (int i = 0; i < unis.size(); ++i) {
			belongs[unis[i]].push_back(i);
		}
		vector<vector<int>>newedges(nums.size());
		for (int i = 0; i < edges.size(); ++i) {
			for (auto j : edges[i]) {
				if (unis[i] != unis[j]) {
					newedges[unis[i]].push_back(unis[j]);
				}
			}
		}
		return make_pair(belongs, newedges);
	}
private:
	vector<int>nums;
	vector<int>unis;


	void dfs(const int id, int &num, const vector<vector<int>>&edges) {
		if (nums[id] != -1)return;
		else {
			nums[id] = -2;
			for (auto i : edges[id]) {
				dfs(i, num, edges);
			}
		}
		nums[id] = num++;
		return;
	}
	void dfs2(const int id, const int &num, const vector<vector<int>>&edges) {
		if (unis[id] != -1)return;
		else {
			unis[id] = -2;
			for (auto i : edges[id])
				dfs2(i, num, edges);
		}
		unis[id] = num;
		return;
	}

}dscc;

int main() {
	int N; cin >> N;
	vector<int>as(N);
	for (int i = 0; i < N; ++i) {
		cin >> as[i];
		as[i]--;
	}
	vector<int>selfs;
	for (int i = 0; i < N; ++i) {
		selfs.push_back(as[i]==i);
	}
	int ans = 0;
	int pa;
	if (accumulate(selfs.begin(),selfs.end(),0)==0) {
		bool flag = false;

		vector<vector<int>>edges(N);
		for (int i = 0; i < N; ++i) {
			edges[i].push_back(as[i]);
		}
		auto p = dscc.get(edges);
		for (int i = 0; i < p.first.size(); ++i) {
			if (p.second[i].empty()) {
				if (!flag) {

					pa = p.first[i][0];
					as[pa] =pa;
					ans++;
					flag = true;
				}
				else {
					as[p.first[i][0]] = pa;
					ans++;
				}
			}
		}
		
	}
	else {
		bool flag = false;
		for (int i = 0; i < N; ++i) {
			if (!flag) {
				if (as[i] == i) {
					pa = i;
					flag = true;
				}
			}
			else {
				if (as[i] == i) {
					as[i] = pa;
					ans++;
				}
			}
		}
		vector<vector<int>>edges(N);
		for (int i = 0; i < N; ++i) {
			edges[i].push_back(as[i]);
		}
		auto p = dscc.get(edges);
		for (int i = 0; i < p.first.size(); ++i) {
			if (p.second[i].empty()) {
				if (!flag) {

					pa = p.first[i][0];
					as[pa] = pa;
					ans++;
					flag = true;
				}
				else {
					if (as[p.first[i][0]] != pa) {

						as[p.first[i][0]] = pa;
						ans++;
					}
				}
			}
		}
	}
	cout << ans << endl;
	for (int i = 0; i < as.size(); ++i) {
		cout << as[i]+1;
		if (i == as.size() - 1)cout << endl;
		else cout << " ";
	}
	
	return 0;
}