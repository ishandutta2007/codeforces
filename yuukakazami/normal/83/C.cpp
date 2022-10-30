/*
 * C. Track.cpp
 *
 *  Created on: 2011-5-16
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;

const int N_ALPHA = 27;
const int MAX_N = 50 + 1;
bool can[N_ALPHA];
int n, m, k;
int map[MAX_N * MAX_N];
string ans;
bool hasAns;
int dist[MAX_N * MAX_N];
int lab[MAX_N * MAX_N];
int prev[MAX_N * MAX_N];
int que[MAX_N * MAX_N], qh, qt;

int VS, VT;

bool cmp(int a, int b) {
	if (lab[a] != lab[b])
		return lab[a] < lab[b];
	return map[a] < map[b];
}

bool equal(int a, int b) {
	return lab[a] == lab[b] && map[a] == map[b];
}

void doit() {
	qh = qt = 0;
	que[qt++] = VS;
	memset(dist, -1, sizeof dist);
	dist[VS] = 0;
	lab[VS] = 0;
	prev[VS] = -1;
	while (qh < qt) {
		int nLab = 0;
		static int tmp[MAX_N * MAX_N];
		sort(que + qh, que + qt, cmp);
		for (int i = qh; i < qt; ++i) {
			if (i != qh && equal(que[i - 1], que[i]))
				tmp[i] = nLab - 1;
			else
				tmp[i] = nLab++;
		}
		int nQt = qt;
		for (int i = qh; i < qt; ++i) {
			int me = que[i];
			lab[me] = tmp[i];
			int r = me / m, c = me % m;
			for (int dr = -1; dr <= 1; dr++)
				for (int dc = -1; dc <= 1; dc++)
					if (dr == 0 ^ dc == 0) {
						int nr = r + dr, nc = c + dc;
						if (nr < 0 || nr >= n || nc < 0 || nc >= m)
							continue;
						int v = nr * m + nc;
						if (!can[map[v]] || dist[v] != -1)
							continue;
						prev[v] = me;
						lab[v] = lab[me];
						dist[v] = dist[me] + 1;
						que[nQt++] = v;
					}
		}
		qh = qt;
		qt = nQt;
	}

	if (dist[VT] == -1)
		return;

	int len = dist[VT] - 1;
	if (hasAns && len > ans.size())
		return;
	string cur = "";
	int at = prev[VT];
	while (at != VS) {
		cur += 'a' + map[at];
		at = prev[at];
	}
	reverse(cur.begin(), cur.end());
	if (!hasAns) {
		hasAns = true;
		ans = cur;
	} else if (len < ans.size() || cur < ans) {
		ans = cur;
	}
}

void dfs(int cur, int rest) {
	if (cur == N_ALPHA) {
		if (rest == 0)
			doit();
		return;
	}
	if (rest > 0) {
		can[cur] = true;
		dfs(cur + 1, rest - 1);
		can[cur] = false;
	}
	dfs(cur + 1, rest);
}

int main() {
	hasAns = false;
	cin >> n >> m >> k;
	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			char ch;
			while (ch = getchar(), ch == '\n')
				;
			int me = r * m + c;
			map[me] = ch - 'a';
			if (ch == 'S')
				map[VS = me] = N_ALPHA;
			if (ch == 'T')
				map[VT = me] = N_ALPHA;
		}
	}
	memset(can, false, sizeof can);
	can[N_ALPHA] = true;
	dfs(0, k);

	if (!hasAns)
		puts("-1");
	else
		cout << ans << endl;
}