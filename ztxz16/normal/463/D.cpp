#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

const int N = 1005;

int n, k;
int pos[N][10], du[N], q[N], dis[N];
vector <int> v[N];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= n; j++) {
			int x;
			scanf("%d", &x);
			pos[x][i] = j;
		}
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int tag1 = 1, tag2 = 1;
			for (int l = 1; l <= k; l++) {
				if (pos[i][l] < pos[j][l]) {
					tag2 = 0;
				} else {
					tag1 = 0;
				}
			}
			
			if (tag1) {
				v[i].push_back(j);
				du[j]++;
			}
			
			if (tag2) {
				v[j].push_back(i);
				du[i]++;
			}
		}
	}
	
	int ans = 1;
	int h = 1, t = 0;
	for (int i = 1; i <= n; i++) {
		if (du[i] == 0) {
			q[++t] = i, dis[i] = 1;
		}
	}
	
	for (; h <= t; h++) {
		int now = q[h];
		ans = max(ans, dis[now]);
		for (int x = 0; x < (int)v[now].size(); x++) {
			int y = v[now][x];
			dis[y] = max(dis[now] + 1, dis[y]);
			du[y]--;
			if (!du[y]) {
				q[++t] = y;
			}
		}
	}
	
	printf("%d\n", ans);
	return 0;
}