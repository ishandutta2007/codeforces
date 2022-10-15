#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
	long long k;
	cin >> n >> k;
	vector<int> a(n);
	for (int &i: a)	scanf("%d", &i);
	long long sm = 0;
	for (int i: a) sm += i;
	int c = 0;
	for (int i: a) if (i == 0) c++;
	int neg = 0, pos = 0;
	int other = 0;
	while (c) {
		if (abs(sm) > k) {
			if (sm > 0) {
				neg++;
				c--;
				sm -= k;
			} else {
				pos++;
				c--;
				sm += k;
			}
		} else {
			if (c > 2) {
				neg++;
				pos++;
				c -= 2;
				continue;
			}
			if (c == 1) {
				other = sm;
				c--;
				sm = 0;
				continue;
			}
			if (c == 2) {
				c = 0;
				if (sm < 0) {
					pos++;
					other = sm + k;
					sm = 0;
				} else {
					neg++;
					other = sm - k;
					sm = 0;
				}
				continue;
			}
			throw "heey";
		}
	}
	if (sm != 0) {
		cout << -1 << endl;
		return;
	}
	vector<int> all;
	for (int i=0;i<pos;++i) all.push_back(k);
	all.push_back(-other);
	for (int i=0;i<neg;++i) all.push_back(-k);
	sort(all.begin(), all.end());

	auto slv = [&](int cnt, bool mx) -> long long {
		int lind = 0, rind = all.size();
		long long mi = 0, ma = 0;
		long long x = 0;
		for (int i: a){
			if (i == 0) {
				if (mx) {
					if (cnt){
						x += all[lind++];
						cnt--;
					}
					else
						x += all[--rind];
				} else {
					if (cnt){
						x += all[--rind];
						cnt--;
					} else {
						x += all[lind++];
					}
				}
			} else {
				x += i;
			}
			mi = min(mi, x);
			ma = max(ma, x);
		}
		return ma - mi + 1;
	};

	// some positives negatives positives
	// some negatives positives negatives
	long long ans = 0;
	for (int i=0;i<all.size();++i) {
		ans = max(ans, slv(i, true));
	}
	for (int i=0;i<all.size();++i) {
		ans = max(ans, slv(i, false));
	}
	cout << ans << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}