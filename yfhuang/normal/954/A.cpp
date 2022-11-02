#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>


using namespace std;

const int maxn = 105;

int dp[maxn];
char s[maxn];

int main(){
	int n;
	cin >> n;
	scanf("%s",s + 1);
	dp[0] = 0;
	dp[1] = 1;
	for(int i = 2;i <= n;i++){
		dp[i] = dp[i - 1] + 1;
		if(s[i] == 'U' && s[i - 1] == 'R')
			dp[i] = min(dp[i],dp[i - 2] + 1);	
		if(s[i] == 'R' && s[i - 1] == 'U')
			dp[i] = min(dp[i],dp[i - 2] + 1);
	}	
	cout << dp[n] << endl;
	return 0;
}