#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")
//for CodeForces
#pragma GCC target("avx,avx2")
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;
using ll=long long ;
ll gcd(ll a, ll b) {
	if(a>b)return gcd(b,a);
	else {
		if(b%a)return gcd(b%a,a);
		else {
			return a;
		}
	}
}
int main() {
//\ncin>>N;
	int N;cin>>N;
	vector<pair<ll,ll>>ps;
	map<ll,ll>mp;
	for (int i = 0; i < N; ++i) {
		ll x,y;scanf("%lld %lld",&x,&y);
		y-=x*x;
		if(mp.find(x)==mp.end())mp[x]=y;
		else {
			mp[x]=max(mp[x],y);
		}
	}
	for(auto m:mp){
		ps.emplace_back(m);
	}

	int num=0;
	pair<ll,ll>now=ps[0];
	vector<pair<ll, ll>>v{ ps[0] };
	for (int i = 1; i < ps.size(); ++i) {
		pair<ll,ll>next=ps[i];
		while (true) {
			if (v.size() == 1) {
				v.push_back(next);
			}
			else {
				pair<ll,ll>now(v.back()),pre(v[v.size()-2]);

				ll dx=now.first-pre.first;
				ll dy=now.second-pre.second;

				ll adx=next.first-now.first;
				ll ady=next.second-now.second;

				if (dx*ady == dy*adx) {
					v.pop_back();
					v.emplace_back(next);
					break;
				}
				else if (dx*ady < dy*adx) {
					v.emplace_back(next);
					break;
				}
				else {
					v.pop_back();
				}
			}
		}
	}
	cout<<v.size()-1<<endl;
	return 0;
}