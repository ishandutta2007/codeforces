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
	vector<int> k(n+1), h(n+1);
	for (int i=1;i<=n;++i) cin >> k[i];
	for (int i=1;i<=n;++i) cin >> h[i];
	// h[i] - k[i] <= h[j] - k[j]
	for (int i=n;i>=1;--i){
		for (int j=i;j>=1;--j){
			if (h[j] - k[j] < h[i] - k[i]){
				h[j] = h[i] - k[i] + k[j];
			}
		}
	}
	// for (int hi:h) cout << hi << " ";
	// cout << endl;
	long long m = 0;
	long long ph = 0;
	for (int i=1;i<=n;++i){
		long long dk = k[i] - k[i-1];
		if (dk >= h[i]){
			m += h[i] * 1ll * (h[i] + 1) / 2;
			ph = h[i];
		} else {
			m += dk * 1ll * (dk + 1) / 2 + ph * dk;
			ph += dk;
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