#include<bits/stdc++.h>
#define ll long long
#define jdb pair<ll,pair<ll,ll> >
using namespace std;
multiset<jdb > s;
ll ans,n;
int main(){
	scanf("%lld",&n);
	for (int i=1;i<=n;i++){
		ll a,b,c,d;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if (a>d||b>c)
			if (a-d>=c-b){
				s.insert({a+b,{a,b}});
				s.insert({c+d,{c,d}});
			}
			else
				if (a>d)
					ans+=a-d;
				else ans-=b-c;
	}
	for (;s.size();){
		jdb x=*s.rbegin();
		ans+=x.second.first;
		s.erase(s.find(x));
		x=*s.rbegin();
		ans-=x.second.second;
		s.erase(s.find(x));
	}
	printf("%lld",ans);
}