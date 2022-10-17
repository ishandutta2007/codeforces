#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
//#define OO(x) fixed<<setprecision(x)
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1e6+10;
struct Q{
	int l,r,id;
}q[M];
int n,m,p[M];
const int N=M<<2;
int len[N],tg[N],mi[N],nm[N],tn[N];
LL sm[N],smh[N],ad[N],adh[N];
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
void pu(int x){
	mi[x]=min(mi[lc],mi[rc]);
	nm[x]=(mi[x]==mi[lc] ? nm[lc] :0)+(mi[x]==mi[rc] ? nm[rc] :0);
	sm[x]=sm[lc]+sm[rc];
	smh[x]=smh[lc]+smh[rc];
}
void build(int x,int l,int r){
//	cerr<<x<<" "<<l<<" "<<r<<"\n";
	len[x]=r-l+1;
	if (l==r){
		mi[x]=0; nm[x]=1;
//		sm[x]=smh[x]=a[l];
		return ;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	pu(x);
}

void madh(int x,LL y,bool dm){
	if (dm) {
		smh[x]+=y*len[x];
//		cerr<<x<<" "<<y<<" "<<len[x]<<"   fuck you\n";
	}
//	cerr<<x<<" "<<y<<"  jia cao\n";
	adh[x]+=y;
}
void mad(int x,LL y){
	if (tg[x]){	
//		cerr<<x<<" "<<tg[x]<<" "<<y<<"   fuck \n";
		madh(x,-1ll*tg[x]*y,0);
	}
	ad[x]+=y;
	sm[x]+=y*len[x];
}
void mtg(int x,int y){
	tg[x]+=y,smh[x]+=1ll*y*nm[x];
}
void tad(int x,int y){
	if (!y) return ;
	tn[x]+=y;
	mi[x]+=y;
}
void pd(int x){
	if (tn[x]){
		tad(lc,tn[x]);
		tad(rc,tn[x]);
		tn[x]=0;
	}
//	if (ad[x]){
//		mad(lc,ad[x]);
//		mad(rc,ad[x]);
//		ad[x]=0;
//	}
//	if (adh[x]){
////		cerr<<x<<" "<<adh[x]<<"   rinima\n"; 
//		madh(lc,adh[x],1);
//		madh(rc,adh[x],1);
//		adh[x]=0;
//	}
	if (tg[x]){
		if (mi[x]==mi[lc])
		mtg(lc,tg[x]);
		if (mi[x]==mi[rc])
		mtg(rc,tg[x]);
		tg[x]=0;
	}
	
}
void upd(int x,int l,int r,int ll,int rr,int y){
	if (r<ll || l>rr) return ;
	if (ll<=l && r<=rr){
//		mad(x,y);
		tad(x,y);
		return ;
	}
	pd(x);
	upd(lc,l,mid,ll,rr,y);
	upd(rc,mid+1,r,ll,rr,y);
	pu(x);
}
LL qryh(int x,int l,int r,int ll,int rr){
	if (r<ll || l>rr) return 0;
	pd(x);
	if (ll<=l && r<=rr) return smh[x];
	return qryh(lc,l,mid,ll,rr)+qryh(rc,mid+1,r,ll,rr);
}
vector<int> v[M];
vector<Q> xiu[M],cha[M];
int rp[M],L[M],R[M],s[M];
LL ans[M];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(); m=read();
	F(i,1,n) p[i]=read(),rp[p[i]]=i;
	F(i,1,m){
		q[i]=(Q){read(),read(),i};
		cha[q[i].l-1].pb((Q){q[i].l,q[i].r,-i});
		cha[q[i].r].pb((Q){q[i].l,q[i].r,i});
	}
	build(1,1,n);
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j+=i){
			if (j/i<=i) v[j].pb(i); 
		}
	}
	int tp=0;
	F(i,1,n){
		while (tp && p[i]>p[s[tp]]) tp--;
		if (!tp) L[i]=1;
		else L[i]=s[tp]+1;
		s[++tp]=i;
	}
	tp=0;
	DF(i,n,1){
		while (tp && p[i]>p[s[tp]]) tp--;
		if (!tp) R[i]=n;
		else R[i]=s[tp]-1;
		s[++tp]=i;
	}
	F(i,1,n){
		for (int d:v[p[i]]){
			int px=rp[d],py=rp[p[i]/d];
			if (px>py) swap(px,py);
			if (px<L[i] || py>R[i] || px==py) continue;
			py=max(py,i);
			px=min(px,i);
			xiu[L[i]].pb((Q){py,R[i],1});
			xiu[px+1].pb((Q){py,R[i],-1});
		}
	}
	build(1,1,n);
	F(i,1,n){
		for (auto O:xiu[i]){
			upd(1,1,n,O.l,O.r,O.id);
//			cerr<<i<<" "<<O.l<<" "<<O.r<<" "<<O.id<<" gai\n";
		}
		mtg(1,1);
		for (auto O:cha[i]){
			LL tmp=qryh(1,1,n,O.l,O.r);
			ans[abs(O.id)]+=(O.id>0 ? 1 : -1)*tmp;
//			cerr<<tmp<<" ???\n";
		}
	}
	F(i,1,m){
		int le=q[i].r-q[i].l+1;
//		cerr<<le<<" "<<ans[i]<<" ooo\n";
		ans[i]=1ll*le*le-ans[i];
		cout<<ans[i]<<"\n";
	}
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
10 1
6 1 3 2 5 8 4 10 7 9
10 10

*/