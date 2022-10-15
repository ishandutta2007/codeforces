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
	for (int i=0;i<n;++i) scanf("%d", &a[i]);
	long long x;
	cin >> x;
	// da[i] = pa[i] - i * x
	// da[i] - da[j] = sum[j+1:i] - (i-j) * x >= 0
	vector<long long> da(n+1);
	for (int i=0;i<n;++i){
		da[i+1] = da[i];
		da[i+1] += a[i];
		da[i+1] -= x;
	}

	// for (int i: da) cout << i << " ";
	// cout << endl;
	// 0 10 1 10 1 10 1 10 1
	// 0 10 1 10 x 10 1 10 1

	// 0 10 11 10

	long long prv1 = da[0], prv2 = da[1];
	int ans = 0;
	for (int i=2;i<=n;++i){
		if (da[i] >= prv1){
			prv1 = max(prv1, prv2);
			prv2 = da[i];
		} else {
			ans++;
			prv1 = da[i];
			i++;
			if (i<=n)prv2 = da[i];
		}
	}
	cout << n - ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}