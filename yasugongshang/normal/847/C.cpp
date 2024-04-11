#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
inline long long read(){
	long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(long long a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(long long a){
    write(a); puts("");
}
long long n,k;
inline void solve(long long n,long long k){
	if(n==0)return ;
	if(k>=n-1){
		solve(n-1,k-n+1); putchar('('); putchar(')');
	}else{
		putchar('('); solve(n-1,k); putchar(')');
	}
}
int main(){
    n=read(); k=read();
    if(n*(n-1)/2<k){
    	puts("Impossible"); return 0;
	}
	
    solve(n,n*(n-1)/2-k);
}