#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"


int main() {
	int N; cin >> N;
	vector<pair<int, int>>ps;
	ps.emplace_back(-3, -1);
	ps.emplace_back(-2, -1);
	for (int i = 0; i < N; ++i) {
		int a, b; cin >> a >> b;
		ps.emplace_back(a, b);
	}
	sort(ps.begin(), ps.end());
	auto it = ps.begin();
	auto jt = ps.begin()+1;
	vector<int>flags(N+2);
	flags[0] = true;
	flags[1] = true;

	while (it!=ps.end()||jt!=ps.end()) {
		if (jt > it)swap(jt, it);
		{
			auto now(*jt);
			while (jt != ps.end()) {
				jt++;
				if (jt == ps.end())break;
				if (now.second < jt->first&&!flags[jt-ps.begin()]) {
					flags[jt - ps.begin()] = true;
					break;
				}
			}
				
		}
	}
	if (all_of(flags.begin(), flags.end(), [](const int a) {
		return a;
	})) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}