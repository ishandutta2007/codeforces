#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 0x3f3f3f3f;

int dp[2800][210][2][110];
int a[5000],s[5000];
int n;

int solve(int l,int r,int k,int p){
	int &ret = dp[l][r - l + 100][k][p];
	if(dp[l][r - l + 100][k][p] != INF) return ret;
	if(k == 0){
		ret = -INF;
		if(l + p + r <= n) ret = max(ret,solve(l + p,r,1,p) + s[l + p] - s[l]);
		if(l + p + r + 1 <= n) ret = max(ret,solve(l + p + 1,r,1,p + 1) + s[l + p + 1] - s[l]);
		if(l + p + r > n) ret = 0;
	}else{
		ret = INF;
		if(l + p + r <= n) ret = min(ret,solve(l,r + p,0,p) - s[n - r] + s[n - r - p]);
		if(l + p + r + 1 <= n) ret = min(ret,solve(l,r + p + 1,0,p + 1) - s[n - r] + s[n - (r + p + 1)]);
		if(l + p + r > n) ret = 0;
	}
	return ret;
}

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		scanf("%d",a + i);
	}
	s[0] = 0;
	for(int i = 1;i <= n;i++){
		s[i] = s[i - 1] + a[i];
	}
	memset(dp,INF,sizeof(dp));
	cout << solve(0,0,0,1) << endl;
	return 0;
}