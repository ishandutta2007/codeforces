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
const int N=100005;
const LL INF=4e18;
int n;
LL k;
LL a[N];
LL f(LL x){
	// (x-1) ^ 3 = x^3 - 3x^2 + 3x - 1
	// 3x^2 - 3x + 1
	return -(3LL*x*x-3*x+1);
}
LL getval(int i,LL v){
	LL L=0,R=a[i],ans=0;
	while (L<=R){
		LL mid=(L+R)>>1;
		if (f(mid)+a[i]>=v)
			L=mid+1,ans=mid;
		else
			R=mid-1;
	}
//	assert(ans<=a[i]);
	return ans;
}
LL calc(LL lim){
	LL res=0;
	For(i,1,n)
		res+=getval(i,lim);
	return res;
}
LL v[N];
namespace chk{
	LL calc(LL *v){
		LL res=0;
		For(i,1,n)
			res+=v[i]*(a[i]-v[i]*v[i]);
		return res;
	}
}
int main(){
	n=read(),k=read();
	For(i,1,n)
		a[i]=read();
//	For(i,1,n)
//		v[i]=read();
//	outval(chk::calc(v));
	LL L=-INF,R=INF,ans=R;
	while (L<=R){
		LL mid=(L+R)/2;
		if (calc(mid)<=k)
			R=mid-1,ans=mid;
		else
			L=mid+1;
	}
	For(i,1,n){
		v[i]=getval(i,ans);
		k-=v[i];
	}
//	outarr(v,1,n);
	For(i,1,n){
		while (k>0&&v[i]<a[i]&&f(v[i]+1)+a[i]>=ans-1){
			k--,v[i]++;
		}
	}
//	assert(k==0);
	For(i,1,n)
		printf("%d ",(int)v[i]);
	puts("");
//	outval(chk::calc(v));
	return 0;
}
/*
10 32
1 2 3 4 5 5 5 5 5 5
1 2 3 3 3 4 4 4 4 4 

*/