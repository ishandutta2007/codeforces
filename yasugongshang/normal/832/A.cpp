#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<set>
#include<ctime>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
inline void write(long long a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(long long a){
	write(a); puts("");
}
inline long long read()// 
{
	long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
		return positive ? x : -x;
}
long long n,k;
int main(){
	n=read(); k=read();
	long long zs=n/k;
	if(zs&1)puts("YES"); else puts("NO");
}