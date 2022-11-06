#include<bits/stdc++.h>
using namespace std;

const long long int mod=998244353;
vector<vector<long long int>>dp;
vector<vector<long long int>>dp2;

using ll=long long ;
ll sum( ll N , ll l , ll r ){
	return (l)*(N-r+1);
}
int main() {
	int N;cin>>N;
	vector<int>v(N);
	for(int i=0;i<N;++i)scanf("%d",&v[i]);

	ll ans=0;
	for(int i=0;i<N;++i){
		ans+=sum(N,v[i],v[i]);
	}
	for(int i=0;i<N-1;++i){
		ans-=sum(N,min(v[i],v[i+1]),max(v[i],v[i+1]));
	}
	cout<<ans<<endl;
	return 0;
}