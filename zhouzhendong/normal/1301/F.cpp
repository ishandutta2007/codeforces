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
const int N=1005,K=41;
int n,m,k,q;
int a[N][N];
short d[K][N][N];
short D[K][N][N];
int vis[N][N];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int check(int x,int y){
	return 1<=x&&x<=n&&1<=y&&y<=m;
}
vector <pii> pos[K];
void getd(){
	For(c,1,k){
		clr(vis);
		queue <pii> Q;
		for (auto pr : pos[c]){
			int i=pr.fi,j=pr.se;
			d[c][i][j]=1,vis[i][j]=1,Q.push(mp(i,j));
		}
		while (!Q.empty()){
			pii p=Q.front();
			Q.pop();
			int x=p.fi,y=p.se;
			For(i,0,3){
				int X=x+dx[i],Y=y+dy[i];
				if (check(X,Y)&&!vis[X][Y]){
					d[c][X][Y]=d[c][x][y]+1;
					vis[X][Y]=1;
					Q.push(mp(X,Y));
				}
			}
		}
	}
}
void getD(){
	For(c,1,k){
		clr(vis);
		queue <pii> Q;
		vis[0][c]=1;
		for (auto pr : pos[c]){
			int i=pr.fi,j=pr.se;
			D[c][i][j]=0,vis[i][j]=1,Q.push(mp(i,j));
		}
		while (!Q.empty()){
			pii p=Q.front();
			Q.pop();
			int x=p.fi,y=p.se;
			For(i,0,3){
				int X=x+dx[i],Y=y+dy[i];
				if (check(X,Y)&&!vis[X][Y]){
					D[c][X][Y]=D[c][x][y]+1;
					vis[X][Y]=1;
					Q.push(mp(X,Y));
				}
			}
			if (!vis[0][a[x][y]]){
				int C=a[x][y];
				vis[0][C]=1;
				for (auto pr : pos[C]){
					int i=pr.fi,j=pr.se;
					if (!vis[i][j]){
						D[c][i][j]=D[c][x][y]+1;
						vis[i][j]=1;
						Q.push(mp(i,j));
					}
				}
			}
		}
	}
}
int main(){
	n=read(),m=read(),k=read();
	For(i,1,n)
		For(j,1,m){
			a[i][j]=read();
			pos[a[i][j]].pb(mp(i,j));
		}
	getd();
	getD();
	int q=read();
	while (q--){
		int x0=read(),y0=read(),x1=read(),y1=read();
		int ans=abs(x0-x1)+abs(y0-y1);
		For(c,1,k)
			ans=min(ans,d[c][x0][y0]+D[c][x1][y1]);
		printf("%d\n",ans);
	}
	return 0;
}