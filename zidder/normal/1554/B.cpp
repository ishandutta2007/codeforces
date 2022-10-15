#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	// (n-k-1) * n
	// n * (n-1) - k * n = n * n - (k + 1) * n
	int n;
	int k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i=0;i<n;++i) scanf("%d", &a[i]);
	long long m = 2 - (a[0] | a[1]) * k;
	for (int i=0;i<min(n, k+5);++i){
		for (int j=0;j<i;++j){
			m = max(m, ((n-i) * 1ll * (n-j)) - (a[n-i-1] | a[n-j-1]) * k);
		}
	}
	cout << m << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}