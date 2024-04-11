#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

__int128 one = 1;

void solve(int test_ind){
	long long n;
	cin >> n;
	if (n % 2 == 1){
		cout << 2 << endl;
		return;
	}
	// n % k = k * (k - 1) / 2 % k
	// n = k * odd
	// n >= 2k * (2k + 1) / 2
	long long p = 1;
	while (n%2 == 0) {
		n/=2;
		p *= 2;
	}
	if (2 * one * n * one * p >= 2 * one * p * one * (2 * p + one)){
		cout << 2 * p << endl;
	} else {
		// p * p > n
		// n / p < sqrt(n)
		if (n == 1) {
			cout << -1 << endl;
		} else {
			cout << n << endl;
		}
		return;
	}
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}