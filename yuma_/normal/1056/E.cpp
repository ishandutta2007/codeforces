#include "bits/stdc++.h"

#pragma warning(disable:4996)
using namespace std;
using ld = long double;

using ll = long long int;
using ha = pair<ll, ll>;
struct RollingHash {
	static const ll mul0 = 10009, mul1 = 10007;
	static const ll add0 = 1000010007, add1 = 1003333331;
	static const ll KK=1e9+77777777;
	size_t len;
	//vector<ll> hash_, hash2_;
	vector<ha>hash_;
	//static vector<ll> pmo_, pmo2_;
	static vector<ha>pmo_;
	void init(const vector<ll>& s) {
		len = s.size();
		hash_.resize(len + 1);
		hash_[0] = make_pair(0, 0);

		if (pmo_.empty()) {
			pmo_.push_back(make_pair(1, 1));
		}
		while (pmo_.size() <= len) {
			pmo_.push_back(make_pair(pmo_.back().first*mul0%KK, pmo_.back().second*mul1%KK));
		}
		for (unsigned int i = 0; i < len; ++i) {
			hash_[i + 1] = make_pair((hash_[i].first * mul0 + s[i]) % KK, (hash_[i].second*mul1 + s[i]) % KK);
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

	// s[l..r]
	ha hash(const int l, const int r)const {
		auto p=make_pair(hash_[r + 1].first - hash_[l].first * pmo_[r + 1 - l].first,
			hash_[r + 1].second - hash_[l].second * pmo_[r + 1 - l].second);
		p.first+=KK*KK;
		p.second+=KK*KK;
		return make_pair(p.first%KK,p.second%KK);
	}
	ha  hash()const { // s[all]
		return hash(0, len - 1);
	}


};
vector<ha> RollingHash::pmo_;

char s[100010], t[1000010];
int main() {

	string S, T;
	{

		scanf("%s %s", s, t);
		S=s;
		T=t;
	}
	if (S[0] == '0') {
		for (auto&c : S) {
			if(c=='0')c++;
			else c--;
		}
	}
	int one_cnt=0;
	int zero_cnt=0;
	for (auto c : S) {
		if(c=='0')zero_cnt++;
		else one_cnt++;
	}
	RollingHash rh;
	rh.init(T);
	int answer=0;
	if (zero_cnt == 0) {
		//if (T.size() % one_cnt == 0) {
		//	bool ok=true;
		//	int one_len=T.size()/one_cnt;
		//	ha h=rh.hash(0,one_len-1);
		//	for (int k = 1; k < one_cnt; ++k) {
		//		ha ah=rh.hash(k*one_len,(k+1)*one_len-1);
		//		if(h!=ah)ok=false;
		//	}
		//	if(ok)answer++;
		//}
		assert(false);
	}
	else {
		for (int one_len = 1; one_len <= int(T.size()) / (one_cnt); ++one_len) {
			int zero_len_total = int(T.size()) - one_len*one_cnt;
			if (zero_len_total > 0 && zero_len_total%zero_cnt == 0) {
				int zero_len = zero_len_total / zero_cnt;

				bool one_flag = false;
				bool zero_flag = false;
				ha one_hash, zero_hash;
				bool ok = true;
				int k = 0;
				for (int i = 0; i < S.size(); ++i) {
					if (S[i] == '0') {
						ha nhash = rh.hash(k, k + zero_len - 1);
						if (!zero_flag) {
							zero_flag = true;
							zero_hash = nhash;
						}
						else {
							if (zero_hash != nhash) {
								ok = false;
								break;
							}
						}
						k += zero_len;
					}
					else {
						ha nhash = rh.hash(k, k + one_len - 1);
						if (!one_flag) {
							one_flag = true;
							one_hash = nhash;
						}
						else {
							if (one_hash != nhash){
								ok = false;
								break;
							}
						}
						k += one_len;
					}
				}
				if (one_flag&&zero_flag&&one_hash == zero_hash) {
					ok = false;
				}
				if (ok) {
					answer++;
				}
			}
		}

	}
	cout<<answer<<endl;

	return 0;
}