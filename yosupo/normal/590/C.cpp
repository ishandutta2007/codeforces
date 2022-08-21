#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;

typedef double R;
typedef pair<int, int> P;


const int MN = 1010;
const int d4[4][2] = {
	{1, 0},
	{0, 1},
	{-1, 0},
	{0, -1}
};

ll dist[3][MN][MN];
char buf[MN];

int n, m;
P p[3];

bool used[3][MN][MN];

int isG[MN][MN];

bool isB(int x, int y) {
	return (0 <= x && x < m && 0 <= y && y < n);
}

int main() {
	for (int i = 0; i < 3; i++) {
		for (int y = 0; y < MN; y++) {
			for (int x = 0; x < MN; x++) {
				dist[i][y][x] = 1LL<<55;
				used[i][y][x] = false;
			}
		}
	}
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", buf);
		for (int j = 0; j < m; j++) {
			isG[i][j] = 0;
			if (buf[j] == '#') isG[i][j] = -1;
			if (buf[j] == '.') isG[i][j] = 1;
			if (buf[j] == '1') {
				p[0] = P(j, i);
			} else if (buf[j] == '2') {
				p[1] = P(j, i);
			} else if (buf[j] == '3') {
				p[2] = P(j, i);
			}
		}
	}
	typedef pair<ll, P> Q;
	for (int i = 0; i < 3; i++) {
		priority_queue<Q, vector<Q>, greater<Q>> que;
		que.push(Q(0LL, p[i]));
		while(que.empty() == false) {
			P p; ll di;
			tie(di, p) = que.top(); que.pop();
			int x, y;
			tie(x, y) = p;
			if (used[i][y][x]) continue;
			used[i][y][x] = true;
			dist[i][y][x] = di;
			for (int d = 0; d < 4; d++) {
				int xx = x + d4[d][0], yy = y + d4[d][1];
				if (isB(xx, yy) == false) continue;
				if (isG[yy][xx] == -1) continue;
				que.push(Q(di + isG[yy][xx], P(xx, yy)));
			}
		}
		// for (int y = 0; y < n; y++) {
		// 	for (int x = 0; x < m; x++) {
		// 		printf("%2lld ", (dist[i][y][x] == 1LL<<55) ? -1 : dist[i][y][x]);
		// 	} printf("\n");
		// }
		// printf("\n");
	}

	ll ma = 1LL<<55;
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (isG[y][x] == -1) continue;
			if (isG[y][x] == 0) {
				ma = min(ma, dist[0][y][x] + dist[1][y][x] + dist[2][y][x]);
			} else {
				ma = min(ma, dist[0][y][x] + dist[1][y][x] + dist[2][y][x] - 2);
			}
		}
	}
	if (ma >= 1LL<<54) ma = -1;
	cout << ma << endl;
    return 0;
}