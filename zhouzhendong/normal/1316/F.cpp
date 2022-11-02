#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
#define outtime() cerr<<"User Time = "\
	<<(double)clock()/CLOCKS_PER_SEC<<endl
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
const int N=300005,S=N*31,mod=1e9+7;
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=(LL)x*x%mod)
		if (y&1)
			ans=(LL)ans*x%mod;
	return ans;
}
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
void Del(int &x,int y){
	if ((x-=y)<0)
		x+=mod;
}
int Add(int x){
	return x>=mod?x-mod:x;
}
int Del(int x){
	return x<0?x+mod:x;
}
int n;
int a[N],val[N*2],p2[N*2];
int ls[S],rs[S];
int cnt[S],lv[S],rv[S],sum[S];
int ndcnt=0,rt=0;
int st[S],top=0;
void recover(int &x){
	ls[x]=rs[x]=cnt[x]=lv[x]=rv[x]=sum[x]=0;
	st[++top]=x;
	x=0;
}
int newnode(){
	return top?st[top--]:++ndcnt;
}
void pushup(int rt){
	sum[rt]=((LL)lv[ls[rt]]*rv[rs[rt]]
			+(LL)sum[ls[rt]]*p2[cnt[rs[rt]]]
			+(LL)sum[rs[rt]]*p2[cnt[ls[rt]]])%mod;
	lv[rt]=((LL)lv[rs[rt]]*p2[cnt[ls[rt]]]+lv[ls[rt]])%mod;
	rv[rt]=((LL)rv[ls[rt]]*p2[cnt[rs[rt]]]+rv[rs[rt]])%mod;
	cnt[rt]=cnt[ls[rt]]+cnt[rs[rt]];
}
void upd(int &rt,int L,int R,int x,int d){
	if (!rt)
		rt=newnode();
	if (L==R){
		cnt[rt]+=d;
		sum[rt]=(LL)val[cnt[rt]]*L%mod*L%mod;
		lv[rt]=rv[rt]=(LL)(p2[cnt[rt]]-1)*L%mod;
		if (cnt[rt]==0)
			recover(rt);
		return;
	}
	int mid=(L+R)>>1;
	if (x<=mid)
		upd(ls[rt],L,mid,x,d);
	else
		upd(rs[rt],mid+1,R,x,d);
	pushup(rt);
	if (cnt[rt]==0)
		recover(rt);
}
int main(){
	n=read();
	For(i,1,n)
		a[i]=read();
	int q=read();
	val[0]=val[1]=0;
	int cc=Pow(2,mod-1-n);
	p2[0]=1;
	For(i,1,n+q)
		p2[i]=p2[i-1]*2%mod;
	For(i,2,n+q)
		val[i]=(2LL*val[i-1]+p2[i-1]-1)%mod;
	For(i,1,n)
		upd(rt,1,1000000000,a[i],1);
	cout<<(LL)sum[rt]*cc%mod<<endl;
	while (q--){
		int i=read(),x=read();
		upd(rt,1,1000000000,a[i],-1);
		upd(rt,1,1000000000,a[i]=x,1);
		cout<<(LL)sum[rt]*cc%mod<<endl;
	}
	return 0;
}