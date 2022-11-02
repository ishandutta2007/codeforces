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
inline long long read(){
	long long x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(long long a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(long long a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const long long N=2005,oo=4e18;
long long n,dist[N],e[N][N],mi=oo,vis[N];
int main(){
	n=read();
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){e[i][j]=e[j][i]=read(); mi=min(e[i][j],mi);}
	}
	for(long long i=1;i<=n;i++){
		dist[i]=oo;
		for(long long j=1;j<=n;j++)if(i^j){
			e[i][j]-=mi; dist[i]=min(dist[i],e[i][j]*2); 
		}
	}
	for(long long i=1;i<=n;i++){
		long long k=-1;
		for(long long j=1;j<=n;j++)if(!vis[j]&&(k==-1||dist[j]<dist[k]))k=j;
		vis[k]=1; 
		for(long long j=1;j<=n;j++)dist[j]=min(dist[k]+e[k][j],dist[j]);
    }
    for(long long i=1;i<=n;i++){
    	writeln(dist[i]+(n-1)*mi);
	}
}