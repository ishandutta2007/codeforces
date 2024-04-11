#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
typedef long long int64;
int S = int(1e6);

int main() {
	int n;
	cin >> n;
	vector<bool> have(S + 1, false);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		have[x] = true;
	}
	int needPair = 0;
	vector<int> y;
	for (int i = 1; i < S + 1 - i; ++i) {
		int j = S + 1 - i;
		if (have[i] && have[j])
			++needPair;
		else if (have[i]) {
			y.push_back(j);
		} else if (have[j]) {
			y.push_back(i);
		}
	}

	for (int i = 1; i < S + 1 - i; ++i) {
		int j = S + 1 - i;
		if (!have[i] && !have[j] && needPair > 0) {
			--needPair;
			y.push_back(i), y.push_back(j);
		}
	}

	cout << y.size() << endl;
	for (int i = 0; i < y.size(); ++i) {
		cout << y[i] << " ";
	}
	cout << endl;
}