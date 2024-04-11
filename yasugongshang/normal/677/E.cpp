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
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
	}
	write(a); puts("");
}
const int mod=1000000007;
const int N=1005,xx[8]={0,0,1,-1,1,1,-1,-1},yy[8]={1,-1,0,0,1,-1,1,-1};
int n,dp[N][N][8],a[N][N],sum[N][N][8][2],tong[2];
pair<int,int> ans;
char ch[N];
inline void dfs(int x,int y,int id){
	if(dp[x][y][id]!=-1)return; 
	if(a[x][y]==0){
		dp[x][y][id]=0; return;
	}
	dfs(x-xx[id],y-yy[id],id);
	dp[x][y][id]=dp[x-xx[id]][y-yy[id]][id]+1;
	for(int i=0;i<2;i++)sum[x][y][id][i]=sum[x-xx[id]][y-yy[id]][id][i];
	if(a[x][y]>1)sum[x][y][id][a[x][y]-2]++;
}
const double s1=log(2),s2=log(3);
inline void geng(PI &x,PI xx){
	double t3=s1*x.first+s2*x.second,t4=s1*xx.first+s2*xx.second;
	if(t4>t3)x=xx;
}
int main(){
	n=read(); int sss=0;
	for(int i=1;i<=n;i++){
		scanf("%s",ch+1);
		for(int j=1;j<=n;j++)sss+=(a[i][j]=ch[j]-'0');
	}
	if(!sss){
		puts("0"); return 0;
	}
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=0;k<8;k++)dfs(i,j,k);
			//for(int k=0;k<8;k++)cout<<dp[i][j][k]<<" "<<i<<" "<<j<<" "<<k<<" "<<a[i][j]<<endl;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)if(a[i][j]){
			int ttt=1e9;
			for(int k=0;k<4;k++){dfs(i,j,k); ttt=min(ttt,dp[i][j][k]);} tong[0]=tong[1]=0;
			for(int k=0;k<4;k++){
				for(int l=0;l<2;l++){
					tong[l]+=sum[i-xx[k]][j-yy[k]][k][l]-sum[i-ttt*xx[k]][j-ttt*yy[k]][k][l];
				}
			}
			if(a[i][j]>=2)tong[a[i][j]-2]++;
			geng(ans,mp(tong[0],tong[1]));
			ttt=1e9;
			for(int k=4;k<8;k++){dfs(i,j,k); ttt=min(ttt,dp[i][j][k]);} tong[0]=tong[1]=0;
			for(int k=4;k<8;k++){
				for(int l=0;l<2;l++){
					tong[l]+=sum[i-xx[k]][j-yy[k]][k][l]-sum[i-ttt*xx[k]][j-ttt*yy[k]][k][l];
				}
			}
			if(a[i][j]>=2)tong[a[i][j]-2]++;
			geng(ans,mp(tong[0],tong[1]));
		}
	}
	int an=1;
	for(int i=0;i<ans.first;i++)an=an*2%mod;
	for(int i=0;i<ans.second;i++)an=(ll)an*3%mod;
	cout<<an<<endl;
}