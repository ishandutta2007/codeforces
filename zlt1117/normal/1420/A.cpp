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
const int maxn=5e4+5;
int T;
int a[maxn],b[maxn],N;
int main()
{
	T=gi();
	while(T--)
	{
		N=gi();
		FOR(i,1,N)a[i]=b[i]=gi();
		bool ok=false;
		int now=1e9+1;
		FOR(i,1,N)
		{
			if(a[i]>=now)
			{
				ok=true;
				printf("YES\n");
				break;
			}
			now=min(a[i],now);
		}
		if(!ok)printf("NO\n");
	}
	return 0;
}