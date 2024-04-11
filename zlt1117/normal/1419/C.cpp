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
const int maxn=1005;
int T,n,x;
int a[maxn];
int main()
{
	T=gi();
	while(T--)
	{
		n=gi(),x=gi();
		bool ok1=true;
		int ok2=0;
		int arg=0,cnt=0;
		FOR(i,1,n)
		{
			a[i]=gi();
			if(a[i]!=x)ok1=false;
			if(a[i]==x)ok2=true;
			a[i]-=x;
			arg+=a[i];
		}
		if(ok1)printf("0\n");
		else if(arg==0)printf("1\n");
		else if(ok2)printf("1\n");
		else printf("2\n");
	}
	return 0;
}