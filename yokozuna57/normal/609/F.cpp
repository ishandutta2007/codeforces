#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define mp make_pair
#define fr first
#define sc second

int n,m;
ll x[200010],t[200010];
ll p[200010],b[200010];
int c[200010];

map<ll,pair<ll,int>> frog;
multimap<ll,ll> mosq;
void f(ll x,ll l){
	auto itr=frog.lower_bound(x);
	itr->sc.fr+=l;
	ll r=itr->sc.fr;
	++itr;
	while(itr!=frog.end()){
		if(itr->fr<=r){
			if(itr->sc.fr<=r)frog.erase(itr++);
			else {
				frog.insert(mp(r+1,itr->sc));
				frog.erase(itr);
				break;
			}
		}
		else break;
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%lld%lld",&x[i],&t[i]);
	for(int i=0;i<m;i++)scanf("%lld%lld",&p[i],&b[i]);
	
	for(int i=0;i<n;i++){
		frog[x[i]]=mp(x[i],i);
	}
	vector<pair<ll,ll>> vec;
	for(int i=0;i<n;i++){
		vec.push_back(mp(x[i],t[i]));
	}
	sort(vec.begin(),vec.end());
	reverse(vec.begin(),vec.end());
	for(auto p: vec){
		f(p.fr,p.sc);
	}
	/*for(int i=0;i<n;i++){
		f(x[i],t[i]);
	}*/
	for(int i=0;i<m;i++){
		mosq.insert(mp(p[i],b[i]));
		auto itr2=mosq.lower_bound(p[i]);
		while(itr2!=mosq.end()){
			auto itr=frog.upper_bound(itr2->fr);
			if(itr==frog.begin())break;
			--itr;
			if(itr->sc.fr<itr2->fr)break;
			f(itr->fr,itr2->sc);
			c[itr->sc.sc]++;
			t[itr->sc.sc]+=itr2->sc;
			mosq.erase(itr2++);
		}
	}
	for(int i=0;i<n;i++){
		printf("%d %lld\n",c[i],t[i]);
	}
}