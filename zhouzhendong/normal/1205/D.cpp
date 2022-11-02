//#pragma GCC optimize("Ofast","inline")
#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
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
const int N=1005;
int n;
vector <int> e[N];
int rt=0;
int sz[N],mx[N];
void dfs(int x,int pre){
	sz[x]=1;
	for (auto y : e[x])
		if (y!=pre){
			dfs(y,x);
			sz[x]+=sz[y];
			mx[x]=max(mx[x],sz[y]);
		}
	mx[x]=max(mx[x],n-sz[x]);
	if (!rt||mx[x]<mx[rt])
		rt=x;
}
int fa[N];
int cnt=-1;
int d[N];
void dfs2(int x,int pre){
	d[x]=++cnt;
	sz[x]=1;
	fa[x]=pre;
	for (auto y : e[x])
		if (y!=pre)
			dfs2(y,x),sz[x]+=sz[y];
}
bool cmpsz(int a,int b){
	return sz[a]<sz[b];
}
int main(){
	n=read();
	if (n==1)
		return 0;
	int v=2*n*n/9;
	For(i,1,n-1){
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
	}
	dfs(1,0);
	int x=rt;
	for (auto y : e[x])
		if (sz[y]>sz[x])
			sz[y]=n-sz[x];
	sort(e[x].begin(),e[x].end(),cmpsz);
	assert(sz[e[x].back()]<=n/2);
	dfs2(x,0);
	//a * b 
	// 1 ~ a, (a+1), 2(a+1), 3(a+1), .. b(a+1)
	int a=0;
	for (auto i : e[x]){
		a+=sz[i];
		if ((a+1)*(n-a)-1>=v)
			break;
	}
	assert((a+1)*(n-a)-1>=v);
	For(i,1,n)
		if (d[i]>a){
			d[i]-=a;
			d[i]*=a+1;
		}
	For(i,1,n)
		if (fa[i]){
			printf("%d %d %d\n",i,fa[i],d[i]-d[fa[i]]);
		}
		
	return 0;
}