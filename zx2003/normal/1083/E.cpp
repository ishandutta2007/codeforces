#include<bits/stdc++.h>
using namespace std;
char ibuf[1<<26],*ih=ibuf;
template<typename T>inline void read(T&x){
	for(;!isdigit(*ih);++ih);
	for(x=0;isdigit(*ih);x=x*10+*ih++-48);
}
typedef __int128 lll;
typedef long long ll;
const int N=1e6+5;
struct P{int x;ll y;};
inline P operator-(P a,P b){return (P){a.x-b.x,a.y-b.y};}
inline lll cross(P a,P b){return (lll)a.x*b.y-(lll)b.x*a.y;}
struct rec{int x,y;ll a;}a[N];
int n,i,w,j;P st[N];
ll f[N],ans;
int main(){
	fread(ibuf,1,1<<26,stdin);
	read(n);for(i=1;i<=n;++i)read(a[i].x),read(a[i].y),read(a[i].a);
	sort(a+1,a+n+1,[&](const rec&a,const rec&b){return a.x<b.x;});
	st[1]=(P){0,0};w=j=1;
	for(i=1;i<=n;++i){
		auto calc=[&](int m){return st[m].y-1ll*a[i].y*st[m].x;};
		for(;j<w && calc(j+1)>calc(j);++j);
		f[i]=calc(j)+1ll*a[i].y*a[i].x-a[i].a;ans=max(ans,f[i]);
		P u=(P){a[i].x,f[i]};for(;w>1 && cross(u-st[w-1],st[w]-st[w-1])<=0;--w);
		st[++w]=u;j=min(j,w);
	}
	printf("%lld\n",ans);
}