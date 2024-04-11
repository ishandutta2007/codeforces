#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


#define SS ;
typedef long long ll;
using namespace std;
int n, d;

int main() {
	cin >> n >> d;
	vector<int> a(n);
	for (size_t i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int ans = n;
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n - i; j++) {
			if (a[j + i] - a[j] <= d)
				ans = n - i - 1;
		}
	}
	cout << ans;
	SS;
	return 0;
}