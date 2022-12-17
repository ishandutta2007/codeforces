//#pragma GCC optimize(4)
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define rd (rand()<<16^rand())
using namespace std;
inline int gi()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=1e5+5;
int r,n;
int a[maxn],b[maxn],t[maxn];
int dp[maxn],ans;
int main()
{
	memset(dp,0xcf,sizeof(dp));
	r=gi(),n=gi();
	a[0]=b[0]=1,t[0]=0,dp[0]=0;;
	FOR(i,1,n)t[i]=gi(),a[i]=gi(),b[i]=gi();
	int last=0,now=0;
	vector<int>vec;
	vec.push_back(0);
	FOR(i,1,n)
	{
		for(int j=i-1;j>=0&&t[j]>=t[i]-3*r;--j)
		{
			if(abs(a[i]-a[j])+abs(b[i]-b[j])<=t[i]-t[j])dp[i]=max(dp[i],dp[j]+1);
		}
		while(last+1<vec.size()&&t[vec[last+1]]+2*r<t[i])last++,now=max(now,dp[last]);
		if(abs(a[i]-a[last])+abs(b[i]-b[last])<=t[i]-t[last])dp[i]=max(dp[i],now+1);
		vec.push_back(i);
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}///