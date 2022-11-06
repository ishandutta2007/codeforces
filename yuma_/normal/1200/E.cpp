#include "bits/stdc++.h"
#include<vector>
#include<iostream>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<iomanip>
#include<assert.h>
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

#define WHATS(var) cout<<__LINE__<<' '<<#var<<"="<<var<<endl;

template<class S, class T> ostream& operator <<(ostream &os, const pair<S, T> v){
  os << "( " << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<T> &v){
  for(int i = 0; i < v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<vector<T>> &v){
  for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const vector<set<T>> &v){
  for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}
template<class T> ostream& operator <<(ostream &os, const set<T> &v){
	int i=0;
  	for(auto it:v){
		if(i > 0){os << ' ';}
		os << it;
		i++;
	} 
	return os;
}
using ll=long long ;
using ll = long long int;
using ha = pair<ll, ll>;
struct RollingHash {
	static const ll mul0 = 10009, mul1 = 10007;
	static const ll add0 = 1000010007, add1 = 1003333331;
	static const ll mod0 = 1000000007, mod1 = 1000000009;

	size_t len=0;
	//vector<ll> hash_, hash2_;
	vector<ha>hash_;
	//static vector<ll> pmo_, pmo2_;
	static vector<ha>pmo_;
	void init(const vector<ll>& s) {
		hash_.resize(len+s.size()+ 1);
		hash_[0] = make_pair(0, 0);

		if (pmo_.empty()) {
			pmo_.push_back(make_pair(1, 1));
		}
		while (pmo_.size() <= len+s.size()) {
			pmo_.push_back(make_pair(pmo_.back().first*mul0%mod0, pmo_.back().second*mul1%mod1));
		}
		for (unsigned int i = 0; i < s.size(); ++i) {
			int id=i+len;
			hash_[id + 1] = make_pair((hash_[id].first * mul0 + s[i])%mod0, (hash_[id].second*mul1 + s[i])%mod1);
		}
		len += s.size();

		return;
	}
	void init(const string& s) {
		vector<ll>v;
		for (char c : s) {
			v.push_back(c);
		}
		init(v);
	}
	ha hash(const int l, const int r)const { // s[l..r]
		auto p=make_pair(hash_[r + 1].first - hash_[l].first * pmo_[r + 1 - l].first,
			hash_[r + 1].second - hash_[l].second * pmo_[r + 1 - l].second);
		
		p.first%=mod0;
		p.second%=mod1;
		if(p.first<0)p.first+=mod0;
		if(p.second<0)p.second+=mod1;

		return p;
	}
	ha  hash()const { // s[all]
		return hash(0, len - 1);
	}

	static ha concat(const ha L, const ha R, const int RLength) { // hash(L+R) 
		return make_pair((R.first + L.first*pmo_[RLength].first)%mod0, (R.second + L.second*pmo_[RLength].second)%mod1);
	}

	ha get_changed_hash(const int index, const ll from, const ll to)const {
		const ha p(hash());
		return make_pair(
			(p.first + (to - from) * pmo_[len - index - 1].first)%mod0,
			(p.second + (to - from) * pmo_[len - index - 1].second)%mod1);
	}
};
vector<ha> RollingHash::pmo_;
int main() {

	ios::sync_with_stdio(false);
	int N;cin>>N;
	RollingHash rh;
	vector<string>sts(N);
	for(int i=0;i<N;++i){
		cin>>sts[i];
	}
	rh.init(sts[0]);
	string answer;
	answer+=sts[0];
	for(int i=0;i<N-1;++i){
		int x=min(rh.len,sts[i+1].size());
		//WHATS(x);
		RollingHash arh;
		arh.init(sts[i+1]);
		for(;x>0;--x){
			if(rh.hash(rh.len-x,rh.len-1)==arh.hash(0,x-1)){
				break;
			}
		}
		//cout<<x<<endl;
		//WHATS(x);
		string k=sts[i+1].substr(x);
		answer+=sts[i+1].substr(x);
		rh.init(k);
	}
	cout<<answer<<endl;
	return 0;
}