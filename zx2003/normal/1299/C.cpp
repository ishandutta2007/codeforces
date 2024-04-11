#include<bits/stdc++.h>
const int N=1e6+5;
typedef long long ll;
struct P{
ll x,y;
inline P operator-(const P&rhs)const{return (P){x-rhs.x,y-rhs.y};}
}a[N];
inline ll cross(const P&a,const P&b){return 1ll*a.x*b.y-1ll*b.x*a.y;}
inline int sgn(ll x){return x?(x>0?1:-1):0;}
inline bool cmp(int x,int y){return a[x].x==a[y].x?a[x].y<a[y].y:a[x].x<a[y].x;}
int n,i,j,c[N],xb,id[N],ans[N],x;
char s[N];
bool b[N];
inline void CH(){
	static int st[N];int w=0,i;
	for(i=1;i<=n;++i)if(!b[id[i]]){
		for(;w>1 && cross(a[id[i]]-a[st[w-1]],a[st[w]]-a[st[w-1]])>=0;--w);
		st[++w]=id[i];
	}
	xb=w;memcpy(c+1,st+1,w<<2);
}
int main(){
	scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",&x),a[i]=(P){i,a[i-1].y+x},id[i]=i;
	CH();
	for(i=1;i<xb && cross(a[c[i]],a[c[i+1]])<=0;++i);c[i-1]=0;
	for(;i<=xb;++i){
		double k=(a[c[i]].y-a[c[i-1]].y)*1.0/(a[c[i]].x-a[c[i-1]].x);
		for(j=c[i-1]+1;j<=c[i];++j)printf("%.12f\n",k);
	}
	return 0;
}