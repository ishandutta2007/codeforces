#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

const ll MOD=998244353;

int main(){
	static ll n,k;
	static ll a[200010];
	scanf("%lld%lld",&n,&k);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	
	vector<ll> vec;
	for(int i=0;i<n;i++){
		if(a[i]>=n-k+1)vec.push_back(i);
	}
	ll ret[2]={0,1};
	for(int i=0;i<k;i++)ret[0]+=n-i;
	for(int i=0;i+1<vec.size();i++){
		ret[1]*=vec[i+1]-vec[i];
		ret[1]%=MOD;
	}
	cout<<ret[0]<<" "<<ret[1]<<endl;
}