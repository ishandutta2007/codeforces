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
const int N=100005;
int f[N],dp[N],a[N],ans,n,m;
int main(){
	n=read(); m=read(); swap(n,m);
	for(int i=1;i<=m;i++){
		int l=read(),r=read();
		a[l]++; a[r+1]--;
	}
	for(int i=1;i<=n;i++)a[i]+=a[i-1];
	for(int i=1;i<=n;i++)f[i]=1e9;
	for(int i=1;i<=n;i++){
		int t=upper_bound(&f[1],&f[n+1],a[i])-f;
		f[t]=a[i]; dp[i]=t;
	}
	for(int i=1;i<=n;i++)f[i]=1e9;
	for(int i=n;i;i--){
		int t=upper_bound(&f[1],&f[n+1],a[i])-f;
		f[t]=a[i]; ans=max(ans,dp[i]+t-1);
	}
	cout<<ans<<endl;
}
/*
2
1 1 1 1
*/