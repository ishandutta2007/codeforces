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
inline long long	read()// 
{
	long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
} 
inline long long digit(long long x){
	long long sum=0;
	while(x){
		sum+=x%10; x/=10;
	}
	return sum;
}
long long n,s,ans;
int main(){
	n=read(); s=read();
	for(long long i=s+1;i<=s+18*9&&i<=n;i++){
		if(i-digit(i)>=s)ans++;
	}
	if(n>s+18*9)ans+=n-s-18*9;
	writeln(ans);
}