#include <bits/stdc++.h>
using namespace std;

const int MAXN = 405;

int T, n, m, nxt[MAXN][26], dp[MAXN][MAXN];
char s[MAXN], t[MAXN];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%s %s", s, t);
		n = strlen(s);
		m = strlen(t);
		
		for(int i = n; i >= 0; i--)
		for(int j = 0; j < 26; j++){
			if(i == n)nxt[i][j] = -1;
			else{
				if(s[i] - 'a' == j)nxt[i][j] = i;
				else nxt[i][j] = nxt[i + 1][j];
			}
		}
		
		bool ok = false;
		for(int sep = 0; sep < m; sep++){
			for(int i = 0; i <= sep; i++)
			for(int j = 0; j <= m - sep; j++){
				if(i == 0 && j == 0)dp[i][j] = 0;
				else{
					dp[i][j] = -1;
					
					if(i > 0 && dp[i - 1][j] != -1){
						if(nxt[dp[i - 1][j]][t[i - 1] - 'a'] != -1){
							dp[i][j] = nxt[dp[i - 1][j]][t[i - 1] - 'a'] + 1;
						}
					}
					if(j > 0 && dp[i][j - 1] != -1){
						if(nxt[dp[i][j - 1]][t[sep + j - 1] - 'a'] != -1){
							if(dp[i][j] == -1 || dp[i][j] > nxt[dp[i][j - 1]][t[sep + j - 1] - 'a'] + 1){
								dp[i][j] = nxt[dp[i][j - 1]][t[sep + j - 1] - 'a'] + 1;
							}
						}
					}
				}
			}
			
			if(dp[sep][m - sep] != -1){
				ok = true;
				break;
			}
		}
		
		if(ok)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}