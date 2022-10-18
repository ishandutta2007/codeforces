#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, ui, vi, li;
vector < pair <int, int> > G[MAXN];

int deg[MAXN];
bool vis[MAXN];
long long d[MAXN];

struct node{
	long long max, maxpref, maxsuf, sum;
} v[MAXN], pref[MAXN], suf[MAXN];

node operator +(node a, node b){
	node c;

	c.max = max(max(a.max, b.max), a.maxsuf + b.maxpref);
	c.maxpref = max(a.maxpref, a.sum + b.maxpref);
	c.maxsuf = max(b.maxsuf, b.sum + a.maxsuf);
	c.sum = a.sum + b.sum;

	return c;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d %d", &ui, &vi, &li);
		ui--, vi--;

		G[ui].push_back({vi, li});
		G[vi].push_back({ui, li});

		deg[ui]++;
		deg[vi]++;
	}

	queue <int> q;
	for(int i = 0; i < n; i++)if(deg[i] == 1){
		q.push(i);
		vis[i] = true;
	}

	long long r = 0;
	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(pair <int, int> e : G[u]){
			if(vis[e.first])continue;

			r = max(r, d[e.first] + d[u] + e.second);
			d[e.first] = max(d[e.first], d[u] + e.second);

			deg[e.first]--;
			if(deg[e.first] == 1){
				q.push(e.first);
				vis[e.first] = true;
			}
		}
	}

	long long rc = 1LL << 60;
	for(int i = 0; i < n; i++)if(!vis[i]){
		int u = i, p = -1, sv = 0;

		do{
			int nxt = -1;
			for(pair <int, int> e : G[u]){
				if(vis[e.first])continue;
				if(e.first == p)continue;

				v[sv++] = {d[u] + d[e.first] + e.second,
						e.second + d[e.first], d[u] + e.second, e.second};

				nxt = e.first;

				break;
			}

			p = u;
			u = nxt;
		}while(u != i);

		for(int j = 0; j < sv; j++){
			if(j == 0)pref[j] = v[j];
			else pref[j] = pref[j - 1] + v[j];
		}

		for(int j = sv - 1; j >= 0; j--){
			if(j == sv - 1)suf[j] = v[j];
			else suf[j] = v[j] + suf[j + 1];
		}

		for(int j = 0; j < sv; j++){
			node a, b;

			if(j == 0)a = {d[i], d[i], d[i], 0};
			else a = pref[j - 1];

			if(j == sv - 1)b = {d[i], d[i], d[i], 0};
			else b = suf[j + 1];

			rc = min(rc, (b + a).max);
		}
		break;
	}

	printf("%I64d\n", max(r, rc));

	return 0;
}