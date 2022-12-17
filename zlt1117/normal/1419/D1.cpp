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
const int maxn=1e5+5;
int a[maxn],n;
int now[maxn],ans;
int main()
{
	n=gi();
	FOR(i,1,n)a[i]=gi();
	sort(a+1,a+n+1);
	FOR(i,1,n)
	{
		if(i%2==0)now[i]=a[i/2];
		else now[i]=a[i/2+n/2+1];
	}
	FOR(i,2,n-1)
	{
		if(now[i]<=now[i-1]&&now[i]<=now[i+1])ans++;
	}
	printf("%d\n",ans);
	FOR(i,1,n)printf("%d ",now[i]);
	printf("\n");
	return 0;
}