#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
	int x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int N=1000005,K=20,mod=1000000007;
int dp[N][K],f[N],sum[N][K];
int main(){
	for(int i=0;i<K;i++)dp[0][i]=2; dp[0][0]=1;
	sum[0][0]=1; for(int i=1;i<K;i++)sum[0][i]=sum[0][i-1]+dp[0][i];
	for(int i=1;i<N;i++){
		for(int j=0;j<K;j++){
			dp[i][j]=sum[i-1][j];
			sum[i][j]=((j?sum[i][j-1]:0)+dp[i][j])%mod;
		}
	}
	for(int i=N-1;i>1;i--){
		for(int j=i;j<N;j+=i){
			f[j]=i;
		}
	}
	int q=read();
	while(q--){
		int r=read(),n=read(),ans=1;
		while(n!=1){
			int tt=f[n],sum=0;
			while(n%tt==0){
				n/=tt; sum++;
			}
			ans=(long long)ans*dp[r][sum]%mod;
		}
		writeln(ans);
	}
}