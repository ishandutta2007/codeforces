#include<bits/stdc++.h>
using namespace std;

int dp[300001];
int a[300001];
map<int,int> m[300001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i],m[i].clear();
		m[0].clear();
		for(int i=1;i<=n;i++){
			if(a[i]==a[i-1]){
				dp[i]=1+dp[i-2];
				swap(m[i],m[i-2]);
				m[i][a[i-2]]=i-2;
			}
			else{
				if(m[i-1].count(a[i])){
					int x=m[i-1][a[i]];
					swap(m[i],m[x-1]);
					m[i][a[x-1]]=x-1;
					dp[i]=1+dp[x-1];
				}
				else
					dp[i]=0;
			}
		}
		long long int ans=0;
		for(int i=1;i<=n;i++)
			ans+=dp[i];
		cout<<ans<<'\n';
	}

}