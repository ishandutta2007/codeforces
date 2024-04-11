#include<bits/stdc++.h>
using namespace std;
int n,dp[20];
string s;
int main(){
	cin>>n>>s;
	for(auto c:s)
		dp[c-'0']++;
	int sum=0,ans=0;
	for(int i=0;i<=9;++i)
		if(i!=8)sum+=dp[i];
	for(int i=1;i<=n;++i)
		if(dp[8]>=i&&(sum+dp[8]-i)>=10*i)
			ans=i;
	printf("%d",ans);
}