#include <bits/stdc++.h>
using namespace std;
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
const int N=3e5+7;
int n,m,cnt,lsh[N<<1];
vector<pii>a[N];
int pre[N],f[N];
bool vis[N];
struct Segment_Tree{
	int t[N<<3],pos[N<<3],gt[N<<3],gp[N<<3];
	#define ls (p<<1)
	#define rs (p<<1|1)
	inline void upd(int p){
		if(t[ls]>=t[rs])t[p]=t[ls],pos[p]=pos[ls];
		else t[p]=t[rs],pos[p]=pos[rs];
	}
	inline void spread(int p){
		if(!gt[p])return;
		if(gt[p]>t[ls])t[ls]=gt[p],pos[ls]=gp[p];
		if(gt[p]>t[rs])t[rs]=gt[p],pos[rs]=gp[p];
		if(gt[p]>gt[ls])gt[ls]=gt[p],gp[ls]=gp[p];
		if(gt[p]>gt[rs])gt[rs]=gt[p],gp[rs]=gp[p];
		gt[p]=gp[p]=0;
	}
	void modify(int p,int l,int r,int x,int y,int val,int P){
		if(x<=l && r<=y){
			if(gt[p]<val)gt[p]=val,gp[p]=P;
			if(t[p]<val)t[p]=val,pos[p]=P;
			return;
		}
		spread(p);int mid=(l+r)>>1;
		if(x<=mid)modify(ls,l,mid,x,y,val,P);
		if(y>mid)modify(rs,mid+1,r,x,y,val,P);
		upd(p);
	}
	pii query(int p,int l,int r,int x,int y){
		if(x<=l && r<=y)return pii(t[p],pos[p]);
		spread(p);int mid=(l+r)>>1;
		if(x>mid)return query(rs,mid+1,r,x,y);
		if(y<=mid)return query(ls,l,mid,x,y);
		pii v=query(ls,l,mid,x,y),w=query(rs,mid+1,r,x,y);
		return v.fi>=w.fi?v:w;
	}
}T;
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		int j=read(),l=read(),r=read();
		a[j].emplace_back(l,r),lsh[++cnt]=l,lsh[++cnt]=r;	
	}
	sort(lsh+1,lsh+cnt+1),cnt=unique(lsh+1,lsh+cnt+1)-lsh-1;
	for(int i=1;i<=n;i++)
		for(int j=0;j<(int)a[i].size();j++){
			a[i][j].fi=lower_bound(lsh+1,lsh+cnt+1,a[i][j].fi)-lsh;
			a[i][j].se=lower_bound(lsh+1,lsh+cnt+1,a[i][j].se)-lsh;
		}
	int k=0;
	for(int i=1;i<=n;i++){
		pii res=pii(0,0);
		for(auto x:a[i]){
			pii tmp=T.query(1,1,cnt,x.fi,x.se);
			if(res.fi<tmp.fi)res=tmp;
		}
		f[i]=res.fi+1,pre[i]=res.se;
		if(f[k]<f[i])k=i;
		for(auto x:a[i])T.modify(1,1,cnt,x.fi,x.se,f[i],i);
	}
	printf("%d\n",n-f[k]);
	while(k)vis[k]=1,k=pre[k];
	for(int i=1;i<=n;i++)if(!vis[i])printf("%d ",i);
	return 0;
}