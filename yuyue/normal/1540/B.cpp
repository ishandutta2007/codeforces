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
const int M=333,mod=1e9+7,i2=(mod+1)/2;
LL f[M][M];
int n;
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
LL iv[M];
void init(){
	F(i,1,n) iv[i]=fast(i,mod-2),f[0][i]=1;
	F(i,1,n){
		F(j,1,n){
			f[i][j]=(f[i-1][j]+f[i][j-1])*i2%mod;
		}
	}
}
vector<int> v[M];
int rt,sz[M],dep[M],ft[M];
void dfs0(int x,int fa){
	ft[x]=fa;
	dep[x]=dep[fa]+1; sz[x]=1;
	for (int y:v[x]){
		if (y^fa) dfs0(y,x),sz[x]+=sz[y];
	}
}
LL ans;
void dfs(int x,int fa){
	if (x>rt){
		ans+=sz[x];
		for (int y=x;y^rt;y=ft[y]){
			int ss=sz[ft[y]]-sz[y];
			ans+=f[dep[x]-dep[ft[y]]][dep[ft[y]]]*ss;
			ans%=mod;
		}
	}
	for (int y:v[x]){
		if (y^fa) dfs(y,x);
	}
}
int main(){
	n=read();
	init();
	F(i,1,n-1){
		int x=read(),y=read();
		v[x].pb(y);
		v[y].pb(x);
	}
	dep[0]=-1;
	F(i,1,n) rt=i,dfs0(i,0),dfs(i,0);
	ans%=mod;
	ans=ans*iv[n]%mod;
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