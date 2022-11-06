#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.txt"

//


vector<int>unis;
vector<int>c_nums;
int N, K;
long long int getans(const int now, const int from,const vector<vector<int>>&edges) {
	//int uni = c_nums[now];
	long long int ans = 0;
	for (auto e : edges[now]) {
		if (e == from)continue;
		else {
			ans += K-abs(K - c_nums[e]);
			ans += getans(e, now,  edges);
		}
	}
	return ans;
}
int dfs(const int now, const int from,const vector<vector<int>>&edges) {
	int c = unis[now];
	for (auto e : edges[now]) {
		if (e == from)continue;
		else {
			c += dfs(e, now, edges);
		}
	}
	return c_nums[now] = c;
}

int main() { cin >> N >> K;
	unis.resize(N);
	c_nums.resize(N);
	for (int i = 0; i < 2 * K; ++i) {
		int a; cin >> a; a--;
		unis[a] = true;
	}
	vector<vector<int>>edges(N);
	for (int i = 0; i < N-1; ++i) {
		int a, b; cin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	long long int ans;
	dfs(0, -1, edges);
	for (int i = 0; i < edges.size(); ++i) {
		ans = getans(i, -1,edges);
		break;
		
	}
	cout << ans << endl;
	
	return 0;
}