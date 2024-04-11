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
int n,m,g[103][103],r[103],c[103],ans=1e9,gg;
void sim()
{
	bool ok=1; int sm=0;
	for(int j=2;j<=n;j++)
		r[j]=g[j][1]-g[1][1]+r[1];
	for(int j=1;j<=m;j++)
		c[j]=g[1][j]-r[1];
	for(int j=1;j<=m;j++)
		ok&=c[j]>=0, sm+=c[j];
	for(int j=1;j<=n;j++)
		ok&=r[j]>=0, sm+=r[j];
	if(ans<=sm) return;
	for(int i=1;i<=n&&ok;i++)
		for(int j=1;j<=m&&ok;j++)
			if(g[i][j]!=r[i]+c[j]) {ok=0; break;}
	if(!ok) return;
	ans=sm; gg=r[1];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&g[i][j]);
	for(r[1]=0;r[1]<=500;++r[1]) sim();
	if(ans>9e8)
	{
		puts("-1");
		return 0;
	}
	r[1]=gg; sim(); printf("%d\n",ans);
	for(int i=1;i<=n;i++)
		while(r[i]--) printf("row %d\n",i);
	for(int i=1;i<=m;i++)
		while(c[i]--) printf("col %d\n",i);
}