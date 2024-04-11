#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
#define oo(x) fixed<<setprecision(x)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=1212;
double dp[M],p[M][M],t[M];
int n;
bool vis[M];
int main(){
	n=read();
	F(i,1,n){
		F(j,1,n){
			p[i][j]=1.0*read()/100.0;
		}
	}
	F(i,1,n) dp[i]=1,t[i]=1.0-p[i][n];
	dp[n]=0; vis[n]=1; 
	F(i,1,n-1){
		int x=0; double mi=1e9;
		F(j,1,n){
			if (!vis[j] && mi>dp[j]/(1.0-t[j])) mi=dp[j]/(1.0-t[j]),x=j;  
		}
		vis[x]=1;
		F(j,1,n){
			if (!vis[j]){
				dp[j]+=p[j][x]*dp[x]*t[j]/(1.0-t[x]);
				t[j]=t[j]*(1.0-p[j][x]);
			} 
		}
	}
	cout<<oo(10)<<dp[1]/(1.0-t[1])<<"\n";
    return 0;
}