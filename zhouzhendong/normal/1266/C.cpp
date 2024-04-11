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
const int N=505;
int n,m;
int a[N][N];
int lcm(int x,int y){
	return x/__gcd(x,y)*y;
}
void check(){
	vi res;
	For(i,1,n){
		int v=0;
		For(j,1,m)
			v=__gcd(v,a[i][j]);
		res.pb(v);
	}
	For(i,1,m){
		int v=0;
		For(j,1,n)
			v=__gcd(v,a[j][i]);
		res.pb(v);
	}
	sort(res.begin(),res.end());
	assert(res.back()==n+m);
	For(i,1,(int)res.size()-1)
		assert(res[i-1]!=res[i]);
}
int main(){
	n=read(),m=read();
	if (n==1&&m==1)
		return puts("0"),0;
	For(i,1,n)
		For(j,1,m)
			a[i][j]=1;
	if (n<m){
		For(i,1,n)
			For(j,1,m)
				a[i][j]=lcm(a[i][j],i);
		For(i,1,m)
			For(j,1,n)
				a[j][i]=lcm(a[j][i],i+n);
	}
	else {
		For(i,1,m)
			For(j,1,n)
				a[j][i]=lcm(a[j][i],i);
		For(i,1,n)
			For(j,1,m)
				a[i][j]=lcm(a[i][j],i+m);
	}
	For(i,1,n){
		For(j,1,m)
			printf("%d ",a[i][j]);
		puts("");
	}
//	check();
	return 0;
}