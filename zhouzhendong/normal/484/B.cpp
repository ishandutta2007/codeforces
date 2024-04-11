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
const int N=1e6+6;
int n;
int a[N*2],s[N*2];
int bru(){
	int ans=0;
	For(i,1,n)
		For(j,i,n)
			if (a[i]&&a[j])
				ckmax(ans,j%i);
	return ans;
}
int main(){
//#ifdef zzd
//	srand(time(NULL));
//	n=1e2;
//	For(i,1,n)
//		a[rand()%500+1]=1;
//	n=1e3;
//#else
	n=read();
	For(i,1,n)
		a[read()]=1;
	n=1e6;
//#endif
	int ans=0;
	For(i,1,n*2)
		s[i]=s[i-1]+a[i];
	Fod(i,n,1){
		if (!a[i])
			continue;
		for (int j=i+i;j<=n*2;j+=i){
			int L=j-i+ans,R=j-1;
			while (L<=R){
				int mid=(L+R)>>1;
				if (s[j-1]-s[mid-1]>0)
					L=mid+1,ckmax(ans,mid-(j-i));
				else
					R=mid-1;
			}
		}
	}
//	outval(bru());
	cout<<ans<<endl;
	return 0;
}