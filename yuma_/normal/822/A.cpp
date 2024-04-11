#include "bits/stdc++.h"
using namespace std;

int main() {
	long long int A, B; cin >> A >> B;
	if (A > B)swap(A, B);
	assert(A <= 12);
	long long int ans = 1;
	for (int i = 1; i <= A; ++i) {
		ans *= i;
	}
	cout << ans << endl;
	return 0;
}