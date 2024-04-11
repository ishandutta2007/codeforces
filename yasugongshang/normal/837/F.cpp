
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
long long k,n,a[200005],zs,z2[1005],z1[1005];
inline long long c(long long a,long long b){
	long long zs=1;
	for(int i=1;i<=b;i++){z1[i]=i; z2[i]=a-i+1;}
	for(int i=1;i<=b;i++){
		for(int j=1;j<=b&&z1[i]>1;j++){
			long long t=__gcd(z1[i],z2[j]);
			z1[i]/=t; z2[j]/=t;
		}
	}
	for(int i=1;i<=b;i++){
		//cout<<z2[i]<<endl;
		if((double)zs*z2[i]>4e18)return 4e18; zs=zs*z2[i];
	}
	//cout<<zs<<endl;
	return zs; 
}
inline bool check(long long x){
	long long sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]>k/c(n-i+x-1,n-i)+1)return 1;
		//cout<<c(n-i+x-1,n-i)<<endl;
		sum+=c(n-i+x-1,n-i)*a[i];
		if(sum>=k)return 1;
	}
	//cout<<sum<<endl;
	return 0;
}
int main(){
	n=read(); k=read();
	for(long long i=1;i<=n;i++){a[i]=read(); if(a[i]>=k){write(0); return 0;}if(a[i]&&!zs)zs=i;}
	if(n-zs+1>=100){
		for(long long j=1;j<=10000;j++){
			for(long long i=1;i<=n;i++){ if(a[i-1]>=k-a[i]){
				writeln(j); return 0;
			}a[i]=a[i-1]+a[i];}
		}
	}else{
		for(long long i=1;i<=n-zs+1;i++)a[i]=a[zs+i-1];
		n=n-zs+1; //cout<<check(1333)<<endl; return 0;
		//for(long long i=1;i<=n;i++)cout<<a[i]<<endl;
		long long l=1,r=k;
		while(l<r){
			long long mid=(l+r)>>1; //cout<<mid<<" "<<check(mid)<<endl;
			if(check(mid))r=mid; else l=mid+1;
		}
		writeln(l);
	}
	
}