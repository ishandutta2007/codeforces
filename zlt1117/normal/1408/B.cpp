#pragma GCC optimize(2)
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
const int maxn=205;
int a[maxn];
int T,n,k;
int main()
{
	T=gi();
	while(T--)
	{
		n=gi(),k=gi();
		memset(a,0,sizeof(a));
		FOR(i,1,n)a[i]=gi();
		if(k==1)
		{
			bool ok=false;
			FOR(i,2,n)if(a[i]!=a[i-1])ok=true;
			if(ok){printf("-1\n");continue;}
			else {printf("1\n");continue;}
		}
		else
		{
			int cnt=unique(a+1,a+n+1)-a-1;
			int ans=0;
			if((cnt-1)%(k-1)==0)ans=max(1,(cnt-1)/(k-1));
			else ans=max(1,(cnt-1)/(k-1)+1);
			printf("%d\n",ans);
		}
	}
	return 0;
}
///