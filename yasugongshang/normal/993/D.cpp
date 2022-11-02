#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
#define PI pair<int,int>
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
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
inline int rnd(int x){
	return (rand()<<16|rand())%x;
}
const int N=55;
const long double eps=1e-7;
int n,a[N],b[N],q[N];
long double dp[N][N][N],c[N];
inline bool cmp(int x,int y){
	return a[x]>a[y];
}
bool check(long double x){
	for(int i=1;i<=n;i++)c[i]=a[i]-b[i]*x;
	for(int i=1;i<=n;i++)q[i]=i;
	sort(&q[1],&q[n+1],cmp);
	a[0]=1e9;
	for(int i=0;i<=n;i++)for(int j=0;j<=i;j++)for(int k=0;j+k<=i;k++)dp[i][j][k]=1e18;
	dp[0][0][0]=0;
	for(int i=0;i<n;i++){
		if(a[q[i]]!=a[q[i+1]]){
			for(int j=0;j<=i;j++)for(int k=1;k+j<=i;k++)dp[i][j+k][0]=min(dp[i][j+k][0],dp[i][j][k]);
		}
		for(int j=0;j<=i;j++){
			for(int k=0;j+k<=i;k++)if(dp[i][j][k]<1e18){
				//cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<" "<<a[q[i+1]]<<" "<<a[q[i]]<<endl;
				dp[i+1][j][k+1]=min(dp[i+1][j][k+1],dp[i][j][k]+c[q[i+1]]);
				if(j)dp[i+1][j-1][k]=min(dp[i+1][j-1][k],dp[i][j][k]);
			}
		}
	}
	long double ans=1e18;
	for(int i=0;i<=n;i++)for(int j=0;i+j<=n;j++)ans=min(ans,dp[n][i][j]);
	return ans<=0;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	//check(8.751); return 0;
	long double l=0,r=1e9;
	while(l+eps<r){
		long double mid=(l+r)/2;
		if(check(mid))r=mid; else l=mid;
	}
	long long t=ceil(l*1000);
	cout<<t<<endl;
}