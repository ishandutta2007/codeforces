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

const int N = 500005;

int dfstot, tot, top, color, n, m;
int dfn[N], low[N], sta[N], belong[N], in[N], deg[N], q[N];
int e[N], succ[N], last[N], sum;
char xx[N], yy[N];
string sx, sy, s[N];
pair <int, long long> val[N], vv[N], f[N];
map <string, int> id;
vector <int> v[N];

void dfs(int i) {
	dfn[i] = low[i] = ++dfstot;
	sta[++top] = i, in[i] = 1;
	for (int x = last[i]; x; x = succ[x]) {
		int y = e[x];
		if (!dfn[y]) {
			dfs(y);
			low[i] = min(low[i], low[y]);
		} else if (in[y]) {
			low[i] = min(low[i], dfn[y]);
		}
	}
 
	if (dfn[i] == low[i]) {
		vv[++color] = make_pair(1000000000, 0);
		while (sta[top] != i) {
			belong[sta[top]] = color;
			vv[color] = min(vv[color], val[sta[top]]);
			in[sta[top]] = 0;
			top--;
		}
 
		belong[sta[top]] = color;
		vv[color] = min(vv[color], val[sta[top]]);
		in[sta[top]] = 0;
		top--;
	}
}

int get(string str) {
	if (id.find(str) != id.end()) {
		return id[str];
	}
	
	id[str] = ++tot;
	for (int i = 0; i < (int)str.size(); i++) {
		val[tot].first += (str[i] == 'r');
		val[tot].second++;
	}
	
	return tot;
}

int main() {
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%s", xx);
		for (int j = 0; xx[j]; j++) {
			if (xx[j] >= 'A' && xx[j] <= 'Z') {
				xx[j] += 32;
			}
		}
		
		s[i] = xx;
	}
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%s", xx);
		for (int j = 0; xx[j]; j++) {
			if (xx[j] >= 'A' && xx[j] <= 'Z') {
				xx[j] += 32;
			}
		}
		
		scanf("%s", yy);
		for (int j = 0; yy[j]; j++) {
			if (yy[j] >= 'A' && yy[j] <= 'Z') {
				yy[j] += 32;
			}
		}
		
		sx = xx, sy = yy;
		int a = get(sx), b = get(sy);
		e[++sum] = b, succ[sum] = last[a], last[a] = sum;
	}
	
	for (int i = 1; i <= tot; i++) {
		if (!dfn[i]) {
			dfs(i);
		}
	}
	
	for (int i = 1; i <= tot; i++) {
		for (int x = last[i]; x; x = succ[x]) {
			int a = belong[i], b = belong[e[x]];
			if (a != b) {
				v[b].push_back(a);
				deg[a]++;
			}
		}
	}
	
	int h = 1, t = 0;
	for (int i = 1; i <= color; i++) {
		f[i] = vv[i];
		if (!deg[i]) {
			q[++t] = i;
		}
	}
	
	for (; h <= t; h++) {
		int now = q[h];
		for (int i = 0; i < (int)v[now].size(); i++) {
			int x = v[now][i];
			f[x] = min(f[x], f[now]);
			deg[x]--;
			if (!deg[x]) {
				q[++t] = x;
			}
		}
	}
	
	pair <int, long long> ans = make_pair(0, 0LL);
	for (int i = 1; i <= m; i++) {
		if (id.find(s[i]) != id.end()) {
			int now = belong[id[s[i]]];
			ans.first += f[now].first;
			ans.second += f[now].second;
		} else {
			for (int j = 0; j < (int)s[i].size(); j++) {
				ans.first += (s[i][j] == 'r');
				ans.second++;
			}
		}
	}
	
	printf("%d %I64d\n", ans.first, ans.second);
	return 0;
}