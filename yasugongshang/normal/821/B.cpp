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
long long ans,m,b,n,sum[5][10005];
int main(){
	m=read(); b=read();
	for(long long i=0;i<=b;i++){long long meiju=(b-i)*m;
		ans=max(((meiju+1)*meiju/2+(i*meiju+i+(1+meiju)*meiju/2))*(i+1)/2,ans);
	}
	writeln(ans);
}