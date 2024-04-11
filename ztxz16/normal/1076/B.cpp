#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 200000;
int isNot[N + 5];
vector <int> v;
long long n;

int main() {
	for (int i = 2; i <= N; i++) {
		if (isNot[i]) {
			continue;
		}
		
		v.push_back(i);
		for (long long j = (long long)i * i; j <= N; j += i) {
			isNot[j] = 1;
		}
	}
	
	cin >> n;
	long long ans = 0;
	while (n & 1) {
		int cur = -1;
		for (int i = 0; i < v.size(); i++) {
			if (n % v[i] == 0) {
				cur = v[i];
				break;
			}
		}
		
		ans++;
		if (cur == -1) {
			n = 0;
		} else {
			n -= cur;
		}
	}
	
	ans += (n >> 1);
	cout << ans << endl;
	return 0;
}