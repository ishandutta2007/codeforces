#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define MN 5000
#define N 20
#define N2 1001000
#define M 998244353
using namespace std;
 
ll T,n,m,x,y,ans,K,MX,nn,num[N2*10],dp[N2][N];
 
ll gcd(ll u,ll v){return v?gcd(v,u%v):u;}
inline void Add(ll &u,ll v){u=(u+v)%M;}
inline void Min(ll &u,ll v){if(v<u) u=v;}
inline void Max(ll &u,ll v){if(v>u) u=v;}
inline ll lcm(ll u,ll v){return u*v/gcd(u,v);}
inline ll po(ll u,ll v)
{
	ll res=1;
	for(;v;)
	{
		if(v&1) res=res*u%M;
		u=u*u%M;
		v>>=1;
	}
	return res;
}
 
int main()
{
	ll i,j,k,p,q,a,b,now;
	cin>>n>>num[0]>>x>>y>>K>>m;
	nn=po(n,M-2);
	for(i=1;i<n;i++) num[i]=(num[i-1]*x+y)%m;
	for(MX=i=1;i<K;i++) MX=lcm(MX,i);
	for(i=0;i<MX;i++)
	{
		for(j=K;j>=1;j--)
		{
			dp[i][j]=(n-1)*nn%M*dp[i][j+1]%M+nn*(dp[i-i%j][j+1]+i)%M;
			dp[i][j]%=M;
		}
	}
	for(i=0;i<n;i++)
	{
//		cout<<" "<<num[i]<<endl; 
		Add(ans,(num[i]-num[i]%MX)*K*nn%M);
		Add(ans,dp[num[i]%MX][1]);
	}
	cout<<ans*po(n,K)%M;
}