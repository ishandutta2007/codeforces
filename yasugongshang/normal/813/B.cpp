#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
inline long long	read()// 
{
	long long x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(long long a){
	if(a>=10)write(a/10);
	putchar('0'+a%10);
}
inline void writeln(long long a){
	write(a); puts("");
}
#include<cmath>
long long n,l,r,sum,sum2,an[10000],a,b,ans;
int main(){
	a=read(); b=read(); l=read(); r=read();
	int meiju1=log(r)/log(a); sum=1;
	for(int x=0;x<=meiju1;x++){
		int meiju2=log(r-sum)/log(b); sum2=1;
		for(int y=0;y<=meiju2;y++){
			if(sum+sum2>=l)an[++n]=sum+sum2;
			sum2*=b;
		}
		sum*=a;
	}
	sort(&an[1],&an[n+1]);
	an[0]=l-1; an[n+1]=r+1;
	for(int i=1;i<=n+1;i++){
		ans=max(ans,an[i]-an[i-1]-1);
	}
	writeln(ans);
}