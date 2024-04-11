#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> P1;
#define mp1(a,b,c) P1(a,P(b,c))

int main(){
	static ll n,m;
	static ll u[300010],v[300010],d[300010];
	scanf("%lld%lld",&n,&m);
	for(int i = 0 ; i < m ; i ++){
		scanf("%lld%lld%lld",&u[i],&v[i],&d[i]);
	}
	
	static ll in[100010] = {};
	static ll out[100010] = {};
	for(int i = 0 ; i < m ; i ++){
		out[u[i]] += d[i];
		in[v[i]] += d[i];
	}
	
	vector<P> A,B;
	for(int i = 1 ; i <= n ; i ++){
		if(out[i] > in[i]){
			A.push_back(P(i,out[i]-in[i]));
		}
		if(out[i] < in[i]){
			B.push_back(P(i,in[i]-out[i]));
		}
	}
	
	vector<P1> ans;
	ll s = 0, t = 0;
	while(s < A.size() && t < B.size()){
		if(A[s].second == 0){
			s ++;
			continue;
		}
		if(B[t].second == 0){
			t ++;
			continue;
		}
		ll x = min( A[s].second , B[t].second );
		ans.push_back(mp1(A[s].first,B[t].first,x));
		A[s].second -= x;
		B[t].second -= x;
	}
	printf("%d\n",(int)ans.size());
	for(int i = 0 ; i < ans.size() ; i ++){
		printf("%lld %lld %lld\n",ans[i].first,ans[i].second.first,ans[i].second.second);
	}
}