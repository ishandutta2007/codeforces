#include "bits/stdc++.h"
using namespace std;
template <typename T>
class cht {
	vector<pair<T,T>>ls;

	bool check(const pair<T, T>&l1, const pair<T, T>&l2, const pair<T, T>&l3)const {
		return 1.0*(l2.first - l1.first)*(l3.second - l2.second) >= 1.0*(l2.second - l1.second)*(l3.first - l2.first);
	}
public:
	cht() :ls() {
	}
	cht(vector<pair<T, T>>&vs) :ls() {
		sort(vs.begin(), vs.end());
		for (auto v : vs) {
			add(v);
		}
	}
	void add(const pair<T, T>&p) {
		while (ls.size() >= 2) {
			if (!check(ls[ls.size() - 2], ls[ls.size() - 1], p)) {
				break;
			}
			else {
				ls.pop_back();
			}
		}
		ls.emplace_back(p);
	}
	T f(int k, const T&x)const  {
		return ls[k].first*x + ls[k].second;
	}
	T query(const T&x)const  {
		int amin = 0;
		int amax = ls.size();
		while (amin + 1 != amax) {
			int amid = (amin + amax) / 2;
			if (f(amid-1, x) <= f(amid, x)) {
				amin = amid;
			}
			else {
				amax = amid;
			}
		}
		return f(amin, x);
	}
};

int main() {
	int N; cin >> N;
	vector<int>as(N);
	for (int i = 0; i < N; ++i) {
		cin >> as[i];
	}
	vector<int>bs(N);
	for (int i = 0; i < N; ++i) {
		cin >> bs[i];
	}
	cht<long long int>ch;
	vector<long long int>dp(N);
	for (int i = 0; i < N; ++i) {
		if (!i)dp[i] = 0;
		else {
			dp[i] = -ch.query(as[i]);
		}
		pair<long long int, long long int>p(-bs[i], -dp[i]);
		ch.add(p);
	}
	cout << dp[N - 1] << endl;

	return 0;
}