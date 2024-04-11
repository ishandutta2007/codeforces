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
#define SZ 277777
//orz kczno1    POD only
template<typename T>
struct vec{T *a;int n;void clear(){n=0;}
void pb(const T &x){if((n&-n)==n)a=(T*)realloc(a,(n*2)*sizeof(T));a[n++]=x;}
inline T* begin(){return a;}inline T* end() {return a+n;}};
set<int> app[100066];
const int M=131072;
int n,m,x[SZ],ro[SZ];
#define S2 14700000
ll sum[S2];
int ch[S2][2],rot[SZ],an=0;
void ins(int r1,int& r2,int l,int r,int p,int q)
{
	if(r1) r2=r1; else r2=++an;
	sum[r2]=sum[r1]+q;
    if(l==r) return; int mid=l+r>>1;
    if(p<=mid) ins(ch[r1][0],ch[r2][0],l,mid,p,q), ch[r2][1]=ch[r1][1];
    else ins(ch[r1][1],ch[r2][1],mid+1,r,p,q), ch[r2][0]=ch[r1][0];
}
ll query(int ro,int l,int r,int p)
{
    if(l>p||!sum[ro]) return 0;
    if(r<=p) return sum[ro];
    int mid=l+r>>1; ll ans=0;
    ans+=query(ch[ro][0],l,mid,min(p,mid));
    if(p>mid) ans+=query(ch[ro][1],mid+1,r,p);
    return ans;
}
void ins(int x,int y,int z)
{
	for(;y<=n;y+=y&-y)
		ins(ro[y],ro[y],1,n,x,z);
}
ll qry(int x,int y)
{
	ll ans=0;
	for(;y>=1;y-=y&-y)
	{
		int b=ro[y];
		ans+=sum[b]-query(b,1,n,x-1);
	}
	return ans;
}
void init(int x)
{
	for(auto g=app[x].begin();g!=app[x].end();
	++g) if(g!=app[x].begin()) 
	{
		auto s=g; --s;
		ins(*s,*g,*g-*s);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",x+i),app[x[i]].insert(i);
	for(int i=1;i<=n;++i) init(i);
	while(m--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a==1)
		{
			auto w=app[x[b]].find(b);
			int A=0;
			if(w!=app[x[b]].begin())
			{
				auto s=w; --s; ++A;
				ins(*s,*w,*s-*w);
			}
			{
				auto s=w; ++s;
				if(s!=app[x[b]].end())
					ins(*w,*s,*w-*s),++A;
			}
			if(A==2)
			{
				auto a=w,b=w;
				--a, ++b;
				ins(*a,*b,*b-*a);
			}
			A=0;
			app[x[b]].erase(w);
			x[b]=c; w=app[c].insert(b).fi;
			if(w!=app[c].begin())
			{
				auto s=w; --s;
				ins(*s,*w,*w-*s),++A;
			}
			{
				auto s=w; ++s;
				if(s!=app[c].end())
					ins(*w,*s,*s-*w),++A;
			}
			if(A==2)
			{
				auto a=w,b=w;
				--a, ++b;
				ins(*a,*b,*a-*b);
			}
		}
		else
			printf("%I64d\n",qry(b,c));
	}
}