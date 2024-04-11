#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2020;
int n,m,x,y;
double dp[M][M],a[M][M],ret[M];
void Gauss(){
	for (int i=1;i<=m;i++){
		if (i<m){
			double tim=a[i+1][i]/a[i][i];
			a[i+1][i+1]-=tim*a[i][i+1]; 
			a[i+1][m+1]-=tim*a[i][m+1]; 
			a[i+1][i]=0;
		}
	}
	ret[m]=-a[m][m+1]/a[m][m]; 
	DF(i,m-1,1){
		ret[i]=-(ret[i+1]*a[i][i+1]+a[i][m+1])/a[i][i]; 
	}
}
int main(){
	cin>>n>>m>>x>>y; n-=x-1; x=1;
	if (m==1){
		cout<<2*(n-x)<<"\n";
		return 0;
	}
	DF(i,n-1,1){
		F(j,1,m){
			if (j-1) a[j][j-1]=1;
			if (j+1<=m) a[j][j+1]=1;
			if (j==1 || j==m) a[j][j]=-2,a[j][m+1]=dp[i+1][j]+3; else a[j][j]=-3,a[j][m+1]=dp[i+1][j]+4;  
		}
		Gauss(); 
		F(j,1,m) dp[i][j]=ret[j]; 
	}
	cout<<fixed<<setprecision(10)<<dp[x][y]<<"\n";
	return 0;
}