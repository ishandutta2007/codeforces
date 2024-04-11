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
void cm(int &x,int y){
	x=min(x,y);
}
const int M=111;
int a[M],p[M],n;
int dp[M][M][M][2];
int main(){
	n=read();
	F(i,1,n) a[i]=read(),p[a[i]]=i;
	int c[2]; c[0]=c[1]=0;
	F(i,1,n){
		if (!p[i]){
			c[i&1]++;
		}
	}
	int ans=1e7;
	ms(dp,1); 
	if (a[1]){
		dp[1][c[0]][c[1]][a[1]&1]=0;
	}
	else {
		if (c[1]) dp[1][c[0]][c[1]-1][1]=0;
		if (c[0]) dp[1][c[0]-1][c[1]][0]=0;
	}
	F(i,1,n-1){
		F(j,0,n){
			F(k,0,n){
				F(l,0,1){
					if (a[i+1]){
						cm(dp[i+1][j][k][a[i+1]&1],dp[i][j][k][l]+(l^(a[i+1]&1)));
						continue;
					}
					if (j){
						cm(dp[i+1][j-1][k][0],dp[i][j][k][l]+(l^0));
					}
					if (k){
						cm(dp[i+1][j][k-1][1],dp[i][j][k][l]+(l^1));
					}
				}
			}
		}
	}
	cout<<min(dp[n][0][0][1],dp[n][0][0][0])<<"\n";
	return 0;
}