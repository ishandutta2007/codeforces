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
const int N=100005,M=205;
int n;
LL a[N];
int c[N];
int ans=N;
int g[M][M];
int main(){
	n=read();
	For(i,1,n){
		a[i]=read();
		if (a[i]==0){
			i--,n--;
			continue;
		}
		For(j,0,61)
			c[j]+=a[i]>>j&1;
	}
	For(i,0,61)
		if (c[i]>2)
			return puts("3"),0;
	For(i,1,n)
		For(j,1,n){
			g[i][j]=(a[i]&a[j])?1:N;
		}
	For(k,1,n){
		For(i,1,k-1)
			For(j,i+1,k-1)
				if ((a[k]&a[i])&&(a[k]&a[j]))
					ans=min(ans,g[i][j]+2);
		For(i,1,n)
			For(j,1,n)
				g[i][j]=min(g[i][j],g[k][i]+g[k][j]);
	}
	if (ans==N)
		ans=-1;
	cout<<ans<<endl;
	return 0;
}