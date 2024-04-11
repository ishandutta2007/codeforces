#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<ctime>
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
inline bool fa(int a,int b){
	while(b){
		if(a==b)return 1;
		b>>=1;
	}
	return 0;
}
const int mod=1000000007;
map<int,int> peo,M;
int n,m,e[10][2],ans,b[10],a[10],vis[10];
inline int pe(int x){
	if(peo.find(x)!=peo.end())return peo[x];
	else{
		if(M.count(x))return 0;
		int t=x,sum=1,zs=x,ans=0;
		while(t<=n){
			ans+=sum;
			t=t<<1|1;
			sum<<=1;
			zs<<=1;
		}
		if(zs>n)return ans; else return ans+n-zs+1;
	}
}
void update(int x){
	if(!x)return;
	peo[x]=M.count(x)?0:pe(x<<1)+pe(x<<1|1)+1;
	update(x>>1);
}
bool bj(int a,int b){
	int t1=a,t2=b;
	while(!fa(a,b)){
		if(M[a])return 1; else M[a]++; a>>=1;
	}
	while(a!=b){
		if(M[b])return 1; else M[b]++; b>>=1;
	}
	if(M[a])return 1; else M[a]++; 
	update(t1); update(t2);
	return 0;
}
int cal(int x){
	int last=0;
	for(int i=x;i;i>>=1){
		if(M.count(i))return pe(last);
		last=i;
	}
	return pe(1);
}
void calc(int x){
	M.clear(); peo.clear(); peo[0]=0;
	for(int i=1;i<x;i++){
		if(bj(e[a[i]][b[i]^1],e[a[i+1]][b[i+1]]))return;
	}
	int s=e[a[1]][b[1]],t=e[a[x]][b[x]^1],i,last=0;
	if(M.count(s)||M.count(t))return;
	for(i=s;!fa(i,t);i>>=1){
		if(M.count(i))return;
		int zs=pe(i)-pe(last); zs=max(zs,0);
		M[i]++; update(i); 
		ans=(ans+(ll)zs*cal(t))%mod;
		last=i;
	}
	if(M.count(i))return; 
	for(int j=i,pos;j;j=pos){
		if(M.count(j))break;
		pos=j==t?0:(fa(j<<1,t)?j*2:j*2+1); 
		int zs=pe(j)-pe(pos); M[j]++; update(j); zs=max(zs,0);
		ans=(ans+(ll)cal(t)*zs)%mod;
		if(--M[j]==0){M.erase(j); update(j);}
	}
	M[i]++; update(i);
	last=i;
	for(i>>=1;i;i>>=1){
		if(M.count(i))return;
		int zs=pe(i)-pe(last); zs=max(zs,0);
		M[i]++; update(i);
		ans=(ans+(ll)zs*cal(t))%mod;
		last=i;
	}
}
void dfs(int p){
	if(p>1){
		calc(p-1); 
	}
	if(p>m)return;
	for(int i=1;i<=m;i++)if(!vis[i]){
		a[p]=i; vis[i]=1; b[p]=1; dfs(p+1); b[p]=0; dfs(p+1); vis[i]=0;
	}
}
int main(){
	n=read();m=read(); peo[0]=0; 
	for(int i=1;i<=m;i++){
		e[i][0]=read(); e[i][1]=read();
	}
	ans=(ll)n*n%mod;
	dfs(1);
	cout<<ans<<endl;
}