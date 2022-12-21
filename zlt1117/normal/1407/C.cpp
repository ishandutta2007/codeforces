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
const int maxn=1e4+5;
int n;
int a[maxn],maxv;
int main()
{
	n=getint();
	int pos=1,maxpos=1;
	FOR(i,2,n)
	{
		printf("? %d %d\n",maxpos,i);
		fflush(stdout);
		int val1=getint();
		printf("? %d %d\n",i,maxpos);
		fflush(stdout);
		int val2=getint();
		if(val2<val1)a[maxpos]=val1,maxpos=i;
		else a[i]=val2;
	}
	a[maxpos]=n;
	printf("! ");
	FOR(i,1,n)printf("%d ",a[i]);
	printf("\n");
	return 0;
}
///