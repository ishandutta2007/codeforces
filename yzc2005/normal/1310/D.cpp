#include <bits/stdc++.h>
int read() {
	int x = 0 ;
	char c = getchar() ;
	while(c < 48) c = getchar() ;
	while(c > 47) x = x * 10 + (c - 48) , c = getchar() ;
	return x ;
}

int n, k;
const int maxn = 88 ;
int dis[maxn][maxn] ;
int dp[11][maxn] ;
int main() {
	n = read() , k = read() ;
	for(int i = 1 ; i <= n ; i ++)
		for(int j = 1 ; j <= n ; j ++)
			dis[i][j] = read() ;
	int seed = 0 ;
	for(char c : "sooketxdy")
		seed = seed * 233 + c ;
	srand(seed) ;
	int times = 5000 ;
	std :: vector < int > col(n + 1 , 0);
	int ans = 1e9 ;
	while(times --) {
		for(int i = 1 ; i <= n ; i ++)
			col[i] = rand() & 1 ;
		memset(dp , 0x3f , sizeof(dp)) ;
		dp[0][1] = 0;
		for(int kk = 0 ; kk < k ; kk ++)
			for(int i = 1 ; i <= n ; i ++)
				for(int j = 1 ; j <= n ; j ++)
					if(col[i] ^ col[j]) dp[kk + 1][j] = std :: min(dp[kk + 1][j] , dp[kk][i] + dis[i][j]) ;
		ans = std :: min(ans , dp[k][1]) ;
	}
	printf("%d" , ans) ;
	return 0 ;
}