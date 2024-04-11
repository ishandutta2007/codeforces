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
const int N=100005;
int q[N],mod,di[N<<1],nedge,peo[N],f[N],que1[N],que2[N],que3[N],ycl[N],r,son[N],nextt[N<<1],ed[N<<1],sum,root,k,vis[N],n;
long long ans;
inline void aedge(int a,int b,int c){
	nextt[++nedge]=son[a]; son[a]=nedge; ed[nedge]=b; di[nedge]=c;
}
void get(int p,int fa){
	peo[p]=1; f[p]=0;
	for(int i=son[p];i;i=nextt[i])if(!vis[ed[i]]&&ed[i]!=fa){
		get(ed[i],p); peo[p]+=peo[ed[i]]; f[p]=max(f[p],peo[ed[i]]);
	}
	f[p]=max(f[p],sum-f[p]); //cout<<p<<" "<<f[p]<<endl;
	if(f[p]<f[root])root=p;
}
inline void exgcd(int a,int b,int &x,int &y){
	if(!b)x=1,y=0;
	else exgcd(b,a%b,y,x),y-=x*(a/b);
}
inline int inv(int a){
	int x,y; exgcd(a,mod,x,y);
	x=(x%mod+mod)%mod;
	return x==0?mod:x;
}
#include<ext/pb_ds/hash_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
__gnu_pbds::gp_hash_table<int,int> M;
void calc(){
	for(int i=1;i<=r;i++){
		int x=(long long)(mod-que1[i])*inv(ycl[que3[i]])%mod;
		//cout<<que1[i]<<" "<<que2[i]<<" "<<que3[i]<<" "<<x<<endl;
		ans+=M[(x%mod+mod)%mod];
	}
	for(int i=1;i<=r;i++)M[que2[i]%mod]++;
	r=0;
}
void dfs(int p,int fa,int dist1,int dist2,int dist){
	que1[++r]=dist1%mod; que2[r]=dist2%mod; que3[r]=dist;
	for(int i=son[p];i;i=nextt[i])if(ed[i]!=fa&&!vis[ed[i]])dfs(ed[i],p,((long long)dist1*10+di[i])%mod,(dist2+(long long)ycl[dist]*di[i])%mod,dist+1);
}
void solve(int p){
	vis[p]=1;
	int tot=0; M.clear();
	for(int i=son[p];i;i=nextt[i])if(!vis[ed[i]]){
		dfs(ed[i],p,di[i],di[i],1); calc(); q[++tot]=i;
	}M.clear();
	for(int i=tot;i;i--){dfs(ed[q[i]],p,di[q[i]],di[q[i]],1); for(int j=1;j<=r;j++)ans+=(que1[j]==0)+(que2[j]==0); calc();}
	for(int i=son[p];i;i=nextt[i])if(!vis[ed[i]]){
		root=0; sum=peo[ed[i]]; get(ed[i],0); solve(root);
	}
}
int main(){
	n=read(); mod=read();
	ans=0; f[0]=1e9; ycl[0]=1;
	memset(son,0,sizeof(son)); nedge=0; memset(vis,0,sizeof(vis));
	for(int i=1;i<n;i++){
		ycl[i]=(long long)ycl[i-1]*10%mod;
		int a=read()+1,b=read()+1,c=read()%mod;
		aedge(a,b,c); aedge(b,a,c);
	}
	sum=n; get(1,0);
	solve(root);
	cout<<ans<<endl;
}