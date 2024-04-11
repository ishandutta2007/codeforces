#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		for(int i=1;i<=n;i++) a[i]=i;
		ll ans=0;
		vector<pair<int,int> > vec;
		for(int i=n;i>=2;i--){
			if(n-i>=i-1){
				swap(a[i],a[n]);
				vec.push_back({i,n});
				ans+=1ll*(n-i)*(n-i);
			}
			else{
				swap(a[i],a[1]);
				vec.push_back({i,1});
				ans+=1ll*(1-i)*(1-i);
			}
		}
		reverse(vec.begin(),vec.end());
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
		cout<<n-1<<"\n";
		for(auto &it:vec){
			cout<<it.first<<" "<<it.second<<"\n";
		}
	}
}