#include <bits/stdc++.h>
using namespace std;
using ld=long double;

map<pair<int,int>,int>memo;
	int N;
int solve(vector<int>&v,int k){
	if(v.size()+k>=N)return N;
	if(v.empty())return k;
	else{
		int ans=1;
		int use=0;
		int l=0;
		int r=0;
		while(r!=v.size()-1){
			use+=v[r+1]-v[r]-1;
			r++;
			while(use>k){
				use-=v[l+1]-v[l]-1;
				l++;
			}
			ans=max(ans,r-l+1);
		}
		return k+ans;
	}
}
int main() {cin>>N;
	string st;cin>>st;
	vector<vector<int>>vs(26);
	for(int i=0;i<N;++i){
		char c=st[i];
		vs[static_cast<int>(c-'a')].push_back(i);
	}
	int Q;cin>>Q;
	while(Q--){
		int k;
		char c;
		cin>>k>>c;
		int a=c-'a';
		int ans;
		if(memo.find(make_pair(a,k))!=memo.end())ans= memo[make_pair(a,k)];
		else{
			ans=memo[make_pair(a,k)]=solve(vs[a],k);
		}
			cout<<ans<<endl;
	}
	return 0;
}