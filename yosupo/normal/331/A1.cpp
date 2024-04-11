#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>

using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	ll d[n];
	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}
	ll result = -1e17;
	int ress;
	std::vector<int> resb(n);
	for (int i = 0; i < n; i++) {
		for (int j = n-1; j > i; j--) {
			if (d[i] == d[j]) {
				std::vector<int> b;
				ll res = d[i]+d[j];
				for (int k = 0; k < i; k++) {
					b.push_back(k+1);
				}
				for (int k = i+1; k < j; k++) {
					if (d[k] < 0) {
						b.push_back(k+1);
					} else {
						res += d[k];
					}
				}
				for (int k = j+1; k < n; k++) {
					b.push_back(k+1);
				}
				if (result < res) {
					result = res;
					ress = b.size();
					copy(b.begin(), b.end(), resb.begin());
				}
			}
		}
	}
	cout << result << ' ' << ress << endl;
	for (int i = 0; i < ress; i++) {
		cout << resb[i];
		if (i == ress-1) {
			cout << endl;
		} else {
			cout << ' ';
		}
	}
	return 0;
}