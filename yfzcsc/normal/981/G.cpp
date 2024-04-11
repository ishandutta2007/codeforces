#include<bits/stdc++.h>
#define maxn 200100
#define mod 998244353
using namespace std;
struct Data{int l,r,v;int operator<(const Data& d)const{return r<d.r;}};
int atg[maxn<<2],mtg[maxn<<2],sum[maxn<<2],len[maxn<<2],n,m,q;
set<Data>st[maxn];
Data A[maxn];
void _pd(int o,int a,int b){
	atg[o]=(1ll*atg[o]*a+b)%mod;
	mtg[o]=1ll*mtg[o]*a%mod;
	sum[o]=(1ll*sum[o]*a+1ll*len[o]*b)%mod;
}
void pd(int o){
	if(mtg[o]==1&&atg[o]==0)return ;
	_pd(o<<1,mtg[o],atg[o]);
	_pd(o<<1|1,mtg[o],atg[o]);
	mtg[o]=1,atg[o]=0;
}
void upd(int o){
	sum[o]=(sum[o<<1]+sum[o<<1|1])%mod;
}
void build(int o,int l,int r){
	len[o]=r-l+1,mtg[o]=0;
	if(l==r)return ;
	int mid=l+r>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
}
void mdy(int o,int l,int r,int ql,int qr,int a,int b){
//	if(o==1)printf("{%d,%d,%d,%d}\n",ql,qr,a,b);
	if(ql<=l&&r<=qr){
		_pd(o,a,b);
		return ;
	}
	int mid=l+r>>1;
	pd(o);
	if(ql<=mid)mdy(o<<1,l,mid,ql,qr,a,b);
	if(qr>mid)mdy(o<<1|1,mid+1,r,ql,qr,a,b);
	upd(o);
}
int qry(int o,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)return sum[o];
	int mid=l+r>>1,ans=0;
	pd(o);
	if(ql<=mid)ans=qry(o<<1,l,mid,ql,qr);
	if(qr>mid)ans=(ans+qry(o<<1|1,mid+1,r,ql,qr))%mod;
	return ans;
}
void ins(int x,int l,int r){
	auto it=st[x].lower_bound(Data{0,l,0});
	if(r<=it->r){
		if(it->v){
			mdy(1,1,n,l,r,2,0);
		} else {
			mdy(1,1,n,l,r,1,1);
			Data d=*it;
			st[x].erase(d);
			if(d.l<l)st[x].insert(Data{d.l,l-1,0});
			if(d.r>r)st[x].insert(Data{r+1,d.r,0});
			st[x].insert(Data{l,r,1});
		}
	} else {
		int tp=0;
		while(it!=st[x].end()&&it->l<=r){
			A[++tp]=*it++;
			st[x].erase(A[tp]);
		}
		for(int i=1;i<=tp;++i){
			int L=max(l,A[i].l),R=min(r,A[i].r);
			if(A[i].v)mdy(1,1,n,L,R,2,0);
			else mdy(1,1,n,L,R,1,1);
			if(A[i].l<l)st[x].insert(Data{A[i].l,l-1,A[i].v});
			if(A[i].r>r)st[x].insert(Data{r+1,A[i].r,A[i].v});
		}
		st[x].insert(Data{l,r,1});
	}
}
int main(){
	scanf("%d%d",&n,&q);
	build(1,1,n);
	for(int i=1;i<=n;++i)st[i].insert(Data{1,n,0});
	for(int i=1,op,l,r,x;i<=q;++i){
		scanf("%d",&op);
		if(op==1)scanf("%d%d%d",&l,&r,&x),ins(x,l,r);
		else scanf("%d%d",&l,&r),printf("%d\n",qry(1,1,n,l,r));
	}
}