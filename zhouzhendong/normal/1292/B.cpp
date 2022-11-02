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
/*
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
*/
const int N=99;
LL x0,y0,ax,ay,bx,by;
LL xs,ys,t;
LL x[N],y[N];
LL absl(LL x){
	return x<0?-x:x;
}
int n=0;
int gao1(int s,LL t){
	if (t<0)
		return 0;
	int val=1;
	For(i,s+1,n-1){
		t-=absl(x[i]-x[i-1])+absl(y[i]-y[i-1]);
		if (t>=0)
			val++;
		else
			break;
	}
	return val;
}
int gao2(int s,LL t){
	if (t<0)
		return 0;
	int val=1;
	Fod(i,s-1,0){
		t-=absl(x[i]-x[i+1])+absl(y[i]-y[i+1]);
		if (t>=0)
			val++;
		else
			break;
	}
	return val;
}
int main(){
	x0=read(),y0=read(),ax=read(),ay=read(),bx=read(),by=read();
	xs=read(),ys=read(),t=read();
	x[0]=x0,y[0]=y0;
	while (1){
		n++;
		x[n]=x[n-1]*ax+bx;
		y[n]=y[n-1]*ay+by;
		if (x[n]>2e16||y[n]>2e16)
			break;
	}
//	outarr(x,0,n-1);
//	outarr(y,0,n-1);
	int ans=0;
	For(i,0,n-1){
		ckmax(ans,gao1(i,t-absl(xs-x[i])-absl(ys-y[i])));
		ckmax(ans,gao2(i,t-absl(xs-x[i])-absl(ys-y[i])));
	}
	cout<<ans<<endl;
	return 0;
}