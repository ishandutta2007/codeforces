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
int n,k,dp[N][N];
ll a[N],sum[N],dq;
int main(){
	n=read(); k=read();
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	for(int i=60;i>=0;i--){
		dq|=(ll)1<<i;
		dp[0][0]=1;
		for(int j=1;j<=n;j++){
			for(int l=1;l<=k;l++){
				dp[j][l]=0;
				for(int o=j-1;o>=0;o--)if(((sum[j]-sum[o])&dq)==dq)dp[j][l]|=dp[o][l-1];
			}
		}
		if(!dp[n][k])dq^=(ll)1<<i;
	}
	cout<<dq<<endl;
}