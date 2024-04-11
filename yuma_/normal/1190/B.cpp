#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
int main() {
	ios::sync_with_stdio(false);
	ll N;cin>>N;
	vector<ll>as(N);
	for(int i=0;i<N;++i)cin>>as[i];

	bool win=true;

	if(N==1){
		win=!(as[0]%2);
	}else{
		sort(as.begin(),as.end());
		vector<int>used(N+1);
		int now=0;
		ll sum=0;
		for(int i=0;i<N;++i){
			if(now<=as[i]){
				used[now]=true;
				sum+=as[i]-now;
				now++;
			}else{
				
			}
		}
		win=!(sum%2);
		map<int,int>mp;
		for(auto a:as)mp[a]++;
		vector<int>v;
		for(auto m:mp){
			if(m.second>=3){
				win=true;
			}else if(m.second==2){
				v.push_back(m.first);
			}
		}
		if(v.size()>=2)win=true;
		if(v.size()==1){
			if(mp[v[0]-1]>=1||v[0]==0)win=true;
		}
	}
	if(win){
		cout<<"cslnb"<<endl;
	}else{
		cout<<"sjfnb"<<endl;
	}
	return 0;
}