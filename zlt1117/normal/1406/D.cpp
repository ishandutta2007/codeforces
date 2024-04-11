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
inline ll max(ll a,ll b){return a>b?a:b;}
inline ll min(ll a,ll b){return a<b?a:b;}
const int maxn=1e5+5;
ll a[maxn],b[maxn],n,m,l,r,x;///
ll ans;
int main()
{
	n=gi();
	FOR(i,1,n)a[i]=gi(),b[i]=a[i]-a[i-1];
	FOR(i,2,n)ans+=max(b[i],0);
	printf("%lld\n",(ll)ceil((double)(a[1]+ans)/2));
	m=gi();
	FOR(i,1,m)
	{
		l=gi(),r=gi(),x=gi();
		if(l==1)a[1]+=x;
		if(b[l]>0&&l>1)ans-=b[l];
		if(b[r+1]>0&&r+1<=n)ans-=b[r+1];
		b[l]+=x,b[r+1]-=x;
		if(l>1)ans+=max(0,b[l]);
		if(r+1<=n)ans=ans+max(0,b[r+1]);
		printf("%lld\n",(ll)ceil((double)(a[1]+ans)/2));
	}
	return 0;
} ///