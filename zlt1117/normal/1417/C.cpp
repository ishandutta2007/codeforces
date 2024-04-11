#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<set>
#define IN inline
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
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
int T,n;
const int maxn=3e5+5;
vector<int>v[maxn];
int d[maxn];
int main()
{
	T=gi();
	while(T--)
	{
		n=gi();
		FOR(i,0,n)d[i]=0x3f3f3f3f,v[i].clear();
		FOR(i,1,n)
		{
			int x=gi();
			v[x].push_back(i);
		}
		FOR(i,1,n)
		{
			if((int)(v[i].size())==0)continue;
			int las=0,ans=0;
			FOR(j,0,(int)v[i].size()-1)ans=max(v[i][j]-las,ans),las=v[i][j];
			ans=max(ans,n+1-v[i][v[i].size()-1]);
			d[ans]=min(d[ans],i);
		}
		FOR(i,1,n)printf("%d ",(d[i]=min(d[i],d[i-1]))==0x3f3f3f3f?-1:d[i]);
		printf("\n");
	}
	return 0;
}