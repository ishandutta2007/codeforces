#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int &i: v) scanf("%d", &i);
	long long s = 0;
	for (int i: v) s += i;
	// n - i - v[i] - p
	for (int i=0;i<n;++i) v[i] = (n - i - 1) - v[i];
	sort(v.begin(), v.end());
	long long ans = s;
	for (int i=0;i<k;++i) ans += v[i];
	ans -= k * 1ll * (k - 1) / 2;
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