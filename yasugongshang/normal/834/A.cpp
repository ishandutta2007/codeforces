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
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
		return positive ? x : -x;
}
char s1,s2;
int n,tong[10005],s3,s4,zs;
int main(){
	s1=getchar(); getchar(); s2=getchar();
	n=read();
	tong['v']=1; tong['^']=3; tong['<']=2; tong['>']=4;
	s3=tong[s1]; s4=tong[s2];
	if((s3+n)%4==s4%4)zs+=1;
	if((s4+n)%4==s3%4)zs+=2;
	if(zs==3||zs==0)puts("undefined"); else if(zs==1)puts("cw"); else puts("ccw");
}