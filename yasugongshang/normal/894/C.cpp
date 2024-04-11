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
inline int read(){
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
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
int n,g,a[10005];
int main(){
	n=read();
	for(int i=1;i<=n;i++)g=__gcd(g,(a[i]=read())); if(g!=a[1]){
		puts("-1"); return 0;
	}
	writeln(n+n);
	for(int i=1;i<=n;i++){
		write(a[i]); putchar(' '); write(g); putchar(' ');
	}
}