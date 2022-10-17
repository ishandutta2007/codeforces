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
const int M=2e4+10,N=10;
const int pw[]={1,5,25,125,625,3125,15625};
int n,m,c[N][N],a[N],b[N];
int dp[N][N][M];
int t[M];
int tint(int *g){
	int ret=0; 
	F(i,1,m) ret+=g[i]*pw[i-1];
	return ret;
}
void tarr(int x){
	F(i,1,m){
		t[i]=x%5;
		x/=5;
	}
}
int main(){
	n=read(); m=read();
	F(i,1,n) a[i]=read();
	F(i,1,m) b[i]=read(); 
	F(i,1,n){
		F(j,1,m){
			c[i][j]=read();
		}
	}
	int lim=pw[m]-1;
	ms(dp,60); 
//	cerr<<dp[0][0][0]<<" ";
	dp[0][0][tint(b)]=0;
//	int as=0;
	F(i,1,n){
		F(j,0,lim) dp[i][a[i]][j]=dp[i-1][0][j];
		DF(j,a[i],1){
			F(l,0,lim){
				if (dp[i][j][l]>=1e9) continue;
				tarr(l);
//				int sm=0;
//				F(k,1,m) sm+=b[k]-t[k];
//				,cerr<<t[k]<<" ";
//				cout<<"\n";
//				cerr<<sm<<" "<<as<<"   hh\n";
//				assert(sm==as);
				F(k,1,m){
					F(num,1,min(j,t[k])){
						t[k]-=num;
						int msk=tint(t);
						dp[i][j-num][msk]=min(dp[i][j-num][msk],dp[i][j][l]+c[i][k]);
						t[k]+=num;
					}
				}	
			}
//			as++;
		}
	}
	int ans=1e9;
	F(i,0,lim) ans=min(ans,dp[n][0][i]);
	cout<<(ans>=1e9 ? -1 : ans)<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/