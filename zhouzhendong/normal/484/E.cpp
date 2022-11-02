#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define kill _z_kill
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
#define User_Time ((double)clock()/CLOCKS_PER_SEC)
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned uint;
typedef long double LD;
typedef vector <int> vi;
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
template <class T> void ckmax(T &x,T y){
	if (x<y)
		x=y;
}
template <class T> void ckmin(T &x,T y){
	if (y<x)
		x=y;
}
//int Pow(int x,int y){
//	int ans=1;
//	for (;y;y>>=1,x=(LL)x*x%mod)
//		if (y&1)
//			ans=(LL)ans*x%mod;
//	return ans;
//}
//void Add(int &x,int y){
//	if ((x+=y)>=mod)
//		x-=mod;
//}
//void Del(int &x,int y){
//	if ((x-=y)<0)
//		x+=mod;
//}
//int Add(int x){
//	return x>=mod?x-mod:x;
//}
//int Del(int x){
//	return x<0?x+mod:x;
//}
const int N=100005;
const int INF=1e9;
int n,m;
int a[N],id[N];
struct qry{
	int L,R,w;
	int ql,qr,qk,ans;
	void getk(){
		qk=(ql+qr)/2;
	}
}q[N];
struct S{
	int L,R,f,v;
};
namespace seg{
	S val[N*4];
	S operator + (S lv,S rv){
		S v={0,0,0,0};
		if (lv.f&&rv.f){
			v.L=v.R=v.v=lv.v+rv.v;
			v.f=1;
		}
		else if (lv.f){
			v.L=lv.v+rv.L;
			v.R=rv.R;
			v.f=0;
			v.v=max(v.L,max(lv.v,rv.v));
		}
		else if (rv.f){
			v.R=rv.v+lv.R;
			v.L=lv.L;
			v.f=0;
			v.v=max(v.R,max(lv.v,rv.v));
		}
		else {
			v.L=lv.L;
			v.R=rv.R;
			v.f=0;
			v.v=max(lv.R+rv.L,max(lv.v,rv.v));
		}
		return v;
	}
	void build(int rt,int L,int R){
		val[rt]={0,0,0,0};
		if (L==R){
			return;
		}
		int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
		build(ls,L,mid);
		build(rs,mid+1,R);
	}
	void update(int rt,int L,int R,int x){
		if (L==R){
			val[rt]={1,1,1,1};
			return;
		}
		int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
		if (x<=mid)
			update(ls,L,mid,x);
		else
			update(rs,mid+1,R,x);
		val[rt]=val[ls]+val[rs];
	}
	S query(int rt,int L,int R,int xL,int xR){
		if (R<xL||L>xR)
			return (S){0,0,0,0};
		if (xL<=L&&R<=xR)
			return val[rt];
		int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
		return query(ls,L,mid,xL,xR)+query(rs,mid+1,R,xL,xR);
	}
}
void gao(vi qid){
	sort(qid.begin(),qid.end(),[&](int x,int y){
		return q[x].qk>q[y].qk;
	});
	seg::build(1,1,n);
	int p=0;
	For(i,1,n){
		while (p<(int)qid.size()&&q[qid[p]].qk>a[id[i]]){
			int i=qid[p];
			if (seg::query(1,1,n,q[i].L,q[i].R).v>=q[i].w)
				q[i].ql=q[i].qk+1,ckmax(q[i].ans,q[i].qk);
			else
				q[i].qr=q[i].qk-1;
			p++;
		}
		seg::update(1,1,n,id[i]);
	}
	while (p<(int)qid.size()){
		int i=qid[p];
		q[i].ql=q[i].qk+1;
		ckmax(q[i].ans,q[i].qk);
		p++;
	}
}
int main(){
	n=read();
	For(i,1,n)
		a[i]=read(),id[i]=i;
	sort(id+1,id+n+1,[&](int x,int y){
		return a[x]>a[y];
	});
	m=read();
	For(i,1,m){
		q[i].L=read(),q[i].R=read(),q[i].w=read();
		q[i].ql=1,q[i].qr=1e9,q[i].ans=1;
	}
	while (1){
		vi qid;
		For(i,1,m){
			if (q[i].ql<=q[i].qr){
				q[i].getk();
				qid.pb(i);
			}
		}
		gao(qid);
		if (qid.empty())
			break;
	}
	For(i,1,m)
		printf("%d\n",q[i].ans);
	return 0;
}