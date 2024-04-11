#include "bits/stdc++.h"
using namespace std;
using ld = long double;
const ld eps = 1e-9;



int main() {
	long long int B;
	long long int D;
	long long int S; cin >> B >> D >> S;
	long long int ans = 5e18;
	for (int i = 0; i < 4; ++i) {
		
		
		for (int j = 0; j < 4; ++j) {
			long long int nextb(B);
			long long int nextd(D);
			long long int nexts(S);
			
			if (i == 0) {

			}
			else if (i == 1) {
				nextb++;
			}
			else if (i == 2) {
				nextd++;
				nextb++;
			}
			else {
				nexts++;
				nextd++;
				nextb++;
			}
			if (j == 0) {
				nexts++;
				nextd++;
				nextb++;
			}
			else if (j == 1) {
				nexts++;
				nextd++;
			}
			else if (j == 2) {
				nexts++;
			}
			long long int amax = max(nextb, nextd);
			amax = max(amax, nexts);
			long long int nans = 0;
				nans += amax - nextb;
				nans += amax - nextd;
				nans += amax - nexts;
				ans = min(ans, nans);
		}
	}
	cout << ans << endl;
	return 0;
}