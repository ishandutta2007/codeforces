#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
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
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
inline int rnd(int x){
	return (rand()<<16|rand())%x;
}
const int P=10000005,N=100005,K=18,mod=1000000007;
int dp[N][K],in[N],out[N],ycl[P],ans[N],n,q,ti;
bitset<P> heshu;
vector<int> v[N];
vector<int> tong[P],sz[P];
vector<PI> b[N];
vector<pair<PI,int> > f[N],g[N];
inline ll ksm(ll a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
void ddd(int p,int fa){
	dp[p][0]=fa; in[p]=++ti;
	for(unsigned i=0;i<v[p].size();i++)if(v[p][i]!=fa){
		ddd(v[p][i],p);
	}
	out[p]=ti;
}
vector<PI> mk(int x){
	vector<PI> ans; ans.clear();
	while(x!=1){
		int t=0,tt=ycl[x];
		while(x%tt==0){
			x/=tt; t++;
		}
		ans.push_back(mp(tt,t));
	}
	return ans;
}
void dfs(int p,int fa){
	for(unsigned i=0;i<b[p].size();i++){
		for(unsigned j=b[p][i].second;j<tong[b[p][i].first].size();j++){
			tong[b[p][i].first][j]+=b[p][i].second; sz[b[p][i].first][j]++;
		}
	}
	for(unsigned i=0;i<f[p].size();i++){
		int jb=tong[f[p][i].first.first][f[p][i].first.second]+f[p][i].first.second*
		(sz[f[p][i].first.first][sz[f[p][i].first.first].size()-1]-sz[f[p][i].first.first][f[p][i].first.second]);
		ans[f[p][i].second]=ans[f[p][i].second]*ksm(f[p][i].first.first,jb)%mod;
	}
	for(unsigned i=0;i<g[p].size();i++){
		int jb=tong[g[p][i].first.first][g[p][i].first.second]+g[p][i].first.second*
		(sz[g[p][i].first.first][sz[g[p][i].first.first].size()-1]-sz[g[p][i].first.first][g[p][i].first.second]);
		ans[g[p][i].second]=ans[g[p][i].second]*ksm(g[p][i].first.first,(ll)jb*(mod-2)%(mod-1))%mod;
	}
	for(unsigned i=0;i<v[p].size();i++)if(v[p][i]!=fa){
		dfs(v[p][i],p); 
	}
	for(unsigned i=0;i<b[p].size();i++){
		for(unsigned j=b[p][i].second;j<tong[b[p][i].first].size();j++){
			tong[b[p][i].first][j]-=b[p][i].second; sz[b[p][i].first][j]--;
		}
	}
}
inline bool fa(int a,int b){
	return in[a]<=in[b]&&out[a]>=out[b];
}
inline int LCA(int a,int b){
	if(fa(a,b))return a; else if(fa(b,a))return b;
	for(int i=K-1;i>=0;i--)if(dp[a][i]&&!fa(dp[a][i],b))a=dp[a][i];
	return dp[a][0];
}
int main(){
	n=read();
	for(int i=1;i<n;i++){
		int s=read(),t=read();
		v[s].push_back(t); v[t].push_back(s);
	}
	int gao=1e7;
	for(int i=2;i<=gao;i++){
		if(!heshu[i]){
			ycl[i]=i;
			for(int j=i+i;j<=gao;j+=i){heshu[j]=1; if(!ycl[j])ycl[j]=i;}
		}
	}
	for(int i=2;i<=gao;i++)if(!heshu[i]){
		int t=0,jb=gao;
		while(jb){
			jb/=i; t++;
		}
		tong[i].resize(t+1); sz[i].resize(t+1);
	}
	for(int i=1;i<=n;i++)b[i]=mk(read()); 
	q=read();
	ddd(1,0);
	for(int i=1;i<K;i++)for(int j=1;j<=n;j++)dp[j][i]=dp[dp[j][i-1]][i-1];
	for(int i=1;i<=q;i++){
		int u=read(),v=read(),x=read();
		vector<PI> t=mk(x);
		ans[i]=1;
		for(unsigned j=0;j<t.size();j++){
			int zs=LCA(u,v);
			f[u].push_back(mp(t[j],i)); 
			f[v].push_back(mp(t[j],i));
			g[zs].push_back(mp(t[j],i));
			g[dp[zs][0]].push_back(mp(t[j],i));
		}
	}
	dfs(1,0);
	for(int i=1;i<=q;i++){
		writeln(ans[i]);
	}
}