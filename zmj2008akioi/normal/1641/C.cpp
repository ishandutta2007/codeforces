#include <cstdio>
#include <cstring>
const int rt=1,inf=0x3f3f3f3f,N=2e5+10;
int n,q;
namespace basic{
	int res;
	char cdc;
	inline int md(int x,int y){return (x+y)>>1;}
	inline int min(int x,int y){return x<y?x:y;}
	inline void cmin(int &x,int y){if(x>y)x=y;}
	inline int read(){
		res=0;
		for(;cdc<'0'||cdc>'9';cdc=getchar());
		for(;!(cdc<'0'||cdc>'9');cdc=getchar())res=(res<<1)+(res<<3)+(cdc^48);
		return res;
	}
}using basic::md;using basic::min;using basic::cmin;using basic::read;
inline int lc(int x){return x<<1;}
inline int rc(int x){return (x<<1)+1;}
namespace SGT1{
	//covered by 0
	bool cov[N<<2],tag[N<<2];
	inline void cover(int x){cov[x]|=1,tag[x]|=1;}
	inline void pushup(int x){cov[x]=cov[lc(x)]&cov[rc(x)];}
	inline void pushdown(int x){if(tag[x])cover(lc(x)),cover(rc(x));}
	void modify(int l,int r,int u,int tl,int tr){
		if(l>=tl&&r<=tr)cover(u);
		else{
			pushdown(u);
			if(md(l,r)>=tl)modify(l,md(l,r),lc(u),tl,tr);
			if(md(l,r)+1<=tr)modify(md(l,r)+1,r,rc(u),tl,tr);
			pushup(u);
		}
	}
	bool query(int l,int r,int u,int tl,int tr){
		if(tl>tr)return true;
		if(l>=tl&&r<=tr)return cov[u];
		else{
			bool res=true;
			pushdown(u);
			if(md(l,r)>=tl)res&=query(l,md(l,r),lc(u),tl,tr);
			if(md(l,r)+1<=tr)res&=query(md(l,r)+1,r,rc(u),tl,tr);
			return res;
		}
	}
}
namespace SGT2{
	int rig[N<<2];
	inline void init(){memset(rig,0x3f,sizeof(rig));}
	inline void pushup(int x){rig[x]=min(rig[lc(x)],rig[rc(x)]);}
	void modify(int l,int r,int u,int tg,int d){
		if(l==r)cmin(rig[u],d);
		else{
			if(md(l,r)>=tg)modify(l,md(l,r),lc(u),tg,d);
			else modify(md(l,r)+1,r,rc(u),tg,d);
			pushup(u);
		}
	}
	int query(int l,int r,int u,int tl,int tr){
		if(l>=tl&&r<=tr)return rig[u];
		else{
			int res=inf;
			if(md(l,r)>=tl)cmin(res,query(l,md(l,r),lc(u),tl,tr));
			if(md(l,r)+1<=tr)cmin(res,query(md(l,r)+1,r,rc(u),tl,tr));
			return res;
		}
	}
}
int main(){
	n=read(),q=read(),SGT2::init();
	for(int opt,i=1;i<=q;++i){
		opt=read();
		if(opt==0){
			int l=read(),r=read(),x=read();
			if(!x)SGT1::modify(1,n,1,l,r);
			else SGT2::modify(1,n,1,l,r);
		}
		if(opt==1){
			int l,r,L,R,mid,u=read();
			if(SGT1::query(1,n,1,u,u)){puts("NO");continue;}
			l=1,r=u;
			while(l!=r){
				mid=md(l,r);
				if(SGT1::query(1,n,1,mid,u-1))r=mid;
				else l=mid+1;
			}
			L=l,l=u,r=n;
			while(l!=r){
				mid=md(l,r+1);
				if(SGT1::query(1,n,1,u+1,mid))l=mid;
				else r=mid-1;
			}
			R=r,puts(SGT2::query(1,n,1,L,u)<=R?"YES":"N/A");
		}
	}
	return 0;
}