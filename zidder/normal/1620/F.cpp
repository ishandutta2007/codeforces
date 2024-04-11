#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>
#include <cassert>
using namespace std;

template<typename T>
class vec: public vector<T> {
	public: int delta;
	vec(int n): vector<T>(2 * n + 1), delta(n) {}
	vec(int n, T x): vector<T>(2 * n + 1, x), delta(n) {}
	T &operator[](int i) { return vector<T>::operator[](i + delta); }
};

void solve(int test_ind){
	int n;
	scanf("%d", &n);
	vector<int> a(n), p(n);
	for (int i=0;i<n;++i) scanf("%d", &a[i]);
	if (n == 1){
		printf("YES\n%d\n", a[0]);
		return;
	}
	// max -> second max mapping
	// if not possible -> MAX
	// is possible without second -> MIN
	// use sets
	const int MAX = 1000000000;
	const int MIN = -MAX;


	// vec<int> max_to_second(n, MAX);

	vector<vector<int> > dp(n, vector<int>(4, MAX));
	vector<vector<int> > prev(n, vector<int>(4, -1));
	dp[0][0] = MIN;
	dp[0][2] = MIN;

	// a[i] is either max or second
	for (int i=1;i<n;++i){
		// -a[i] after max
		for (int ind2 = 0;ind2<4;++ind2){
			int cur = a[i];
			bool first = true;
			if (ind2 < 2) cur = -a[i];
			if (ind2 & 1) first = false;
			int ind = -1;
			for (int ind1 = 0;ind1<4;++ind1){
				int prvmx, prvsec;
				if (ind1 == 0){
					prvmx = -a[i-1];
					prvsec = dp[i-1][0];
				} else if (ind1 == 1){
					prvmx = dp[i-1][1];
					prvsec = -a[i-1];
				} else if (ind1 == 2){
					prvmx = a[i-1];
					prvsec = dp[i-1][2];
				} else {
					prvmx = dp[i-1][3];
					prvsec = a[i-1];
				}
				if (first){
					if (prvmx < cur){
						if (prvsec < dp[i][ind2]){
							dp[i][ind2] = prvsec;
							ind = ind1;
						}
					}
				} else {
					if (prvmx > cur && prvsec < cur){
						if (dp[i][ind2] > prvmx){
							dp[i][ind2] = prvmx;
							ind = ind1;
						}
					}
				}
			}
			if (ind != -1) prev[i][ind2] = ind;
		}

		// for (int j=-n;j<=n;++j){
		// 	if (j < -a[i]){
		// 		if (max_to_second[j] != MAX){
		// 			mn = min(mn, max_to_second[j]);
		// 			max_to_second[j] = MAX;
		// 		}
		// 	} else if (j == -a[i]){
		// 		if (i == 0) mn = MIN;
		// 		max_to_second[j] = mn;
		// 	} else if (j < a[i]) {
		// 		mn = min(mn, max_to_second[j]);
		// 		if (max_to_second[j] > -a[i]){
		// 			max_to_second[j] = MAX;
		// 		} else {
		// 			max_to_second[j] = -a[i];
		// 		}
		// 	} else if (j == a[i]){
		// 		max_to_second[j] = mn;
		// 	} else {
		// 		if (max_to_second[j] > -a[i]){
		// 			if (max_to_second[j] > a[i]) max_to_second[j] = MAX;
		// 			else max_to_second[j] = a[i];
		// 		} else {
		// 			max_to_second[j] = -a[i];
		// 		}
		// 	}
		// }
	}

	int ind1 = -1;
	for (int ind=0;ind<4;++ind){
		if (prev[n-1][ind] != -1){
			ind1 = ind;
			break;
		}
	}
	if (ind1 == -1){
		printf("NO\n");
		return;
	}

	for (int i=n-1;i>=0;--i){
		p[i] = ind1<2?-a[i]:a[i];
		ind1 = prev[i][ind1];
	}

	printf("YES\n");
	for (int i=0;i<n;++i){
		printf("%d ", p[i]);
	}
	printf("\n");
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}