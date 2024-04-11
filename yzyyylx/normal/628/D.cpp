#include<bits/stdc++.h>
#define ll long long
#define N 2010
#define M 1000000007
using namespace std;
 
ll n,m,d,ans,num[N],dp[N][N];
char str[N];
 
ll ask(ll now,ll sum,bool lim,bool zero)
{
	if(!now) return !sum;
	if(!lim && !zero && dp[now][sum]!=-1) return dp[now][sum];
	ll i,res=0,mx=(lim?num[now]:9);
	for(i=0;i<=mx;i++)
	{
		if((i || !zero) && ((i==d) ^ ((n-now)&1))) continue;
		res=(res+ask(now-1,(sum*10+i)%m,lim&&i==mx,zero&&!i))%M;
	}
	if(!lim && !zero) dp[now][sum]=res;
	return res;
}
 
inline ll work()
{
	ll i,j;
	n=strlen(str+1);
	for(i=1;i<=n;i++) num[i]=str[i]-'0';
	reverse(num+1,num+n+1);
	return ask(n,0,1,1);
}
 
int main()
{
	memset(dp,-1,sizeof(dp));
	ll i,j,t;
	cin>>m>>d;
	scanf("%s",str+1);
	ans=M-work();
	for(i=n,t=0;i>=1;i--)
	{
		if(((n-i)&1) ^ (num[i]==d)) break;
		t=(t*10+num[i])%m;
	}
	if(!i && !t) ans++;
	scanf("%s",str+1);
	ans=(ans+work())%M;
	cout<<ans;
}