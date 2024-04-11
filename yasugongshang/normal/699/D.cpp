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
inline int read()// 
{
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
const int N=1000005;
int ans,que[N],quan,r,vvv[N],vvvv[N],vv[N],nedge,vis[N],ed[N],nextt[N],son[N],color,a[N],flag,n,v[N];
inline bool dfs(int p,int last){
	vis[p]=color; 
	for(int i=son[p];i;i=nextt[i])if(!vis[ed[i]]){
		que[++r]=p;dfs(ed[i],i);r--;
	}else {if(last!=((i-1)^1)+1&&!vvv[p]){while(que[r]!=ed[i]&&r)vvv[que[r--]]=1;vvv[que[r--]]=1;vvv[p]=1;}}
}
inline void aedge(int a,int b){
	nextt[++nedge]=son[a];
	son[a]=nedge;
	ed[nedge]=b;
}
int main(){
	n=read(); 
	for(int i=1;i<=n;i++){a[i]=read(); if(a[i]==i)flag=i;}
	for(int i=1;i<=n;i++){aedge(i,a[i]); aedge(a[i],i);}
	for(int i=1;i<=n;i++)if(!vis[i]){color++;  r=0; quan=i; dfs(i,i);}
	if(!flag)writeln(color); else writeln(color-1);
	//for(int i=1;i<=n;i++)cout<<vvv[i]<<" "<<i<<endl;
	//if(!flag){flag=1;a[1]=1;}
	if(!flag){for(int i=1;i<=n;i++)if(vvv[i]){
		flag=i; a[i]=i; break;
	}
	if(!flag){flag=1; a[1]=1;}}
	for(int i=1;i<=n;i++)if(a[i]==i)vv[vis[i]]=true;
	for(int i=1;i<=n;i++){
		if(vis[i]!=vis[flag]&&(!vv[vis[i]]||a[i]==i)&&(vvv[i]||vv[vis[i]])){
			if(!v[vis[i]])a[i]=flag; v[vis[i]]=1;
		}
	}
	for(int i=1;i<=n;i++){
		write(a[i]); putchar(' ');
	}
}