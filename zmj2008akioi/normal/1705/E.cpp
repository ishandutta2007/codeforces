#pragma GCC optimize("Ofast")
#include <cstdio>
#include <cstring>
const int N=2e5+30;
int n,q,a[N];
inline int min(int x,int y){return x<y?x:y;}
namespace SGT{
	int L=1,R=2e5+20;
	int l0[N<<2],l1[N<<2],lif[N<<2],rig[N<<2],len[N<<2],sum[N<<2],cov[N<<2];
	inline int lc(int x){return x<<1;}
	inline int rc(int x){return (x<<1)+1;}
	inline int md(int x,int y){return (x+y)>>1;}
	inline void cover(int x,int d){cov[x]=d,sum[x]=len[x]*d;if(d)l0[x]=N,l1[x]=lif[x];else l1[x]=N,l0[x]=lif[x];}
	inline void pushup(int x){sum[x]=sum[lc(x)]+sum[rc(x)],l0[x]=min(l0[lc(x)],l0[rc(x)]),l1[x]=min(l1[lc(x)],l1[rc(x)]);}
	inline void pushdown(int x){if(~cov[x])cover(lc(x),cov[x]),cover(rc(x),cov[x]),cov[x]=-1;}
	void build(int l,int r,int u){
		lif[u]=l,rig[u]=r;
		if(l==r)len[u]=1,l0[u]=l,l1[u]=N;
		else build(l,md(l,r),lc(u)),build(md(l,r)+1,r,rc(u)),pushup(u),len[u]=r-l+1;
	}
	inline void init(){
		memset(cov,0xff,sizeof(cov));
		build(L,R,1);
	}
	int findr0(int l,int r,int u,int tl,int tr){
		if(l>=tl&&r<=tr)return l0[u];
		else{
			pushdown(u);int res=N;
			if(md(l,r)>=tl)res=min(res,findr0(l,md(l,r),lc(u),tl,tr));
			if(md(l,r)+1<=tr)res=min(res,findr0(md(l,r)+1,r,rc(u),tl,tr));
			return res;
		}
	}
	int findr1(int l,int r,int u,int tl,int tr){
		if(l>=tl&&r<=tr)return l1[u];
		else{
			pushdown(u);int res=N;
			if(md(l,r)>=tl)res=min(res,findr1(l,md(l,r),lc(u),tl,tr));
			if(md(l,r)+1<=tr)res=min(res,findr1(md(l,r)+1,r,rc(u),tl,tr));
			return res;
		}
	}
	int gsum(int l,int r,int u,int tl,int tr){
		if(l>=tl&&r<=tr)return sum[u];
		else{
			int res=0;pushdown(u);
			if(md(l,r)>=tl)res+=gsum(l,md(l,r),lc(u),tl,tr);
			if(md(l,r)+1<=tr)res+=gsum(md(l,r)+1,r,rc(u),tl,tr);
			return res;
		}
	}
	void cover(int l,int r,int u,int tl,int tr,int w){
		if(tl>tr)return;
		if(l>=tl&&r<=tr)cover(u,w);
		else{
			pushdown(u);
			if(md(l,r)>=tl)cover(l,md(l,r),lc(u),tl,tr,w);
			if(md(l,r)+1<=tr)cover(md(l,r)+1,r,rc(u),tl,tr,w);
			pushup(u);
		}
	}
	void add(int u){
		int l=findr0(L,R,1,u,R);
		cover(L,R,1,l,l,1);
		cover(L,R,1,u,l-1,0);
	}
	void del(int u){
		int l=findr1(L,R,1,u,R);
		cover(L,R,1,l,l,0);
		cover(L,R,1,u,l-1,1);
	}
	int query(){
		int mid,l=L,r=R;
		while(l!=r){
			mid=md(l,r);
			if(gsum(L,R,1,mid,R))l=mid+1;
			else r=mid;
		}
		return l-1;
	}
}
int main(){
	scanf("%d %d",&n,&q),SGT::init();
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		SGT::add(a[i]);
	}
	for(int k,l,i=1;i<=q;++i){
		scanf("%d %d",&k,&l);
		SGT::del(a[k]),SGT::add(a[k]=l);
		printf("%d\n",SGT::query());
	}
	return 0;
}