#include <bits/stdc++.h>
using namespace std;
#define y1 __y1__
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
#define pii pair<int,int>
#define fi first
#define se second
const int N=1e5+7,inf=1e7;
struct node{
	int x,y,t;
}q[N];
struct plane{
	int x1,y1,x2,y2,h,id;
}a[N];
struct KD_Tree{
	int tot,id[N],ls[N],rs[N],xl[N],xr[N],yl[N],yr[N];
	pii t[N];
	inline void upd(int p){
		t[p]=min({t[ls[p]],t[rs[p]],(pii){q[id[p]].t,id[p]}});
	}
	void build(int &p,int l,int r,int o){
		if(l>r)return;
		p=++tot,xl[p]=yl[p]=inf;
		for(int i=l;i<=r;i++){
			xl[p]=min(xl[p],q[i].x),xr[p]=max(xr[p],q[i].x);
			yl[p]=min(yl[p],q[i].y),yr[p]=max(yr[p],q[i].y);
		}
		id[p]=(l+r)>>1;
		//cout<<p<<" "<<xl[p]<<" "<<xr[p]<<" "<<yl[p]<<" "<<yr[p]<<endl;
		if(l==r)return upd(p);
		if(o)nth_element(q+l,q+id[p],q+r+1,[&](auto x,auto y){return x.x<y.x;});
		else nth_element(q+l,q+id[p],q+r+1,[&](auto x,auto y){return x.y<y.y;});
		o^=1,build(ls[p],l,id[p]-1,o),build(rs[p],id[p]+1,r,o),upd(p);
	}
	void modify(int p,int x){
		if(x<id[p])modify(ls[p],x);
		else if(x>id[p])modify(rs[p],x);
		else q[x].t=inf;
		upd(p);
	}
	pii query(int p,int x1,int x2,int y1,int y2){
		if(!p || xl[p]>x2 || xr[p]<x1 || yl[p]>y2 || yr[p]<y1)return {inf,0};
		if(x1<=xl[p] && xr[p]<=x2 && y1<=yl[p] && yr[p]<=y2)return t[p];
		pii mn=min(query(ls[p],x1,x2,y1,y2),query(rs[p],x1,x2,y1,y2));
		if(x1<=q[id[p]].x && q[id[p]].x<=x2 && y1<=q[id[p]].y && q[id[p]].y<=y2)
			mn=min(mn,pii(q[id[p]].t,id[p]));
		return mn;
	}
}T;
int n,m,rt,ans[N];
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read();
	for(int i=1;i<=n;i++)
		a[i].x1=read(),a[i].x2=read(),a[i].y1=read(),a[i].y2=read(),a[i].h=read(),a[i].id=i;
	sort(a+1,a+n+1,[&](auto x,auto y){return x.h<y.h;});
	m=read();
	for(int i=1;i<=m;i++)q[i].x=read(),q[i].y=read(),q[i].t=i;
	T.t[0]={inf,0},T.build(rt,1,m,1);
	for(int i=1;i<=n;i++){
		pii x=T.query(rt,a[i].x1,a[i].x2,a[i].y1,a[i].y2);
		if(x.fi!=inf)ans[x.fi]=a[i].id,T.modify(rt,x.se);
	}
	for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
	return 0;
}