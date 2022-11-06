#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.answer"
int main() {
	int N, M; cin >> N >> M;
	vector<vector<int>>edges(N);
	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b;
		a--; b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	vector<int>types(N,-1);
	int now = 0;
	bool ok = true;
	while (ok&&now!=N) {
		if (types[now] == -1) {

			queue<int>que;
			que.push(now);
			types[now] = 1;
			while (!que.empty()) {
				const int n = que.front();
				que.pop();
				const int nt = types[n];
				for (auto e : edges[n]) {
					if (nt == types[e]) {
						ok = false;
						break;
					}
					else if(types[e]==-1){
						types[e]=!nt;
						que.push(e);
					}
				}
				if (!ok)break;
			}
		}
		now++;
	}
	vector<vector<int>>vs(2);
	if (ok) {
		for (int i = 0; i < N; ++i) {
			vs[types[i]].push_back(i + 1);
		}
		for (int i = 0; i < 2; ++i) {
			cout << vs[i].size() << endl;
			for (int j = 0; j < vs[i].size(); ++j) {
				cout << vs[i][j];
				if (j != vs[i].size() - 1)cout << " ";
				else cout << endl;
			}
		}
	}
	else {
		cout << -1 << endl;
	}
	
	return 0;
}