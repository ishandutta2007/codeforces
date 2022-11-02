#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 998244353;
ll dp[3010][3010];
pair<ll,int> a[3010][3010];
pair<ll,int> b[3010][3010];
ll c[3010][3010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	srand(time(0));
	int n,k;cin>>n>>k;
	for(int i=1;i<=n;i++){
		int m;cin>>m;
		for(int j=1;j<=m;j++){
			int tmp;cin>>tmp;
			if(j<=k){
				a[i][j].first=tmp+a[i][j-1].first;
				a[i][j].second=i;
				b[j][i]=a[i][j];
			}
		}
	}
	for(int i=1;i<=k;i++){
		sort(b[i]+1,b[i]+n+1,greater<pair<ll,int> >());
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(j>=2&&a[i][j]<b[j][k/j+1]) c[i][j]=0;
			else c[i][j]=a[i][j].first;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			// cout<<c[i][j]<<" ";
			if(!j||c[i][j]){
				for(int o=k-j;o>=0;o--){
					int now=o+j;
					dp[i][now]=max(dp[i][now],dp[i-1][o]+c[i][j]);
				}
			}
			// cout<<dp[i][j]<<" ";
		}
		// cout<<endl;
	}
	cout<<dp[n][k]<<endl;
}