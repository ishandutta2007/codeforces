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
inline long long gcd(long long a,long long b){
	return b?gcd(b,a%b):a;
}
long long n,a,b,c,d,zs;
double eps=1e-8;
int main(){
	n=read(); 
	for(long long i=1;i<=n;i++){
		a=read(); b=read();
		long long t=gcd(a,b);
		c=a/t; d=b/t;
		if(t%(c*d)==0){
			long long tt=t/(c*d);
			long long zs=(pow((double)tt,(double)1/3)); //cout<<tt<<" "<<zs<<endl;
			if(zs*zs*zs==tt||(zs+1)*(zs+1)*(zs+1)==tt)puts("YES"); else puts("NO");
		}else puts("NO");
	}
}