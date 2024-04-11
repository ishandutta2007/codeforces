#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10; 
int ct[M<<3],mi[M<<3],tg[M<<3],ti[M<<3];
LL as[M<<3];
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
void pu(int x){
	mi[x]=min(mi[lc],mi[rc]); ct[x]=0;
	if (mi[x]==mi[lc]) ct[x]+=ct[lc]; 
	if (mi[x]==mi[rc]) ct[x]+=ct[rc];
}
void jia(int x,int y){
	mi[x]+=y;
	tg[x]+=y;
}
void xiu(int x,int t){
	as[x]+=1ll*t*ct[x];
	ti[x]+=t;
}
void pd(int x){
	if (tg[x]){
		jia(lc,tg[x]);
		jia(rc,tg[x]);
		tg[x]=0;
	}
	if (ti[x]){
		if (mi[x]==mi[lc]) xiu(lc,ti[x]);
		if (mi[x]==mi[rc]) xiu(rc,ti[x]);
		ti[x]=0;
	}
}
void build(int x,int l,int r){
	if (l==r){
		mi[x]=-l;
		ct[x]=1;
		return ;
	}
	build(lc,l,mid);
	build(rc,mid+1,r); 
	pu(x);
}
void upd(int x,int l,int r,int ll,int rr,int d){//	cerr<<x<<"\n";
	if (l==ll && r==rr){
		jia(x,d);
		return ;
	}
	pd(x);
	if (rr<=mid) upd(lc,l,mid,ll,rr,d);
	else if (ll>mid) upd(rc,mid+1,r,ll,rr,d);
	else upd(lc,l,mid,ll,mid,d),upd(rc,mid+1,r,mid+1,rr,d);
	pu(x);
}
LL qry(int x,int l,int r,int ll,int rr){

	if (l==ll && r==rr) return as[x];
	pd(x);
	if (rr<=mid) return qry(lc,l,mid,ll,rr);
	if (ll>mid) return qry(rc,mid+1,r,ll,rr);
	return  qry(lc,l,mid,ll,mid)+qry(rc,mid+1,r,mid+1,rr);
}
struct Q{
	int r,id;
};
int si[M],sx[M];
vector<Q> v[M];
LL ans[M];
int n,m,p[M];
int main(){
	n=read();
	F(i,1,n) p[i]=read();
	build(1,1,n);
//	cout<<ct[1]<<" "<<as[1]<<"     hhhh \n"; 
	m=read();
	F(i,1,m){
		int x=read(),y=read();
		v[x].pb((Q){y,i});
	}
//	cerr<<"   good \n";
	int px=1,pi=1; si[1]=sx[1]=n+1;
	DF(i,n,1){
		while (px>1 && p[i]>p[sx[px]]){
			upd(1,1,n,sx[px],sx[px-1]-1,-p[sx[px]]);
			px--;
		}
		upd(1,1,n,i,sx[px]-1,p[i]);
		sx[++px]=i;
		while (pi>1 && p[i]<p[si[pi]]){
			upd(1,1,n,si[pi],si[pi-1]-1,p[si[pi]]);
			pi--;
		}
		upd(1,1,n,i,si[pi]-1,-p[i]);		
		si[++pi]=i;
		xiu(1,1);
		for (auto O:v[i]){
			int pr=O.r,id=O.id;
			ans[id]=qry(1,1,n,i,pr);
		}
//		cout<<ct[1]<<" "<<as[1]<<"     hhhh \n"; 
	}
	F(i,1,m){
		cout<<ans[i]<<"\n";
	}
	return 0;
}
/*
*/