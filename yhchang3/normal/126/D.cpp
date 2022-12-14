#include<bits/stdc++.h>
using namespace std;

long long int f[100];
long long int dp[100][2];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	f[1]=1;f[2]=2;
	int sz;
	for(int i=3;;i++){
		f[i]=f[i-1]+f[i-2];
		if(f[i]>1e18){
			sz=i;
			break;
		}
	}
	int T;
	cin>>T;
	while(T--){
		long long int n;
		vector<int> v;
		cin>>n;
		for(int i=sz;i>=1;i--)
			if(n>=f[i]){
				v.emplace_back(i);
				n-=f[i];
			}
		sort(v.begin(),v.end());
		dp[0][0]=1,dp[0][1]=0;
		for(int i=0;i<v.size();i++){
			int x=v[i];
			dp[i+1][0]=dp[i][0]+dp[i][1];
			dp[i+1][1]=dp[i][0]*((v[i]-(i==0?0:v[i-1])-1)/2)+dp[i][1]*((v[i]-(i==0?0:v[i-1]))/2);
			
		}
		cout<<dp[v.size()][0]+dp[v.size()][1]<<'\n';
	}
}