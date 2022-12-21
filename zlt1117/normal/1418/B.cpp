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
const int maxn=105;
int T,a[maxn],l[maxn],n;
int main()
{
	T=getint();
	while(T--)
	{
		vector<int>v;
		v.clear();
		n=getint();
		FOR(i,1,n)a[i]=getint();
		FOR(i,1,n)l[i]=getint();
		FOR(i,1,n)if(!l[i])v.push_back(a[i]);
		sort(v.begin(),v.end(),greater<int>());
		int pos=0;
		FOR(i,1,n)
		{
			if(l[i]==1)printf("%d ",a[i]);
			else printf("%d ",v[pos]),pos++;
		}
		printf("\n");
	}
	return 0;
}