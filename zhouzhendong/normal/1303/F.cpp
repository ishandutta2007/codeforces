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
const int N=305,M=2e6+5;
int n,m,q,mc;
int a[N][N];
struct P{
	int x,y,t;
	P(){}
	P(int _x,int _y,int _t){
		x=_x,y=_y,t=_t;
	}
};
vector <P> I[M],O[M];
int res[M];
int fa[N*N];
int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
inline int ID(int x,int y){
	return (x-1)*m+y;
}
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
inline int check(int x,int y){
	return 1<=x&&x<=n&&1<=y&&y<=m&&a[x][y];
}
int main(){
	n=read(),m=read(),q=read(),mc=0;
	For(i,1,n)
		For(j,1,m)
			I[0].pb(P(i,j,0));
	For(i,1,q){
		int x=read(),y=read(),c=read();
		mc=max(mc,c);
		if (a[x][y]!=c){
			O[a[x][y]].pb(P(x,y,i));
			I[a[x][y]=c].pb(P(x,y,i));
		}
	}
	For(i,1,n)
		For(j,1,m)
			O[a[i][j]].pb(P(i,j,q+1));
	For(c,0,mc){
		For(i,1,n*m)
			fa[i]=i;
		For(i,1,n)
			For(j,1,m)
				a[i][j]=0;
		for (auto p : I[c]){
			int x=p.x,y=p.y,t=p.t;
			res[t]++;
			a[x][y]=1;
			For(d,0,3){
				int X=x+dx[d],Y=y+dy[d];
				if (check(X,Y)){
					int f1=getf(ID(x,y));
					int f2=getf(ID(X,Y));
					if (f1!=f2)
						res[t]--,fa[f1]=f2;
				}
			}
		}
		For(i,1,n*m)
			fa[i]=i;
		For(i,1,n)
			For(j,1,m)
				a[i][j]=0;
		reverse(O[c].begin(),O[c].end());
		for (auto p : O[c]){
			int x=p.x,y=p.y,t=p.t;
			res[t]--;
			a[x][y]=1;
			For(d,0,3){
				int X=x+dx[d],Y=y+dy[d];
				if (check(X,Y)){
					int f1=getf(ID(x,y));
					int f2=getf(ID(X,Y));
					if (f1!=f2)
						res[t]++,fa[f1]=f2;
				}
			}
		}
	}
	For(i,1,q){
		res[i]+=res[i-1];
		printf("%d\n",res[i]);
	}
	return 0;
}