#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;

int n, q, li, ri, a[MAXN], f[MAXN][MAXN], g[MAXN][MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
		
	for(int i = n - 1; i >= 0; i--)
	for(int j = i; j < n; j++){
		if(i == j)f[i][j] = a[i];
		else f[i][j] = f[i + 1][j] ^ f[i][j - 1];
	}
	
	for(int i = n - 1; i >= 0; i--)
	for(int j = i; j < n; j++){
		if(i == j)g[i][j] = a[i];
		else g[i][j] = max(f[i][j], max(g[i + 1][j], g[i][j - 1]));
	}
	
	scanf("%d", &q);
	while(q--){
		scanf("%d %d", &li, &ri);
		li--, ri--;
		
		printf("%d\n", g[li][ri]);
	}
	
	return 0;
}