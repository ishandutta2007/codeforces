#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
inline int read(){
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    write(a); puts("");
}
const int N=400005;
int nextt[N],ed[N],son[N],vis[N],flag,a[N],b[N],nedge,n;
inline void aedge(int a,int b){
	nextt[++nedge]=son[a];
	son[a]=nedge;
	ed[nedge]=b;
	swap(a,b);
	nextt[++nedge]=son[a];
	son[a]=nedge;
	ed[nedge]=b;
}
inline void dfs(int p,int color){
	vis[p]=color;
	for(int i=son[p];i;i=nextt[i]){
		if(vis[ed[i]]==-1)dfs(ed[i],color^1); else if(vis[ed[i]]==color){
			flag=1; return;
		}
	}
}
int main(){
    n=read();
    for(int i=1;i<=n;i++){
    	aedge(i*2-1,i*2); a[i]=read(); b[i]=read(); aedge(a[i],b[i]);
	}
	memset(vis,-1,sizeof(vis));
	for(int i=1;i<=n*2;i++)if(vis[i]==-1){
		dfs(i,0); 
		if(flag){
			puts("-1"); return 0;
		}
	}
    for(int i=1;i<=n;i++){
    	write(vis[a[i]]+1); putchar(' '); writeln(vis[b[i]]+1);
	}
}