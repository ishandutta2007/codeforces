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
template <class T> void ckmax(T &x,const T &y){
	if (x<y)
		x=y;
}
template <class T> void ckmin(T &x,const T &y){
	if (x>y)
		x=y;
}
LL absl(LL x){
	return x<0?-x:x;
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
const int N=114;
LL p[N],v[N],sp[N];
void solve(){
	LL n=read(),k=read();
	LL B=k*k+1;
	LL c=(n-1)/B;
	clr(p),clr(sp),clr(v);
	for (LL i=c;i;i/=k)
		p[++*p]=i%k,v[*p]=i;
	v[*p+1]=0;
	sp[*p+1]=k*(k+1)/2;
	Fod(i,*p,1){
		//(v[i+1]B + p[i]k)
		LL L=v[i+1]*B+p[i]*k+1;
		LL R=L+k-1;
		LL coef=0;
		if (L>=sp[i+1])
			coef=k;
		else if (R>=sp[i+1])
			coef=R-sp[i+1]+1;
//		outval(sp[i]);
		sp[i]=v[i+1]*B*k+p[i]*k*k+k*(k+1)/2+coef;
	}
//	outval(B),outval(c);
//	outarr(p,1,*p);
//	outarr(v,1,*p+1);
//	outarr(sp,1,*p+1);
	LL d,e;
	if (n==sp[1]){
		if (c==0){
			cout<<k+1<<endl;
			return;
		}
		c=v[2];
		d=p[1];
		e=k+1;
	}
	else {
		LL nd=n-c*B-(n>sp[1])-1;
		d=nd/k,e=nd%k+1;
	}
//	outval(c),outval(d),outval(e);
	LL res=c*(k*(k+1))+d*(k+1)+e;
	cout<<res<<endl;
}
/*
(1,2,_3,4,5,_9,6,7,_13,8,10,_18)
(1,2,3,4,5,_15,6,7,8,9,10,_40)
*/
int main(){
	int T=read();
	while (T--)
		solve();
	return 0;
}