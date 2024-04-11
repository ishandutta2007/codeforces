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
	vector<int> a(n);
	for (int &i: a) scanf("%d", &i);
	for (int i=n-1;i>=1;--i) a[i] -= a[i-1];
	// a[0]++
	// a[0]-- a[i+1]++
	// a[i+1]--
	long long ans = 0;
	long long a0 = a[0];
	for (int i=1;i<n;++i) {
		if (a[i] > 0) {
			ans += a[i];
		} else if (a[i] < 0) {
			a0 += a[i];
			ans -= a[i];
		}
	}
	ans += abs(a0);
	cout << ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}