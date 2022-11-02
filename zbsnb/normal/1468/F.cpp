#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
	ios::sync_with_stdio(0);cin.tie(0);

	int t;cin>>t;
	while(t--){
		int n;cin>>n;
		map<pair<int,int>,int> mp,mp2;
		LL ans=0;
		for(int i=1;i<=n;i++){
			int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
			int x=x2-x1,y=y2-y1;
			int gcd=abs(__gcd(x,y));
			x/=gcd,y/=gcd;
			// cout<<i<<" "<<x<<" "<<y<<endl;
			mp[{x,y}]++;
			mp2[{-x,-y}]++;
		}
		for(auto &it:mp){
			ans+=1ll*it.second*mp2[it.first];
		}
		cout<<ans/2<<endl;
	}
}