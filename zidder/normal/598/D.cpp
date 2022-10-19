#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;
#define mp make_pair

int w, h, k;
vector<string> gr;
vector<vector<bool> > visited;
map<pair<int, int>, int> indx;
int cnt[1000000];
int mw = 0;
void dfs(int y, int x) {
	if (y >= h || y < 0 || x >= w || x < 0)
		return;
	if (gr[y][x] == '*') {
		cnt[mw]++;
		return;
	}
	if (visited[y][x])
		return;

	indx[mp(y, x)] = mw;
	visited[y][x] = true;
	dfs(y + 1, x);
	dfs(y - 1, x);
	dfs(y, x + 1);
	dfs(y, x - 1);
}
void dfs() {
	visited = vector<vector<bool> >(h, vector<bool>(w, false));
	for (size_t i = 0; i < h; i++) {
		for (size_t j = 0; j < w; j++) {
			if (gr[i][j] != '.')
				continue;
			if (visited[i][j])
				continue;
			dfs(i, j);
			mw++;
		}
	}
}
int main() {
	cin >> h >> w >> k;
	gr = vector<string>(h);
	for (size_t i = 0; i < h; i++)
	{
		cin >> gr[i];
	}
	dfs();
	for (size_t i = 0; i < k; i++)
	{
		int x, y;
		cin >> y >> x;
		cout << cnt[indx[mp(y - 1, x - 1)]] << endl;
	}
	return 0;
}