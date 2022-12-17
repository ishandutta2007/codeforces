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
const int maxn=1005;
int a[maxn],b[maxn][maxn],max1,max2,maxv=-1;
bool chosen[maxn];
int main()
{
	int T=getint();
	while(T--)
	{
		memset(chosen,0,sizeof(chosen));
		int n=getint();
		FOR(i,1,n)a[i]=getint();
		maxv=-1;
		FOR(i,1,n)
		{
			if(a[i]>maxv)
			{
				maxv=a[i];
				max1=i;
			}
		}
		vector<int>v;
		v.push_back(max1);
		chosen[max1]=1;
		FOR(i,1,n-1)
		{
			int now=-1,pos=0;
			FOR(j,1,n)
			{
				if(!chosen[j]&&__gcd(maxv,a[j])>now)
				{
					now=__gcd(maxv,a[j]),pos=j;
				}
			}
			v.push_back(pos);
			chosen[pos]=1;
			maxv=now;
		}
		FOR(i,1,n)printf("%d ",a[v[i-1]]);
		printf("\n");
	}
	return 0;
}
///