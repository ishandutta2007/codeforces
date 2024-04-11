#include <bits/stdc++.h>
using namespace std;

const int MAXN = 150005;

int t, n, dp[MAXN][3][3], c[MAXN][3][3];
char s[MAXN], a[] = "one", b[] = "two";

int main(){	
	scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		n = strlen(s);
		
		for(int i = n; i >= 0; i--)
		for(int x = 0; x < 3; x++)
		for(int y = 0; y < 3; y++){
			if(i == n){
				dp[i][x][y] = 0;
			}else{
				dp[i][x][y] = 1 + dp[i + 1][x][y];
				c[i][x][y] = 0;
				
				int nx;
				if(s[i] == a[x])nx = x + 1;
				else if(s[i] == a[0])nx = 1;
				else nx = 0;
				
				int ny;
				if(s[i] == b[y])ny = y + 1;
				else if(s[i] == b[0])ny = 1;
				else ny = 0;
				
				if(nx < 3 && ny < 3){
					if(dp[i + 1][nx][ny] < dp[i][x][y]){
						dp[i][x][y] = dp[i + 1][nx][ny];
						c[i][x][y] = 1;
					}
				}
			}
		}
		
		printf("%d\n", dp[0][0][0]);
		
		int i = 0, x = 0, y = 0, first = 1;
		while(i < n){
			if(c[i][x][y] == 0){
				i = i + 1;
				
				if(first)first = 0;
				else printf(" ");
				
				printf("%d", i);
			}else{
				int nx;
				if(s[i] == a[x])nx = x + 1;
				else if(s[i] == a[0])nx = 1;
				else nx = 0;
				
				int ny;
				if(s[i] == b[y])ny = y + 1;
				else if(s[i] == b[0])ny = 1;
				else ny = 0;
				
				i = i + 1;
				x = nx;
				y = ny;
			}
		}
		printf("\n");
	}
	return 0;
}