#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000005;

int n, m;
long long A[N], ans[N];
int dis[N];
vector <int> v[N];
vector <pair <int, int> > q[N];

long long sum = 0;

void add(int a, int b) {
	//printf("%d %d\n", a, b);
	sum += b;
	for (int i = a; i <= n; i += (i & -i)) {
		A[i] += b;
	}
}

long long ask(int a) {
	long long ret = 0;
	for (int i = a; i > 0; i -= (i & -i)) {
		ret += A[i];
	}
	
	return ret;
}

void dfs(int now) {
	for (int i : v[now]) {
		if (dis[i] == 0) {
			dis[i] = dis[now] + 1;
			dfs(i);
		}
	}
}

void work(int now) {
	for (int i = 0; i < q[now].size(); i++) {
		int deep = min(n, q[now][i].first + dis[now]);
		add(deep, q[now][i].second);
	}
	
	ans[now] = sum - ask(dis[now] - 1);
	//printf("now = %d, sum = %I64d, %d, %I64d\n", now, sum, dis[now] - 1, ask(dis[now] - 1));
	for (int i : v[now]) {
		if (dis[i] > dis[now]) {
			work(i);
		}
	}
	
	for (int i = 0; i < q[now].size(); i++) {
		int deep = min(n, q[now][i].first + dis[now]);
		add(deep, -q[now][i].second);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		int root, d, x;
		scanf("%d %d %d", &root, &d, &x);
		q[root].push_back(make_pair(d, x));
	}
	
	dis[1] = 1;
	dfs(1);
	work(1);
	for (int i = 1; i <= n; i++) {
		printf("%I64d ", ans[i]);
	}
	printf("\n");
	
	return 0;
}