#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, m, a[MAXN], ia[MAXN], b[MAXN], ib[MAXN], p[MAXN];

int tree[2][MAXN];
void add(int id, int i, int v){
	while(i < MAXN){
		tree[id][i] += v;
		i += i & (-i);
	}
}
int count(int id, int i){
	int r = 0;
	while(i > 0){
		r += tree[id][i];
		i -= i & (-i);
	}
	return r;
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		ia[a[i]] = i + 1;
	}
	for(int i = 0; i < m; i++){
		scanf("%d", &b[i]);
		ib[b[i]] = i + 1;
	}

	p[0] = p[1] = 0;
	for(int i = 2; i <= n; i++){
		int j = p[i - 1];
		while(j > 0){
			if(count(0, ia[i]) == count(1, ia[j + 1]))break;
			else{
				int k = p[j];
				for(int z = j; z > k; z--){
					add(0, ia[i - z], -1);
					add(1, ia[z], -1);
				}
				j = k;
			}
		}
		add(0, ia[i], 1);
		add(1, ia[j + 1], 1);
		p[i] = j + 1;
	}

	memset(tree, 0, sizeof tree);

	int j = 0, r = 0;
	for(int i = 1; i <= m; i++){
		while(j == n || (j > 0 && count(0, ib[i]) != count(1, ia[j + 1]))){
			int k = p[j];
			for(int z = j; z > k; z--){
				add(0, ib[i - z], -1);
				add(1, ia[z], -1);
			}
			j = k;
		}


		add(0, ib[i], 1);
		add(1, ia[j + 1], 1);
		j++;

		if(j == n)r++;
	}
	printf("%d\n", r);


	return 0;
}