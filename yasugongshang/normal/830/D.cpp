#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld long double
#define PI pair<int,int>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
	ll x = 0; char ch = gc(); bool positive = 1;
	for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
	return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
	}
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(ll a){write(a); puts("");}
inline void wri(ll a){write(a); putchar(' ');}
const int N=405,mod=1000000007;
int n;
ll dp[N][N];
int main(){
	n=read();
	dp[1][1]=dp[1][0]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k+j<=n;k++){
				ll t=dp[i][j]*dp[i][k]%mod;
				dp[i+1][j+k]=(dp[i+1][j+k]+t*(2*(j+k)+1))%mod;
				dp[i+1][j+k+1]=(dp[i+1][j+k+1]+t)%mod;
				if(j+k)dp[i+1][j+k-1]=(dp[i+1][j+k-1]+t*(j+k)*(j+k-1))%mod;
			}
		}
	}
	cout<<dp[n][1]<<endl;
}