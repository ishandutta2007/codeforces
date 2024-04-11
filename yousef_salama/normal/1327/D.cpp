#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int T, n, p[MAXN], c[MAXN];
bool vis[MAXN];

int m, v[MAXN];
bool check(int d){
	for(int j = 0; j < d; j++){
		int z = c[v[j]];
		for(int k = j + d; k < m; k += d){
			if(c[v[k]] != z){
				z = -1;
				break;
			}
		}
		if(z != -1){
			return true;
		}
	}
	return false;
}

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d", &p[i]);
			p[i]--;
		
			vis[i] = false;
		}
		for(int i = 0; i < n; i++)
			scanf("%d", &c[i]);
			
		int res = n;
		for(int i = 0; i < n; i++){
			if(vis[i])continue;
			
			m = 0;
			int u = i;
			while(!vis[u]){
				vis[u] = true;
				v[m++] = u;
				u = p[u];
			}
			
			for(int d = 1; d * d <= m; d++)if(m % d == 0){
				if(check(d)){
					res = min(res, d);
				}else if(d * d < m){
					if(check(m / d)){
						res = min(res, m / d);
					}
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}