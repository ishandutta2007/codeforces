#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, p[MAXN], l[MAXN], q, xj, yj;

vector < pair <int, int> > evs[MAXN];
int res[MAXN];

int tree[4 * MAXN], flag[4 * MAXN];
void push(int i, int L, int R){
	if(flag[i] == -1)return;
	
	if(L < R){
		flag[2 * i] = flag[i];
		flag[2 * i + 1] = flag[i];
	}
	tree[i] = flag[i];
	flag[i] = -1;
}
void myset(int i, int L, int R, int u, int v, int val){
	push(i, L, R);
	
	if(v < L || R < u)return;
	if(u <= L && R <= v){
		flag[i] = val;
		push(i, L, R);
		
		return;
	}
	
	int mid = (L + R) / 2;
	myset(2 * i, L, mid, u, v, val);
	myset(2 * i + 1, mid + 1, R, u, v, val);
	
	tree[i] = tree[2 * i] + tree[2 * i + 1];
}
int sum(int i, int L, int R, int u, int v){
	push(i, L, R);
	
	if(v < L || R < u)return 0;
	if(u <= L && R <= v)return tree[i];
	
	int mid = (L + R) / 2;
	return sum(2 * i, L, mid, u, v) + sum(2 * i + 1, mid + 1, R, u, v);
}

int main(){	
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d %d", &p[i], &l[i]);
		
	scanf("%d", &q);
	for(int i = 0; i < q; i++){
		scanf("%d %d", &xj, &yj);
		xj--, yj--;
		
		evs[xj].push_back(make_pair(yj, i));
	}
	
	memset(flag, -1, sizeof flag);
	
	for(int i = n - 1; i >= 0; i--){
		int j = upper_bound(p, p + n, p[i] + l[i]) - p;
		
		myset(1, 0, n - 1, i, j - 1, 0);
		
		if(j < n){
			int vi = p[j] - (p[i] + l[i]);
			int vj = sum(1, 0, n - 1, j, j);
			if(vi < vj)myset(1, 0, n - 1, j, j, vi);
		}
		
		for(pair <int, int> e : evs[i])
			res[e.second] = sum(1, 0, n - 1, i, e.first);
		
		if(i > 0)myset(1, 0, n - 1, i, i, p[i] - p[i - 1]);
	}
	
	for(int i = 0; i < q; i++)
		printf("%d\n", res[i]);
	
	return 0;
}