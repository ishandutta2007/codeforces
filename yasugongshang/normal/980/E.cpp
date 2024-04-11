#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
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
const int N=1000005,K=20;
int n,k,ti,in[N],out[N],vis[N];
int dp[N][K],dep[N];
vector<int> v[N];
void dfs(int p,int fa){
	in[p]=++ti; dp[p][0]=fa; dep[p]=dep[fa]+1;
	for(unsigned i=0;i<v[p].size();i++)if(v[p][i]!=fa)dfs(v[p][i],p);
	out[p]=ti;
}
inline bool fa(int a,int b){
	return in[a]<=in[b]&&out[a]>=out[b];
}
inline int lca(int a,int b){
	if(fa(a,b))return a; else if(fa(b,a))return b;
	for(int i=K-1;i>=0;i--)if(dp[a][i]&&!fa(dp[a][i],b))a=dp[a][i];
	return dp[a][0];
}
int main(){
	n=read(); k=read();
	for(int i=1;i<n;i++){
		int a=read(),b=read();
		v[a].push_back(b); v[b].push_back(a);
	}
	dfs(1,0);
	for(int i=1;i<K;i++)for(int j=1;j<=n;j++)dp[j][i]=dp[dp[j][i-1]][i-1];
	vis[n]=1; int sum=1,dq=n; 
	for(int i=n-1;i;i--)if(!vis[i]){
		if(fa(dq,i)){
			int x=i;
			for(int j=K-1;j>=0;j--)if(dp[x][j]&&!vis[dp[x][j]]&&dep[dp[x][j]]>=dep[dq])x=dp[x][j]; 
			if(dep[i]-dep[x]+1+sum<=n-k){sum+=dep[i]-dep[x]+1; for(int j=i;!vis[j];j=dp[j][0])vis[j]=1;} 
		}else{
			int x=lca(i,dq),t=dep[dq]+dep[i]-2*dep[x]; 
			if(t+sum<=n-k){
				sum+=t;
				for(int j=i;j!=x;j=dp[j][0])vis[j]=1;
				for(int j=dq;j!=x;j=dp[j][0])vis[j]=1; vis[x]=1; dq=x;
			}
		}
	}
	for(int i=1;i<=n;i++)if(!vis[i]){
		write(i); putchar(' ');
	}
}