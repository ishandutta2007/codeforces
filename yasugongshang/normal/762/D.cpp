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
#define int long long
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
const int N=100005,oo=4e18;
int n,a[3][N],dp[3][N],sum[N],mx[3][N],zs[3];
signed main(){
	n=read();
	for(int i=0;i<3;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=read();
		}
	}
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[0][i]+a[1][i]+a[2][i];
	mx[2][0]=dp[1][0]=dp[2][0]=-oo;
	for(int i=1;i<=n;i++){
		dp[0][i]=dp[0][i-1]+a[0][i];
		dp[2][i]=dp[2][i-1]+a[2][i];
		dp[1][i]=dp[1][i-1]+a[1][i];
		zs[0]=max(dp[0][i],max(dp[1][i]+a[0][i],dp[2][i]+a[0][i]+a[1][i]));
		zs[1]=max(dp[1][i],max(dp[0][i]+a[1][i],dp[2][i]+a[1][i]));
		zs[2]=max(dp[2][i],max(dp[1][i]+a[2][i],dp[0][i]+a[1][i]+a[2][i]));
		for(int j=0;j<3;j++)dp[j][i]=zs[j];
		mx[0][i]=max(mx[0][i-1],(dp[0][i]=max(dp[0][i],sum[i]+mx[2][i-1]))-sum[i]);
		mx[2][i]=max(mx[2][i-1],(dp[2][i]=max(dp[2][i],sum[i]+mx[0][i-1]))-sum[i]);
		//cout<<dp[0][i]<<" "<<dp[1][i]<<" "<<dp[2][i]<<endl;
	}
	//cout<<dp[0][1]<<" "<<mx[0][1]<<endl;
	cout<<dp[2][n]<<endl;
}