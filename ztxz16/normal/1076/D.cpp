#include <queue>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1000005;
const long long INF = 1LL << 60;
long long dis[N];
vector <pair <int, int> > v[N];
vector <int> id[N];
priority_queue <pair <long long, int> > q;
int que[N], n, m, k, good[N], pre[N];

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; i++) {
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		v[x].push_back(make_pair(y, w));
		v[y].push_back(make_pair(x, w));
		id[x].push_back(i);
		id[y].push_back(i);
	}
	
	for (int i = 1; i <= n; i++) {
		dis[i] = INF;
	}
	
	dis[1] = 0;
	q.push(make_pair(0, 1));
	while (q.size() > 0) {
		int now = q.top().second;
		if (dis[now] != -q.top().first) {
			q.pop();
			continue;
		}
	
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int cur = v[now][i].first;
			if (dis[now] + v[now][i].second < dis[cur]) {
				dis[cur] = dis[now] + v[now][i].second;
				q.push(make_pair(-dis[cur], cur));
			}
		}
	}
	
	que[1] = 1;
	good[1] = 1;
	int h = 1, t = 1; 
	for (; h <= t; h++) {
		int now = que[h];
		for (int i = 0; i < v[now].size(); i++) {
			int cur = v[now][i].first;
			if (dis[now] + v[now][i].second == dis[cur] && !good[cur]) {
				pre[cur] = id[now][i];
				que[++t] = cur;
				good[cur] = 1;
			}
		}
	}
	
	k = min(t - 1, k);
	printf("%d\n", k);
	for (int i = 2; i <= k + 1; i++) {
		printf("%d ", pre[que[i]]);
	}
	
	printf("\n");
	return 0;
}