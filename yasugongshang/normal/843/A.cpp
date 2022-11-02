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
const int N=200005;
int ans,n,que[N],vis[N],ed[N],son[N],nextt[N],nedge,r;
struct data{
	int val,pos;
}a[N];
inline bool cmp(data a,data b){
	return a.val<b.val;
}
inline void dfs(int p){
	if(vis[p])return; else vis[p]=1;
	que[++r]=p;
	for(int i=son[p];i;i=nextt[i])dfs(ed[i]);
}
inline void aedge(int a,int b){
	nextt[++nedge]=son[a]; son[a]=nedge; ed[nedge]=b;
}
int main(){
    n=read();
    for(int i=1;i<=n;i++){a[i].val=read(); a[i].pos=i;}
    sort(&a[1],&a[n+1],cmp);
    for(int i=1;i<=n;i++){
    	aedge(a[i].pos,i); aedge(i,a[i].pos);
	}
	for(int i=1;i<=n;i++)if(!vis[i]){
		dfs(i);
		ans++;
	}
	writeln(ans); memset(vis,0,sizeof(vis)); r=0;
	for(int i=1;i<=n;i++)if(!vis[i]){
		dfs(i);
		write(r); putchar(' ');
		while(r){
			write(que[r--]); putchar(' ');
		}puts("");
	}
}