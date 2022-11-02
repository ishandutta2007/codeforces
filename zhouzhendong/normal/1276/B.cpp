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
const int N=200005*2;
int n,m,k;
int A,B;
vector <int> e[N],t[N];
int dfn[N],low[N],st[N],Time,top;
void Add_Edge(int x,int y){
    t[x].pb(y),t[y].pb(x);
}
void Tarjan(int x){
    dfn[x]=low[x]=++Time;
    st[++top]=x;
    for (auto y : e[x])
        if (!dfn[y]){
            Tarjan(y);
            low[x]=min(low[x],low[y]);
            if (low[y]>=dfn[x]){
                Add_Edge(x,++k);
                do {
                    Add_Edge(st[top],k);
                } while (st[top--]!=y);
            }
        }
        else
            low[x]=min(low[x],dfn[y]);
}
int sz[N];
void dfs(int x,int pre){
	sz[x]=x<=n;
	for (auto y : t[x])
		if (y!=pre){
			dfs(y,x);
			sz[x]+=sz[y];
		}
}
void solve(){
    n=read(),m=read(),A=read(),B=read();
    k=n;
    For(i,1,n*2)
    	e[i].clear(),t[i].clear();
    For(i,1,m){
        int x=read(),y=read();
        e[x].pb(y),e[y].pb(x);
	}
	Time=0,top=0;
	For(i,1,n)
		dfn[i]=low[i]=0;
	Tarjan(1);
//	outval(k);
	dfs(A,0);
//	outarr(sz,1,k);
	int vb=sz[B]-1;
	dfs(B,0);
//	outarr(sz,1,k);
	int va=sz[A]-1;
	printf("%lld\n",(LL)va*vb);
}
int main(){
	int T=read();
	while (T--)
		solve();
	return 0;
}