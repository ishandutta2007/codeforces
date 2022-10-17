#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define N 200100
#define M 998244353
using namespace std;

ll T,n,m,num[N],dp[N][4][2][2][2];
char str[N];

inline void Add(ll &u,ll v){u=(u+v)%M;}
inline void Min(ll &u,ll v){if(v<u) u=v;}
inline void Max(ll &u,ll v){if(v>u) u=v;}
ll dfs(ll now,ll pos,bool lA,bool lB,bool lC)
{
	if(!now) return pos==3;
	if(dp[now][pos][lA][lB][lC]!=-1) return dp[now][pos][lA][lB][lC];
	ll res=0;
	bool a,b,c;
	a=(num[now] || !lA);
	b=(num[now] || !lB);
	c=(num[now] || !lC);
	
	if(!pos)
	{
		Add(res,dfs(now-1,0,lA && !num[now],lB && !num[now],lC && !num[now]));
		if(a && b && c) Add(res,dfs(now-1,0,lA,lB,lC));
		
		if(a && c) Add(res,dfs(now-1,1,lA,lB && !num[now],lC));
		if(b) Add(res,dfs(now-1,1,lA && !num[now],lB,lC && !num[now]));
	}
	else if(pos==1)
	{
		Add(res,dfs(now-1,1,lA && !num[now],lB && !num[now],lC && !num[now]));
		if(a && b && c) Add(res,dfs(now-1,1,lA,lB,lC));
		if(a && c) Add(res,dfs(now-1,1,lA,lB && !num[now],lC));
		if(b) Add(res,dfs(now-1,1,lA && !num[now],lB,lC && !num[now]));
		
		if(b && c) Add(res,dfs(now-1,2,lA && !num[now],lB,lC));
		if(a) Add(res,dfs(now-1,2,lA,lB && !num[now],lC && !num[now]));
	}
	else if(pos==2)
	{
		Add(res,dfs(now-1,2,lA && !num[now],lB && !num[now],lC && !num[now]));
		if(a && b && c) Add(res,dfs(now-1,2,lA,lB,lC));
		if(a && c) Add(res,dfs(now-1,2,lA,lB && !num[now],lC));
		if(b) Add(res,dfs(now-1,2,lA && !num[now],lB,lC && !num[now]));
		if(b && c) Add(res,dfs(now-1,2,lA && !num[now],lB,lC));
		if(a) Add(res,dfs(now-1,2,lA,lB && !num[now],lC && !num[now]));
		
		if(c) Add(res,dfs(now-1,3,lA && !num[now],lB && !num[now],lC));
		if(a && b) Add(res,dfs(now-1,3,lA,lB,lC && !num[now]));
	}
	else
	{
		Add(res,dfs(now-1,3,lA && !num[now],lB && !num[now],lC && !num[now]));
		if(a && b && c) Add(res,dfs(now-1,3,lA,lB,lC));
		if(a && c) Add(res,dfs(now-1,3,lA,lB && !num[now],lC));
		if(b) Add(res,dfs(now-1,3,lA && !num[now],lB,lC && !num[now]));
		if(b && c) Add(res,dfs(now-1,3,lA && !num[now],lB,lC));
		if(a) Add(res,dfs(now-1,3,lA,lB && !num[now],lC && !num[now]));
		if(c) Add(res,dfs(now-1,3,lA && !num[now],lB && !num[now],lC));
		if(a && b) Add(res,dfs(now-1,3,lA,lB,lC && !num[now]));
	}
	return dp[now][pos][lA][lB][lC]=res;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	ll i,j,l,r,mid,t;
	scanf("%s",str+1);
	n=strlen(str+1);
	reverse(str+1,str+n+1);
	for(i=1;i<=n;i++) num[i]=str[i]-'0';
	cout<<dfs(n,0,1,1,1)*6%M;
}