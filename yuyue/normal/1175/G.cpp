#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define int LL
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=4e4+10; 
const int inf=1e9; 
int dp[111][M];
struct Line{
	int k,b; 
	Line (int _=0,int __=0){
		k=_ ; b=__;
	}
	int gv(int x){
		return k*x+b; 
	}
}t[M<<3];
struct pv{
	int x,y;
	pv(int _=0,int __=0){
		x=_; y=__; 
	}
};
#define lc (x<<1) 
#define rc (x<<1|1)
#define mid (l+r>>1)
void build(int x,int l,int r){
	t[x].k=0; t[x].b=inf; 
	if (l==r){
		return ;
	}
	build(lc,l,mid); build(rc,mid+1,r);
}
int qry(int x,int l,int r,int p){
	if (l==r) return t[x].gv(p);
	int tmp=t[x].gv(p);
	if (p<=mid) return min(tmp,qry(lc,l,mid,p)); 
	return min(tmp,qry(rc,mid+1,r,p));
}
void upd(int x,int l,int r,int ll,int rr,Line o){
	if (ll>r || rr<l) return;
	if (ll<=l && r<=rr){
		if (o.gv(mid)<t[x].gv(mid))swap(t[x],o);
		if (l==r) return; 
		if (o.gv(l)<t[x].gv(l)) upd(lc,l,mid,ll,rr,o);
		if (o.gv(r)<t[x].gv(r)) upd(rc,mid+1,r,ll,rr,o);
		return ; 
	}
	upd(lc,l,mid,ll,rr,o);
	upd(rc,mid+1,r,ll,rr,o);
}
#undef mid
int L[M],R[M],a[M],tid[M];
deque<int> q[M];
inline int Y(int x,int o){
	return dp[o][x];
}
void pf(int id,int x,int o){
	while (q[id].size()>1){
		int pp=q[id].front(),p=q[id][1];
		if (1ll*(Y(p,o)-Y(pp,o))*(pp-x)<=1ll*(Y(pp,o)-Y(x,o))*(p-pp)) q[id].pop_front();
		else break; 
	}
	q[id].push_front(x); 
}
void ib(int id,int x,int o){
	while (q[id].size()>1){
		int pp=q[id].back(),p=q[id][SZ(q[id])-1];
		if (1ll*(Y(pp,o)-Y(p,o))*(x-pp)>=1ll*(Y(x,o)-Y(pp,o))*(pp-p)) q[id].pop_back();
		else break; 
	}
	q[id].push_back(x); 
}
int tt,n;
void solve(int o,int x,int l,int r){
	if (L[x]) solve(o,L[x],l,x-1);
	int len1=x-l,len2=r-x,ob=tid[L[x]];
	if (!L[x]){
		while (q[ob].size()) q[ob].pop_back(); 
	}
	ib(ob,x-1,o); 
	int ll=1,rr=SZ(q[ob]),ans=0;
	while (ll<=rr){
		int mid=(ll+rr>>1);
		if (Y(q[ob][mid],o)-Y(q[ob][mid-1],o)<=1ll*(q[ob][mid]-q[ob][mid-1])*a[x]){
			ans=mid; ll=mid+1;
		}
		else rr=mid-1;
	}
//	cout<<x<<" "<<l<<" "<<r<<"  tree\n";
//	cout<<SZ(q[ob])<<" "<<q[ob][ans]<<" "<<x<<" <-> "<<r<<" add line K: "<<a[x]<<" B:"<<Y(q[ob][ans],o)-a[x]*q[ob][ans]<<"  jj\n";
	if (SZ(q[ob])>=0) upd(1,0,n,x,r,Line(a[x],Y(q[ob][ans],o)-a[x]*q[ob][ans]));
	if (R[x]) solve(o,R[x],x+1,r);
	if (!L[x] && !R[x]){
		tid[x]=++tt;
		pf(tid[x],x-1,o);
		return; 
	}
	if (len1<len2){
		tid[x]=tid[R[x]];
		pf(tid[x],x-1,o);
		if (L[x]){
			int tmp=tid[L[x]];
			while(q[tmp].size()){
				pf(tid[x],q[tmp].back(),o); 
				q[tmp].pop_back();
			}
		}
	}
	else{
		tid[x]=tid[L[x]];
		ib(tid[x],x-1,o);
		if (R[x]){
			int tmp=tid[R[x]];
			while(q[tmp].size()){
				ib(tid[x],q[tmp].front(),o); 
				q[tmp].pop_front();
			}
		}
	}
//	cout<<SZ(q[tid[x]])<<" "<<l<<" "<<r<<"   ggsb\n";
} 
int rt,k,tp,s[M]; 
signed main(){
	n=read(); k=read(); 
	F(i,1,n) a[i]=read();
	ms(dp,64); dp[0][0]=0;
	F(i,1,n){
		int tmp=tp;
		while (tp && a[s[tp]]<a[i]) tp--;
		if (tmp>tp) L[i]=s[tp+1];
		if (tp) R[s[tp]]=i; 
		s[++tp]=i;  
	}
	rt=s[1];
	int tmp=0; 
//	F(i,1,n) tmp=max(tmp,a[i]),dp[1][i]=i*tmp;  
	F(i,1,k){
		build(1,0,n);
		solve(i-1,rt,1,n);
		F(j,1,n) dp[i][j]=qry(1,0,n,j);
		ms(tid,0);
		F(j,1,tt){
			while (q[j].size()) q[j].pop_back(); 
		} 
		tt=0;
	}
	cout<<dp[k][n]<<"\n"; 
	return 0;
}