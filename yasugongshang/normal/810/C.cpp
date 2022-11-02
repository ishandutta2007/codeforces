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
const int N=300005;
int n,fac[N],a[N],mod=1000000007,ans;
int main(){
	n=read(); fac[0]=1;
	for(int i=1;i<=n;i++){a[i]=read(); fac[i]=fac[i-1]*2%mod;}
	sort(&a[1],&a[n+1]);
	for(int i=1;i<=n;i++){
		ans=(ans+(long long)(fac[i-1]-fac[n-i])*a[i])%mod;
	}
	writeln(ans);
}