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
const int M=2e5+10;
int n;
vector<int> v[M],t[M];
bool vis[M];
int d[M],tot,del,all,fd,dfn[M],sz[M]; 
LL f[M];
void dfs(int x,int fa){
	dfn[x]=++tot; sz[x]=1;
	F(i,0,SZ(v[x])){
		int y=v[x][i];
		if (y==fa) continue;
		dfs(y,x); sz[x]+=sz[y];
	}
	if (sz[x]==fd || all-sz[x]==fd){
		del=x;
	}
}
bool solve(vector<int> s){
	int num=d[SZ(s)+1];
//	cout<<num<<"\n";
	if (num==1) return 1;
	if (!num) return 0;
	F(i,0,SZ(s)){
		vis[s[i]]=1;
//		cout<<s[i]<<"  v\n";
	}
	F(i,0,SZ(s)){
		int x=s[i];
		t[x].clear();
		F(j,0,SZ(v[x])){
			int y=v[x][j];
			if (vis[y]) t[x].pb(y);
		}
		v[x]=t[x];
	}
	tot=del=0; all=f[num];
	fd=f[num-2];
	dfs(s[0],0);
	if (!del) return 0;
	int l=dfn[del],r=dfn[del]+sz[del]-1;
	vector<int> p1,p2;
	F(i,0,SZ(s)){
		int y=s[i];
		vis[y]=0;
		if (dfn[y]>=l && dfn[y]<=r){
			p2.pb(y);
		}
		else p1.pb(y);
	}
	bool a1=solve(p1);
	if (!a1) return 0;
	return solve(p2);
}
int main(){
	n=read();
	vector<int> id;
	f[0]=1; f[1]=1; d[1]=1;
	F(i,2,30){
		f[i]=f[i-1]+f[i-2];
		if (f[i]<=n) d[f[i]]=i;
//		cout<<f[i]<<"\n";
	}
	F(i,1,n-1){
		int x=read(),y=read();
		v[x].pb(y); v[y].pb(x);
	}
	F(i,1,n) id.pb(i);
	bool ans=solve(id);
	cout<<(ans ? "YES" : "NO")<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
13
1 2
2 3
1 4
4 5
5 6
5 7
5 8
1 9
9 10
10 11
11 12
11 13

13
1 2
2 3
1 4
4 5
5 6
5 7
7 8
1 9
9 10
10 11
11 12
11 13
*/