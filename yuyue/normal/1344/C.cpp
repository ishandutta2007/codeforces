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
int n,m,de[M],rd[M],f[M],g[M],q[M],l,r;
vector<int> v[M],rv[M];
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(); m=read();
	F(i,1,m){
		int x=read(),y=read();
		v[x].pb(y);
		rv[y].pb(x);
		de[y]++;
		rd[x]++;
	}
	F(i,1,n) f[i]=g[i]=i; 
	F(i,1,n) if (!de[i]) f[i]=i,q[++r]=i;
	while (l<=r){
		int x=q[l++];
		for (int y:v[x]){
			de[y]--;
			if (!de[y]) q[++r]=y;
			f[y]=min(f[y],f[x]);
		}
	}
	if (r!=n){
		puts("-1");
		return 0;
	}
	l=1,r=0;
	F(i,1,n) if (!rd[i]) g[i]=i,q[++r]=i;
	while (l<=r){
		int x=q[l++];
		for (int y:rv[x]){
			rd[y]--;
			if (!rd[y]) q[++r]=y;
			g[y]=min(g[y],g[x]);
		}
	}
	int ans=0;
	F(i,1,n) ans+=(min(f[i],g[i])>=i);
	cout<<ans<<"\n";
	F(i,1,n){
		cout<<"EA"[(min(f[i],g[i])>=i)]; 
	}
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/