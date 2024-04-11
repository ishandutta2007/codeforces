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
const int N=1005,M=200005;
int n,m,q,x[M],y[M],ans[M];
int dp[N][N];
struct data{
	int l,r,s,t,id;
}a[M];
void insert(int id){
	if(x[id]==y[id])return;
	for(int i=1;i<=n;i++){
		if(i==x[id])dp[y[id]][i]=id; else if(i==y[id])dp[x[id]][i]=id;
		else if(dp[x[id]][i]<dp[y[id]][i])dp[y[id]][i]=dp[x[id]][i]; else dp[x[id]][i]=dp[y[id]][i];
	}
}
inline bool cmp(data a,data b){
	return a.l>b.l;
}
int main(){
	n=read(); m=read(); q=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)dp[i][j]=m+1;
	for(int i=1;i<=m;i++){
		x[i]=read(); y[i]=read();
	}
	for(int i=1;i<=q;i++){
		a[i].l=read(); a[i].r=read(); a[i].s=read(); a[i].t=read(); a[i].id=i;
	}
	sort(&a[1],&a[q+1],cmp); int j=m;
	for(int i=1;i<=q;i++){
		while(j>=a[i].l&&j){
			insert(j--);
		}
		ans[a[i].id]=dp[a[i].s][a[i].t]<=a[i].r;
	}
	for(int i=1;i<=q;i++)puts(ans[i]?"Yes":"No");
}