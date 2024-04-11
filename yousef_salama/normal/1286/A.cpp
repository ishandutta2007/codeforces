#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int n, v[MAXN], dp[MAXN][MAXN][MAXN][2];

int main(){
	scanf("%d", &n);
	
	int a = 0, b = 0;
	for(int i = 1; i <= n; i++){
		if(i & 1)b++;
		else a++;
	}
	
	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
		if(v[i] != 0){
			if(v[i] & 1)b--;
			else a--;
		}
	}
	
	for(int i = n; i >= 0; i--)
	for(int x = 0; x <= a; x++)
	for(int y = 0; y <= b; y++)
	for(int p = 0; p <= 1; p++){
		if(i == n){
			dp[i][x][y][p] = 0;
		}else{
			dp[i][x][y][p] = 1 << 20;
			
			if(v[i] == 0){
				if(x > 0){
					dp[i][x][y][p] = min(dp[i][x][y][p], (i > 0 && p == 1) + dp[i + 1][x - 1][y][0]);
				}
				if(y > 0){
					dp[i][x][y][p] = min(dp[i][x][y][p], (i > 0 && p == 0) + dp[i + 1][x][y - 1][1]);
				}
			}else{
				dp[i][x][y][p] = (i > 0 && (v[i] & 1) != p) + dp[i + 1][x][y][v[i] & 1];
			}
		}
	}
	
	printf("%d\n", dp[0][a][b][0]);
	
	return 0;
}