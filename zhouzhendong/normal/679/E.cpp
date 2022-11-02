#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define isinf _zzd001
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int,int> pii;
LL read(){
    LL x=0,f=0;
    char ch=getchar();
    while (!isdigit(ch))
        f=ch=='-',ch=getchar();
    while (isdigit(ch))
        x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    return f?-x:x;
}
const int N=100005*4;
const LL INF=1e17;
int n,q;
LL a[N];
LL lev[N];
LL Mi[N],Ma[N],add[N],val[N],l[N],isinf[N];
void pushup(int rt){
	int ls=rt<<1,rs=ls|1;
	Mi[rt]=min(Mi[ls],Mi[rs]);
	Ma[rt]=max(Ma[ls],Ma[rs]);
	val[rt]=min(val[ls],val[rs]);
}
void build(int rt,int L,int R){
	add[rt]=isinf[rt]=0;
	if (L==R){
		Mi[rt]=Ma[rt]=a[L];
		for (l[rt]=0;lev[l[rt]]<a[L];l[rt]++);
		val[rt]=lev[l[rt]]-a[L];
		return;
	}
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	build(ls,L,mid);
	build(rs,mid+1,R);
	pushup(rt);
}
void pushdown(int rt){
	int ls=rt<<1,rs=ls|1;
	if (isinf[rt]){
		add[rt]=0;
		Mi[ls]=Mi[rs]=Ma[ls]=Ma[rs]=INF;
		isinf[ls]=isinf[rs]=1;
		val[ls]=val[rs]=INF*2;
		isinf[rt]=0;
		add[rt]=0;
	}
	else {
		LL v=add[rt];
		add[ls]+=v;
		add[rs]+=v;
		Mi[ls]+=v;
		Mi[rs]+=v;
		Ma[ls]+=v;
		Ma[rs]+=v;
		val[ls]-=v;
		val[rs]-=v;
		add[rt]=0;
	}
}
LL getpre(int rt,int L,int R,int x){
	if (L>x)
		return -1;
	if (Mi[rt]>=INF)
		return -1;
	if (L==R)
		return Mi[rt];
	pushdown(rt);
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	LL ans=getpre(rs,mid+1,R,x);
	if (ans==-1)
		ans=getpre(ls,L,mid,x);
	return ans;
}
LL Ask(int rt,int L,int R,int x){
	if (L==R)
		return Mi[rt];
	pushdown(rt);
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	if (x<=mid)
		return Ask(ls,L,mid,x);
	else
		return Ask(rs,mid+1,R,x);
}
void Modify(int rt,int L,int R,int x,LL v){
	if (L==R){
		Mi[rt]=Ma[rt]=v;
		for (l[rt]=0;lev[l[rt]]<v;l[rt]++);
		val[rt]=lev[l[rt]]-v;
		return;
	}
	pushdown(rt);
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	if (x<=mid)
		Modify(ls,L,mid,x,v);
	else
		Modify(rs,mid+1,R,x,v);
	pushup(rt);
}
void recover(int x){
	LL v=getpre(1,1,n,x);
	Modify(1,1,n,x,v);
}
void Cover(int rt,int L,int R,int xL,int xR){
	if (R<xL||L>xR)
		return;
	if (xL<=L&&R<=xR){
		isinf[rt]=1;
		Mi[rt]=Ma[rt]=INF;
		val[rt]=INF*2;
		l[rt]=10;
		add[rt]=0;
		return;
	}
	pushdown(rt);
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	Cover(ls,L,mid,xL,xR);
	Cover(rs,mid+1,R,xL,xR);
	pushup(rt);
}
int update(int rt,int L,int R,int xL,int xR,LL v){
	if (R<xL||L>xR)
		return 0;
	if (xL<=L&&R<=xR){
		if (v<val[rt]){
			add[rt]+=v;
			val[rt]-=v;
			Mi[rt]+=v;
			Ma[rt]+=v;
			return 0;
		}
		if (L==R){
			LL now=Mi[rt]+v;
			Mi[rt]=Ma[rt]=now;
			while (lev[l[rt]]<now)
				l[rt]++;
			int flag=0;
			if (lev[l[rt]]==now)
				flag=1,l[rt]++;
			val[rt]=lev[l[rt]]-now;
			return flag;
		}
	}
	pushdown(rt);
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	int res=update(ls,L,mid,xL,xR,v);
	res|=update(rs,mid+1,R,xL,xR,v);
	pushup(rt);
	return res;
}
int main(){
	n=read(),q=read();
	For(i,1,n)
		a[i]=read();
	lev[0]=1;
	for (int c=1;;c++){
		lev[c]=lev[c-1]*42;
		if (lev[c]>1e15){
			lev[c+1]=1e18;
			outval(c);
			break;
		}
	}
	build(1,1,n);
	while (q--){
		int type=read();
		if (type==1){
			int x=read();
			recover(x);
			printf("%lld\n",Ask(1,1,n,x));
		}
		else {
			int L=read(),R=read(),x=read();
			if (type==2){
				if (R<n)
					recover(R+1);
				Modify(1,1,n,L,x);
				if (L+1<=R)
					Cover(1,1,n,L+1,R);
			}
			else if (type==3){
				recover(L);
				if (R<n)
					recover(R+1);
				while (update(1,1,n,L,R,x));
			}
		}
	}
	return 0;
}