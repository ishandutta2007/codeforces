#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
int main() {
	ios::sync_with_stdio(false);
	ll N,M,K;cin>>N>>M>>K;
	vector<ll>as(M);
	for(int i=0;i<M;++i){
		cin>>as[i];
		as[i]--;
	}
	ll now=0;
	ll answer=0;
	auto it=as.begin();
	while(it!=as.end()){
		ll sa=*it-now;
		if(sa>=K){
			now+=(sa/K)*K;
		}
		auto jt=lower_bound(it,as.end(),now+K);
		answer++;
		now+=jt-it;
		it=jt;

	}
	cout<<answer<<endl;
	return 0;
}