#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"

class Compare {
public:
	bool operator()(const pair<int, long long int>&l, const pair<int, long long int>&r) {
		return abs(l.second) > abs(r.second);
	}
};	//aa

int main() {
	int N, K, X; cin >> N >> K >> X;
	bool isminus = false;
	priority_queue<pair<int, long long int>, vector<pair<int, long long int>>, Compare>que;
	for (int i = 0; i < N; ++i) {
		int a; cin >> a;
		que.emplace(i, a);
		if (a < 0)isminus = !isminus;
	}
	
	for (int i = 0; i < K; ++i) {
		auto atop(que.top());
		que.pop();
		if (atop.second > 0) {
			if (isminus) {
				atop.second += X;
			}
			else {
				atop.second -= X;
				if (atop.second < 0)isminus = true;
			}
		}
		else if (atop.second == 0) {
			if (isminus) {
				atop.second += X;
			}
			else {
				atop.second -= X;
				if (atop.second < 0)isminus = true;
			}
		}
		else {
			if (isminus) {
				atop.second -= X;
			}
			else {
				atop.second += X;
				if (atop.second >= 0)isminus = true;
			}
		}
		que.emplace(atop);
		
	}
	vector<long long int>anss(N);
	while (!que.empty()) {
		auto atop(que.top());
		que.pop();
		anss[atop.first] = atop.second;
	}
	for (int i = 0; i < N; ++i) {
		cout << anss[i];
		if (i == N - 1)cout << endl;
		else cout << " ";
	}

	return 0;
}