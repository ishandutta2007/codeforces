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
const int N=100005;
int n,ans,res,all;
int a[N],b[N];
int g[20],f[20],fa[20];
int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
void dfs(int k,int s){
	if (k==20){
		ckmin(res,ans-s);
		return;
	}
	dfs(k+1,s);
	if (~all>>k&1)
		return;
	vi bkf(f,f+20);
	int flag=1;
	For(i,0,19)
		if (g[i]>>k&1){
			if (bkf[k]>>i&1){
				flag=0;
				break;
			}
			For(j,0,19)
				if (f[j]>>i&1)
					f[j]|=f[k];
		}
	if (flag)
		dfs(k+1,s+1);
	For(i,0,19)
		f[i]=bkf[i];
}
void solve(){
	clr(g),clr(f),iota(fa,fa+20,0);
	ans=20,all=0,res=233;
	n=read();
	string s;
	cin>>s;
	For(i,0,n-1)
		a[i+1]=s[i]-'a';
	cin>>s;
	For(i,0,n-1)
		b[i+1]=s[i]-'a';
	For(i,1,n)
		g[a[i]]|=1<<b[i];
	For(i,0,19)
		if (g[i]>>i&1)
			g[i]^=1<<i;
	For(i,0,19)
		all|=g[i];
	For(i,0,19)
		For(j,0,19)
			if ((g[i]|1<<i)&(g[j]|1<<j))
				fa[getf(i)]=getf(j);
	For(i,0,19)
		if (getf(i)==i)
			ans--;
	ans+=__builtin_popcount((uint)all);
	For(i,0,19)
		f[i]|=1<<i;
	dfs(0,0);
	cout<<res<<endl;
}
int main(){
	int T=read();
	while (T--)
		solve();
	return 0;
}