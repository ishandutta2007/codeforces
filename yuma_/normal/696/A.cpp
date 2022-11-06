#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;

int getdepth(long long int id) {
	int num = -1;
	while (id) {
		id /= 2;
		num++;
	}
	return num;
}
int main() {
	int N; cin >> N;
	map<long long int, long long int>fees;
	while (N--) {
		int a; cin >> a;
		if (a == 1) {
			long long int b, c, d; cin >> b >> c >> d;
			int bd = getdepth(b);
			int cd = getdepth(c);
			if (bd > cd) {
				swap(b, c);
				swap(bd, cd);
			}
			long long int nb = b;
			long long int nc = c;
			for (int i = 0; i < cd - bd; ++i) {
				fees[nc] += d;
				nc /= 2;
			}
			while (nb != nc) {
				fees[nb] += d;
				fees[nc] += d;
				nb /= 2;
				nc /= 2;
			}

		}
		else {
			long long int b, c; cin >> b >> c;
			int bd = getdepth(b);
			int cd = getdepth(c);
			if (bd > cd) {
				swap(b, c);
				swap(bd, cd);
			}
			long long int fee = 0;
			long long int nb = b;
			long long int nc = c;
			for (int i = 0; i < cd - bd; ++i) {
				fee += fees[nc];
				nc /= 2;
			}
			while (nb != nc) {
				fee+=fees[nb];
				fee+=fees[nc];
				nb /= 2;
				nc /= 2;
			}
			cout << fee << endl;
		}
	}
	return 0;
}