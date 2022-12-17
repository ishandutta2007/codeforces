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
int T,n,m;
ll ans,a[105][105];
int main()
{
	T=gi();
	while(T--)
	{
		ans=0;
		n=gi(),m=gi();
		FOR(i,1,n)
		{
			FOR(j,1,m)a[i][j]=gi();
		}
		FOR(i,1,(n+1)/2)
		{
			FOR(j,1,(m+1)/2)
			{
				vector<int>v;
				v.push_back(a[i][j]);
				if(n-i+1!=i)v.push_back(a[n-i+1][j]);
				if(n-i+1!=i&&m-j+1!=j)v.push_back(a[n-i+1][m-j+1]);
				if(m-j+1!=j)v.push_back(a[i][m-j+1]);
				ll sum=0;
				for(auto x:v)sum+=x;
				ll ans1=1e18;
				for(auto x:v)
				{
					ll ret=0;
					for(auto y:v)ret+=abs(x-y);
					ans1=min(ans1,ret);
				}
				ans+=ans1;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}