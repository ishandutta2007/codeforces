#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=55;
int n,sz[M];
double dp[M][M],g[M],c[M][M];
vector<int> v[M];
void trans(double *f,int m){
	ms(g,0);
	F(i,0,m+1){
		F(j,0,m){
			if (j+1<=i)
				g[i]=g[i]+f[i-1]/(m+1);
			
			else
				g[i]=g[i]+f[j]/2/(m+1);
			
		}
	}
	F(i,0,m+1) f[i]=g[i];
}
void dfs(int x,int fa){
	dp[x][0]=1; sz[x]=0;
	for (int y:v[x]){
		if (y==fa) continue;
		dfs(y,x);
		trans(dp[y],sz[y]);
		ms(g,0);
		DF(i,sz[x],0){
			DF(j,sz[y]+1,0){
				g[i+j]=(g[i+j]+dp[x][i]*dp[y][j]*
				c[sz[x]][i]*c[sz[y]+1][j]/c[sz[x]+sz[y]+1][i+j]);
			}
		}
		sz[x]+=sz[y]+1;
		F(i,0,sz[x]) dp[x][i]=g[i];
	}
//	cout<<x<<' ';
//	F(i,0,sz[x]){
//		cout<<dp[x][i]<<" ";
//	}
//	cout<<"\n";
//	cout<<x<<" "<<s[x]<<"\n";
}
int main(){
	n=read();  
	F(i,1,n-1){
		int x=read(),y=read();
		v[x].pb(y); v[y].pb(x);
	}
	F(i,0,n){
		c[i][0]=1;
		F(j,1,i) c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
	F(i,1,n){
		ms(dp,0);
		dfs(i,0);
		cout<<fixed<<setprecision(10)<<dp[i][0]<<"\n";
	}
    return 0;
}