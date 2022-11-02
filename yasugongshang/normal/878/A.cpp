#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long  LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define F first
#define S second
inline int read(){
	int x = 0; char ch = getchar(); bool positive = 1;
	for (; !isdigit(ch); ch = getchar())	if (ch == '-')	positive = 0;
	for (; isdigit(ch); ch = getchar())	x = x * 10 + ch - '0';
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
#include<string>
const int N=500005;
int n,dp[N][11],an,xo,oor,s1;
char ch[10];
int main(){
	n=read();
	for(int i=0;i<10;i++)dp[0][i]=2;
	for(int i=1;i<=n;i++){
		scanf("%s%d",&ch,&s1);
		if(ch[0]=='|'){
			for(int j=0;j<10;j++)if(s1&(1<<j))dp[i][j]=1; else dp[i][j]=dp[i-1][j];
		}else if(ch[0]=='&'){
			for(int j=0;j<10;j++)if((s1&(1<<j))==0)dp[i][j]=0; else dp[i][j]=dp[i-1][j];
		}else{
			for(int j=0;j<10;j++)if(s1&(1<<j))dp[i][j]=dp[i-1][j]^1; else dp[i][j]=dp[i-1][j];
		}
	}
	for(int i=0;i<10;i++)if(!dp[n][i])an|=1<<i; else if(dp[n][i]==1)oor|=1<<i; else if(dp[n][i]==3)xo|=1<<i;
	cout<<3<<endl<<"& "<<(an^1023)<<endl<<"| "<<oor<<endl<<"^ "<<xo<<endl;
}