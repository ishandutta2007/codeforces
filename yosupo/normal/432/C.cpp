#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <algorithm>
#include <cassert>

using namespace std;
const int MN = 101000;

int main() {
	int n;
	cin >> n;
	int d[MN] = {}, rd[MN] = {};
	for (int i = 0; i < n; i++) {
		int v;
		scanf("%d", &v); v--;
		d[i] = v;
		rd[v] = i;
	}


	bool prime[MN] = {};
	vector<int> primes;
	for (int i = 2; i < MN; i++) {
		if (!prime[i]) {
			primes.push_back(i-1);
			for (int j = i+i; j < MN; j += i) {
				prime[j] = true;
			}
		}
	}
	reverse(primes.begin(), primes.end());
	vector<pair<int, int>> res;
	for (int i = 0; i < n; i++) {
		int index = rd[i];
		while (i < index) {
			int j = lower_bound(primes.begin(), primes.end(), index-i, greater<int>()) - primes.begin();
			int k = index - primes[j];
			res.push_back(pair<int, int>(k+1, index+1));
			swap(rd[d[index]], rd[d[k]]);
			swap(d[index], d[k]);
			index = k;
		}
	}

	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		printf("%d %d\n", res[i].first, res[i].second);
	}
}