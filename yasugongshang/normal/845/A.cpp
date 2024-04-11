#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
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
    write(a); puts("");
}
int n,a[1000005];
int main(){
    n=read(); n*=2;
    for(int i=1;i<=n;i++)a[i]=read();
    sort(&a[1],&a[n+1]);
    if(a[n/2]==a[n/2+1]){
    	puts("NO");
	}else puts("YES");
}