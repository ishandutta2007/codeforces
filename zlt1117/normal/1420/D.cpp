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
const int maxn=9e5+5,mod=998244353;
ll n,k,l[maxn],r[maxn],d1[maxn],d2[maxn],inv[maxn],fac[maxn],invf[maxn],ans,b[maxn],tot;
inline ll C(ll x,ll k)
{
	if(x<k)return 0;
	else return (((fac[x]*invf[k])%mod)*invf[x-k])%mod;
}
int main()
{
//	freopen("1.in","r",stdin);
	n=gi(),k=gi();
	FOR(i,1,n)l[i]=gi(),r[i]=gi();
	FOR(i,1,n)b[++tot]=l[i],b[++tot]=r[i],b[++tot]=r[i]+1;
	sort(b+1,b+tot+1);
	tot=unique(b+1,b+tot+1)-b-1;
	FOR(i,1,n)l[i]=lower_bound(b+1,b+tot+1,l[i])-b,r[i]=lower_bound(b+1,b+tot+1,r[i])-b;
	FOR(i,1,n)d1[l[i]]++,d1[r[i]+1]--,d2[l[i]]++,d2[r[i]]--;
	tot=3*n;
	fac[0]=1,inv[0]=inv[1]=1,invf[0]=1;
	FOR(i,1,tot)fac[i]=(i*fac[i-1])%mod;
	FOR(i,2,tot)inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	FOR(i,1,tot)invf[i]=invf[i-1]*inv[i]%mod;
	FOR(i,1,tot)
	{
		d1[i]+=d1[i-1];
		d2[i]+=d2[i-1];
		ans=(ans+C(d1[i],k))%mod;
		ans=((ans-C(d2[i],k))%mod+mod)%mod;
	}
	printf("%lld\n",ans%mod);
	return 0;
}