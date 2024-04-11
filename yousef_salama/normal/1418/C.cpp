#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		int n;
		scanf("%d", &n);
		
		vector <int> a(n);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
			
		vector < vector <int> > dp(n + 1, vector <int>(2));
		
		for(int i = n; i >= 0; i--)
		for(int j = 0; j <= 1; j++){
			if(i == n){
				dp[i][j] = 0;
			}else{
				if(j == 0){
					dp[i][j] = dp[i + 1][j ^ 1] + a[i];
					if(i + 1 < n)dp[i][j] = min(dp[i][j], dp[i + 2][j ^ 1] + a[i] + a[i + 1]);
				}else{
					dp[i][j] = dp[i + 1][j ^ 1];
					if(i + 1 < n)dp[i][j] = min(dp[i][j], dp[i + 2][j ^ 1]);
				}
			}
		}
		printf("%d\n", dp[0][0]);
	}
	return 0;
}