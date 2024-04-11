#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, a, b;
vector <int> G[MAXN];

int C[MAXN], mx;
void color(int u, int parent = -1){
	int m = 1;
	for(int v : G[u]){
		if(v == parent)continue;

		while(m == C[u] || (parent != -1 && m == C[parent]))m++;
		C[v] = m++;

		color(v, u);
	}
	mx = max(mx, m - 1);
}
int main(){
	scanf("%d", &n);
	for(int i = 0; i < n - 1; i++){
		scanf("%d %d", &a, &b);
		a--, b--;

		G[a].push_back(b);
		G[b].push_back(a);
	}

	mx = 1;

	C[0] = 1;
	color(0);

	printf("%d\n", mx);
	for(int i = 0; i < n; i++){
		if(i > 0)printf(" ");
		printf("%d", C[i]);
	}
	printf("\n");
	return 0;
}