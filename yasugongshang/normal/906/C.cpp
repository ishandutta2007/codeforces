#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
int tot,n,m,u,v,e[30],ans,sum,out[30],zs[30],q[500];
inline bool dfs(int p){
	if(p>n){
		for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)if((e[i]&(1<<j))==0)return 0;
		if(sum<ans){
			ans=sum; for(int i=1;i<=ans;i++)out[i]=zs[i];
		}
		return 1;
	}
	if(sum>=ans)return 1;
	zs[++sum]=p;
	for(int i=1;i<=n;i++)q[++tot]=e[i];
	for(int i=1;i<=n;i++)if(e[p]&(1<<i))e[i]|=e[p];
	int t=dfs(p+1);
	sum--;
	for(int i=n;i;i--)e[i]=q[tot--];
	if(t)dfs(p+1);
	return t;
}
int main(){
	n=read(); m=read(); 
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		e[u]|=1<<v; e[v]|=1<<u;
	}
	for(int i=1;i<=n;i++)e[i]|=1<<i;
	ans=n+1;
	dfs(1);
	writeln(ans);
	for(int i=1;i<=ans;i++){
		write(out[i]); putchar(' ');
	}
}