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
int N;
const int maxn=1005;
int a[maxn],ans[maxn];
int main()
{
	N=gi();
	int pre=0;
	FOR(i,2,N)
	{
		printf("? %d %d\n",1,i);
		fflush(stdout);
		ans[i]=gi();
		if(i>=3)a[i]=ans[i]-pre;
		pre=ans[i];
	}
	printf("? %d %d\n",2,3);
	fflush(stdout);
	int now=gi();
	a[1]=ans[3]-now;
	a[2]=ans[2]-a[1];
	printf("! ");
	FOR(i,1,N)printf("%d ",a[i]);
	printf("\n");
	fflush(stdout);
	return 0;
}