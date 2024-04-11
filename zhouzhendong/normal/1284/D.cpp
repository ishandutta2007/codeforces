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
const int N=100005,INF=1e9;
int n;
struct A{
	int l0,r0,l1,r1;
}a[N],b[N];
int rt;
namespace seg{
	const int S=N*30*2;
	int cnt=0;
	int ls[S],rs[S],sum[S];
	void clear(){
		rt=cnt=0;
		clr(ls);
		clr(rs);
		clr(sum);
	}
	void update(int &rt,int L,int R,int x){
		if (!rt)
			rt=++cnt;
		sum[rt]++;
		if (L==R)
			return;
		int mid=(L+R)>>1;
		if (x<=mid)
			update(ls[rt],L,mid,x);
		else
			update(rs[rt],mid+1,R,x);
	}
	int query(int rt,int L,int R,int xL,int xR){
		if (!rt||xR<L||xL>R)
			return 0;
		if (xL<=L&&R<=xR)
			return sum[rt];
		int mid=(L+R)>>1;
		return query(ls[rt],L,mid,xL,xR)+query(rs[rt],mid+1,R,xL,xR);
	}
}
int main(){
	n=read();
	For(i,1,n){
		a[i].l0=read();
		a[i].r0=read();
		a[i].l1=read();
		a[i].r1=read();
	}
	For(__,0,1){
		For(_,0,1){
			For(i,1,n)
				b[i]=a[i];
			sort(a+1,a+n+1,[&](A x,A y){
				return x.l0<y.l0;
			});
			sort(b+1,b+n+1,[&](A x,A y){
				return x.r0<y.r0;
			});
			seg::clear();
			int p=0;
			For(i,1,n){
				while (p<n&&b[p+1].r0<a[i].l0){
					++p;
					seg::update(rt,0,INF,b[p].l1);
					seg::update(rt,0,INF,b[p].r1);
				}
				if (seg::query(rt,0,INF,a[i].l1,a[i].r1))
					return puts("NO"),0;
			}
			For(i,1,n){
				a[i].l0=INF-a[i].l0;
				a[i].r0=INF-a[i].r0;
				swap(a[i].l0,a[i].r0);
			}
		}
		For(i,1,n)
			swap(a[i].l0,a[i].l1),swap(a[i].r0,a[i].r1);
	}
	puts("YES");
	return 0;
}