#include <cstdio>
#include <algorithm>
const int inf=1e9,W=11,N=1e5+10;
int n,m,nt,qnt,a[N],l[N],r[N],p[N],ls[N],nx[N],sz[N],bkt[N],ans[N];
template<typename T>void cmin(T &x,T y){if(x>y)x=y;}
namespace IO{
	int lt,nw,res,dig[30];char c;
	int read(){
		res=0;for(;c<'0'||c>'9';c=getchar());
		for(;!(c<'0'||c>'9');c=getchar())res=(res<<1)+(res<<3)+(c^48);
		return res;
	}
	void write(int x){
		if(!x)putchar('0');
		for(;x;x=nw)nw=x/10,dig[++lt]=x-(nw<<1)-(nw<<3);
		for(;lt;--lt)putchar(dig[lt]^48);putchar('\n');
	}
}using IO::read;using IO::write;
int bk(int x){return x>>W;}
struct opt{
	int id,l,r,t,k;opt(){};
	opt(int id,int l,int r,int t,int k):id(id),l(l),r(r),t(t),k(k){};
	bool operator<(const opt &nxt)const{
		int a1=bk(t),a2=bk(l),b1=bk(nxt.t),b2=bk(nxt.l);
		if(a1!=b1)return a1<b1;if(a2!=b2)return a2<b2;return r<nxt.r;
	}
}qrr[N];
void link(int t,int x,int y){ls[t]=x,nx[t]=y,ls[y]=t,nx[x]=t;}
void del(int x){if(!(--sz[x]))nx[ls[x]]=nx[x],ls[nx[x]]=ls[x];}
void inc(int x){int t=bkt[x]++;if(!(sz[t+1]++))link(t+1,t,nx[t]);del(t);}
void dec(int x){int t=bkt[x]--;if(!(sz[t-1]++))link(t-1,ls[t],t);del(t);}
void got(int t,int x,int y){a[p[t]]=r[t];if(p[t]<x||p[t]>y)return;dec(l[t]),inc(r[t]);}
void bat(int t,int x,int y){a[p[t]]=l[t];if(p[t]<x||p[t]>y)return;dec(r[t]),inc(l[t]);}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int x,y,k,i=1;i<=m;++i){
		switch(read()){
			case 1:x=read(),y=read(),k=read(),++qnt,qrr[qnt]=opt(qnt,x,y,nt,k);break;
			case 2:p[++nt]=read(),l[nt]=a[p[nt]],a[p[nt]]=r[nt]=read();break;
			default:puts("I AK IOI!");break;
		}
	}
	for(int i=nt;i;--i)a[p[i]]=l[i];
	sz[0]=n+1,std::sort(qrr+1,qrr+qnt+1);
	for(int t=0,p=1,q=0,i=1;i<=qnt;++i){
		int l=qrr[i].l,r=qrr[i].r,g=qrr[i].t,k=qrr[i].k,id=qrr[i].id;
		while(p>l)inc(a[--p]);while(q<r)inc(a[++q]);
		while(p<l)dec(a[p++]);while(q>r)dec(a[q--]);
		while(t<g)got(++t,p,q);while(t>g)bat(t--,p,q);ans[id]=inf;
		for(int v=0,s=0,i=nx[0];i;s-=sz[i],i=nx[i]){
			while(nx[v]&&s<k)s+=sz[v=nx[v]];
			if(s<k)break;cmin(ans[id],v-i);
		}
	}
	for(int i=1;i<=qnt;++i){
		if(ans[i]==inf)puts("-1");
		else write(ans[i]);
	}
	return 0;
}