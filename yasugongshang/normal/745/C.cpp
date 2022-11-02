#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
inline int	read()// 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
const int N=1000005,M=1000005;
bool tt[N],t[N];
int vis[N],ed[M],nedge,nextt[M],son[N],n,m,k,color,tong[N],mmax,sum,ans;
inline void dfs(int p){
	if(vis[p])return;
	if(tt[p])t[color]=true;
	vis[p]=color; tong[color]++;
	for(int i=son[p];i;i=nextt[i]){
		dfs(ed[i]);
	}
}
inline void aedge(int a,int b){
	nextt[++nedge]=son[a];
	son[a]=nedge;
	ed[nedge]=b;
}

int main(){
	n=read(); m=read(); k=read();
	for(int i=1;i<=k;i++){
		tt[read()]=true;
	}
	for(int i=1;i<=m;i++){
		int s1=read(),s2=read(); aedge(s1,s2); aedge(s2,s1);
	}
	for(int i=1;i<=n;i++)if(!vis[i]){
		color++; dfs(i); if(t[color])mmax=max(mmax,tong[color]); ans+=tong[color]*(tong[color]-1)/2;
	}
	for(int i=1;i<=n;i++){for(int j=i+1;j<=n;j++)if(!t[i]&&!t[j]){
		ans+=tong[i]*tong[j];
	}if(!t[i])ans+=tong[i]*mmax;}
	cout<<ans-m<<endl;
}