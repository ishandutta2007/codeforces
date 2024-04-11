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
const int M=404,mod=998244353;
LL dp[2][M][M][3][3];
LL f[2][M][2][2],g[2];
int n,c[M];
int main(){
	n=read();
	F(i,1,26) c[i]=read();
	int now=1,pre=0;
	g[now]=1;
	F(i,1,n){
		swap(now,pre);
		if (i<=2) g[now]=g[pre]*26%mod; 
		else g[now]=g[pre]*25%mod;
	}
	LL ans=g[now];
	now=1; pre=0;
	f[now][0][0][0]=1;
	F(i,1,n){
		swap(now,pre);
		ms(f[now],0);
		F(j,0,i){
			F(k,0,1){
				int kk=(i<=2 ? -1 : k);
				F(l,0,1){
					if (kk==-1){
						f[now][j+1][l][1]=(f[now][j+1][l][1]+f[pre][j][k][l])%mod;
						f[now][j][l][0]=(f[now][j][l][0]+f[pre][j][k][l]*25)%mod;
					}
					if (kk==1){
						f[now][j][l][0]=(f[now][j][l][0]+f[pre][j][k][l]*25)%mod;
					}
					if (kk==0){
						f[now][j+1][l][1]=(f[now][j+1][l][1]+f[pre][j][k][l])%mod;
						f[now][j][l][0]=(f[now][j][l][0]+f[pre][j][k][l]*24)%mod;
					}
				}
			}
		}
//		if (i==5){
//			cout<<f[now][3][0][1]<<"   fuck \n";
//		}
	}
	F(i,1,26){
		F(a1,c[i]+1,n)
		F(j,0,1) F(k,0,1){
//			assert(f[now][c[i]+1][j][k]==0);
			ans=(ans+mod-f[now][a1][j][k])%mod;
		}
	}
	now=1; pre=0;
	dp[now][0][0][0][0]=1;
	F(i,1,n){
		swap(now,pre);
		ms(dp[now],0);
		F(j,0,i){
			F(jj,0,i-j){
				F(k,0,2){
					int kk=(i<=2 ? -1 : k);
					F(l,0,2){
						if (kk==-1){
							dp[now][j+1][jj][l][1]=(dp[now][j+1][jj][l][1]+dp[pre][j][jj][k][l])%mod;
							dp[now][j][jj+1][l][2]=(dp[now][j][jj+1][l][2]+dp[pre][j][jj][k][l])%mod;
							dp[now][j][jj][l][0]=(dp[now][j][jj][l][0]+dp[pre][j][jj][k][l]*24)%mod;
						}
						if (kk==1){
							dp[now][j][jj+1][l][2]=(dp[now][j][jj+1][l][2]+dp[pre][j][jj][k][l])%mod;
							dp[now][j][jj][l][0]=(dp[now][j][jj][l][0]+dp[pre][j][jj][k][l]*24)%mod;
						}
						if (kk==0){
							dp[now][j+1][jj][l][1]=(dp[now][j+1][jj][l][1]+dp[pre][j][jj][k][l])%mod;
							dp[now][j][jj+1][l][2]=(dp[now][j][jj+1][l][2]+dp[pre][j][jj][k][l])%mod;
							dp[now][j][jj][l][0]=(dp[now][j][jj][l][0]+dp[pre][j][jj][k][l]*23)%mod;
						}
						if (kk==2){
							dp[now][j+1][jj][l][1]=(dp[now][j+1][jj][l][1]+dp[pre][j][jj][k][l])%mod;
							dp[now][j][jj][l][0]=(dp[now][j][jj][l][0]+dp[pre][j][jj][k][l]*24)%mod;
						}
					}
				}
			}
		}
	}
//	ans=0;
	F(i,1,26){
		F(j,i+1,26){
			F(a1,c[i]+1,n){
				F(a2,c[j]+1,n-a1){
					F(x,0,2){
						F(y,0,2){
//							if(dp[now][c[i]+1][c[j]+1][x][y]!=dp[now][c[j]+1][c[i]+1][x][y]){
//		//						cout<<c[i]+1<<" "<<c[j]+1<<" "<<x<<" "<<y<<"\n";
//							}
							ans=(ans+dp[now][a1][a2][x][y])%mod;
						}
					}
				}
			}
			
		}
	}
	cout<<ans<<"\n";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/