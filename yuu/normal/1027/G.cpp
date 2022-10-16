#include <bits/stdc++.h>
using namespace std;
long long m, x;
vector <pair <long long, int>> fact;
vector <pair <long long, long long>> d;
vector <pair <long long, int>> g;
vector <pair <long long, int>> r;
long long mulmod(long long a, long long b, long long mod){
	if(a>=mod) a%=mod;
	if(b>=mod) b%=mod;
	if(a==0||b==0) return 0;
	if(a<=8e18/b) return (a*b)%mod;
	else return ((mulmod(a, b/80000, mod)*80000)%mod+mulmod(a, b%80000, mod))%mod;
}
long long powerx(long long a, long long mod){
	if(a==0) return 1%mod;
	long long t=powerx(a/2, mod);
	t=mulmod(t, t, mod);
	if(a%2)	t=mulmod(t, x, mod);
	return t;
}
void backtrack(int u, int v, long long s, int mu=1){
	if(u==fact.size()){
		if(mu) r.push_back({s, mu});
		g.push_back({s, mu});
	}
	else{
		backtrack(u+1, 0, s, mu);
		if(v<fact[u].second){
			if(v) backtrack(u, v+1, s*fact[u].first, 0);
			else backtrack(u, v+1, s*fact[u].first, -mu);
		}
	}
}
int main(){
	cin>>m>>x;
	long long ans=0;
	long long phi=m;
	long long temp=m;
	for(long long i=2; i*i<=temp; i++){
		if(temp%i==0){
			fact.push_back({i, 0});
			while(temp%i==0){
				temp/=i;
				fact.back().second++;
			}
		}
	}
	if(temp>1){
		fact.push_back({temp, 1});
	}
	for(auto &x: fact){
		phi/=x.first;
		phi*=x.first-1;
	}
	long long sz=phi;
	long long val=1;
	for(long long i=1; i*i<=phi; i++){
		if(phi%i==0){
			d.push_back({i, i});
			d.push_back({phi/i, phi/i});
		}
	}
	sort(d.begin(), d.end());
	d.erase(unique(d.begin(), d.end()), d.end());
	for(auto &x: d) x.second=powerx(x.first, m);
	backtrack(0, 0, 1);
	sort(g.begin(), g.end());
	sort(r.begin(), r.end());
	for(auto &x: g){
		long long cnt=0;
		for(auto y: r){
			if(x.first>m/y.first) break;
			y.first*=x.first;
			if(m%y.first) continue;
			cnt+=(m/y.first)*y.second;
		}
		for(auto sz: d){
			if((sz.second-1)%(m/x.first)==0){
				ans+=cnt/sz.first;
				break;
			}
		}
	}
	cout<<ans<<'\n';
}