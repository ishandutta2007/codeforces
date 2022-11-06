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

vector<int>primes;
void getprimes(const int amax) {
	static bool flag = false;
	if (flag)return;
	vector<int>sos;
	sos = vector<int>( amax + 1,true);
	sos[0] = false; sos[1] = false;
	for (int i = 2; i <= amax; ++i) {
		if (sos[i]) {
			for (int j = 2*i; j <= amax; j += i)sos[j] = false;
		}
	}
	for (int i = 0; i <= amax; ++i) {
		if (sos[i]) {
			primes.push_back(i);
		}
	}
	flag = true;
}
map<long long int, int> kmp;
map<long long int, int>soinnsuu2(long long int a) {
	getprimes(1e6+2);
	map<long long int, int>ans;
	for (auto i : primes) {
		if (i*i > a)break;
		while (a%i == 0) {
			ans[i]++;
			a /= i;
		}
	}
	if (a != 1)ans[a]++;
	return ans;
}
map<long long int, int>soinnsuu(long long int a) {
	getprimes(1e6 + 2);
	map<long long int, int>ans;
	for (auto km : kmp) {
		int i = km.first;
		if (i> a)break;
		while (a%i == 0) {
			ans[i]++;
			a /= i;
		}
	}
	if (a != 1)ans[a]++;
	return ans;
}
int main() {
	int N, K; cin >> N >> K;
	kmp=soinnsuu2(K);
	vector<int>as;
	map<long long int, int>sos;
	for (int i = 0; i < N; ++i) {
		int a; scanf("%d", &a);
		as.push_back(a);
		
	}
	sort(as.begin(), as.end());
	as.erase(unique(as.begin(), as.end()), as.end());
	for (auto a : as) {
		auto mp(soinnsuu(a));
		for (auto m : mp) {
			if (kmp.find(m.first) != kmp.end())
				sos[m.first] = max(sos[m.first], m.second);
		}
	}
	bool ok = true;
	for (auto km : kmp) {
		if (sos[km.first] < km.second)ok = false;
	}
	if (ok)cout << "Yes" << endl;
	else cout << "No" << endl;
	
	return 0;
}