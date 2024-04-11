#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;
const int MAXM = 1000005;

int n, m, g[MAXN][MAXN], p[MAXM];
char c[MAXN][MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf(" %s", c[i]);
		
	for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++){
		if(i == j)g[i][j] = 0;
		else if(c[i][j] == '0')g[i][j] = 1 << 20;
		else g[i][j] = 1;
	}
	
	for(int k = 0; k < n; k++)
	for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++)
		g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
		
	scanf("%d", &m);
	scanf("%d", &p[0]);
	p[0]--;
	
	vector <int> v;
	v.push_back(p[0]);
	
	int prev = 0;
	for(int i = 1; i < m; i++){
		scanf("%d", &p[i]);
		p[i]--;
		
		if(g[p[prev]][p[i]] != i - prev){
			prev = i - 1;
			v.push_back(p[i - 1]);
		}
	}
	v.push_back(p[m - 1]);
	
	printf("%d\n", (int)v.size());
	for(int i = 0; i < (int)v.size(); i++){
		if(i > 0)printf(" ");
		printf("%d", v[i] + 1);
	}
	printf("\n");
	
	return 0;
}