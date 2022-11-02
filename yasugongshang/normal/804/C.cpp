#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
inline void write(long long a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(long long a){
	write(a); puts("");
}
inline long long read()// 
{
	long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
const int N=300005;
int ans,an,vis[N],color[N],n,m,nextt[N<<1],son[N],ed[N<<1],nedge;
vector<int> v[N];
map<int,bool> M;
inline void aedge(int a,int b){
	nextt[++nedge]=son[a]; son[a]=nedge; ed[nedge]=b;
}
inline void dfs(int p){
	int meiju=v[p].size(); M.clear(); vis[p]=1;
	for(int i=0;i<meiju;i++)if(color[v[p][i]]){
		M[color[v[p][i]]]=1;
	}int j=1;
	for(int i=0;i<meiju;i++)if(!color[v[p][i]]){
		while(M[j])j++; M[j]=1; color[v[p][i]]=j;
	}
	for(int i=son[p];i;i=nextt[i])if(!vis[ed[i]]){
		dfs(ed[i]);
	}
}
int main(){
	n=read(); m=read(); ans=1;
	for(int i=1;i<=n;i++){
		int zs=read(); if(zs>ans){
			ans=zs; an=i;
		}while(zs--)v[i].push_back(read());
	}
	for(int i=1;i<n;i++){
		int s1=read(),s2=read();
		aedge(s1,s2); aedge(s2,s1);
	}
	writeln(ans);
	dfs(an);
	for(int i=1;i<=m;i++){if(color[i])
		write(color[i]); 
	else write(1); putchar(' ');}
}