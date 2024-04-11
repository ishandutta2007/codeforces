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
const int M=1e5+10;
int n;
vector<int> v[M];
int dep[M];
int s[M],f[M];
void dfs(int x,int fa){
	dep[x]=dep[fa]+1; f[x]=fa;
	if (dep[x]==1) s[x]=0;
	else if (dep[x]==2) s[x]=1;
	else s[x]=s[1]-s[fa];
	for (int y:v[x]){
		if (y^fa) dfs(y,x);
	}
}
void work(){
	n=read();
	F(i,1,n) v[i].clear();
	F(i,1,n-1){
		int x=read(),y=read();
		v[x].pb(y); v[y].pb(x);
	}
	dfs(1,0);
	F(i,1,n){
		int tmp=s[i];
		for (int y:v[i]){
			if (y^f[i]) tmp-=s[y]; 
		}
		cout<<tmp<<" ";
	}
	cout<<"\n";
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read();
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