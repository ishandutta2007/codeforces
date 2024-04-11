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
const int M=1.5e5+10; 
#define pii pair<int,int> 
#define vec vector<pii> 
#define mp make_pair
vec t[M<<3];
int len[M<<3];
int ct; 
#define mid (l+r>>1)
#define lc (x<<1)
#define rc (x<<1|1)
vec mg(vec A,vec B){
	vec ret=A; 
	F(i,0,SZ(B)){
		bool flag=0;
		int num=B[i].first,tim=B[i].second,mi=1e9,ps=-1;
		F(j,0,SZ(ret)){
			if (ret[j].first==num){
				ret[j].second+=tim; 
				flag=1;
			}
			if (ret[j].second<mi) mi=ret[j].second,ps=j;
		}
		if (flag) continue;		
		if (SZ(ret)+1<ct){
			ret.pb(B[i]);
			continue; 
		}
		if (ps==-1) continue; 
		if (tim>mi) ret[ps]=B[i]; 
		F(j,0,SZ(ret)) ret[j].second-=min(mi,tim); 
	}
	return ret;
}
int a[M],tg[M<<3];
void build(int x,int l,int r){
	len[x]=r-l+1;
	if (l==r){
		t[x].pb(mp(a[l],1)); 
		return ; 
	}
	build(lc,l,mid); build(rc,mid+1,r);
	t[x]=mg(t[lc],t[rc]);
//	cout<<l<<" "<<r<<"   range\n";
//	F(i,0,SZ(t[x])) cout<<t[x][i].first<<" "<<t[x][i].second<<"   sbyy\n";
//	cout<<"\n";
}
void cov(int x,int d){
	tg[x]=d; t[x].clear();
	t[x].pb(mp(d,len[x])); 
}
void pd(int x){
	if (tg[x]){
		cov(lc,tg[x]);
		cov(rc,tg[x]);
		tg[x]=0;
	}
}
void upd(int x,int l,int r,int ll,int rr,int d){
	if (l==ll && r==rr){
		cov(x,d); 
		return ;
	}
	pd(x); 
	if (rr<=mid) upd(lc,l,mid,ll,rr,d);
	else if (ll>mid) upd(rc,mid+1,r,ll,rr,d);
	else upd(lc,l,mid,ll,mid,d),upd(rc,mid+1,r,mid+1,rr,d); 
	t[x]=mg(t[lc],t[rc]);
}
vec qry(int x,int l,int r,int ll,int rr){
	if (l==ll && r==rr) return t[x];
	pd(x); 
	if (rr<=mid) return qry(lc,l,mid,ll,rr);
	if (ll>mid) return qry(rc,mid+1,r,ll,rr);
	return mg(qry(lc,l,mid,ll,mid),qry(rc,mid+1,r,mid+1,rr)); 
}
int n,m,p; 
int main(){
	n=read(); m=read(); p=read(); ct=100/p; 
	F(i,1,n) a[i]=read(); 
	build(1,1,n); 
	F(i,1,m){
		int op=read(),l=read(),r=read(),x;
		if (op==1){
			x=read();
			upd(1,1,n,l,r,x);
		} 
		else {
			vec tmp=qry(1,1,n,l,r);
			cout<<SZ(tmp)+1<<" ";
			F(j,0,SZ(tmp)) cout<<tmp[j].first<<" "; cout<<"\n";  
		}
	}
	return 0;
}