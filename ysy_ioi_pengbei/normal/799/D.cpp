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
#define SZ 666666
int a,b,h,w,n,v[SZ];
set<ll> g;
int f(int x,int y)
{
	if(x<=1&&y<=1) return 0;
	ld a=1,b=1; int mx=n;
	for(int i=1;i<=n;i++)
	{
		if(a<x) a*=v[i];
		else if(b<y) b*=v[i];
		if(a>=x&&b>=y) {mx=i; break;}
	}
	g.clear(); g.insert(1); ld s=1; ll s2=1;
	for(int i=1;i<=mx;i++)
	{
		s*=v[i]; s2*=v[i];
		for(int j=200000;j>=1;--j)
			if(g.count(j)) g.insert(j*(ll)v[i]);
		set<ll>::iterator r=g.lower_bound(x);
		if(r!=g.end()&&((s/(*r)>=y+100)||(s/(*r)>=y-100&&s2/(*r)>=y)))
			return i;
	}
	return 1e9;
}
int main()
{
	scanf("%d%d%d%d%d",&a,&b,&h,&w,&n);
	for(int i=1;i<=n;i++) scanf("%d",v+i);
	sort(v+1,v+1+n); reverse(v+1,v+1+n);
	int aa=(min(f((a+h-1)/h,(b+w-1)/w)
	,f((a+w-1)/w,(b+h-1)/h)));
	if(aa>n) puts("-1");
	else printf("%d\n",aa);
}