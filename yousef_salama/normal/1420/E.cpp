#include <bits/stdc++.h>
using namespace std;

const int MAXN = 85;

int a[MAXN], dp[2][MAXN][MAXN * MAXN];

int main(){
	int n;
	scanf("%d", &n);
	
	vector <int> v;
	
	int c = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if(a[i] == 1){
			v.push_back(i - (int)v.size());
		}else{
			c++;
		}
	}
	
	int m = n * (n - 1) / 2, k = v.size();
	
	for(int i = k; i >= 0; i--)
	for(int j = 0; j <= c; j++)
	for(int r = 0; r <= m; r++){
		if(i == k){
			dp[i & 1][j][r] = 0;
		}else{
			dp[i & 1][j][r] = 0;
			for(int l = j; l <= c; l++){
				if(r >= abs(v[i] - l))dp[i & 1][j][r] = max(dp[i & 1][j][r], dp[(i + 1) & 1][l][r - abs(v[i] - l)] + (l - j) * (c - l));
			}
		}
	}
	
	for(int i = 0; i <= m; i++){
		if(i > 0)printf(" ");
		printf("%d", dp[0][0][i]);
	}
	printf("\n");
	
	return 0;
}