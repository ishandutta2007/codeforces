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
void ckmax(int &x,int y){
	if (x<y)
		x=y;
}
void ckmin(int &x,int y){
	if (x>y)
		x=y;
}
const int N=100005;
int n;
vi e[N];
int dp[N][2];
int ans=0;
void dfs(int x,int pre){
	int es=(int)e[x].size();
	ckmax(ans,es);
	dp[x][1]=1;
	for (auto y : e[x])
		if (y!=pre){
			dfs(y,x);
			ckmax(ans,dp[y][0]+1);
			ckmax(ans,es-1+max(dp[y][0],dp[y][1]));
			ckmax(ans,es-2+dp[x][0]+max(dp[y][0],dp[y][1]));
			ckmax(ans,dp[x][1]+dp[y][0]);
			ckmax(dp[x][0],max(dp[y][0],dp[y][1]));
			ckmax(dp[x][1],dp[y][0]+1);
		}
	dp[x][0]+=es-1-(bool)pre;
	ckmax(dp[x][0],es-(bool)pre);
}
int main(){
	n=read();
	For(i,1,n-1){
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
	}
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}