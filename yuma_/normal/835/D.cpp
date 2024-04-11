#include "bits/stdc++.h"
using namespace std;

string st;
vector<vector<int>>memo;

using ll = long long int;
using ha = pair<ll, ll>;
struct RollingHash {
	static const ll mul0 = 10009, mul1 = 10007;
	static const ll add0 = 1000010007, add1 = 1003333331;
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
			pmo_.push_back(make_pair(pmo_.back().first*mul0, pmo_.back().second*mul1));
		}
		for (unsigned int i = 0; i < len; ++i) {
			hash_[i + 1] = make_pair((hash_[i].first * mul0 + s[i]), (hash_[i].second*mul1 + s[i]));
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
		return make_pair(hash_[r + 1].first - hash_[l].first * pmo_[r + 1 - l].first,
			hash_[r + 1].second - hash_[l].second * pmo_[r + 1 - l].second);
	}
	ha  hash()const { // s[all]
		return hash(0, len - 1);
	}

	//hash
	static ha concat(const ha L, const ha R, const int RLength) { // hash(L+R) 
		return make_pair((R.first + L.first*pmo_[RLength].first), (R.second + L.second*pmo_[RLength].second));
	}

	//indexfromto
	ha get_changed_hash(const int index, const ll from, const ll to)const {
		const ha p(hash());
		return make_pair(
			p.first + (to - from) * pmo_[len - index - 1].first,
			p.second + (to - from) * pmo_[len - index - 1].second);
	}
};
vector<int>anss;
vector<ha> RollingHash::pmo_;
RollingHash rh,revrh;
bool is_asame(int l, int r) {
	return rh.hash(l, r-1) == revrh.hash(st.size() - r, st.size() - l-1);
}
int solve(int l, int r) {
	if (memo[l][r] != -1)return memo[l][r];
	int ans = -200000;
	if (l > r)ans = -200000;
	else if (l == r)ans = -200000;

	else if (l + 1 == r)ans = 1;
	else {
		int t = (l + r) / 2;
		if ((r - l) % 2) {
			if (rh.hash(l, t-1) == rh.hash(t + 1, r-1)) {
				ans = solve(l, t) + 1;
			}
		}
		else {
			if (rh.hash(l, t-1) == rh.hash(t, r-1)) {
				ans = solve(l, t)+1;
			}
		}
		if (is_asame(l, r)) {
			ans = max(ans, 1);
		}
	}
	return memo[l][r]=ans;
}
int main() {
	cin >> st;
	anss.resize(st.size() + 1);
	rh.init(st);
	reverse(st.begin(), st.end());
	revrh.init(st);
	memo = vector<vector<int>>(st.size() + 1, vector<int>(st.size()+1, -1));
	solve(0, st.size());
	for (int i = 0; i <= st.size(); ++i) {
		for (int j = 0; j <= st.size(); ++j) {
			solve(i, j);
		}
	}

	for (int i = 0; i <= st.size(); ++i) {
		for (int j = 0; j <= st.size(); ++j) {
			if (memo[i][j]>=0) {
				anss[memo[i][j]]++;
			}
		}
	}
	for (int i = 0; i < st.size(); ++i) {
		int a = accumulate(anss.begin() + i+1, anss.begin() + st.size() + 1, 0);
		cout << a;
		if (i == st.size() - 1)cout << endl;
		else cout << " ";
	}
	
	return 0;
}