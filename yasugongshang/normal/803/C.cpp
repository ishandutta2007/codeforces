#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long n,k,flag,quan;
inline long long read()// 
{
	long long a=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	a=a*10+ch-'0';
	ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		a=a*10+ch-'0';
		ch=getchar();
	}
	return a;
}
inline void write(long long a)
{
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(long long a){
	write(a); puts("");
}
inline void check(long long x){
	if(x>=(k+1)*k/2){
		for(long long i=1;i<k;i++){write(i*quan); putchar(' ');}
		x-=k*(k-1)/2;
		writeln(x*quan); flag=1;
	}
}
int main(){
	n=read(); k=read(); if(k>200000){
		puts("-1"); return 0;
	}long long meiju=sqrt(n);
	for(long long i=1;i<=sqrt(n);i++){
		if(n%i==0){
			quan=n/i; check(i); if(flag)return 0;
		}
	}
	for(long long i=sqrt(n);i;i--){
		if(n%i==0){
			quan=i; check(n/i); if(flag)return 0;
		}
	}
	puts("-1");
}