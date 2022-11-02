#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<ctime>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define uint unsigned
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
const int N=105,mod=1000000007;
int n,x,dp[N][N][N];
char ch[N];
ll len[N];
int main(){
	n=read(); x=read();
	scanf("%s",ch+1);
	for(int i=1;i<=n;i++)if(ch[i]=='0')dp[0][i][i]=1; else dp[1][i][i]=1;
	len[0]=len[1]=2;
	for(int i=2;i<=x;i++){
		len[i]=len[i-1]*len[i-2]%mod;
		for(int j=1;j<=n;j++){
			for(int k=j;k<=n;k++){
				for(int l=j;l<k;l++){
					//if(i==4&&j==1&&k==2)cout<<l<<" "<<dp[i-2][j][l]*dp[i-1][l+1][k]<<endl;
					dp[i][j][k]=(dp[i][j][k]+(ll)dp[i-1][j][l]*dp[i-2][l+1][k])%mod;
				}
				dp[i][j][k]=(dp[i][j][k]+dp[i-1][j][k]*(k!=n?1:len[i-2]))%mod;
				dp[i][j][k]=(dp[i][j][k]+dp[i-2][j][k]*(j!=1?1:len[i-1]))%mod;
				//cout<<dp[i][j][k]<<" "<<i<<" "<<j<<" "<<k<<endl;
			}
		}
	}
	cout<<dp[x][1][n]<<endl;
}
/*
0 1 01 101 01101
8
1 3
1
*/