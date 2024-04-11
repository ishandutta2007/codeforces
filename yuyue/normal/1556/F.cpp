#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=(1<<14)+10,mod=1e9+7;
int n,a[M];
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
} 
LL g[M],c[20][M];
int sz[M];
#define lowbit(x) (x&-x)
int main(){
	n=read();
	F(i,0,n-1) a[i]=read();
	F(i,0,n-1){
		c[i][0]=1;
		F(j,0,n-1){
			if (i^j) c[i][(1<<j)]=fast(a[i]+a[j],mod-2)*a[i]%mod;
		}
		F(j,1,(1<<n)-1){
			c[i][j]=c[i][j^lowbit(j)]*c[i][lowbit(j)]%mod;
		}
	}
	g[0]=1;
	LL ans=0;
	F(s,1,(1<<n)-1){
		sz[s]=sz[s^lowbit(s)]+1;
		g[s]=1;
		for (int t=(s-1)&s;t;t=(t-1)&s){
			LL coe=g[t]; 
			F(j,0,n-1) if (t>>j&1) coe=coe*c[j][s^t]%mod;
			g[s]=(g[s]+mod-coe)%mod;
		}
		LL coe=g[s];
		F(i,0,n-1){
			if (s>>i&1) coe=coe*c[i][((1<<n)-1)^s]%mod;
		}
		ans=(ans+coe*sz[s])%mod;
	}
	cout<<ans<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/