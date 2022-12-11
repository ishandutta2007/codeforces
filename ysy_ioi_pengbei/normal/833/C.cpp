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
#include <unordered_map>
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
ll L,R;
int pl[SZ],pr[SZ],cho[SZ];
int ps=0,cn[23333][19],ok[23333],rm[23333];
void tryy(int d,int s=0)
{
	if(d<0) return;
	bool OO=0;
	for(int g=0;g<=9;++g)
	{
		if(g<pl[d]&&!(s&1)) continue;
		if(g>pr[d]&&!(s&2)) continue;
		int ns=s;
		if(g>pl[d]) ns|=1;
		if(g<pr[d]) ns|=2;
		if(ns!=3) cho[d]=g,tryy(d-1,ns);
		else OO=1;
	}
	if(OO);else return;
	++ps; for(int i=d+1;i<=19;++i) ++cn[ps][cho[i]]; rm[ps]=d;
	for(int g=0;g<=9;++g)
	{
		if(g<pl[d]&&!(s&1)) continue;
		if(g>pr[d]&&!(s&2)) continue;
		int ns=s;
		if(g>pl[d]) ns|=1;
		if(g<pr[d]) ns|=2;
		if(ns!=3) continue;
		ok[ps]|=1<<g;
	}
}
ll ans=0;
int cur[18],ls[233];
void dfs(int x)
{
	//check with cur
	for(int i=ps;i>=1;--i)
	{
		register int tn=0,pp=0;
		for(register int j=1;j<=9;++j)
		{
			if(cn[i][j]<cur[j])
				tn+=cur[j]-cn[i][j],pp|=1<<j;
			else if(cn[i][j]>cur[j]) goto ed;
		}
		if(pp&ok[i]) --tn; else
		if(ok[i]&1); else continue;
		if(tn<=rm[i]) {++ans; break;}
		ed:;
	}
	if(x>=19) return;
	for(ls[x]=ls[x-1];ls[x]<=9;++ls[x])
		++cur[ls[x]],dfs(x+1),--cur[ls[x]];
}
int main()
{
	cin>>L>>R; --L,++R;
	for(int i=0;i<=19;++i)
	{
		pl[i]=L%10,L/=10;
		pr[i]=R%10,R/=10;
	}
	tryy(19);
	ls[0]=1; dfs(1);
	cout<<ans<<"\n";
}