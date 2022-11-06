#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;

struct RollingHash {
	static const long long int mul0 = 10009, mul1 = 10007;
	static const long long int add0 = 1000010007, add1 = 1003333331;
	size_t len;
	vector<long long int> hash_, hash2_;
	static vector<long long int> pmo_, pmo2_;
	void init(vector<long long int> s) {
		len = s.size();
		hash_.resize(len + 1);
		hash2_.resize(len + 1);



hash_[0] = 0;
hash2_[0] = 0;

if (pmo_.empty()) {
	pmo_.push_back(1), pmo2_.push_back(1);
}
while (pmo_.size() <= len) {
	pmo_.push_back(pmo_.back() * mul0);
	pmo2_.push_back(pmo2_.back() * mul1);
}
for (int i = 0; i < len; ++i) {
	hash_[i + 1] = (hash_[i] * mul0 + s[i]);
	hash2_[i + 1] = (hash2_[i] * mul1 + s[i]);
}
	}
	void init(string s) {
		len = s.size();
		hash_.resize(len + 1);
		hash2_.resize(len + 1);



		hash_[0] = 0;
		hash2_[0] = 0;

		if (pmo_.empty()) {
			pmo_.push_back(1), pmo2_.push_back(1);
		}
		while (pmo_.size() <= len) {
			pmo_.push_back(pmo_.back() * mul0);
			pmo2_.push_back(pmo2_.back() * mul1);
		}
		for (int i = 0; i < len; ++i) {
			hash_[i + 1] = (hash_[i] * mul0 + s[i]);
			hash2_[i + 1] = (hash2_[i] * mul1 + s[i]);
		}
	}
	pair<long long int, long long int >  hash(int l, int r) { // s[l..r]
		return make_pair(hash_[r + 1] - hash_[l] * pmo_[r + 1 - l],
			hash2_[r + 1] - hash2_[l] * pmo2_[r + 1 - l]);
	}
	pair<long long int, long long int >  hash() { // s[all]
		return hash(0, len - 1);
	}

	//hash
	static pair<long long int, long long int> concat(pair<long long int, long long int> L, pair<long long int, long long int> R, int RLength) { // hash(L+R) 
		return make_pair((R.first + L.first*pmo_[RLength]), (R.second + L.second*pmo2_[RLength]));
	}
};
vector<long long int> RollingHash::pmo_;
vector<long long int> RollingHash::pmo2_;
int main() {
	int N, M; cin >> N >> M;
	vector<pair<long long int, char>>froms, tos;
	for (int i = 0; i < N; ++i) {
		int a; char c;
		scanf("%d-%c", &a, &c);
		if (froms.size() && froms.back().second == c) {
			froms.back().first += a;
		}
		else {
			froms.push_back(make_pair(a, c));
		}
	}
	for (int i = 0; i < M; ++i) {
		int a; char c;
		scanf("%d-%c", &a, &c);
		if (tos.size() && tos.back().second == c) {
			tos.back().first += a;
		}
		else {
			tos.push_back(make_pair(a, c));
		}
	}
	if (froms.size() < tos.size()) {
		cout << 0 << endl;
	}
	else if (tos.size() == 1) {
		long long int ans = 0;
		for (auto f : froms) {
			if (f.second == tos[0].second)ans += max(f.first - tos[0].first + 1, 0ll);
		}
		cout << ans << endl;
	}
	else if (tos.size() >= 2) {
		RollingHash from_ro, to_ro;
		vector<long long int>fh, th;
		for (int i = 0; i < froms.size(); ++i) {
			fh.push_back(froms[i].first * 30 + froms[i].second-'a');
		}
		for (int i = 0; i < tos.size(); ++i) {
			th.push_back(tos[i].first * 30 + tos[i].second - 'a');
		}

		from_ro.init(fh);
		to_ro.init(th);
		long long int ans = 0;
		for (int i = 0; i <= froms.size() - tos.size(); ++i) {
			bool ok = false;
			if (tos.size() == 2)ok = true;
			else {
				if (from_ro.hash(i + 1, i + tos.size()-2) == to_ro.hash(1, tos.size() - 2)) {
					ok = true;
				}
				else {
					ok = false;
				}
			}
			if (ok) {
				if (froms[i].second==tos[0].second&&
					froms[i].first >= tos[0].first&&
					froms[i + tos.size() - 1].second==tos[tos.size()-1].second&&
					froms[i + tos.size()-1].first >= tos[tos.size() - 1].first) {
					ans++;
				}
			}
			
		}
		cout << ans << endl;
	}
	return 0;
}