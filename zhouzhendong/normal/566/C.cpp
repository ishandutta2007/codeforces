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
// d/dx (x+a)^(3/2) = 3/2 * (x+a)^(1/2)
// d/dx (a-x)^(3/2) = -3/2 * (a-x)^(1/2)
const int N=200005;
int n;
int w[N];
vector <pair <int,int> > e[N];
double ans=1e30,tmp;
int ansid=0;
int vis[N];
int size[N],mx[N];
int Size,RT;
double dao[N];
void getroot(int x,int pre=0){
	size[x]=1,mx[x]=0;
	for (auto E : e[x])
		if (E.fi!=pre&&!vis[E.fi]){
			int y=E.fi;
			getroot(y,x);
			size[x]+=size[y];
			mx[x]=max(mx[x],size[y]);
		}
	mx[x]=max(mx[x],Size-size[x]);
	if (!RT||mx[x]<mx[RT])
		RT=x;
}
void dfs(int x,int pre,double d){
	dao[x]=sqrt(d)*w[x];
	tmp+=pow(d,1.5)*w[x];
	for (auto E : e[x])
		if (E.fi!=pre){
			int y=E.fi;
			dfs(y,x,d+E.se);
			dao[x]+=dao[y];
		}
}
void Solve(int x){
	RT=0;
	getroot(x);
	x=RT;
	tmp=0;
	dfs(x,0,0);
	if (tmp<ans)
		ans=tmp,ansid=x;
	vis[x]=1;
	for (auto E : e[x]){
		int y=E.fi;
		if (vis[y])
			continue;
		if (size[y]>size[x])
			size[y]=Size-size[x];
		double d=dao[x]-dao[y]*2;
		if (d<-1e-6){
			Size=size[y],Solve(y);
			break;
		}
	}
}
int main(){
	n=read();
	For(i,1,n)
		w[i]=read();
	For(i,1,n-1){
		int x=read(),y=read(),z=read();
		e[x].pb(mp(y,z));
		e[y].pb(mp(x,z));
	}
	Size=n,Solve(1);
	printf("%d %.8lf\n",ansid,ans);
	return 0;
}
/*
10
1 1 1 1 1 1 1 1 1  1
1 2 1 
2 3 1 
3 4 1 
4 5 1 
5 6 1 
6 7 1 
7 8 1 
8 9 1 
9 10 1 
*/