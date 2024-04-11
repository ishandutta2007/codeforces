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
const int M=5e5+10; 
int n,m;
bool vis[M];
vector<int> g[M],v[M];
void dfs(int x){
	vis[x]=1;
	for (int y:g[x]){
		if (!vis[y]){
			v[x].pb(y);
			v[y].pb(x);
			dfs(y);
		}
	}
}
int tar,X[M],Y[M];
vector<int> path;
bool dfs1(int x,int fa){
	if (x==tar){
		path.pb(x);
		return 1;
	}
	bool fl=0;
	F(i,0,SZ(v[x])){
		int y=v[x][i];
		if (y==fa) continue;
		fl|=dfs1(y,x);
	}
	if (fl) path.pb(x);
	return fl;
}
int d[M];
int main(){
	n=read(); m=read();
	F(i,1,m){
		int x=read(),y=read();
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1);
	int Q=read();
	F(i,1,Q){
		int x=read(),y=read();
		X[i]=x; Y[i]=y;
		d[x]^=1; d[y]^=1;
	}
	int sum=0;
	F(i,1,n){
		sum+=d[i];
	}
	if (!sum){
		puts("YES");
		F(i,1,Q){
			tar=Y[i]; path.clear();
			dfs1(X[i],0);
			reverse(path.begin(),path.end());
			cout<<path.size()<<"\n";
			for (int x:path){
				cout<<x<<" ";
			} 
			cout<<"\n";
		}
		return 0;
	}
	puts("NO");
	cout<<sum/2<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/