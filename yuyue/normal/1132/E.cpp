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
const int M=888; 
int dp[9][M*8];
LL a[M],w,lcm=840,lim=lcm*8; 
int q1[M*8],q2[M*8];
int main(){
	cin>>w;  
	LL tt=0; 
	F(i,1,8) cin>>a[i],tt+=a[i]/(lcm/i);
	ms(dp,-1); dp[0][0]=0; 
	F(i,1,8){
		int d=a[i]%(lcm/i);
		LL c1=a[i]/(lcm/i),c2=c1-1;	
		LL k=min(lcm/i,a[i]);
		if (k<=d) d=k,k=d-1;
		F(j,0,i-1){
			int l1=1,r1=0,l2=1,r2=0; 
			for (int t=0,l=j;l<=lcm*i;l+=i,t++){				
				if (dp[i-1][l]!=-1){
					while (l1<=r1 && dp[i-1][l]>dp[i-1][j+i*q1[r1]]) r1--;
					q1[++r1]=t;
				}
				if (t-d-1>=0){
					int o=t-d-1; 
					if (dp[i-1][o*i+j]!=-1){
						while (l2<=r2 && dp[i-1][o*i+j]>dp[i-1][j+i*q2[r2]]) r2--; 
						q2[++r2]=o;
					}
				}
				while (l1<=r1 && t-q1[l1]>d) l1++;
				while (l2<=r2 && t-q2[l2]>k) l2++;
				if (l1<=r1) {
					dp[i][l]=dp[i-1][j+i*q1[l1]]+1;
				}
				if (l2<=r2) {
					dp[i][l]=max(dp[i-1][j+i*q2[l2]],dp[i][l]);	
				}
			}
		}
//		F(j,0,lim){
//			if (dp[i-1][j]==-1) continue;
//			for (int l=0;l<=min(k,a[i]);l++){
//				if (j+l*i<=lim) dp[i][j+l*i]=max(dp[i-1][j]+(a[i]-l)/(lcm/i),dp[i][j+l*i]);
//			}
//		}
	}
	LL ans=0;
	F(i,0,lcm*8){
		LL tmp=w-i;
		if (tmp>=0 && dp[8][i]>-1) ans=max(ans,i+min(tt-8+dp[8][i],tmp/lcm)*lcm);
	}
	cout<<ans<<"\n";
	return 0;
}