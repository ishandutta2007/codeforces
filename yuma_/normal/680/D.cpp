#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.answer"
vector<pair<long long int,long long int>>memo;
vector<long long int>tris;
pair<long long int,long long int> getans(const long long int x) {
	if (x <=100) {
		return memo[x];
	}
	else {
		auto it = lower_bound(tris.begin(), tris.end(), x);
		
		it--;
		{
			auto pa = getans(x- *(it));
			pa.first++;
			pa.second += *it;
			auto pb = getans(*(it)-*(prev(it)));
			pb.first++;
			pb.second += *(prev(it));
			return max(pa, pb);
			
		}
	}
}

int main() {
	for (long long int i = 0; i < 1e6; ++i) {
		tris.push_back(i*i*i);
	}
	vector<long long int>dp(101);
	for (int i = 0; i <=100; ++i) {
		int num(i);
		int tow = 0;
		while (4 * 4 * 4<=num) {
			num -= 64; tow++;
		}
		while (3 * 3 * 3 <= num) {
			num -= 27; tow++;
		}
		while (2 * 2 * 2 <= num) {
			num -= 8; tow++;
		}
		tow += num;
		dp[i] = tow;
	}
	memo.push_back(make_pair(0, 0));
	int maxtow = 0;
	int maxpre = 0;
	for (int i = 1; i <= 100; ++i) {
		if (maxtow <= dp[i]) {
			maxtow = dp[i];
			maxpre = i;

		}
		memo.push_back(make_pair(maxtow, maxpre));
	}
	//for (int k = 101; k < 10000; ++k) {

		long long int X; cin >> X;
		auto p(getans(X));
		cout << p.first << " " << p.second << endl;
	//}
	return 0;
}