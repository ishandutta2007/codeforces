#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
//#define OO(x) fixed<<setprecision(x)
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=5e5+10;
int n,m,a[M];
LL f[M],g[M];
LL ans;
vector<pair<int,int> > v[M];
void dfs(int x,int fa){
	f[x]=a[x];
	ans=max(ans,1ll*a[x]);
	for (auto O:v[x]){
		int y=O.first,z=O.second;
		if (y^fa){
			dfs(y,x);
			LL tmp=f[y]-z;
			ans=max(ans,tmp+f[x]);
			f[x]=max(f[x],tmp+a[x]);
		}
	}
}
void work(){
	n=read();
	F(i,1,n) a[i]=read();
	F(i,1,n-1){
		int x=read(),y=read(),z=read();
		v[x].pb({y,z});
		v[y].pb({x,z}); 
	}
	dfs(1,0);
	cout<<ans<<"\n";
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int T=1;
	while (T--) work(); 
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/