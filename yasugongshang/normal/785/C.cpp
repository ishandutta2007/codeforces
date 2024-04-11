#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
using namespace std;
inline void write(unsigned long long a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(unsigned long long a){
	write(a); puts("");
}
inline unsigned long long	read()// 
{
	unsigned long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
unsigned long long n,m,zs;
int main(){
	n=read(); m=read();
	if(m>=n){
		writeln(n); return 0;
	}else{
		n-=m;
		zs=sqrt(n*2)-1;
		while(zs*(zs+1)/2<n)zs++;
		writeln(zs+m);
	}
}