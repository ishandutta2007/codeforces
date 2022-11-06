#include "bits/stdc++.h"
using namespace std;

struct aa {
	int x;
	int y;
	int flag;
	int cost;
};
class Compare {
public:
	bool operator()(const aa&l, const aa&r) {
		return l.cost > r.cost;
	}
};

const int dx[4] = { -1,0,1,0 };
const int dy[4] = { 0,1,0,-1 };
int main() {
	int H, W, K; cin >> H >> W >> K;
	vector<vector<int>>field(H + 2, vector<int>(W + 2));
	for (int i = 0; i < H; ++i) {
		string st; cin >> st;
		for (int j = 0; j < W; ++j) {
			if (st[j] == '.')field[i + 1][j + 1] = 1;
		}
	}
	priority_queue<aa,vector<aa>,Compare>que;
	vector<vector<vector<int>>>memo(H + 2, vector<vector<int>>(W + 2,vector<int>(5,1e9)));
	int sx, sy, gx, gy; cin >> sy >> sx >> gy >> gx;
	que.push(aa{ sx,sy,4 });
	memo[sy][sx][4] = 0;
	while (!que.empty()) {
		auto atop(que.top());
		que.pop();
		int nextcost = atop.cost + 1;
		for (int way = 0; way < 4; ++way) {
			if (way == atop.flag)continue;
			int nx = atop.x;
			int ny = atop.y;
			nx += dx[way];
			ny += dy[way];
			int nk = 1;
			while (field[ny][nx] == 1&&nk<=K) {
				int nextflag = nk == K ? 4 : way;
				if (memo[ny][nx][nextflag] <= nextcost) {
					break;
				}
				else if (memo[ny][nx][nextflag]>nextcost) {
					memo[ny][nx][nextflag] = nextcost;
					que.push(aa{ nx,ny,nextflag,nextcost });
				}nx += dx[way];
				ny += dy[way];

				nk++;
			}
		}
	}
	int ans = 1e9;
	for (int i = 0; i < 5; ++i)ans = min(ans, memo[gy][gx][i]);
	if (ans == 1e9)ans = -1;
	cout << ans << endl;
	
	return 0;
}