#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
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
const int N=4005,K=80,mod=998244353;
const ll mod2=(ll)mod*mod;
int n1,n2,k,f[2][N][K],g[2][N][K],ans[2][K],c[K][K],tot;
vector<int> v[N];
void cal(int *g,int *f){
	g[0]=1;
	for(int i=1;i<=k;i++){
		ll jb=0; 
		for(int j=1;j<=i;j++){jb+=(ll)f[j]*g[i-j]; if(jb>=mod2)jb-=mod2;}
		g[i]=jb%mod;
		//cout<<g[i]<<" "<<f[1]<<endl;
	}
}
void dfs1(int p,int fa,int id){
	f[id][p][0]=1;
	for(unsigned i=0;i<v[p].size();i++)if(v[p][i]!=fa){
		dfs1(v[p][i],p,id);
		for(int j=1;j<=k;j++)f[id][p][j]=(f[id][p][j]+g[id][v[p][i]][j-1])%mod;
	}
	cal(g[id][p],f[id][p]);
}
void dfs2(int p,int fa,int id){
	cal(g[id][p],f[id][p]);
	//for(int i=1;i<=k;i++)cout<<f[id][p][i]<<" "; puts("");
	//for(int i=1;i<=k;i++)cout<<g[id][p][i]<<" "; puts("");
	//cout<<g[id][p][0]<<" "<<g[id][p][1]<<" "<<g[id][p][2]<<" "<<g[id][p][3]<<endl;
	for(int i=0;i<=k;i++)ans[id][i]=(ans[id][i]+g[id][p][i])%mod;
	for(unsigned i=0;i<v[p].size();i++)if(v[p][i]!=fa){
		for(int j=1;j<=k;j++)f[id][p][j]=(f[id][p][j]-g[id][v[p][i]][j-1])%mod;
		cal(g[id][p],f[id][p]);
		for(int j=1;j<=k;j++)f[id][v[p][i]][j]=(f[id][v[p][i]][j]+g[id][p][j-1])%mod;
		dfs2(v[p][i],p,id);
		for(int j=1;j<=k;j++)f[id][v[p][i]][j]=(f[id][v[p][i]][j]-g[id][p][j-1])%mod;
		cal(g[id][v[p][i]],f[id][v[p][i]]);
		for(int j=1;j<=k;j++)f[id][p][j]=(f[id][p][j]+g[id][v[p][i]][j-1])%mod;
	}
	//cal(g[id][p],f[id][p]);
}
signed main(){
	n1=read(); n2=read(); k=read();
	if(k%2){puts("0"); return 0;}else k/=2;
	for(int i=1;i<n1;i++){
		int s=read(),t=read();
		v[s].push_back(t); v[t].push_back(s);
	}
	dfs1(1,0,0);
	dfs2(1,0,0);
	for(int i=1;i<=n2;i++)v[i].clear();
	for(int i=1;i<n2;i++){
		int s=read(),t=read();
		v[s].push_back(t); v[t].push_back(s);
	}
	dfs1(1,0,1);
	dfs2(1,0,1);
	for(int i=0;i<=k*2;i++){
		c[i][0]=1; for(int j=1;j<=i;j++)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	for(int i=0;i<=k;i++)tot=(tot+(ll)c[k*2][i*2]*ans[0][i]%mod*ans[1][k-i])%mod;
	cout<<(tot+mod)%mod<<endl;
}