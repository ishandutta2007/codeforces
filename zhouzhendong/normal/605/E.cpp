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
double p[N][N];
double dis[N],sp[N],val[N];
int vis[N];
int main(){
	n=read();
	For(i,1,n)
		For(j,1,n)
			p[i][j]=(double)read()/100;
	For(i,1,n)
		sp[i]=1;
	vis[n]=1;
	For(i,1,n-1)
		dis[i]+=p[i][n],sp[i]*=1-p[i][n];
	For(_,1,n-1){
		int k=0;
		For(i,1,n)
			if (!vis[i]){
				// E = dis[i] + sp[i] * (E+1) -> E = (dis[i]+sp[i])/(1-sp[i])
				val[i]=(dis[i]+sp[i])/(1-sp[i]);
				if (!k||val[i]<val[k])
					k=i;
			}
		vis[k]=1;
		dis[k]=val[k];
		For(i,1,n)
			if (!vis[i])
				dis[i]+=p[i][k]*sp[i]*(dis[k]+1),sp[i]*=1-p[i][k];
	}
	printf("%.8lf\n",dis[1]);
	return 0;
}