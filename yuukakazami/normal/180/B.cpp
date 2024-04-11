#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;

int main() {
	int b, d;
	cin >> b >> d;
	int tp = -1, mxL = 0;
	int x = d;
	bool can[20] = { };
	fill(can, can + 20, true);
	bool bad = false;
	for (int i = 2; i <= x; i++) {
		bool my[20] = { };
		int p = i, c = 0, pc = 1;
		while (x % i == 0) {
			x /= i;
			++c;
			pc *= i;
		}
		if (!c)
			continue;
		//check my type!
		int r = b % pc, L = -1;
		for (int i = 1; i <= 100; ++i) {
			if (r == 0) {
				L = i;
				break;
			}
			r = r * b % pc;
		}
		if (L != -1) {
			my[2] = true;
//			goto end;
		}
		//check 3
		if (b % pc == 1) { //3 type!
			my[3] = true;
		}
		//check 11
		if (b % pc == pc - 1) { //11 type
			my[11] = true;
		}
		//type 7 :(
//		tp = 7;
//		memset(can, 0, sizeof can);
		if (count(my, my + 20, true) == 0) {
			bad = true;
			break;
		}
//		break;

		end: {
			mxL = max(mxL, L);
			for (int i = 0; i < 20; ++i) {
				can[i] = can[i] && my[i];
			}
		}
	}
	if (bad) {
		puts("7-type");
		return 0;
	}
	tp = 6;
	for (int i = 0; i < 20; ++i) {
		if (can[i]) {
			tp = i;
			break;
		}
	}
	cout << tp << "-" << "type" << endl;
	if (tp == 2) {
		cout << mxL << endl;
	}
	return 0;
}