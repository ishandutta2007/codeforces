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
const int N=200005;
int n,f[N],g[N],a[N];
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n+1;i++)f[i]=g[i]=2e9;
	for(int i=1;i<=n;i++){
		int t1=upper_bound(&f[1],&f[n+1],a[i]-i)-f,t2=upper_bound(&g[1],&g[n+1],a[i+1]-i)-g;
		g[t1]=min(g[t1],f[t1]=min(f[t1],a[i]-i)); g[t2]=min(g[t2],a[i+1]-i);
	}
	for(int i=1;i<=n+1;i++)if(g[i]==2e9){
		//writeln(i-1);
		write(max(0,n-1-(i-1))); return 0;
	}
}