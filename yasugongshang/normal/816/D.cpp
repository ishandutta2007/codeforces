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
const long long N=2000005;
long long n,b[N],a[N],ans,mod=1000000007,zs;
inline long long ksm(long long a,long long b){
	long long t=1,y=a;
	while (b){
		if (b&1) t=(long long)t*y%mod;
		y=(long long)y*y%mod;
		b>>=1;
	}
	return t;
}
int main(){
	n=read();
	long long m=n/2; a[1]=1;
	for(long long i=2;i<=m;i++)a[i*2-1]=a[i*2-3]*(m-1-i+1+1)%mod*ksm(i-1,mod-2)%mod;
	for(long long i=2;i<=m*2;i+=2)a[i]=((m&1)?1:-1)*a[i-1];
	//for(long long i=1;i<=n;i++)cout<<a[i]<<endl;
	for(long long i=1;i<=n;i++)b[i]=read();
	if(!(n&1)){
		for(long long i=1;i<=n;i++)ans=(ans+(long long)a[i]*b[i]%mod+mod)%mod; writeln((ans%mod+mod)%mod);
	}else{
		for(long long i=1;i<=n;i++)ans=(ans+(long long)((i&1)?a[i]-a[i-1]:a[i]+a[i-1])*b[i]%mod+mod)%mod; writeln((ans%mod+mod)%mod);
	}
}