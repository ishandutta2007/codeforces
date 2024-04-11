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
	long long ans = -1;
	for (int i=0;i<n;++i){
		// b[i] = 0
		long long cur = 0;
		long long prev = 0;
		for (int j=i+1;j<n;++j){
			cur += (prev / a[j] + 1);
			prev = (prev / a[j] + 1) * a[j];
		}
		prev = 0;
		for (int j=i-1;j>=0;--j){
			cur += (prev / a[j] + 1);
			prev = (prev / a[j] + 1) * a[j];
		}
		if (ans == -1) ans = cur;
		else ans = min(ans, cur);
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