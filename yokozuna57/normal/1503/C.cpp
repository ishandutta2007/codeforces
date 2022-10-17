#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

ll n;
ll a[100010],c[100010];

int main(){
	scanf("%lld",&n);
	for(int i=0;i<n;i++)scanf("%lld%lld",&a[i],&c[i]);
	
	ll ret=0;
	for(int i=0;i<n;i++)ret+=c[i];
	
	vector<pair<ll,ll>> vec;
	for(int i=0;i<n;i++){
		vec.push_back(mp(a[i],c[i]));
	}
	sort(vec.begin(),vec.end());
	for(int i=0;i<n;i++){
		a[i]=vec[i].fr;
		c[i]=vec[i].sc;
	}
	ll MAX=a[0]+c[0];
	for(int i=1;i<n;i++){
		ret+=max((ll)0,a[i]-MAX);
		MAX=max(MAX,a[i]+c[i]);
	}
	cout<<ret<<endl;
}