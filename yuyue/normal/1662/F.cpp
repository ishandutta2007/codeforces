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
const int M=2e5+10,inf=1e9;
int n,X,Y,p[M];
struct info{
	int x,val;
};
info ta[M<<2],tb[M<<2];
info operator +(info A,info B){
	return A.val<B.val ? B :A;
}
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
void build(int x,int l,int r){
	if (l==r){
		ta[x]=(info){l,p[l]-l};
		tb[x]=(info){l,p[l]+l};
		return ;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	ta[x]=ta[lc]+ta[rc];
	tb[x]=tb[lc]+tb[rc];
}
void upd(int x,int l,int r,int p){
	if (l==r){
		ta[x]=(info){l,-inf};
		tb[x]=(info){l,-inf};
		return ;
	}
	if (p<=mid) upd(lc,l,mid,p);
	else upd(rc,mid+1,r,p);
	ta[x]=ta[lc]+ta[rc];
	tb[x]=tb[lc]+tb[rc];
}
info qa(int x,int l,int r,int ll,int rr){
	if (ll>rr) return (info){0,-inf};
	if (ll<=l && r<=rr) return ta[x];
	if (rr<=mid) return qa(lc,l,mid,ll,rr);
	if (ll>mid) return qa(rc,mid+1,r,ll,rr);
	return qa(lc,l,mid,ll,rr)+qa(rc,mid+1,r,ll,rr);
}
info qb(int x,int l,int r,int ll,int rr){
	if (ll>rr) return (info){0,-inf};
	if (ll<=l && r<=rr) return tb[x];
	if (rr<=mid) return qb(lc,l,mid,ll,rr);
	if (ll>mid) return qb(rc,mid+1,r,ll,rr);
	return qb(lc,l,mid,ll,rr)+qb(rc,mid+1,r,ll,rr);
}
int dis[M],q[M];
void work(){
	n=read(); X=read(); Y=read();
	F(i,1,n) p[i]=read();
	build(1,1,n);
	F(i,1,n) dis[i]=inf; dis[X]=0;
	int l=1,r=1; q[1]=X; upd(1,1,n,X);
	while (l<=r){
		int x=q[l++];
		int lp=max(1,x-p[x]),rp=min(n,x+p[x]);
//				cerr<<A.x<<" "<<B.x<<" ??\n";
//		cerr<<x<<" ???\n";
		while (1){
			info A=qa(1,1,n,x+1,rp);
			if (A.val+x>=0){
				dis[A.x]=dis[x]+1;
				upd(1,1,n,A.x);
				q[++r]=A.x;
			}
			else break;  
		}
		while (1){
			info B=qb(1,1,n,lp,x-1);
			if (B.val-x>=0){
				dis[B.x]=dis[x]+1;
				q[++r]=B.x;
				upd(1,1,n,B.x);
			}
			else break;
		}
	}
	cout<<dis[Y]<<"\n";
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);

	int T=read();
	while (T--) work();
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/