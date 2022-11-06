#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;


int main() {
	int N; cin >> N;
	int now = 1;
	int num = 0;
	while (1) {
		if (num == N) {
			cout << 5 << endl;
			for (int i = 0; i < 5; ++i) {
				cout << now * 5-5+i;
				if (i != 4)cout << " ";
			}
			cout << endl;
			return 0;
		}
		else if (num > N) {
			cout << 0 << endl;
			return 0;
		}
		int rest = now;
		while (1) {
			num++;
			if (rest % 5 == 0) {
				rest /= 5;
			}
			else {
				break;
			}
		}
		now++;
	}
	return 0;
}