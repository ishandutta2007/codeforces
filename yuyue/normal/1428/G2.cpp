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
const int M=999999;
LL dp[M+10],G[10];
int k,ten[M];
int main(){
	k=read(); 
	F(i,0,5) G[i]=read(); 
	fill(dp,dp+M,-(1ll<<50));
	dp[0]=0; 
	ten[0]=1;
	F(i,1,5) ten[i]=ten[i-1]*10;
	F(i,0,5){
		int sz=1,now=3*(k-1);
		while (now){
			sz=min(sz,now);
			LL val=G[i]*sz,_sz=1ll*sz*ten[i]*3;
			DF(j,M,_sz){
				dp[j]=max(dp[j],dp[j-_sz]+val);
			}
			now-=sz;
			sz=sz*2;
		}
	}
//	F(i,0,100){
//		cout<<dp[i]<<" "<<i<<"  hh\n";
//	}
//	cout<<dp[30000]<<"\n";
	for (int i=0;i<=5;i++){
		DF(k,M,0){
			F(j,0,9){
				LL val=0;
				if (j%3==0) val=G[i]*(j/3);
				if (k>=j*ten[i]){
					dp[k]=max(dp[k],dp[k-j*ten[i]]+val);
				}
			}
		}
	}
	int Q=read();
	while (Q--){
		int x=read();
		cout<<dp[x]<<"\n";
	}
	return 0;
}