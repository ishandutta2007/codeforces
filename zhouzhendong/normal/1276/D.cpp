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
const int mod=998244353;
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
const int N=200005;
int n;
vector <pii> e[N];
int dp[N][6];
void dfs(int x,int eid){
	For(i,0,(int)e[x].size()-1){
		if (e[x][i].fi==eid){
			swap(e[x][i],e[x].back());
			e[x].pop_back();
			break;
		}
	}
	sort(e[x].begin(),e[x].end());
	for (auto y : e[x])
		dfs(y.se,y.fi);
	int p=0,sz=e[x].size();
	while (p<sz&&e[x][p].fi<eid)
		p++;
	vi y(sz);
	For(i,0,sz-1)
		y[i]=e[x][i].se;
	vi pre(sz+1),suf(sz+1);
	pre[0]=suf[sz]=1;
	For(i,0,sz-1)
		pre[i+1]=(LL)pre[i]*(dp[y[i]][2]+dp[y[i]][5])%mod;
	Fod(i,sz-1,0)
		suf[i]=(LL)suf[i+1]*(dp[y[i]][1]+dp[y[i]][3])%mod;
	{
		int v=0;
		For(i,0,p-1)
			Add(v,(LL)pre[i]*dp[y[i]][4]%mod*suf[i+1]%mod);
		dp[x][1]=dp[x][2]=v;
	}
	{
		int v=pre[sz];
		For(i,p,sz-1)
			Add(v,(LL)pre[i]*dp[y[i]][4]%mod*suf[i+1]%mod);
		dp[x][3]=dp[x][4]=v;
	}
	{
		dp[x][5]=(LL)pre[p]*suf[p]%mod;
	}
//	printf("dfs(%d,%d): ",x,eid);outarr(dp[x],1,5);
}
int main(){
	n=read();
	For(i,1,n-1){
		int x=read(),y=read();
		e[x].pb(mp(i,y));
		e[y].pb(mp(i,x));
	}
	int rt=0;
	For(i,1,n)
		if (e[i].size()==1){
			rt=i;
			break;
		}
	assert(rt);
	int realrt=e[rt][0].se;
	dfs(realrt,e[rt][0].fi);
	int ans=((LL)dp[realrt][2]+dp[realrt][4]+dp[realrt][5])%mod;
	cout<<ans<<endl;
	return 0;
}