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
inline void write(int a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
inline int read()// 
{
	long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
int c,v0,v1,a,zs,ans,l;
int main(){
	c=read(); v0=read();v1=read(); a=read(); l=read();zs=min(v0,v1); 
	for(int i=zs;i<c;i+=zs-l){ zs=min(zs+a,v1); ans++;}
	writeln(ans+1);
}