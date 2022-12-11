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
int n,k,a[SZ],pre[SZ],cp[SZ];
int f[53][35003];
const int M=65536,M2=M+M;
int ls[SZ],rs[SZ];
int mx[SZ],tag[SZ];
void build()
{
	memset(mx,0,sizeof(int)*(M+M));
	memset(tag,0,sizeof(int)*(M+M));
}
inline void pd(int x)
{
    if(tag[x])
    {
        mx[x]+=tag[x];
        if(x<=M) tag[x+x]+=tag[x], tag[x+x+1]+=tag[x];
        tag[x]=0;
    }
}
void upd(int x)
{
    pd(x+x); pd(x+x+1);
    mx[x]=max(mx[x+x],mx[x+x+1]);
}
void edit(int x,int ql,int qr,int v)
{
    if(x>M2||qr<ls[x]||rs[x]<ql) return;
    pd(x);
    if(ql<=ls[x]&&rs[x]<=qr) {tag[x]+=v; return;}
    int mid=ls[x]+rs[x]>>1;
    edit(x+x,ql,qr,v);
    edit(x+x+1,ql,qr,v);
    upd(x);
}
int gmax(int x,int ql,int qr)
{
    if(x>M2||qr<ls[x]||rs[x]<ql) return -1e9;
    pd(x);
    if(ql<=ls[x]&&rs[x]<=qr) return mx[x];
    int mid=ls[x]+rs[x]>>1;
    int gg=max(gmax(x+x,ql,qr),gmax(x+x+1,ql,qr));
    upd(x); return gg;
}
int main()
{
    for(int i=M+1;i<=M+M;i++) ls[i]=rs[i]=i-M;
    for(int i=M-1;i;i--) ls[i]=ls[i+i], rs[i]=rs[i+i+1];
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i),pre[i]=cp[a[i]],cp[a[i]]=i;
	for(int i=1;i<=k;++i)
	{
		build();
		for(int j=1;j<=n;++j)
		{
			edit(1,1,pre[j],-1);
			f[i][j]=gmax(1,1,j)+j;
			edit(1,j+1,j+1,f[i-1][j]-j);
		}
	}
	printf("%d\n",f[k][n]);
}