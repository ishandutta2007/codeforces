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
const int N=80;
int n,q[4][N],num[4];
char ch[N];
int dp[N][N][N][2];
inline int calc(int i,int j,int k,int pos){
	return max(0,lower_bound(&q[1][1],&q[1][num[1]+1],pos)-&q[1][0]-i-1)+max(0,lower_bound(&q[2][1],&q[2][num[2]+1],pos)-&q[2][0]-j-1)+
	max(0,lower_bound(&q[3][1],&q[3][num[3]+1],pos)-&q[3][0]-k-1);
}
int main(){
	n=read();
	scanf("%s",ch+1);
	for(int i=1;i<=n;i++){
		if(ch[i]=='V')q[1][++num[1]]=i;
		else if(ch[i]=='K')q[2][++num[2]]=i;
		else q[3][++num[3]]=i;
	}
	//cout<<calc(0,1,0,4)<<endl;
	for(int i=0;i<=num[1];i++)for(int j=0;j<=num[2];j++)for(int k=0;k<=num[3];k++)dp[i][j][k][0]=dp[i][j][k][1]=10000;
	dp[0][0][0][0]=0;
	for(int i=0;i<=num[1];i++){
		for(int j=0;j<=num[2];j++){
			for(int k=0;k<=num[3];k++){
				for(int l=0;l<2;l++){
					//cout<<dp[i][j][k]<<" "<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<dp[i][j][k][l]<<endl;
					dp[i+1][j][k][1]=min(dp[i+1][j][k][1],dp[i][j][k][l]+calc(i,j,k,q[1][i+1]));
					if(!l)dp[i][j+1][k][0]=min(dp[i][j+1][k][0],dp[i][j][k][l]+calc(i,j,k,q[2][j+1]));
					dp[i][j][k+1][0]=min(dp[i][j][k+1][0],dp[i][j][k][l]+calc(i,j,k,q[3][k+1]));
				}
			}
		}
	}
	cout<<min(dp[num[1]][num[2]][num[3]][0],dp[num[1]][num[2]][num[3]][1])<<endl;
}