#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n, p[MAXN][MAXN];

double e[MAXN], skip[MAXN];
bool vis[MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	for(int j = 0; j < n; j++)
		scanf("%d", &p[i][j]);

	e[n - 1] = 0.0;
	for(int i = 0; i < n - 1; i++)
		e[i] = 1e9;

	for(int itr = 0; itr < n - 1; itr++){
		int u = -1;
		for(int i = 0; i < n; i++){
			if(vis[i])continue;

			if(u == -1)u = i;
			else if(e[i] < e[u])u = i;
		}
		vis[u] = true;

		for(int i = 0; i < n; i++)if(p[i][u] > 0){
			if(vis[i])continue;

			if(e[i] > 1e8){
				e[i] = e[u] + 100.0 / p[i][u];
				skip[i] = 1.0 - p[i][u] / 100.0;
			}else{
				if(e[i] < e[u])continue;

				e[i] = (e[i] * (1.0 - skip[i]) + skip[i] * p[i][u] / 100.0 * e[u]) /
						(1.0 - skip[i] * (1.0 - p[i][u] / 100.0));
				skip[i] = skip[i] * (1.0 - p[i][u] / 100.0);
			}
		}
	}

	printf("%.15f\n", e[0]);

	return 0;
}