#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i=(a);i<(n);i++)

typedef long long ll;

static map<pair<int,ll>,int> mp;

int calc(int rem,ll mask){
	mask &= (1ll<<(rem+1))-1;
	auto key = make_pair(rem,mask);

	if(mp.count(key))
		return mp[key];
	bool has[65]={};
	rep(i,1,rem+1) if(~mask>>i&1)
		has[calc(rem-i,mask|(1<<i))] = 1;

	rep(i,0,rem+1) if(!has[i]) return mp[key]=i;
	return -1;
}

int main(){
	int ans = 0;
	int n;cin>>n;
	rep(i,0,n) { int x; cin>>x; ans^= calc(x,0);}
	puts(ans==0?"YES":"NO");
	return 0;
}