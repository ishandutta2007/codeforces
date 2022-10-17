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
const int M=1e5+10;
int n,m;
LL a[M];
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
LL suan(LL x){
	LL tmp=1;
	while (x>tmp) tmp=tmp*42;
	return tmp-x;
}
LL mi[M<<3],tg[M<<3],tgv[M<<3],val[M<<3];// minimum gap / minus tag / assignment tag
bool sm[M<<3];
void pu(int x){
	mi[x]=min(mi[lc],mi[rc]);
	val[x]=min(val[lc],val[rc]);
	sm[x]=0;
}
void build(int x,int l,int r){
	if (l==r){
		val[x]=a[l];
		mi[x]=suan(a[l]);
		return ;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	pu(x);
//	cerr<<val[x]<<"  val val\n";
}
void assign(int x,LL y){
//	cout<<x<<"   fuck \n";
	val[x]=tgv[x]=y;
	sm[x]=1;
	mi[x]=suan(y);
//	assert(y>2);
}
void sub(int x,LL y){
	val[x]+=y;
	if (tgv[x]) tgv[x]+=y;
	mi[x]-=y;
	tg[x]+=y;
}
void pd(int x){
	if (tg[x]){
		sub(lc,tg[x]);
		sub(rc,tg[x]);
		tg[x]=0;
	}
	if (tgv[x]){
//		cout<<x<<" "<<tgv[2]<<"   og\n";
//		assert(tgv[x]>2);
		assign(lc,tgv[x]);
		assign(rc,tgv[x]);
		tgv[x]=0;
	}
}
void upde(int x,int l,int r,int ll,int rr,int v){
	if (r<ll || l>rr) return ;
	if (ll<=l && r<=rr){
//		assert(v>2);
		assign(x,v);
		return ;
	}
	pd(x);
	upde(lc,l,mid,ll,rr,v);
	upde(rc,mid+1,r,ll,rr,v);
	pu(x);
}
void upd(int x,int l,int r,int ll,int rr,int v){
	if (r<ll || l>rr) return ;
//	cout<<l<<" "<<r<<" "<<val[x]<<" "<<tgv[x]<<"  ri ni ma val \n";
	if (ll<=l && r<=rr){
		if (mi[x]>=v){
			sub(x,v);
			return ;
		}
		if (l==r || sm[x]){
//			cerr<<"assign "<<l<<" "<<r<<" "<<val[x]<<"   hh\n";
			val[x]+=v;
//			assert(val[x]>=0);
			assign(x,val[x]);
			return ;
		}
	}
	pd(x);
	upd(lc,l,mid,ll,rr,v);
	upd(rc,mid+1,r,ll,rr,v);
	pu(x);
}
LL qry(int x,int l,int r,int p){
	if (l==r) return val[x];
	pd(x);
	if (p<=mid) return qry(lc,l,mid,p);
	return qry(rc,mid+1,r,p);
}
int main(){
	n=read(); m=read();
	F(i,1,n) a[i]=read();
	build(1,1,n);
	F(i,1,m){
		int op=read(),l,r,x;
		if (op>1) l=read(),r=read();
		x=read();
		if (op==1) cout<<qry(1,1,n,x)<<"\n";
		if (op==2) upde(1,1,n,l,r,x);
		if (op==3){
			upd(1,1,n,l,r,x);
			while (!mi[1]) upd(1,1,n,l,r,x);//,cerr<<"   again\n";
		}
//		cout<<tgv[2]<<" "<<tgv[1]<<"   val of rt \n";
	}
	return 0;
}
/* 
6 18
40 1700 7 1672 4 1722
3 2 4 42
1 2
1 3
3 2 6 50
1 2
1 4
1 6
2 3 4 41
1 1
1 2
1 3
1 4
1 5
1 6
3 1 5 1
1 1
1 3
1 5


stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/