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
//const int mod=;
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
//void ckmax(int &x,int y){
//	if (x<y)
//		x=y;
//}
//void ckmin(int &x,int y){
//	if (x>y)
//		x=y;
//}
const int N=500005*4,INF=1e9;
int n,q;
int a[N];
int mx[N],mi[N],val[N],vl[N],vr[N];
int query(int rt,int L,int R,int lmi,int rmx){
	if (L==R||lmi<=rmx||lmi<mi[rt]||rmx>mx[rt])
		return 0;
	if (lmi>mx[rt]&&rmx<mi[rt])
		return val[rt];
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	int res=0;
	if (min(lmi,mi[ls])>max(rmx,mx[rs]))
		res++;
	if (lmi>mx[ls]&&rmx<=mx[rs])
		res+=vl[rt];
	else
		res+=query(ls,L,mid,lmi,max(rmx,mx[rs]));
	if (rmx<mi[rs]&&lmi>=mi[ls])
		res+=vr[rt];
	else
		res+=query(rs,mid+1,R,min(lmi,mi[ls]),rmx);
	return res;
}
void pushup(int rt,int L,int R){
	int ls=rt<<1,rs=ls|1;
	mi[rt]=min(mi[ls],mi[rs]);
	mx[rt]=max(mx[ls],mx[rs]);
	if (mi[ls]>mx[rs]){
		val[rt]=val[ls]+val[rs]+1;
		vl[rt]=val[ls],vr[rt]=val[rs];
		return;
	}
	int mid=(L+R)>>1;
	vl[rt]=query(ls,L,mid,INF,mx[rs]);
	vr[rt]=query(rs,mid+1,R,mi[ls],-INF);
	val[rt]=vl[rt]+vr[rt];
}
void build(int rt,int L,int R){
	if (L==R){
		mi[rt]=mx[rt]=a[L];
		val[rt]=0;
		return;
	}
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	build(ls,L,mid);
	build(rs,mid+1,R);
	pushup(rt,L,R);
}
void update(int rt,int L,int R,int x,int v){
	if (L==R){
		mx[rt]=mi[rt]=v;
		val[rt]=0;
		return;
	}
	int mid=(L+R)>>1,ls=rt<<1,rs=ls|1;
	if (x<=mid)
		update(ls,L,mid,x,v);
	else
		update(rs,mid+1,R,x,v);
	pushup(rt,L,R);
}
int main(){
	n=read(),q=read();
	For(i,1,n)
		a[i]=read();
	build(1,1,n);
//	outval(val[1]+1);
	while (q--){
		int x=read(),v=read();
		update(1,1,n,x,v);
		printf("%d\n",val[1]+1);
	}
	return 0;
}