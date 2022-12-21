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
const int maxn=3e5+5;
int T,n;
int a[maxn],b[maxn],val[maxn],now[maxn];
int main()
{
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	T=gi();
	while(T--)
	{
		ll sum=0;
		n=gi();
		FOR(i,1,3*n)a[i]=b[i]=val[i]=0;
		FOR(i,1,n)now[i]=gi(),sum+=now[i];
		if(sum%n!=0)printf("-1\n");
		else
		{
			int tot=0;
			sum/=n;
			FOR(i,2,n)
			{
				a[++tot]=1,b[tot]=i,val[tot]=i-((now[i]-1)%i+1);
				now[i]+=val[tot];now[1]-=val[tot];
				a[++tot]=i,b[tot]=1,val[tot]=now[i]/i;
				now[i]-=val[tot]*i,now[1]+=val[tot]*i;
			}
			FOR(i,2,n)a[++tot]=1,b[tot]=i,val[tot]=sum,now[i]+=sum,now[1]-=sum;
			FOR(i,1,n)cerr<<now[i]<<' ';cerr<<endl;
			printf("%d\n",tot);
			FOR(i,1,tot)printf("%d %d %d\n",a[i],b[i],val[i]);
		}
	}
	return 0;
}