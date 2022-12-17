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
inline int getint()
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
const int maxn=505;
int T,n;
int a[maxn];
int main()
{
	T=getint();
	while(T--)
	{
		n=getint();
		memset(a,0,sizeof(a));
		FOR(i,1,n)
		{
			int x=getint();
			a[x]++;
		}
		int now1=-1,now2=-1;
		FOR(i,0,n)
		{
			if(a[i]>=2&&now1==i-1)now1++;
			if(a[i]>=1&&now2==i-1)now2++;
		}
		printf("%d\n",now1+now2+2);
	}
	return 0;
}