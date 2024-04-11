#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

const int MAX_N = 1000 + 10;

char map[MAX_N][MAX_N];
int n, m;

bool okr[MAX_N], okc[MAX_N];

bool swaped;

int cnt;

bool put(int r, int c) {
	if (map[r][c] == '.')
		return false;
	if (map[r][c] == '#') {
		map[r][c] = 'X';
		++cnt;
	}
	return true;
}

bool put(int rl, int rr, int cl, int cr) {
	for (int c = cl; c <= cr; ++c) {
		if (!put(rl, c) || !put(rr, c))
			return false;
	}
	for (int r = rl; r <= rr; ++r) {
		if (!put(r, cl) || !put(r, cr))
			return false;
	}
	return true;
}

void reset(int r, int c) {
	if (map[r][c] == 'X')
		map[r][c] = '#';
}

void reset(int rl, int rr, int cl, int cr) {
	for (int c = cl; c <= cr; ++c) {
		reset(rl, c), reset(rr, c);
	}
	for (int r = rl; r <= rr; ++r) {
		reset(r, cl), reset(r, cr);
	}
}

int main() {
	cin >> n >> m;

	int total = 0;

	for (int r = 0; r < n; ++r) {
		scanf("%s", map[r]);
		for (int c = 0; c < m; ++c) {
			if (map[r][c] == '#')
				++total;
		}
	}

	for (int r = 0; r < n; ++r) {
		for (int c = 0; c < m; ++c) {
			if (c > 0 && c + 1 < m && map[r][c - 1] == '#' && map[r][c] == '#'
					&& map[r][c + 1] == '#')
				okr[r] = true;
			if (r > 0 && r + 1 < n && map[r - 1][c] == '#' && map[r][c] == '#'
					&& map[r + 1][c] == '#')
				okc[c] = true;
		}
	}

	vector<int> rs, cs;
	for (int r = 0; r < n; ++r) {
		if (okr[r])
			rs.push_back(r);
	}

	for (int c = 0; c < m; ++c) {
		if (okc[c])
			cs.push_back(c);
	}

	if (rs.size() > 4)
		rs.erase(++++rs.begin(), ----rs.end());
	if (cs.size() > 4)
		cs.erase(++++cs.begin(), ----cs.end());

	for (vector<int>::iterator r1 = rs.begin(); r1 != rs.end(); ++r1) {
		for (vector<int>::iterator r2 = rs.begin(); r2 != rs.end(); ++r2) {
			for (vector<int>::iterator c1 = cs.begin(); c1 != cs.end(); ++c1) {
				for (vector<int>::iterator c2 = cs.begin(); c2 != cs.end(); ++c2) {
					if (*r2 - *r1 > 1 && *c2 - *c1 > 1) {
						for (vector<int>::iterator r3 = rs.begin(); r3 != rs.end(); ++r3) {
							for (vector<int>::iterator r4 = rs.begin(); r4 != rs.end(); ++r4) {
								for (vector<int>::iterator c3 = cs.begin(); c3 != cs.end(); ++c3) {
									for (vector<int>::iterator c4 = cs.begin(); c4 != cs.end();
											++c4) {
										if (*r4 - *r3 > 1 && *c4 - *c3 > 1) {
											cnt = 0;
											if (put(*r1, *r2, *c1, *c2) && put(*r3, *r4, *c3, *c4)
													&& cnt == total) {
												cout << "YES" << endl;
												cout << *r1 + 1 << " " << *c1 + 1 << " " << *r2 + 1
														<< " " << *c2 + 1 << endl;
												cout << *r3 + 1 << " " << *c3 + 1 << " " << *r4 + 1
														<< " " << *c4 + 1 << endl;
												return 0;
											}
											reset(*r1, *r2, *c1, *c2);
											reset(*r3, *r4, *c3, *c4);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	puts("NO");

	return 0;
}