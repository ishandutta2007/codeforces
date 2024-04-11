#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define sz(x) (int)(x.size())
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define int ll
//#define gc (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2))?EOF:*p1++;
#define gc getchar()
#define iter set<int>::iterator
using namespace std;
char buf[100000],*p1=buf,*p2=buf;
inline int gi()
{
	int x=0,f=1;char ch=gc;
	while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gc;}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48),ch=gc;}
	return (f==1)?x:-x;
}
char s[100];
ll now=1,maxv=1e14;
inline int query(int x)
{
	if(x>maxv)return 0;
	printf("? %lld\n",x);
	fflush(stdout);
	scanf("%s",s);
	if(s[0]=='L')return now+=x,1;
	else if(s[0]=='F')return now-=x,0;
	else puts("Wrong Answer"),assert(0);
}
inline void answer(int x)
{
	printf("! %lld\n",x);
	fflush(stdout);
	return ;
}
inline void input()
{
	now=1;
	///no input
}
int dp[505][505];
bool vis[505][505];
inline void solve()
{
	ll l=1,r=1e14;
	if(query(1)==0)return answer(0);
	while(1)
	{
		int k=now;
		if(query(k))l=k;
		else {r=k-1;break;}
	}
	now=0;///no money
	query(l);
	int x=1,y=(now>=r),ret=l;
	while(dp[x][y]<=r-l)x++;///at least
	while(l<=r)
	{
		while(r-l>dp[x][y])query(l-1),++y;
		int mid=dp[x-1][y-1]+l;
		while(now<mid)query(l-1);
		if(query(mid))y++,x--,l=mid+1,ret=mid;
		else y--,x--,r=mid-1; 
	}	
	answer(ret);
}
inline int DP(int x,int y)
{
	if(vis[x][y])return dp[x][y];
	vis[x][y]=1;
	if(x==0)return 0;
	else if(y==0)return dp[x][y]=DP(x-1,1);
	else return dp[x][y]=DP(x-1,y+1)+1+DP(x-1,y-1);
}
signed main()
{
	FOR(i,0,100)FOR(j,0,i)dp[i][j]=DP(i,j);
	//FOR(x,0,10)FOR(y,0,10)printf("dp[%d][%d]=%d\n",x,y,dp[x][y]);
	int T=gi();
	while(T--)
	{
		input();
		solve();
	}
	return 0;
}