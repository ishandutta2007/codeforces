#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
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
const int N=1005;
int n;
int g[N][N],d[N];
vi e[N];
void Answer(int r){
	printf("! %d\n",r);
	fflush(stdout);
	exit(0);
}
int Ask(int x,int y){
	printf("? %d %d\n",x,y);
	fflush(stdout);
	return read();
}
vector <int> id;
void dfs(int x,int pre){
	id.pb(x);
	for (auto y : e[x])
		if (g[x][y]&&y!=pre)
			dfs(y,x);
}
int get(int x,int pre,int a){
	for (auto y : e[x])
		if (g[x][y]&&y!=pre){
			if (y==a)
				return x;
			int res=get(y,x,a);
			if (res)
				return res;
		}
	return 0;
}
int main(){
	n=read();
	For(i,1,n-1){
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
		g[x][y]=g[y][x]=1;
		d[x]++,d[y]++;
	}
	dfs(1,0);
	while (1){
//		outarr(id,0,(int)id.size()-1);
		if (id.size()==1)
			Answer(id[0]);
		sort(id.begin(),id.end(),[&](int x,int y){return d[x]<d[y];});
		int a=id[0],b=id[1];
//		assert(d[b]==1);
		int c=Ask(a,b);
		if (c==a||c==b)
			Answer(c);
		int na=get(a,0,c);
		int nb=get(b,0,c);
//		outval(na),outval(nb);
		d[na]--,d[nb]--,d[c]-=2;
		g[na][c]=g[c][na]=g[nb][c]=g[c][nb]=0;
		id.clear();
		dfs(c,0);
	}
	return 0;
}