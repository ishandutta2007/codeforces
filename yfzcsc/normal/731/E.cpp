#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
long long s[200111],ans;
long long dp[200111],mx;
int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i){
		int a;scanf("%d",&a);
		s[i]=s[i-1]+a;
	}
	mx=dp[n]=s[n];
	for(int i=n-1;i>=2;--i){
		dp[i]=s[i]-mx;
		mx=max(mx,dp[i]);
	}
	cout<<mx;
}