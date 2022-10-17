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
inline LL read(){
	char ch=getchar(); LL w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2e5+10,mod=998244353,i2=(mod+1)/2;
struct rg{
	int l,r; LL s;
};
rg operator +(rg A,rg B){
	return (rg){A.l,B.r,A.s+B.s};
}
bool operator <(rg A,rg B){
	return A.s<B.s;
}
struct node{
	bool rev;
	rg smx,smi,sm,lmi,lmx,rmi,rmx;
	void mk(int x,int y){
		rev=0;
		sm=lmi=rmi=lmx=rmx=smi=smx=(rg){x,x,y};
	}
	void fan(){
		rev^=1;
		smx.s=-smx.s; smi.s=-smi.s; lmi.s=-lmi.s; lmx.s=-lmx.s; rmi.s=-rmi.s; rmx.s=-rmx.s; sm.s=-sm.s;
		swap(smx,smi); swap(lmi,lmx); swap(rmi,rmx);
	}
}t[M<<2];
node operator +(node A,node B){
	node C; C.rev=0;
	C.sm=A.sm+B.sm;
	C.smx=max(A.smx,max(B.smx,A.rmx+B.lmx));
	C.smi=min(A.smi,min(B.smi,A.rmi+B.lmi));
	C.lmx=max(A.lmx,A.sm+B.lmx);
	C.lmi=min(A.lmi,A.sm+B.lmi);
	C.rmx=max(B.rmx,A.rmx+B.sm);
	C.rmi=min(B.rmi,A.rmi+B.sm);
	return C;
}
int n,a[M];
LL K,b[M];
#define mid (l+r>>1)
#define lc (x<<1)
#define rc (x<<1|1)
void pd(int x){
	if (t[x].rev){
		t[x].rev=0;
		t[lc].fan(); t[rc].fan();
	}
}
void build(int x,int l,int r){
	if (l==r){
		t[x].mk(l,a[l]);
		return ;
	}
	build(lc,l,mid);
	build(rc,mid+1,r);
	t[x]=t[lc]+t[rc];
}
void upd(int x,int l,int r,int ll,int rr){
	if (r<ll || l>rr) return ;
	if (ll<=l && r<=rr){
		t[x].fan();
		return ;
	}
	pd(x);
	upd(lc,l,mid,ll,rr);
	upd(rc,mid+1,r,ll,rr);
	t[x]=t[lc]+t[rc];
}
void xiu(int x,int l,int r,int p){
	if (l==r){
		t[x].mk(l,a[l]);
		return ;
	}
	pd(x);
	if (p<=mid) xiu(lc,l,mid,p);
	else xiu(rc,mid+1,r,p);
	t[x]=t[lc]+t[rc];
}
node query(int x,int l,int r,int ll,int rr){
	if (ll==l && r==rr){
		return t[x];
	}
	pd(x);
	if (rr<=mid)  return query(lc,l,mid,ll,rr);
	if (ll>mid) return query(rc,mid+1,r,ll,rr);
	return query(lc,l,mid,ll,mid)+query(rc,mid+1,r,mid+1,rr); 
}
LL c[M];
int m=0,pt[M],sl[M],sr[M],tp;
int main(){
//	freopen("seg.in","r",stdin);
//	freopen("seg.out","w",stdout);
	n=read();
	F(i,1,n) a[i]=read();
	build(1,1,n); 
	int q=read();
	while (q--){
		int op=read();
		if (op==0){
			int x=read(),y=read();
			a[x]=y;
			xiu(1,1,n,x); 
		}
		else{
			int l=read(),r=read(),k=read();
			LL ans=0;
			F(i,1,k){
				rg tmp=query(1,1,n,l,r).smx;
				if (tmp.s>0) ans+=tmp.s,upd(1,1,n,tmp.l,tmp.r),sl[++tp]=tmp.l,sr[tp]=tmp.r;
				if (i==k || tmp.s<=0){
					while (tp){
						upd(1,1,n,sl[tp],sr[tp]);
						tp--;
					}
					break;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
20
8 -10 0 -5 -2 -1 -10 -2 -1 3 4 -1 -8 6 0 8 -6 -4 -1 -9
20
1 10 15 1
0 12 -6
0 10 -3
0 4 4
1 8 15 1
0 12 -9
1 9 17 2
1 4 15 2
1 9 19 2
1 5 13 3
1 3 12 3
1 6 13 1
0 3 4
0 18 -5
1 6 14 2
0 1 1
1 4 12 2
1 7 13 2
0 4 -9
1 6 20 4
*/