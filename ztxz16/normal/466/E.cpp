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
#define pb push_back
#define mp make_pair

int FASTBUFFER;

using namespace std;

const int N = 200005;

int e[N], succ[N], last[N], sum;
int fa[N], f[N][25], dis[N], q[N], exist[N];
int n, m, type[N], x[N], y[N];
vector <pair <int, int> > v[N];
string ans[N];

int find(int i) {
	return fa[i] == i ? i : fa[i] = find(fa[i]);
}

void add(int a,int b) {
	e[++sum] = b, succ[sum] = last[a], last[a] = sum;
}

int lca(int a, int b) {
	int i;
	if (dis[a] < dis[b])
		swap(a, b);
	for (i = 22; i >= 0; i--)
		if (dis[f[a][i]] >= dis[b])
			a = f[a][i];
	for (i = 22; i >= 0; i--)
		if (f[a][i] != f[b][i])
			a = f[a][i], b = f[b][i];
	if (a == b)
		return a;
	return f[a][0];
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &type[i]);
		if (type[i] == 1) {
			scanf("%d %d", &x[i], &y[i]);
			add(y[i], x[i]);
			exist[x[i]] = 1;
		} else if (type[i] == 2) {
			scanf("%d", &x[i]);
		} else {
			scanf("%d %d", &x[i], &y[i]);
			v[y[i]].pb(mp(x[i], i));
		}
	}
	
	int h = 1, t = 0;
	for (int i = 1; i <= n; i++) {
		if (!exist[i]) {
			q[++t] = i;
			dis[i] = 1;
		}
	}
	
	for (; h <= t; h++) {
		int now = q[h];
		for (int x = last[now]; x != 0; x = succ[x]) {
			if (e[x] == f[now][0]) {
				continue;
			}
			
			f[e[x]][0] = now;
			dis[e[x]] = dis[now] + 1;
			q[++t] = e[x];
		}
	}
	
	for (int j = 1; j <= 22; j++)
		for (int i = 1; i <= n; i++)
			f[i][j] = f[f[i][j - 1]][j - 1];
	
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	
	int tot = 0;
	for (int i = 1; i <= m; i++) {
		if (type[i] == 1) {
			fa[find(x[i])] = find(y[i]);
		} else if (type[i] == 2) {
			int nowa = x[i];
			tot++;
			for (int j = 0; j < (int)v[tot].size(); j++) {
				int nowb = v[tot][j].first;
				if (find(nowa) != find(nowb) || lca(nowa, nowb) != nowb) {
					ans[v[tot][j].second] = "NO";
				} else {
					ans[v[tot][j].second] = "YES";
				}
			}
		} else {
			printf("%s\n", ans[i].c_str());
		}
	}
	
	return 0;
}