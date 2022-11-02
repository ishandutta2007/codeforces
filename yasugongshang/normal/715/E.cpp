#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
inline ull rnd(){
	return ((ull)rand()<<30^rand())<<4|rand()%4;
}
const int N=2005,mod=998244353;
int tong[N],to[N],p[N],q[N],v[N],c[N][N];
ll f[N],g[N];
int cnt,jb,xs,dd,jj;
int main(){
	//freopen("wys.in","r",stdin); freopen("wys.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++)tong[p[i]=read()]=i;
	for(int i=1;i<=n;i++)to[q[i]=read()]=1;
	for(int i=0;i<=n;i++)for(int j=c[i][0]=1;j<=i;j++)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	f[0]=1;
	for(int i=1;i<=n;i++)if(!to[p[i]]||!p[i]){
		int j=i,fff=0; v[i]=1;
		while(tong[q[j]]&&q[j]){j=tong[q[j]]; v[j]=1;}
		if(!p[i]&&!q[j]){
			memset(g,0,sizeof(g));
			cnt++; jb++; xs++; for(int j=1;j<=i;j++)g[j]=(f[j-1]+f[j]*(jb-1))%mod;
		}else if(!p[i]&&q[j]){
			memset(g,0,sizeof(g));
			jb++; for(int j=1;j<=jb;j++)g[j]=(f[j-1]+f[j]*(jb-1))%mod;
		}else if(!q[j]){
			jj++; continue;
		}else {dd++; continue;}
		swap(f,g);
	}
	for(int i=1;i<=jj;i++){
		memset(g,0,sizeof(g));
		jb++; for(int j=1;j<=jb;j++)g[j]=(f[j-1]+f[j]*xs)%mod; xs++;
		swap(f,g);
	}
	for(int i=1;i<=n;i++)if(!v[i]){
		v[i]=1; for(int j=tong[q[i]];j!=i;j=tong[q[j]]){v[j]=1;}
		for(int j=n;j;j--)f[j]=f[j-1]; f[0]=0;
	}
	ll sum=1; 
	for(int i=1;i<=cnt;i++)sum=sum*i%mod; //sum=sum*c[cnt][dd]%mod; 
	for(int i=1;i<=n;i++)f[i]=f[i]*sum%mod;
	for(int i=n;i;i--)wri(f[i]);
}
/*
3
0 0 1
2 0 0

*/