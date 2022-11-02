#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

char s[1005];
int a[1005];

typedef long long LL;
LL dp[1005][1005];
LL dp1[1005][1005];
vector<int> b[1005];
const LL mod = 1e9 + 7;
int k;
void upd(LL &a,LL b){
	a += b;
	if(a >= mod) a -= mod;
}
int main(){
	int m;
	scanf("%s",s + 1);	
	m = strlen(s + 1);
	scanf("%d",&k);
	if(k == 0){
		printf("1\n");
		return 0;
	}
	for(int i = 1;i <= m;i++) 
		a[i] = s[i] - '0';
	for(int i = 2;i <= 1000;i++){
		int bitcount = __builtin_popcount(i);
		b[bitcount].push_back(i);
	}
	dp[1][0] = 1;
	for(int j = 0;j < k;j++){
		for(int i = 1;i <= 1000;i++){
			for(auto to:b[i]){
				upd(dp[to][j + 1],dp[i][j]);
			}
		}
	}
	int num = 1;
	dp1[1][0] = 1;
	for(int i = 2;i <= m;i++){
			for(int j = 0;j <= 1000;j++){
				upd(dp1[i][j],dp1[i - 1][j]);
				upd(dp1[i][j + 1],dp1[i - 1][j]);
			}
			if(a[i] == 1){
				upd(dp1[i][num],1);
				num++;
			}
	}
	upd(dp1[m][num],1);
	upd(dp1[m][1],mod - 1);
	LL ans = 0;
	for(int i = 1;i <= 1000;i++){
		if(dp[i][k - 1] > 0){
			upd(ans,dp1[m][i]);
		}
	}
	cout << ans << endl;
	return 0;
}