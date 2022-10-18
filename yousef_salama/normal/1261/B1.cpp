#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, a[MAXN], m, kj, posj;

vector < pair <int, int> > evs[MAXN];
int res[MAXN], tree[4 * MAXN];

void add(int i, int L, int R, int u){
	if(u < L || R < u)return;
	
	tree[i]++;
	
	if(L < R){
		int mid = (L + R) / 2;
		add(2 * i, L, mid, u);
		add(2 * i + 1, mid + 1, R, u);
	}	
}
int query(int i, int L, int R, int k){
	if(L == R)return L;
	
	int mid = (L + R) / 2;
	
	if(tree[2 * i] > k)return query(2 * i, L, mid, k);
	else return query(2 * i + 1, mid + 1, R, k - tree[2 * i]);
}

int main(){
	scanf("%d", &n);
	
	vector < pair <int, int> > v;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		v.push_back(make_pair(-a[i], i));
	}
	sort(v.begin(), v.end());
	
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d", &kj, &posj);
		evs[kj - 1].push_back(make_pair(posj - 1, i));
	}
	
	for(int i = 0; i < n; i++){
		add(1, 0, n - 1, v[i].second);
		
		for(pair <int, int> q : evs[i])
			res[q.second] = a[query(1, 0, n - 1, q.first)];
	}
	
	for(int i = 0; i < m; i++)
		printf("%d\n", res[i]);
		
	return 0;
}