#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<utility>
#include<functional>
#include<cmath>
#include<vector>
#include<assert.h>
//using namespace std;
using std::min;
using std::max;
using std::swap;
using std::sort;
using std::reverse;
using std::random_shuffle;
using std::lower_bound;
using std::upper_bound;
using std::unique;
using std::vector;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
void open(const char *s){
#ifndef ONLINE_JUDGE
	char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
void open2(const char *s){
#ifdef DEBUG
	char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
int rd(){int s=0,c,b=0;while(((c=getchar())<'0'||c>'9')&&c!='-');if(c=='-'){c=getchar();b=1;}do{s=s*10+c-'0';}while((c=getchar())>='0'&&c<='9');return b?-s:s;}
void put(int x){if(!x){putchar('0');return;}static int c[20];int t=0;while(x){c[++t]=x%10;x/=10;}while(t)putchar(c[t--]+'0');}
int upmin(int &a,int b){if(b<a){a=b;return 1;}return 0;}
int upmax(int &a,int b){if(b>a){a=b;return 1;}return 0;}
const int N=310;
const ll p=998244353;
int fa[N],e1[N],e2[N];
int a[N],b[N];
int n;
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
	x=find(x);
	y=find(y);
	e2[x]++;
	if(x==y)
		return;
	e1[y]+=e1[x];
	e2[y]+=e2[x];
	fa[x]=y;
}
int s1,s2,s3,s4;
ll fac[N],ifac[N],inv[N];
ll f[N],g[N],h[N];
ll ans1[N],ans2[N];
ll s[N][N];
int deg[N];
int c[N];
int c1[N],c2[N],d1[N],d2[N];
ll binom(int x,int y)
{
	return fac[x]*ifac[y]%p*ifac[x-y]%p;
}
int main()
{
	open("cf715e");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
		e1[i]=1;
	}
	for(int i=1;i<=n;i++)
		if(a[i]&&b[i])
			merge(a[i],b[i]);
	for(int i=1;i<=n;i++)
	{
		if(a[i]&&find(a[i])==find(b[i])&&e1[a[i]]==e2[a[i]])
		{
			if(find(a[i])==a[i])
				s3++;
		}
		if(a[i])
			a[i]=find(a[i]);
		if(b[i])
			b[i]=find(b[i]);
		if(a[i]&&b[i]!=a[i])
		{
			c1[a[i]]=1;
			d1[a[i]]=bool(b[i]);
		}
		if(b[i]&&a[i]!=b[i])
		{
			c2[b[i]]=1;
			d2[b[i]]=bool(a[i]);
		}
	}
	for(int i=1;i<=n;i++)
		if(!a[i]&&!b[i])
			s4++;
	for(int i=1;i<=n;i++)
	{
		if(c1[i]&&c2[i]&&!d1[i]&&!d2[i])
			s4++;
		else
		{
			if(c1[i]&&!d1[i])
				s1++;
			if(c2[i]&&!d2[i])
				s2++;
		}
	}
	fac[0]=fac[1]=ifac[0]=ifac[1]=inv[1]=1;
	for(int i=2;i<=n;i++)
	{
		inv[i]=(-p/i*inv[p%i]%p+p)%p;
		fac[i]=fac[i-1]*i%p;
		ifac[i]=ifac[i-1]*inv[i]%p;
	}
	s[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			s[i][j]=(s[i-1][j-1]+s[i-1][j]*(i-1))%p;
	if(s4)
	{
		for(int i=0;i<=s1;i++)
			for(int j=i;j<=s1;j++)
				f[i]=(f[i]+binom(s1,j)*s[j][i]%p*fac[s4+s1-j-1]%p*ifac[s4-1])%p;
		for(int i=0;i<=s2;i++)
			for(int j=i;j<=s2;j++)
				g[i]=(g[i]+binom(s2,j)*s[j][i]%p*fac[s4+s2-j-1]%p*ifac[s4-1])%p;
		for(int i=0;i<=s4;i++)
			h[i]=s[s4][i]*fac[s4]%p;
	}
	else
	{
		for(int i=0;i<=s1;i++)
			f[i]=s[s1][i];
		for(int i=0;i<=s2;i++)
			g[i]=s[s2][i];
		h[0]=1;
	}
	for(int i=0;i<=s1;i++)
		for(int j=0;j<=s2;j++)
			ans1[i+j]=(ans1[i+j]+f[i]*g[j])%p;
	for(int i=0;i<=s1+s2;i++)
		for(int j=0;j<=s4;j++)
			ans2[i+j]=(ans2[i+j]+ans1[i]*h[j])%p;
	for(int i=n;i>=1;i--)
		printf("%I64d ",i-s3>=0?ans2[i-s3]:0);
	return 0;
}