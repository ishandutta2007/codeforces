#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;

const int dx[4] = { 0,0,0 };
const int dy[4] = { 0,1,-1 };
int field[5][110];
bool memo[5][110];
int main() {
	int T; cin >> T;
	while(T--){
		vector<pair<int, int>>que;
		memset(field, 0, sizeof(field));
		memset(memo, 0, sizeof(memo));
		int N, K; cin >> N >> K;
		for (int i = 0; i < 110; ++i) {
			field[0][i] = 1;
			field[4][i] = 1;
		}
		for (int i = 0; i < 3; ++i) {
			string st; cin >> st;
			for (int j = 0; j < int(st.size()); ++j) {
				if (st[j] == '.') {

				}
				else if (st[j] == 's') {
					memo[i + 1][j + 1] = true;
					que.emplace_back(i+1, j+1);
				}
				else {
					field[i + 1][j + 1]=1;
				}
			}
		}
		string st = "NO";
		while (!que.empty()) {
			pair<int, int>atop(que.back());
			
			que.pop_back();
			const int ny = atop.first;
			const int nx = atop.second+1;
			if (field[ny][nx])continue;
			if (nx > N+2) {
				st = "YES"; break;
			}
			for (int i = 0; i < 3; ++i) {
				const int newy = ny + dy[i]; 
				const int newx = nx + dx[i];
				if (!field[newy][newx] && !field[newy][newx + 1] && !field[newy][newx + 2]) {
					if (!memo[newy][newx + 2]) {
						memo[newy][newx + 2] = true;
						que.emplace_back(newy, newx + 2);
					}
				}
			}
		}
		cout << st << endl;
	}
	return 0;
}