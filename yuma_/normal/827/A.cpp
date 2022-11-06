#include "bits/stdc++.h"
using namespace std;
using ld = long double;
const ld eps = 1e-9;


int main() {
	int N; cin >> N;
	vector<int>memo(2e6,-1);
	vector<string>sts;
	int amax = 0;
	for (int i = 0; i < N; ++i) {
		string st; cin >> st;
		sts.emplace_back(st);
		int k; cin >> k;
		vector<int>v;
		for (int j = 0; j < k; ++j) {
			int a;
			scanf("%d", &a);
			a--;
			amax = max(amax, int(a +int( st.size())));
			v.emplace_back(a);
		}
		for (auto n : v) {
			if(memo[n]==-1||sts[memo[n]].size()<st.size())
			memo[n] = i;
		}

	}
	vector<int>used(false);
	string answer;
	int t = 0;
	for (int i = 0; i < amax;++i ) {
		if (memo[i] != -1&& t < sts[memo[i]].size()) {
			answer += sts[memo[i]].substr(t);
			t = sts[memo[i]].size();
		}
		{
			if (t) {
				t--;
			}
			else {
				answer += "a";
			}
		}
	}
	cout << answer << endl;
	return 0;
}