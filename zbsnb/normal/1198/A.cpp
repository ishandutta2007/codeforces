#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	int n,i;cin>>n>>i;
	map<int,int> mp;
	for(int i=1;i<=n;i++){
		int tmp;cin>>tmp;
		mp[tmp]++;
	}

	if(8*i/n>=30) {
		cout<<0<<endl;
		return 0;
	}
	int k=1;
	for(int j=1;j<=8*i/n;j++) k*=2;

	// cout<<k<<endl;

	if(k>=n) cout<<0<<endl;
	else{
		vector<int> vec;
		for(auto &it:mp)vec.push_back(it.second);
		int now=0;
		for(int i=k;i<vec.size();i++)now+=vec[i];
		int ans=now;
		for(int i=1;i+k-1<vec.size();i++){
			now-=vec[i+k-1]-vec[i-1];
			ans=min(ans,now);
			// cout<<i<<" "<<now<<endl;
		}
		cout<<ans<<endl;
	}
}