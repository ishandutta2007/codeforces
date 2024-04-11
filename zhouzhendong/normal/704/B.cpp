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
const int N=5005;
const LL INF=1e18;
int n,S,E;
int x[N],a[N],b[N],c[N],d[N];
LL dp[N][N];
void ckmin(LL &a,LL b){
	if (a>b)
		a=b;
}
int main(){
	n=read(),S=read(),E=read();
	For(i,1,n)
		x[i]=read();
	For(i,1,n)
		a[i]=read();
	For(i,1,n)
		b[i]=read();
	For(i,1,n)
		c[i]=read();
	For(i,1,n)
		d[i]=read();
	For(i,0,N-1)
		For(j,0,N-1)
			dp[i][j]=INF;
	if (S>E){
		swap(S,E);
		For(i,1,n)
			swap(d[i],b[i]),swap(a[i],c[i]);
	}
	For(i,1,n)
		a[i]+=x[i],b[i]-=x[i],c[i]+=x[i],d[i]-=x[i];
	if (S==1)
		dp[1][0]=d[1];
	else
		dp[1][1]=d[1]+b[1];
	For(i,2,n){
		int A=a[i],B=b[i],C=c[i],D=d[i];
		For(j,0,i){
			LL v=dp[i-1][j];
			if (v==INF)
				continue;
			int k=j+(i>S)-(i>E);
			if (!j&&!k)
				continue;
			if (i==S){
				ckmin(dp[i][j],v+D);
				if (j)
					ckmin(dp[i][j-1],v+C);
			}
			else if (i==E){
				ckmin(dp[i][j],v+A);
				ckmin(dp[i][j+1],v+B);
			}
			else {
				ckmin(dp[i][j],v+A+D);
				if (j)
					ckmin(dp[i][j],v+C+B);
				ckmin(dp[i][j+1],v+B+D);
				if (j)
					ckmin(dp[i][j-1],v+C+A);
			}
		}
	}
	cout<<dp[n][0]<<endl;
	return 0;
}