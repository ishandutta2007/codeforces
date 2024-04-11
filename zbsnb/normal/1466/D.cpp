#include<bits/stdc++.h>
using namespace std;
#define ll long long
int val[1000010];
int deg[1000010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		vector<int> vec;
		ll ans=0;
		for(int i=1;i<=n;i++) cin>>val[i],ans+=val[i],deg[i]=0;
		for(int i=1;i<n;i++){
			int a,b;cin>>a>>b;
			deg[a]++;deg[b]++;
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<deg[i];j++){
				vec.push_back(val[i]);
			}
		}
		sort(vec.begin(),vec.end(),greater<int>());
		for(auto &it:vec){
			cout<<ans<<" ";
			ans+=it;
		}
		cout<<ans<<"\n";
	}
}