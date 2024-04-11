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
*/
const int N=100005,INF=1e9;
int n,m,sqn;
vi e[N],res;
int dep[N],fa[N],vis[N],chosen[N];
void dfs(int x,int pre,int d){
	dep[x]=d,fa[x]=pre,vis[x]=1;
	for (auto y : e[x])
		if (y!=pre){
			if (vis[y]){
				if (dep[y]<=dep[x]-sqn+1){
					puts("2");
					printf("%d\n",dep[x]-dep[y]+1);
					for (int i=x;i!=fa[y];i=fa[i])
						printf("%d ",i);
					puts("");
					exit(0);
				}
			}
			else {
				dfs(y,x,d+1);
			}
		}
	int flag=0;
	for (auto y : e[x])
		flag|=chosen[y];
	if (!flag)
		res.pb(x),chosen[x]=1;
}
int main(){
	n=read(),m=read();
	sqn=ceil(sqrt(n));
	For(i,1,m){
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
	}
	For(i,1,n)
		if (!vis[i])
			dfs(i,0,0);
	res.resize(sqn);
	puts("1");
	for (auto i : res)
		printf("%d ",i);
	puts("");
	return 0;
}