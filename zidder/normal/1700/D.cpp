#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i=0;i<n;++i) scanf("%d", &v[i]);
	long long mx = 0;
	long long sm = 0;
	for (int i=0;i<n;++i){
		sm += v[i];
		mx = max(mx, (sm + i) / (i + 1));
	}
	int q;
	cin >> q;
	for (int i=0;i<q;++i) {
		int t;
		scanf("%d", &t);
		if (t < mx) {
			printf("-1\n");
		} else {
			printf("%lld\n", (sm + t - 1) / t);
		}
	}
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}