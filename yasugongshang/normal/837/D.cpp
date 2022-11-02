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
const long long N=205;
long long ans,n,m,a1[N],a2[N],dp[N][N*30],sum[N],summ;
int main(){
	n=read(); m=read();
	for(long long i=1;i<=n;i++){
		long long s=read();
		while(s%2==0){a1[i]++; s/=2;}
		while(s%5==0){a2[i]++; s/=5;} summ+=a2[i];
	}
	for(long long j=0;j<=m;j++)for(long long l=0;l<=summ;l++)dp[j][l]=-1000000; dp[0][0]=0;
	for(long long i=1;i<=n;i++){sum[i]=sum[i-1]+a2[i];
		for(long long j=min(i,m);j;j--){
			for(long long l=sum[i];l>=a2[i];l--){
				dp[j][l]=max(dp[j][l],dp[j-1][l-a2[i]]+a1[i]);
			}
		}
	}
	for(long long j=0;j<=sum[n];j++)ans=max(ans,min(dp[m][j],j));
	writeln(ans);
}