#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;
const int MAXK = 55;

int n, m, k, q, a[MAXN], b[MAXN], e[MAXN], c[MAXN];

int sz[MAXK][MAXN], p[MAXK][MAXN];
bool l[MAXK][MAXN];

stack < pair <int, pair <int, int> >  > S;

pair <int, int> find(int id, int u){
	if(u == p[id][u])return {u, l[id][u]};
	else{
		pair <int, int> t = find(id, p[id][u]);
		return {t.first, t.second ^ l[id][u]};
	}
}
void join(int id, int u, int v){
	pair <int, int> tu = find(id, u);
	pair <int, int> tv = find(id, v);

	u = tu.first;
	v = tv.first;

	if(u == v){
		S.push({-1, {u, v}});
		return;
	}

	if(sz[id][v] < sz[id][u])swap(u, v);

	S.push({id, {u, v}});

	sz[id][v] += sz[id][u];
	p[id][u] = v;
	l[id][u] ^= l[id][v] ^ (tu.second == tv.second);
}
void rollback(int k){
	while(k > 0){
		pair <int, pair <int, int> > t = S.top();
		S.pop();

		if(t.first != -1){
			sz[t.first][t.second.second] -= sz[t.first][t.second.first];
			p[t.first][t.second.first] = t.second.first;
		}
		k--;
	}
}

queue <int> qi[MAXN];
int ci[MAXN];

vector <int> tree[4 * MAXN];
void update(int i, int L, int R, int x, int y, int z){
	if(y < x)return;
	if(y < L || x > R)return;
	if(x <= L && R <= y){
		tree[i].push_back(z);
		return;
	}

	int mid = (L + R) / 2;
	update(2 * i, L, mid, x, y, z);
	update(2 * i + 1, mid + 1, R, x, y, z);
}
void solve(int i, int L, int R){
	int k = 0;
	for(int x : tree[i]){
		join(c[x], a[e[x]], b[e[x]]);
		k++;
	}

	if(L == R){
		qi[e[L]].pop();

		pair <int, int> tu = find(c[L], a[e[L]]);
		pair <int, int> tv = find(c[L], b[e[L]]);

		if(tu.first != tv.first || tu.second != tv.second){
			printf("YES\n");
			ci[e[L]] = L;
		}else printf("NO\n");

		if(ci[e[L]] != -1)update(1, 0, q - 1, L + 1, qi[e[L]].front() - 1, ci[e[L]]);
	}else{
		int mid = (L + R) / 2;

		solve(2 * i, L, mid);
		solve(2 * i + 1, mid + 1, R);
	}

	rollback(k);
}
int main(){
	scanf("%d %d %d %d", &n, &m, &k, &q);

	for(int i = 0; i < m; i++){
		scanf("%d %d", &a[i], &b[i]);
		a[i]--, b[i]--;
	}

	for(int i = 0; i < q; i++){
		scanf("%d %d", &e[i], &c[i]);
		e[i]--, c[i]--;

		qi[e[i]].push(i);
	}
	for(int i = 0; i < m; i++){
		qi[i].push(q);
		ci[i] = -1;
	}

	for(int j = 0; j < k; j++)
	for(int i = 0; i < n; i++){
		sz[j][i] = 1;
		p[j][i] = i;
		l[j][i] = 0;
	}
	solve(1, 0, q - 1);

	return 0;
}