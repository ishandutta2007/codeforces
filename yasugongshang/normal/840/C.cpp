#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline long long read()//??????yy 
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
inline void write(long long a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(long long a){
    write(a); puts("");
}
const long long N=305;
long long ycl[N],n,cc[N][N],mod=1000000007,dp[N][N],sum,c[N],b[N],a[N],tong[N],r;
#include<cmath>
int main(){
    n=read(); ycl[0]=cc[0][0]=1; 
    for(long long i=1;i<=n;i++){
    	cc[i][0]=1; ycl[i]=(long long)ycl[i-1]*i%mod;
    	for(long long j=1;j<=i;j++)cc[i][j]=(cc[i-1][j-1]+cc[i-1][j])%mod;
	}
    for(long long i=1;i<=n;i++)a[i]=read();
    for(long long i=1;i<=n;i++)tong[i]=i;
    for(long long i=1;i<=n;i++){
    	for(long long j=i+1;j<=n;j++){
    		long long t=a[i]*a[j];
    		long long zs=sqrt(t);
    		if(zs*zs==t)tong[j]=tong[i];
		}
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++)if(tong[j]==i)b[i]++;
	}
	long long ans=1;
	for(long long i=1;i<=n;i++)if(b[i])ans=(long long)ans*ycl[c[++r]=b[i]]%mod;
	dp[1][c[1]-1]=1; sum=c[1];
	for(long long i=2;i<=r;i++){
		for(long long j=0;j<sum;j++){
			for(long long k=1;k<=c[i];k++){
				for(long long l=0;l<=min(k,j);l++){
					dp[i][j-l+c[i]-k]=(dp[i][j-l+c[i]-k]+(long long)dp[i-1][j]*cc[j][l]%mod*cc[sum+1-j][k-l]%mod*cc[c[i]-1][k-1])%mod;
				}
			}
		}
		sum+=c[i];
	}
	writeln((long long)dp[r][0]*ans%mod);
}