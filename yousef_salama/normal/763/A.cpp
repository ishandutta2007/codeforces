#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int n, u, v, c[MAXN], d, cnt[MAXN];
vector <int> G[MAXN];

int root;
int combine(int x, int y){
	if(x == -2)return y;
	if(y == -2)return x;
	if(x != y)return -1;
	return x;
}
void add(int x, int parent = -1){
	if(cnt[c[x]] == 0)d++;
	cnt[c[x]]++;

	for(int y : G[x]){
		if(y == parent)continue;
		add(y, x);
	}
}
void remove(int x, int parent = -1){
	cnt[c[x]]--;
	if(cnt[c[x]] == 0)d--;

	for(int y : G[x]){
		if(y == parent)continue;
		remove(y, x);
	}
}
int sz[MAXN];
void prepare(int x, int parent = -1){
	sz[x] = 1;
	for(int y : G[x]){
		if(y == parent)continue;

		prepare(y, x);
		sz[x] += sz[y];
	}
}
int dfs(int x, int parent = -1, bool erase = false){
	int r = -2;
	bool ok = true;

	int bigchild = -1;
	for(int y : G[x]){
		if(y == parent)continue;

		if(bigchild == -1 || sz[y] > sz[bigchild])
			bigchild = y;
	}
	for(int y : G[x]){
		if(y == parent)continue;
		if(y == bigchild)continue;

		int ry = dfs(y, x, true);
		r = combine(r, ry);

		if(ry == -1)ok = false;
	}

	if(bigchild != -1){
		int ry = dfs(bigchild, x, false);
		r = combine(r, ry);
		if(ry == -1)ok = false;
	}

	for(int y : G[x]){
		if(y == parent)continue;
		if(y == bigchild)continue;

		remove(y, x);
	}

	cnt[c[x]]--;
	if(cnt[c[x]] == 0)d--;

	if((d <= 1) && ok)root = x + 1;

	r = combine(r, c[x]);
	if(erase)add(x, parent);

	return r;
}
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++){
		scanf("%d %d", &u, &v);
		u--, v--;

		G[u].push_back(v);
		G[v].push_back(u);
	}

	d = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &c[i]);

		if(cnt[c[i]] == 0)d++;
		cnt[c[i]]++;
	}

	root = -1;
	prepare(0);
	dfs(0);

	if(root == -1)printf("NO\n");
	else printf("YES\n%d\n", root);


	return 0;
}