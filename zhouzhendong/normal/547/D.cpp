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
const int N=200005*2;
int n,m=200000;
int xp[N],yp[N],co[N];
vector <int> e[N];
int d[N];
void dfs(int x){
	while (!e[x].empty()){
		int i=e[x].back();
		e[x].pop_back();
		if (co[i])
			continue;
		int y=yp[i]==x?xp[i]:yp[i];
		co[i]=x<y?1:-1;
		d[x]--,d[y]--;
		dfs(y);
		break;
	}
}
int main(){
	n=read();
	For(i,1,n){
		int x=xp[i]=read(),y=yp[i]=read()+m;
		e[x].pb(i);
		e[y].pb(i);
	}
	For(i,1,m*2)
		d[i]=e[i].size();
	For(i,1,m*2)
		if (d[i]&1)
			dfs(i);
	For(i,1,m*2)
		while (e[i].size())
			dfs(i);
	For(i,1,n)
		putchar(co[i]==1?'r':'b');
	return 0;
}
/*
3
1 2
1 3 
1 4

*/