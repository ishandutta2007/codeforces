#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;

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
	int N,M;cin>>N>>M;
	vector<vector<int>>edges(N);
	vector<vector<int>>revedges(N);
	for (int i = 0; i < N; ++i) {
		int k;cin>>k;
		for (int j = 0; j < k; ++j) {
			int a;scanf("%d",&a);
			a--;
			edges[i].push_back(a);
			revedges[a].push_back(i);
		}
	}

	int start; cin >> start;
	start--;
	{

		vector<vector<int>>nexts(N, vector<int>(2, -1));
		queue<pair<int, int>>que;

		vector<vector<int>>wins(N, vector<int>(2));
		for (int i = 0; i < N; ++i) {
			if (edges[i].size() == 0) {
				wins[i][0] = 1;
				que.push(make_pair(i, 0));
			}
		}

		while (!que.empty()) {
			auto p(que.front());
			que.pop();
			int now(p.first);
			int is_a = p.second;

			for (auto re : revedges[now]) {
				if (wins[re][!is_a] == 0) {
					wins[re][!is_a] = 1;
					nexts[re][!is_a] = now;
					que.push(make_pair(re,!is_a));
				}
			}
		}


		if (wins[start][1] == 1) {
			{
				cout << "Win" << endl;
				int now = start;
				vector<int>roots;
				bool is_a=true;
				while (nexts[now][is_a] != -1) {
					roots.push_back(now);
					now = nexts[now][is_a];
					is_a=!is_a;
				}
				roots.push_back(now);
				for (int i = 0; i < roots.size(); ++i) {
					cout << roots[i] + 1;
					if (i == roots.size() - 1)cout << endl;
					else cout << " ";
				}
			}
			return 0;
		}
	}


	{
		auto p=dscc.get(edges);
		vector<vector<int>>nexts(N, vector<int>(2, -1));
		queue<pair<int, int>>que;

		vector<vector<int>>wins(N, vector<int>(2));
		
		for (auto belong : p.first) {
			if (belong.size() >= 2) {
				for (auto be : belong) {
					wins[be][0]=1;
					wins[be][1]=1;
					que.push(make_pair(be,0));
					que.push(make_pair(be,1));
				}
			}
		}

		while (!que.empty()) {
			auto p(que.front());
			que.pop();
			int now(p.first);
			int is_a = p.second;

			for (auto re : revedges[now]) {
				if (wins[re][!is_a] == 0) {
					wins[re][!is_a] = 1;
					nexts[re][!is_a] = now;
					que.push(make_pair(re, !is_a));
				}
			}
		}


		if (wins[start][1] == 1) {
			{
				cout << "Draw" << endl;
				
			}
			return 0;
		}
	}

	cout<<"Lose"<<endl;

	return 0;
}