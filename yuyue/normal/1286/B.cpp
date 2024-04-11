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
const int M=2020;
vector<int> v[M];
int res[M][M],c[M],tt[M],ans[M],sz[M];
bool dfs(int x){
	sz[x]=1;
	F(i,0,SZ(v[x])){
		int y=v[x][i];
		if (!dfs(y)) return 0;
		sz[x]+=sz[y];
	}
	if (c[x]>=sz[x]) return 0;
	F(i,0,SZ(v[x])){
		int y=v[x][i];
		F(j,1,tt[y]){
			++tt[x];
			if (tt[x]-1==c[x]){
				res[x][tt[x]]=x;
				tt[x]++;
			}
			res[x][tt[x]]=res[y][j];
		}
	}
	if (c[x]==sz[x]-1) res[x][++tt[x]]=x;
	return 1;
}
int n,p[M],rt;
int main(){
	n=read();
	F(i,1,n){
		p[i]=read(); c[i]=read();
		if (p[i]) v[p[i]].pb(i);
		else rt=i;
	}
	if (dfs(rt)){
		puts("YES");
		F(i,1,n){
			ans[res[rt][i]]=i;
		}
		F(i,1,n) cout<<ans[i]<<" ";
	}
	else puts("NO");
	return 0;
}