#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"

bool check(const vector<int>&as, const vector<int>&es, const int amid) {
	vector<int>lasts(as.size(), -1);
	for (int i = 0; i < amid; ++i) {
		if (es[i])lasts[es[i]-1] = i;
	}
	if (find(lasts.begin(), lasts.end(), -1) !=lasts.end())return false;
	else {
		long long int sum = 0;
		for (int i = 0; i < amid; ++i) {
			if (!es[i] || (es[i] && i != lasts[es[i] - 1])) {
				sum++;
			}
			else {
				sum -= as[es[i] - 1];
				if (sum < 0)return false;
			}
		}
		return true;
	}
}

int main() {
	int N, M; cin >> N >> M;
	vector<int>es(N);
	for (int i = 0; i < N; ++i) {
		cin >> es[i];
	}
	vector<int>as(M);
	for (int i = 0; i < M; ++i)cin >> as[i];

	int amin = 0;
	int amax = N+1;
	while (amin + 1 != amax) {
		int amid = (amin + amax) / 2;
		if (check(as,es,amid)) {
			amax = amid;
		}
		else {
			amin = amid;
		}
	}
	if (amin == N)amax = -1;
	cout << amax << endl;
	return 0;
}