#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define per(i,a,b) for(int i=a;i>=int(b);i--)
#define rep(i,a,b) for(int i=a;i<=int(b);i++)
const int N=5e5+5;
vector<int> e[N];
int d[N],f[1<<22];
int n,mk[N],s[N],mv[N],m,dfn[N],fin[N],p[N],ans[N];
int dfs(int x){
	s[x]=1;dfn[x]=++m;p[m]=x;
	for(int y:e[x]){
		d[y]=d[x]+1;dfs(y);s[x]+=s[y];
		if(s[mv[x]]<s[y])mv[x]=y;
	}
	fin[x]=m;
}
int Mx(int&a,int b){
	return a<b?a=b,1:0;
}
#define z p[i]
int qry(int x){
	int ret=-1e9;if(f[x])ret=f[x];
	rep(i,0,21)if(f[x^1<<i])Mx(ret,f[x^1<<i]);
	return ret;
}
int dfs(int x,int fg){
	for(int y:e[x])if(y!=mv[x])dfs(y,0);
	if(mv[x])dfs(mv[x],1);
	for(int y:e[x]){
		Mx(ans[x],ans[y]);if(fg&&y==mv[x])continue;
		rep(i,dfn[y],fin[y])if(y!=mv[x])Mx(ans[x],d[z]+qry(mk[z])-2*d[x]);
		rep(i,dfn[y],fin[y])if(y!=mv[x])Mx(f[mk[z]],d[z]);
	}
	Mx(f[mk[x]],d[x]);
	Mx(ans[x],qry(mk[x])-d[x]);
	if(!fg)rep(i,dfn[x],fin[x])f[mk[z]]=0;
}
int main(){
	cin>>n;
	rep(y,2,n){
		int x;char s[3];
		scanf("%d%s",&x,s);
		e[x].pb(y);
		mk[y]=mk[x]^1<<s[0]-'a';
	}
	d[1]=1;dfs(1);dfs(1,1);
	rep(i,1,n)printf("%d ",ans[i]);
}