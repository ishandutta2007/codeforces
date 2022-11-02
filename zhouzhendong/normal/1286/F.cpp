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
const int N=20;
int n,all;
LL a[N];
int dp[1<<N];
namespace checker{
	int n;
	LL a[N];
	LL v1[1<<N],c1;
	LL v2[1<<N],c2;
	LL getv(LL *a,int n,LL *v,LL &c){
		v[0]=0,c=1;
		LL sum=0;
		For(i,0,n-1){
			sum+=a[i];
			For(j,0,c-1)
				v[j+c]=v[j]+a[i]*2;
			inplace_merge(v,v+c,v+c*2);
			c*=2;
		}
		For(i,0,c-1)
			v[i]-=sum;
		return sum;
	}
	int check01(){
		int res=(n-1)&1;
		For(i,0,n-1)
			if (a[i]%2!=0)
				res^=1;
		return res==0;
	}
	int check(){
		if (!check01())
			return 0;
		int mid=n/2;
		LL sum=getv(a,mid,v1,c1)+getv(a+mid,n-mid,v2,c2);
		int lp=0,rp=0,tot=n!=1&&absl(sum)<=n-1?-2:0;
		For(i,0,c1-1){
			while (lp<c2&&v2[lp]<v1[i]-(n-1))
				lp++;
			while (rp<c2&&v2[rp]<=v1[i]+(n-1))
				rp++;
			tot+=rp-lp;
			if (tot>0)
				return 1;
		}
		return 0;
	}
}
int check(int s){
	checker::n=0;
	For(i,0,n-1)
		if (s>>i&1)
			checker::a[checker::n++]=a[i];
	return checker::check();
}
int main(){
	n=read();
	For(i,0,n-1)
		a[i]=read();
	all=1<<n;
	For(i,0,all-1)
		dp[i]=__builtin_popcount(i);
	For(i,1,all-1){
		For(j,0,n-1)
			ckmin(dp[i|1<<j],dp[i]+1);
		if (dp[i]==__builtin_popcount(i)&&check(i)){
			dp[i]--;
			int highbit=n-1;
			while (~i>>highbit&1)
				highbit--;
			int u=((1<<(highbit+1))-1)^i;
			for (int j=u;j;j=(j-1)&u)
				ckmin(dp[i+j],dp[i]+dp[j]);
		}
	}
	cout<<dp[all-1]<<endl;
	return 0;
}