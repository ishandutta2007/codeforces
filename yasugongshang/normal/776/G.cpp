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
#define int long long
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
#define N 16
int dp[N][N][1<<N],x,y,q[N],len;
inline int dfs(int len,int mx,int zt,int flag){
	if(!len)return (zt>>mx)&1;
	if(!flag&&dp[len][mx][zt]!=-1)return dp[len][mx][zt];
	int meiju=flag?q[len]:15,ans=0;
	for(int i=0;i<=meiju;i++){
		ans+=dfs(len-1,max(mx,i),len<=4?zt|(i<<(len*4-4)):zt,flag&&i==meiju);
	}
	if(!flag)dp[len][mx][zt]=ans;
	return ans;
}
inline int solve(int x){
	if(x<0)return 0;
	len=0;
	while(x){
		q[++len]=x&15; x>>=4;
	}
	return dfs(len,0,0,1);
}
signed main(){
	memset(dp,-1,sizeof(dp));
	int q=read();
	while(q--){
		cin>>hex>>x>>hex>>y;
		cout<<solve(y)-solve(x-1)<<endl;
	}
}