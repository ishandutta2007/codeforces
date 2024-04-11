#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt"


const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };

int field[1002][1002][4];
int memo[1002][1002][4];
struct aa {
	int x;
	int y;
	int way;
	int time;
};
int main() {
	for (int i = 0; i < 1002; ++i) {
		for (int j = 0; j < 1002; ++j) {
			for (int k = 0; k < 4; ++k) {
				memo[i][j][k] = 1e9;
			}
		}
	}
	memset(field, 0, sizeof(field));
	int H, W; cin >> H >> W;
	map<char, vector<int>>mp;
	mp['+'] = { 1,1,1,1 };
	mp['-'] = { 1,0,1,0 };
	mp['|'] = { 0,1,0,1 };
	mp['^'] = { 0,0,0,1 };
	mp['>'] = { 0,0,1,0 };
	mp['<'] = { 1,0,0,0 };
	mp['v'] = { 0,1,0,0 };
	mp['L'] = { 0,1,1,1 };
	mp['R'] = { 1,1,0,1 };
	mp['U'] = { 1,1,1,0 };
	mp['D'] = { 1,0,1,1 };
	mp['*'] = { 0,0,0,0 };
	for (int i = 0; i < H; ++i) {
		string st; cin >> st;
		for (int j = 0; j < W; ++j) {
			for (int way = 0; way < 4; ++way) {
				field[i + 1][j + 1][way] = mp[st[j]][way];
			}
		}
	}
	int sx, sy, gx, gy; cin >> sy >> sx >> gy >> gx;
	memo[sx][sy][0] = 0;
	queue<aa>que;
	que.push(aa{ sx,sy,0,0 });
	int ans = -1;
	while (!que.empty()) {
		aa atop(que.front());
		que.pop();
		const int ax = atop.x;
		const int ay = atop.y;
		const int away = atop.way;
		const int atime = atop.time;
		if (ax == gx&&ay == gy) {
			ans = atime;
			break;
		}
		for (int way = 0; way < 4; ++way) {
			const int newx = ax + dx[way];
			const int newy = ay + dy[way];
			const int newtime = atime + 1;
			if (field[ay][ax][(away + way) % 4]&&field[newy][newx][(away+way+2)%4]) {
				if (memo[newx][newy][away]>newtime) {
					memo[newx][newy][away] = newtime;
					que.push(aa{ newx,newy,away,newtime });
				}
			}
		}
		{
			const int newtime = atime + 1;
			const int newway = (away + 1) % 4;
			if (memo[ax][ay][newway]>newtime) {
				memo[ax][ay][newway] = newtime;
				que.push(aa{ ax,ay,newway,newtime });
			}
		}
	}
	cout << ans << endl;

	return 0;
}