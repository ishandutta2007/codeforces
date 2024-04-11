#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2005;
struct P{int x,y;}a[N];
void in(P&a){scanf("%d%d",&a.x,&a.y);}
void out(P a){printf("%d %d\n",a.x,a.y);}
P operator-(P a,P b){return (P){a.x-b.x,a.y-b.y};}
ll operator*(P a,P b){return 1ll*a.x*b.y-1ll*b.x*a.y;}
ll geta(int x,int y,int z){return abs((a[x]-a[z])*(a[y]-a[z]));}
void E(int x,int y,int z){puts("Yes");out(a[x]);out(a[y]);out(a[z]);exit(0);}
int n,i,j,id[N],rk[N];
ll S;
struct eve{
	P dt;int x,y;
	bool operator<(const eve&rhs)const{return dt*rhs.dt>0;}
	void setv(int i,int j){
		x=i;y=j;dt=a[x]-a[y];
		if(dt.x<0 || dt.x==0 && dt.y>0)dt=a[y]-a[x];
	}
	void doo(){
		int l,r,m,ix=id[x],iy=id[y];
		swap(rk[id[x]],rk[id[y]]);swap(id[x],id[y]);
		r=min(ix,iy)-1;
		if(r>0){
			for(l=1;l<r;)m=l+r>>1,geta(rk[m],x,y)<=S*2?r=m:l=m+1;
			if(geta(rk[l],x,y)==S*2)E(rk[l],x,y);
		}
		l=max(ix,iy)+1;
		if(l<n){
			for(r=n;l<r;)m=l+r>>1,geta(rk[m],x,y)<S*2?l=m+1:r=m;
			if(geta(rk[l],x,y)==S*2)E(rk[l],x,y);
		}
	}
}ev[N*N/2];int evcnt;
int main(){
	scanf("%d%lld",&n,&S);for(i=1;i<=n;++i)in(a[i]),rk[i]=i;
	sort(rk+1,rk+n+1,[&](int x,int y){return a[x].x==a[y].x?a[x].y>a[y].y:a[x].x<a[y].x;});
	for(i=1;i<=n;++i)id[rk[i]]=i;
	for(i=1;i<n;++i)for(j=i+1;j<=n;++j)ev[++evcnt].setv(i,j);sort(ev+1,ev+evcnt+1);
	for(i=1;i<=evcnt;++i)ev[i].doo();
	puts("No");
}