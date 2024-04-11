#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;


int main() {
	
	long long int B, Q, L, M; cin >> B >> Q >> L >> M;
	vector<long long int>as;
	for (int i = 0; i < M; ++i) {
		int a; cin >> a;
		as.emplace_back(a);
	}
	sort(as.begin(), as.end());
	{
		long long int now(B);
		int ans = 0;
		int rest = 1e3;
		while (abs(now) <= L) {
			rest--;
			if (!rest)break;
			if (find(as.begin(), as.end(), now)==as.end()) {
				ans++;
			}
			now *= Q;
		}
		if (ans > 1e2)cout << "inf" << endl;
		else cout << ans << endl;
	}
	return 0;
}