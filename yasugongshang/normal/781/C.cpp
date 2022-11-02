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
const int N=200005;
int vis[N],tot,ans[N<<1],n,m,k;
vector<int> e[N];
inline void dfs(int p){
	vis[p]=1; ans[++tot]=p;
	for(int i=0;i<e[p].size();i++)if(!vis[e[p][i]]){
		vis[e[p][i]]=1; dfs(e[p][i]); ans[++tot]=p;
	}
}
int main(){
	n=read(); m=read(); k=read();
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		e[u].push_back(v); e[v].push_back(u);
	}
	dfs(1); int len=(2*n+k-1)/k;
	for(int i=1;i<=k;i++){
		//cout<<tot-(i-1)*len<<" "<<len<<" "<<i<<endl;
		if(min(tot,i*len)-(i-1)*len<=0){
			puts("1 1"); continue;
		}
		write(min(tot,i*len)-(i-1)*len); putchar(' ');
		for(int j=i*len-len+1;j<=i*len&&j<=tot;j++){
			write(ans[j]); putchar(' ');
		}
		puts("");
	}
}