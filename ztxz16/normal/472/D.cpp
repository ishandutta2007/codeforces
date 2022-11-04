#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <string>
#define PQ priority_queue
#define OO 2147483647
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)

int FASTBUFFER;

using namespace std;

const int N = 2005;

int n, a[N][N], LCA[N][N], f[N], dis[N], vis[N], flag;
int e[N << 1], succ[N << 1], last[N], val[N << 1], sum;

pair <int, int> p[N];

void add(int a, int b, int c) {
	e[++sum] = b, succ[sum] = last[a], last[a] = sum;
	val[sum] = c;
}

int find(int i) {
	return f[i] == i ? i : f[i] = find(f[i]);
}

void dfs(int i, int d, int fa) {
	if (a[1][i] != d || !flag) {
		flag = 0;
		return;
	}
	
	dis[i] = d;
	vis[i] = 1;
	for (int x = last[i]; x; x = succ[x]) {
		if (e[x] == fa) {
			continue;
		}
		
		dfs(e[x], d + val[x], i);
	}
	
	for (int j = 1; j <= n; j++) {
		if (vis[j]) {
			LCA[i][j] = find(j);
		}
	}
	
	f[find(i)] = find(fa);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (a[i][i]) {
			printf("NO\n");
			return 0;
		}
		
		for (int j = i + 1; j <= n; j++) {
			if (a[i][j] != a[j][i] || a[i][j] == 0) {
				printf("NO\n");
				return 0;
			}
		}
	}
	
	for (int i = 2; i <= n; i++) {
		p[i] = make_pair(a[1][i], i);
	}
	
	sort(p + 2, p + n + 1);
	for (int i = 2; i <= n; i++) {
		int now = p[i].second, sel = 1;
		for (int j = 2; j < i; j++) {
			if (a[sel][now] > a[p[j].second][now]) {
				sel = p[j].second;
			}
		}
		
		add(sel, now, a[sel][now]);
	}
	
	flag = 1;
	for (int i = 1; i <= n; i++) {
		f[i] = i;
	}
	
	dfs(1, 0, 0);
	if (!flag) {
		printf("NO\n");
		return 0;
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int c;
			if (LCA[i][j]) {
				c = LCA[i][j];
			} else {
				c = LCA[j][i];
			}
			
			if (a[i][j] != dis[i] + dis[j] - dis[c] - dis[c]) {
				printf("NO\n");
				return 0;
			}
		}
	}
	
	printf("YES\n");
	return 0;
}