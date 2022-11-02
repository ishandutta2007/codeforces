#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
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
const int N=505;
int n,k;
bitset<N> dp[N];
int main(){
	n=read(); k=read();
	dp[0][0]=1;
	for(int i=0;i<n;i++){
		int t=read();
		for(int j=k-t;j>=0;j--){
			if(j+t<=k)dp[j+t]|=(dp[j]<<t)|dp[j];
		}
	}
	writeln(dp[k].count());
	for(int i=0;i<=k;i++)if(dp[k][i])cout<<i<<" ";
}