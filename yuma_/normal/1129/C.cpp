#include "bits/stdc++.h"
#pragma warning(disable:4996)
using namespace std;


const long long int mod = 1000000007;


using ll = long long int;
using ha = pair<ll, ll>;
struct RollingHash {
	static const ll mul0 = 10009, mul1 = 10007;
	static const ll add0 = 1000010007, add1 = 1003333331;
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
		auto al=( hash_[r + 1].first - hash_[l].first * pmo_[r + 1 - l].first) % mod;
		if(al<0)al+=mod;
		auto ar= (hash_[r + 1].second - hash_[l].second * pmo_[r + 1 - l].second) % mod;
		if(ar<0)ar+=mod;
		return make_pair(al,ar);
		
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
bool oks[3010][3010];
int main() {
	int N;
	string st;
	cin>>N;
	for (int i = 0; i < N; ++i) {
		char ch;cin>>ch;
		st.push_back(ch);
	}
	RollingHash rh;
	rh.init(st);
	vector<pair<pair<int, int>,int>>vs;
	for (int l = 0; l < N; ++l) {
		for (int r = l; r < N; ++r) {
			ha h=rh.hash(l,r);
			pair<int,int>p(h.first,h.second);
			vs.push_back(make_pair(p,r<<12|l));
		}
	}
	sort(vs.begin(),vs.end());
	vs.erase(unique(vs.begin(), vs.end(), [](
		const pair<pair<int,int>,int>&l,
		const pair<pair<int, int>,int>&r) {
		return l.first == r.first;
	}),vs.end());
	for (auto x : vs) {
		oks[x.second&4095][x.second >> 12] =true;
	}
	vector<string>out_sts = {
		"0011",
		"0101",
		"1110",
		"1111"
	};
	vector<long long int>answers(N);
	for (int l = 0; l < N; ++l) {
		vector<long long int>nums{ 0,0,0,1 };

		for (int r = l; r < N; ++r) {
			
			long long int nans=0;
			for (int x = 0; x < 4; ++x) {
				if (x == 0) {
					if (r >= 3) {
						string ast = st.substr(r - 3, 4);
						if (find(out_sts.begin(), out_sts.end(), ast) == out_sts.end()) {
							nans+=nums[x];
						}
						else {
						}
					}
				}
				else {
					nans += nums[x];
				}
			}
			while(nans>=mod)nans-=mod;
			if (oks[l][r]) {
				answers[r]+=nans;
				if(answers[r]>=mod)answers[r]-=mod;
			}
			for (int x = 0; x < 3; ++x) {
				nums[x]=nums[x+1];
			}
			nums[3]=nans;
		}
	}
	long long int sum=0;
	for (int i = 0; i < N; ++i) {
		sum+=answers[i];
		if(sum>=mod)sum-=mod;
		printf("%lld\n",sum);
	}
	return 0;
}