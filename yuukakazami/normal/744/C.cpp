#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int dp[1<<16][200];//set,saved_r
int r[16],b[16],n;
char cr[16];

int main(){
	cin>>n;

	int mx_save = 0;
	rep(i,n) mx_save += i;

	rep(i,n) cin>>cr[i]>>r[i]>>b[i];

	memset(dp,-1,sizeof dp);

	dp[0][0] = 0;

	rep(vis,1<<n) rep(j,mx_save+1){
		int c = dp[vis][j];

		if(c == -1) continue;

		int A=0,B=0;

		rep(i,n) if(vis>>i&1) {if(cr[i]=='R') ++A; else ++B;}

		rep(nxt,n) if(~vis>>nxt&1){
			int save_a = min(A,r[nxt]);
			int save_b = min(B,b[nxt]);

			dp[vis|(1<<nxt)][j+save_a] = max(dp[vis|(1<<nxt)][j+save_a],c + save_b);
		}
	}

	int totr=0,totb=0;
	rep(i,n) totr+=r[i],totb+=b[i];

	int ans = ~0U>>1;

	rep(save_a,mx_save+1){
		int save_b = dp[(1<<n)-1][save_a];

		if(save_b == -1) continue;
		
		int tmp = max(totr-save_a,totb-save_b);
		ans=min(ans,tmp);
	}

	cout<<ans+n<<endl;
}