#include<bits/stdc++.h>
#define mo 1000000007
#define N 300005
#define M 26000
using namespace std;
int pri[N],mn[N],tot;
vector<int> vec[M];
int fac[N],inv[N];
int C[N],dp[N],n;
int main(){
	for (int i=2;i<N;i++){
		if (!mn[i]){
			pri[++tot]=i;
			mn[i]=tot;
		}
		for (int j=1;i*pri[j]<N&&j<=tot;j++){
			mn[i*pri[j]]=j;
			if (i%pri[j]==0) break;
		}
	}
	fac[0]=inv[0]=inv[1]=1;
	for (int i=2;i<N;i++)
		inv[i]=1ll*inv[mo%i]*(mo-mo/i)%mo;
	for (int i=1;i<N;i++){
		inv[i]=1ll*inv[i-1]*inv[i]%mo;
		fac[i]=1ll*fac[i-1]*i%mo;
	}
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		C[i]=1ll*fac[n-1]*inv[i]%mo*inv[n-i-1]%mo;
	for (int i=1;i<=n;i++){
		int x; scanf("%d",&x);
		for (;x!=1;){
			int tmp=mn[x],cnt=0;
			for (;x%pri[tmp]==0;x/=pri[tmp],cnt++);
			vec[tmp].push_back(cnt);
		}
	}
	dp[n]=1;
	for (int i=1;i<n;i++)
		dp[n]=dp[n]*2%mo;
	dp[n]--;
	for (int i=n-1;i;i--)
		dp[i]=(dp[i+1]+2ll*mo-C[i]-C[i-1])%mo;
	int ans=0;
	for (int i=1;i<=tot;i++){
		sort(vec[i].begin(),vec[i].end());
		int tmp=vec[i].size();
		for (int j=0;j<tmp;j++)
			ans=(ans+1ll*dp[n-tmp+j+1]*vec[i][j])%mo;
	}
	printf("%d",ans);
}