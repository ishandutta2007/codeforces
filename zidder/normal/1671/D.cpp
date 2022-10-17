#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i=0;i<n;++i) scanf("%d", &a[i]);
	int mn=a[0], mx=a[0];
	long long s = 0;
	for (int i=0;i<n;++i){
		mn = min(mn, a[i]);
		mx = max(mx, a[i]);
		if (i) {
			s += abs(a[i] - a[i-1]);
		}
	}

	s += min(min((mn - 1) * 2, (a[0] - 1)), (a[n-1]-1));
	if (mx < x) {
		s += min(min((x - mx) * 2, (x - a[0])), (x-a[n-1]));
	}
	cout << s << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}