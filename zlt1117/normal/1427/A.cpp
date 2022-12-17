#pragma GCC optimize(4)
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
const int maxn=55;
int T,n;
int a[maxn];
int main()
{
	T=gi();
	while(T--)
	{
		n=gi();
		int sum=0;
		FOR(i,1,n)a[i]=gi(),sum+=a[i];
		if(sum==0)printf("NO\n");
		else
		{
			if(sum>0)sort(a+1,a+n+1,greater<int>());
			else sort(a+1,a+n+1);
			printf("YES\n");
			FOR(i,1,n)printf("%d ",a[i]);
			printf("\n");
		}
	}
	return 0;
}