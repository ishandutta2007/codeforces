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
vector<vector<int> > td;
vector<int> c3(int a,int b,int c)
{
	vector<int> v;
	v.pb(a); v.pb(b);
	v.pb(c); return v;
}
vector<int> c4(int a,int b,int c,int d)
{
	vector<int> v;
	v.pb(a); v.pb(b);
	v.pb(c); v.pb(d);
	return v;
}
void prt(int s,int l,int r)
{
	if(s<=2) throw "!!!";
	if(s==3)
	{
		td.pb(c3(l,l+1,l+2));
		td.pb(c3(l,l+1,l+2));
		return;
	}
	if(s==4)
	{
		--l;
		td.pb(c4(l+1,l+2,l+3,l+4));
		td.pb(c4(l+1,l+2,l+4,l+3));
		td.pb(c4(l+1,l+3,l+2,l+4));
		return;
	}
	if(s==5)
	{
		--l;
		td.pb(c3(l+5,l+4,l+2));
		td.pb(c3(l+3,l+1,l+5));
		td.pb(c3(l+4,l+2,l+1));
		td.pb(c3(l+3,l+1,l+5));
		td.pb(c4(l+4,l+5,l+2,l+3));
		td.pb(c4(l+4,l+3,l+2,l+1));
		return;
	}
	if(s==6)
	{
		--l;
		td.pb(c3(l+1,l+2,l+4));
		td.pb(c3(l+1,l+2,l+5));
		td.pb(c3(l+1,l+3,l+4));
		td.pb(c3(l+1,l+3,l+6));
		td.pb(c3(l+1,l+5,l+6));
		td.pb(c3(l+2,l+3,l+4));
		td.pb(c4(l+2,l+6,l+5,l+3));
		td.pb(c4(l+2,l+6,l+4,l+5));
		td.pb(c4(l+3,l+6,l+4,l+5));
		return;
	}
	throw "!!!";
}
void fz(int l,int r)
{
	if(r-l+1<=6)
	{
		prt(r-l+1,l,r);
		return;
	}
	int m=(l+r)>>1,lm=m-l+1;
	if((lm&1)&&!((r-l+1)&1))
		--lm;
	int l1=l,r1=l+lm-1,l2=l+lm,r2=r;
	fz(l1,r1); fz(l2,r2);
	if((r1-l1+1)&1) swap(l1,l2),swap(r1,r2);
	//[l1,r1] is even
	if((r1-l1+1)&1) throw 233;
	for(int _=l2;_<=r2;_++)
	{
		int a=_,b=(_==r2)?l2:(_+1);
		for(int g=l1;g<=r1;g+=2)
			td.pb(c4(g,a,g+1,b));
	}
}
int main()
{
	int n; cin>>n; fz(1,n);
	printf("%d\n",int(td.size()));
	for(unsigned _=0;_<td.size();_++)
	{
		vector<int>&v=td[_];
		printf("%d",int(v.size()));
		for(unsigned i=0;i<v.size();++i)
			printf(" %d",v[i]);
		puts("");
	}
}