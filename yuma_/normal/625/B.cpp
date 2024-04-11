#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;


int main() {
	/*long long int N; cin >> N;
	long long int A, B, C; cin >> A >> B >> C;
	if (A <= (B - C)) {
		long long int ans = N / A;
		cout << ans << endl;
	}
	else {
		long long int num = (N - B) / (B - C);
		long long int rest = N - num*(B - C);
		long long int ans(num);
		while (rest >= B) {
			ans++;
			rest -= (B - C);
		}
		ans += rest / A;
		cout << ans << endl;
	}
	return 0;*/
	string from;
	string to;
	cin >> from >> to;
	int ans = 0;
	while (1) {
		int a=from.find(to);
		if (a == -1)break;
		from = from.substr(a + to.size(), from.size() - (a + to.size()));
		ans++;
	}
	cout << ans << endl;
	return 0;
}