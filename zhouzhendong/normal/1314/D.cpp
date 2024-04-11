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
const int N=85,INF=1e9+7;
int n,k;
int a[N][N];
int id[N][N][N];
int vis[N];
LL ans=INF;
int v[N];
LL calc(){
	LL now=0;
	For(i,1,k){
		int t=1;
		int x=v[i-1],y=v[i];
		while (vis[id[x][y][t]])
			t++;
		int ID=id[x][y][t];
		now+=a[x][ID]+a[ID][y];
	}
	return now;
}
void dfs(int t){
	if (t==k){
		ans=min(ans,calc());
		return;
	}
	For(i,1,n){
		vis[i]++;
		v[t]=i;
		dfs(t+1);
		vis[i]--;
	}
}
int main(){
	n=read(),k=read()/2;
	For(i,1,n)
		For(j,1,n)
			a[i][j]=read();
	For(i,1,n)
		a[i][0]=a[0][i]=INF;
	For(i,1,n)
		For(j,1,n){
			For(k,1,n)
				id[i][j][k]=k;
			sort(id[i][j]+1,id[i][j]+n+1,[&](int x,int y)->bool{
				return a[i][x]+a[x][j]<a[i][y]+a[y][j];
			});
		}
	v[0]=v[k]=1,vis[1]=1;
	dfs(1);
	cout<<ans<<endl;
	return 0;
}