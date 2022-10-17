#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
	int x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i=0;i<n;++i) scanf("%d", &a[i]);
	sort(a.begin(), a.end());
	long long s = 0;
	for (int i=0;i<n;++i) s += a[i];
	long long d = -1;
	long long ans = 0;
	for (int i=n-1;i>=0;i--){
		long long dm = (x - s) / (i + 1);
		if (x >= s && dm > d) {
			// cout << x << " " << s << " " << i + 1 << " " << dm << " " << d << endl;
			ans += (dm - d) * (i + 1);
			d = dm;
		}
		s -= a[i];
	}
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