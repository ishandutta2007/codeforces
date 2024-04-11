/*
 * B. Tetris revisited.cpp
 *
 *  Created on: 2011-5-23
 *      Author: user
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cassert>
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)
using namespace std;

const int MAX_N = 1000 + 10;
char map[MAX_N][MAX_N];
int nR, nC;
int id[MAX_N][MAX_N];
int color[MAX_N][MAX_N];
int nId;

int main() {
	scanf("%d%d", &nR, &nC);
	for (int r = 0; r < nR; ++r) {
		scanf(" ");
		scanf("%s", map[r]);
	}

	for (int r = 0; r < nR; ++r) {
		for (int c = 0; c < nC; ++c) {
			if (map[r][c] == '.') {
				bool check = false;
				for (int dr = -1; dr <= 1; ++dr) {
					for (int dc = -1; dc <= 1; ++dc) {
						if (dr == 0 ^ dc == 0) {
							int nr = r + dr, nc = c + dc;
							if (nr >= 0 && nr < nR && nc >= 0 && nc < nC) {
								if (map[nr][nc] == '.') {
									check = true;
									break;
								}
							}
						}
					}
				}
				if (!check) {
					puts("-1");
					return 0;
				}
			}
		}
	}

	memset(id, -1, sizeof id);
	nId = 0;
	for (int r = 0; r < nR; ++r) {
		for (int c = 0; c < nC; ++c) {
			if (map[r][c] == '.' && id[r][c] == -1) {
				if (r + 1 < nR && map[r + 1][c] == '.' && id[r + 1][c] == -1) {
					color[r][c] = 3 * (r % 3) + c % 3;
					id[r][c] = id[r + 1][c] = nId++;
					color[r + 1][c] = color[r][c];
				} else if (c + 1 < nC && map[r][c + 1] == '.' && id[r][c + 1]
						== -1) {
					color[r][c] = 3 * (r % 3) + c % 3;
					id[r][c] = id[r][c + 1] = nId++;
					color[r][c + 1] = color[r][c];
				}
			}
		}
	}

	for (int r = 0; r < nR; ++r) {
		for (int c = 0; c < nC; ++c) {
			if (map[r][c] == '.' && id[r][c] == -1) {
				for (int dr = -1; dr <= 1; ++dr) {
					for (int dc = -1; dc <= 1; ++dc) {
						if (dr == 0 ^ dc == 0) {
							int nr = r + dr, nc = c + dc;
							if (nr >= 0 && nr < nR && nc >= 0 && nc < nC) {
								if (map[nr][nc] == '.') {
									assert(id[nr][nc]!=-1);
									id[r][c] = id[nr][nc];
									color[r][c] = color[nr][nc];
								}
							}
						}
					}
				}
				assert(id[r][c] != -1);
			}
		}
	}

	for (int r = 0; r < nR; ++r) {
		for (int c = 0; c < nC; ++c) {
			if (map[r][c] == '.')
				printf("%d", color[r][c]);
			else
				printf("#");
		}
		printf("\n");
	}
}