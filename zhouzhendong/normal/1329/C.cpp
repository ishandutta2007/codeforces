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
const int N=1<<21;
int n,h,g;
int a[N];
int sz[N];
vi res;
int check(int x){
	if (!a[x])
		return 0;
	if (x>=(1<<g))
		return 1;
	int ls=x<<1,rs=ls|1;
	return check(a[ls]>a[rs]?ls:rs);
}
void pop(int x){
	int ls=x<<1,rs=ls|1;
	if (!a[ls]&&!a[rs])
		a[x]=0;
	else if (a[ls]>a[rs])
		a[x]=a[ls],pop(ls);
	else
		a[x]=a[rs],pop(rs);
}
void dfs(int x){
	if (!a[x])
		return;
	while (check(x)){
		res.pb(x);
		pop(x);
	}
	int ls=x<<1,rs=ls|1;
	dfs(ls),dfs(rs);
}
void solve(){
	h=read(),g=read(),n=(1<<h)-1;
	For(i,1,n)
		a[i]=read();
	For(i,n+1,(1<<(h+1))-1)
		a[i]=0;
	res.clear();
	dfs(1);
	LL sum=0;
	For(i,1,(1<<g)-1)
		sum+=a[i];
	cout<<sum<<endl;
	for (auto i : res)
		printf("%d ",i);
	puts("");
}
int main(){
	int T=read();
	while (T--)
		solve();
	return 0;
}