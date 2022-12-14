#include<iostream>
using namespace std;

long long int dp[300001][3];

int a[300001],b[300001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int q;
	cin>>q;
	while(q--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=0;j<3;j++)
				dp[i][j]=4e18;//Infinity
		for(int i=1;i<=n;i++)
			cin>>a[i]>>b[i];
		for(int i=1;i<=n;i++)
			for(int inc=0;inc<3;inc++)
				for(int pre=0;pre<3;pre++)
					if(a[i-1]+pre!=a[i]+inc)
						dp[i][inc]=min(dp[i][inc],dp[i-1][pre]+inc*b[i]);
		long long int ans=4e18;
		for(int i=0;i<3;i++)
			ans=min(dp[n][i],ans);
		cout<<ans<<'\n';
	}
}