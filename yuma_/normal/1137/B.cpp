#include "bits/stdc++.h"
#pragma GCC optimize("Ofast")

#pragma GCC target("avx,avx2")
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;

const long long int mod = 1000000007;
#include<random>
#include<time.h>
using ll = long long int;

std::random_device rd;
std::mt19937 mt(int(std::time(NULL)));
ll add0=mt();

using ha = pair<ll, ll>;
struct RollingHash {
	static const ll mul0 = 10009, mul1 = 10007;
	ll  add1 = 1003333331;
	size_t len;
	vector<ha>hash_;
	static vector<ha>pmo_;
	void init(const vector<ll>& s) {
		len = s.size();
		hash_.resize(len + 1);
		hash_[0] = make_pair(0, 0);

		if (pmo_.empty()) {
			pmo_.push_back(make_pair(1, 1));
		}
		while (pmo_.size() <= len) {
			pmo_.push_back(make_pair(pmo_.back().first*mul0, pmo_.back().second*mul1));
			pmo_.back().first %= mod;
			pmo_.back().second %= mod;
		}
		for (unsigned int i = 0; i < len; ++i) {
			hash_[i + 1] = make_pair((hash_[i].first * mul0 + s[i]), (hash_[i].second*mul1 + s[i]));
			hash_[i + 1].first %= mod;
			hash_[i + 1].second %= mod;
		}
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
		auto al = (hash_[r + 1].first - hash_[l].first * pmo_[r + 1 - l].first) % mod;
		if (al<0)al += mod;
		auto ar = (hash_[r + 1].second - hash_[l].second * pmo_[r + 1 - l].second) % mod;
		if (ar<0)ar += mod;
		return make_pair(al, ar);

		return make_pair(
			(((hash_[r + 1].first - hash_[l].first * pmo_[r + 1 - l].first) % mod) + mod) % mod,
			(((hash_[r + 1].second - hash_[l].second * pmo_[r + 1 - l].second) % mod) + mod) % mod);
	}
	ha  hash()const { // s[all]
		return hash(0, len - 1);
	}

	//hash
	static ha concat(const ha L, const ha R, const int RLength) { // hash(L+R)
		assert(false);
		return make_pair((R.first + L.first*pmo_[RLength].first), (R.second + L.second*pmo_[RLength].second));
	}

	//indexfromto
	ha get_changed_hash(const int index, const ll from, const ll to)const {
		const ha p(hash());
		assert(false);
		return make_pair(
			p.first + (to - from) * pmo_[len - index - 1].first,
			p.second + (to - from) * pmo_[len - index - 1].second);
	}
};
vector<ha> RollingHash::pmo_;
int main() {
	string s,t;cin>>s>>t;
	RollingHash rh1,rh2;
	rh1.init(s);
	rh2.init(t);

	int asz=0;
	for (int sz= t.size()-1; sz >=1;--sz) {
		if (rh2.hash(t.size()-sz, t.size()-1) == rh2.hash(0, sz-1)) {
			asz=sz;
			break;
		}
	}
	int place=asz;
	int rest_zero_num=count(s.begin(),s.end(),'0');
	int rest_one_num=count(s.begin(),s.end(),'1');
	int tl_zero_num=count(t.begin(),t.begin()+place,'0');
	int tl_one_num=count(t.begin(),t.begin()+place,'1');
	int tr_zero_num=count(t.begin()+place,t.end(),'0');
	int tr_one_num=count(t.begin()+place,t.end(),'1');

	string answer="";
	if (tl_zero_num + tr_zero_num <= rest_zero_num&&tl_one_num + tr_one_num <= rest_one_num) {
		rest_zero_num -= tl_zero_num + tr_zero_num;
		rest_one_num -= tl_one_num + tr_one_num;
		answer += t;
		while (true) {
			if (tr_zero_num <= rest_zero_num&&tr_one_num <= rest_one_num) {
				rest_zero_num-=tr_zero_num;
				rest_one_num-=tr_one_num;
				answer+=t.substr(place);
			}
			else {
				break;
			}
		}
		
	}
	for (int i = 0; i < rest_zero_num; ++i) {
		answer += "0";
	}
	for (int i = 0; i < rest_one_num; ++i) {
		answer += "1";
	}
	cout<<answer<<endl;
		return 0;
}