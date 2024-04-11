#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int odd[71],even[71],mask[71];

int prime[19]={
	2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67
};
int dp[71][1<<19];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=70;i++)
		even[i]=1;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		odd[x]=even[x]=(even[x]+odd[x])%mod;
	}
	for(int i=1;i<=70;i++){
		int x=i;
		for(int j=0;j<19;j++){
			while(x%prime[j]==0){
				mask[i]^=(1<<j);
				x/=prime[j];
			}
		}
	}
	dp[0][0]=1;
	for(int i=1;i<=70;i++)
		for(int j=0;j<(1<<19);j++)
			dp[i][j]=((long long int)dp[i-1][j]*even[i]+(long long int)dp[i-1][j^mask[i]]*odd[i])%mod;
	cout<<dp[70][0]-1<<endl;
}