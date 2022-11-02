#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
inline long long read(){
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
const long long N=2000005;
long long n,x,y,tong[N],ti[N],sum[N],an,ans;
int main(){
    n=read(); x=read(); y=read();
    for(long long i=1;i<=n;i++)tong[read()]++;
    for(long long i=1;i<N;i++){ti[i]=ti[i-1]+tong[i]; sum[i]=sum[i-1]+tong[i]*i;} ans=x*n;
    for(long long i=2;i<N;i++){
    	an=0;
    	for(long long j=i;j<N;j+=i){
    		an+=(ti[max(j-i,j-x/y-1)]-ti[j-i])*x+(-sum[j]+sum[max(j-i,j-x/y-1)]+(ti[j]-ti[max(j-i,j-x/y-1)])*j)*y;
    		if(an>ans)break;
		}
		ans=min(an,ans);
	}
	writeln(ans);
}