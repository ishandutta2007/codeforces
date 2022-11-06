#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 998244353;
int main() {
	ll N,K;cin>>N>>K;
	string a,b;cin>>a>>b;
	ll answer=0;
	ll sum=0;
	for(int i=0;i<N;++i){
		sum*=2;
		sum+=int(b[i])-int(a[i]);
		sum=min(sum,ll(1e10));
		answer+=min(K,sum+1);
	}
	cout<<answer<<endl;
	return 0;
}