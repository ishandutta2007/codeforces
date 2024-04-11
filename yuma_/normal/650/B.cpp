#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;

const double eps = 1e-9, pi = acos(-1.0);

int main() {
	long long int N, A, B, T; cin >> N >> A >> B >> T;
	string st; cin >> st;
	vector<long long int>times(st.size(),1);
	for (int i = 0; i < st.size(); ++i) {
		if (st[i] == 'w') {
			times[i] += B;
		}
	}
	if (times[0] > T) {
		cout << 0 << endl;
		return 0;
	}
	else {
		T -= times[0];
		{
			if (accumulate(times.begin() + 1, times.end(), A*(N-1)) <= T) {
				cout << N << endl;
				return 0;
			}
			else {
				vector<long long int>rdp,ldp;
				{
					rdp.push_back(0);
					long long int ntime = 0;
					for (int i = 1; i < N; ++i) {
						ntime += A + times[i];
						rdp.push_back(ntime);
					}
				}
				{
					ldp.push_back(0);
					long long int ntime = 0;
					for (int i = N-1; i >=1; --i) {
						ntime += A + times[i];
						ldp.push_back(ntime);
					}
				}
				long long int ans = 1;
				for (long long int i = 0; i < N; ++i) {
					int resttime = T - rdp[i]-A*i;
					if (rdp[i] > T)break;
					auto it = upper_bound(ldp.begin(), ldp.end(), resttime);
					ans = max(ans, i+(it - ldp.begin()));
				}
				for (long long int i = 0; i < N; ++i) {
					int resttime = T - ldp[i] - A*i;
					if (ldp[i] > T)break;
					auto it = upper_bound(rdp.begin(), rdp.end(), resttime);
					ans = max(ans, i + (it - rdp.begin()));
				}
				cout << ans << endl;
			}
		}
	}
	return 0;
}