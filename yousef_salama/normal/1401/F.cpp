#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1 << 22;

int n, q, a[MAXN], qi, xi, ki, li, ri;

int m, mask, g[MAXN][2];
long long sum[MAXN];

void add(int u, int val){
	int cur = 0;
	sum[cur] += val;
	
	for(int i = n - 1; i >= 0; i--){
		int c = (u & (1 << i)) != 0;
		if(g[cur][c] == -1){
			g[cur][c] = m++;
		}
		cur = g[cur][c];
		sum[cur] += val;
	}
}
long long query(int r){
	long long ret = 0;
	int cur = 0;
	
	for(int i = n - 1; i >= 0; i--){
		int c = (mask & (1 << i)) != 0;
		if(r & (1 << i)){
			if(g[cur][c] != -1){
				ret += sum[g[cur][c]];
			}
			if(g[cur][c ^ 1] != -1){
				cur = g[cur][c ^ 1];
			}else{
				return ret;
			}
		}else{
			if(g[cur][c] != -1){
				cur = g[cur][c];
			}else{
				return ret;
			}
		}
	}
	ret += sum[cur];
	return ret;
}

int main(){
	m = 1;
	memset(g, -1, sizeof g);
	
	scanf("%d %d", &n, &q);
	for(int i = 0; i < (1 << n); i++){
		scanf("%d", &a[i]);
		add(i, a[i]);
	}
	
	mask = 0;
	while(q--){
		scanf("%d", &qi);
		if(qi == 1){
			scanf("%d %d", &xi, &ki);
			xi--;
			
			add(xi ^ mask, ki - a[xi ^ mask]);
			a[xi ^ mask] = ki;
		}else if(qi == 2){
			scanf("%d", &ki);
			for(int i = 0; i < ki; i++)
				mask ^= 1 << i;
		}else if(qi == 3){
			scanf("%d", &ki);
			mask ^= 1 << ki;
		}else{
			scanf("%d %d", &li, &ri);
			li--, ri--;
			
			long long res = query(ri);
			if(li > 0)res -= query(li - 1);
			
			printf("%lld\n", res);
		}
	}
	return 0;
}