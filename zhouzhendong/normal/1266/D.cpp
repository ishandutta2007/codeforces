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
const int N=100005,M=N*3;
int n,m;
LL val[N];
vi v0,v1;
int main(){
	n=read(),m=read();
	For(i,1,m){
		int x=read(),y=read(),v=read();
		val[x]+=v,val[y]-=v;
	}
	For(i,1,n){
		if (val[i]>0)
			v0.pb(i);
		if (val[i]<0)
			v1.pb(i);
	}
	vector <pair <pii,LL> > e;
	while (!v0.empty()&&!v1.empty()){
		int x=v0.back(),y=v1.back();
		v0.pop_back(),v1.pop_back();
		LL d=min(val[x],-val[y]);
		e.pb(mp(mp(x,y),d));
		val[x]-=d,val[y]+=d;
		if (val[x])
			v0.pb(x);
		if (val[y])
			v1.pb(y);
	}
	cout<<e.size()<<endl;
	for (auto E : e)
		printf("%d %d %lld\n",E.fi.fi,E.fi.se,E.se);
	return 0;
}