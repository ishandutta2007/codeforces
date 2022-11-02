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
long long r,que[10005],x,y;
inline long long gcd(long long a,long long b){
	return b?gcd(b,a%b):a;
}
inline long long f(long long x,long long y){
	if(y==0)return 0; 
	long long t=gcd(x,y),tt=t; //cout<<x<<" "<<y<<" "<<t<<endl; 
	if(t>1)for(long long i=1;i<=r;i++){
		if(tt==1)break;
		if(que[i]>0&&tt%que[i]==0){ tt/=que[i];que[i]=0;}
	}
	if(t>1)return f(x/t,y/t);
	long long mmax=0;
	for(long long i=1;i<=r;i++)if(que[i]){
		mmax=max(mmax,y/que[i]*que[i]); //if(y/que[i]*que[i]==mmax)cout<<que[i]<<endl;
	}//cout<<x<<" "<<y<<" "<<mmax<<endl;
	return y-mmax+f(x,mmax);
}
int main(){
	x=read(); y=read(); long long xx=x;
	long long meiju=sqrt(xx);
	for(long long i=2;i<=meiju;i++){
		while(xx%i==0){
			que[++r]=i; xx/=i;
		}
	}
	if(xx>1)que[++r]=xx;
	writeln(f(x,y));
}
//421412444 41241424