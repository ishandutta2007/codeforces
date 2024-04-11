#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;

int dis[3000][3000];
int main() {
	for (int i = 0; i < 3000; ++i){
		for (int j = 0; j < 3000;++j)
			dis[i][j] = 99999;
	}	
	int N, M; cin >> N >> M;
	vector<vector<int>>edges(N);
	for (int i = 0; i < M; ++i){
		int s, t; cin >> s >> t;
		s--; t--;
		edges[s].push_back(t);
		edges[t].push_back(s);
	}
	for (int start = 0; start < N; ++start){
		deque<pair<int, int>>que;
		que.push_back(make_pair(start, 0));
		dis[start][start] = 0;
		while (!que.empty()){
			pair<int, int>atop(que.front());
			que.pop_front();
			for (int i = 0; i < edges[atop.first].size(); ++i){
				if (dis[start][edges[atop.first][i]] > atop.second + 1){
					dis[start][edges[atop.first][i]] = atop.second + 1;
					que.push_back(make_pair(edges[atop.first][i], atop.second + 1));
				}
			}
		}
	}
	int ans = 99999;
	int s[2], l[2], t[2];
	cin >> s[0] >> t[0] >> l[0] >> s[1] >> t[1] >> l[1];
	s[0]--; s[1]--; t[0]--; t[1]--;
	for (int a = 0; a < N; ++a){
		for (int b = 0; b < N; ++b){
			{
				const int adis = dis[s[0]][a] + dis[a][b] + dis[b][t[0]];
				const int bdis = dis[s[1]][a] + dis[a][b] + dis[b][t[1]];
				if (adis <= l[0] && bdis <= l[1]){
					ans = min(ans, dis[s[0]][a] + dis[a][b] + dis[b][t[0]] + dis[s[1]][a] + dis[b][t[1]]);
				}
			}
			{
			const int adis = dis[s[0]][b] + dis[a][b] + dis[a][t[0]];
			const int bdis = dis[s[1]][a] + dis[a][b] + dis[b][t[1]];
			if (adis <= l[0] && bdis <= l[1]){
				ans = min(ans, dis[s[0]][b] + dis[a][b] + dis[a][t[0]] + dis[s[1]][a] + dis[b][t[1]]);
			}
		}
		}
	}
	{
		const int adis = dis[s[0]][t[0]];
		const int bdis = dis[s[1]][t[1]];
		if (adis <= l[0] && bdis <= l[1]){
			ans = min(ans, dis[s[0]][t[0]] + dis[s[1]][t[1]]);
		}
	}
	if (ans == 99999)ans = -1;
	else ans = M - ans;
	cout << ans << endl;
	return 0;
}