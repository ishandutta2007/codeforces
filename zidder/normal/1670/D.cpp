#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
using namespace std;

void solve(int test_ind){
	// a, b, c
	// 2(a * b + b * c + a * c) >= n
	int n;
	cin >> n;
	long long a = sqrtl(n / 6);
	while (true) {
		if (6 * a * a >= n) {
			cout << 3 * a << endl;
			return;
		}
		if (2 * a * a + 4 * a * (a + 1) >= n) {
			cout << 3 * a + 1 << endl;
			return;
		}
		if (4 * a * (a + 1) + 2 * (a + 1) * (a + 1) >= n) {
			cout << 3 * a + 2 << endl;
			return;
		}
		a++;
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