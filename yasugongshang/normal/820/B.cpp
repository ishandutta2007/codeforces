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
int n,a,ans1;
int main(){
	n=read(); a=read();
    double zs=(double)(n-2)*180/n/(n-2),ans=100000000;
    for(int i=1;i<=n-2;i++)if(fabs(zs*i-a)<ans){ans=fabs(zs*i-a); ans1=i; }
    cout<<1<<" "<<2<<" "<<n-ans1+1<<endl;
}