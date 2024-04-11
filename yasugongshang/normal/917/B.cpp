#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<complex>
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
const int N=105;
int n,m;
int dp[N][N][26];
vector<pair<int,int> > v[N];
inline int dfs(int x,int y,int last){
	if(dp[x][y][last]!=-1)return dp[x][y][last];
	for(int i=0;i<v[x].size();i++)if(v[x][i].second>=last&&!dfs(y,v[x][i].first,v[x][i].second))return dp[x][y][last]=1;
	return dp[x][y][last]=0;
}
int main(){
	n=read(); m=read(); memset(dp,-1,sizeof(dp));
	for(int i=1;i<=m;i++){
		int s=read(),t=read(),di=getchar()-'a';
		v[s].push_back(mp(t,di));
	}
	//cout<<dfs(4,4,0)<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			putchar(dfs(i,j,0)?'A':'B');
		}
		puts("");
	}
}