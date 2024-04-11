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
void ckmax(int &x,int y){
	if (x<y)
		x=y;
}
void ckmin(int &x,int y){
	if (x>y)
		x=y;
}
*/
const int N=100005;
int n,m;
vi e[N];
int vis[N],inst[N];
int dep[N];
int dfs(int x,int d=1){
	vis[x]=d;
	inst[x]=1;
	for (auto i : e[x]){
		if (!vis[i]){
			if (!dfs(i,d+1))
				return 0;
		}
		else if (!inst[i])
			return 0;
	}
	inst[x]=0;
	return 1;
}
int check(int x){
	For(i,1,n)
		vis[i]=inst[i]=0;
	return dfs(x);
}
int tmp[N],top[N];
vi ans;
int kill[N];
int solve(int x){
	int now=0;
	vis[x]=1;
	top[x]=x;
	for (auto i : e[x])
		if (!vis[i]){
			now+=solve(i);
			if (dep[top[i]]<dep[top[x]])
				top[x]=top[i];
		}
		else {
			now++,tmp[i]++;
			if (dep[i]<dep[top[x]])
				top[x]=i;
		}
	now-=tmp[x];
	if (now>1)
		kill[x]=1;
	return now;
}
void gao(int x){
	vis[x]=1;
	if (kill[top[x]])
		kill[x]=1;
	for (auto i : e[x])
		if (!vis[i])
			gao(i);
}
void Solve(){
	n=read(),m=read();
	For(i,1,n)
		e[i].clear();
	For(i,1,m){
		int a=read(),b=read();
		e[a].pb(b);
	}
	vi a;
	For(i,1,n)
		a.pb(i);
	random_shuffle(a.begin(),a.end());
	int t=100,x=0;
	for (auto i : a){
		if (check(i)){
			x=i;
			break;
		}
		if (!--t)
			break;
	}
	For(i,1,n)
		dep[i]=vis[i];
//	outval(x);
	if (x==0){
		puts("-1");
		return;
	}
	For(i,1,n)
		tmp[i]=vis[i]=kill[i]=0;
	solve(x);
	For(i,1,n)
		vis[i]=0;
	gao(x);
	ans.clear();
	For(i,1,n)
		if (!kill[i])
			ans.pb(i);
	sort(ans.begin(),ans.end());
	if ((int)ans.size()*5<n)
		return (void)puts("-1");
	for (auto i : ans)
		printf("%d ",i);
	puts("");
}
int main(){
	srand(114514);
	int T=read();
	while (T--)
		Solve();
	return 0;
}