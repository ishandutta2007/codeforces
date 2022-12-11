#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 1234567
typedef pair<ll,ll> pll;
pll operator + (pll a,pll b)
{
	return pll(a.fi+b.fi,a.se+b.se);
}
pll operator - (pll a,pll b)
{
	return pll(a.fi-b.fi,a.se-b.se);
}
pll bs[SZ]; int n,a[SZ];
void add(int l,int r,pll x)
{
	if(l>r) return;
	bs[l]=bs[l]+x; bs[r+1]=bs[r+1]-x;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i),--a[i];
	for(int i=0;i<n;i++)
	{
		//a[i]=i-p
		//i-p=0
		vector<int> g;
		g.pb(i+1); g.pb(0); g.pb((i-a[i]+n)%n);
		g.pb(n); sort(g.begin(),g.end());
		for(int j=0;j+1<g.size();++j)
		{
			int l=g[j],r=g[j+1]-1;
			if(l>r||l>=n) continue;
			int x=a[i],y=i-l,ss=0;
			if(y<0) ss+=n, y+=n;
			if(x>=y)
				add(l,r,pll(a[i]-i-ss,1));
			else
				add(l,r,pll(i-a[i]+ss,-1));
		}
	}
	for(int i=1;i<n;i++) bs[i]=bs[i-1]+bs[i];
	ll ans=1e18; int ps;
	for(int i=0;i<n;i++)
	{
		ll c=bs[i].fi+bs[i].se*i;
		if(c<ans) ans=c, ps=i; 
	}
	printf("%I64d %d\n",ans,(n-ps)%n);
}

/*
padding p
|a[(i+p)%n]-i|
let i+p=g
|a[g]-(g-p)%n|
a[g]>=(g-p)%n
p
shit 
where a={0,1,...,n-1}
*/