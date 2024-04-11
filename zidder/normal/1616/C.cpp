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
	for (int i=0;i<n;++i){
		cin >> a[i];
	}

	int ans = n-1;
	for (int i=0;i<n;++i){
		for (int j=i+1;j<n;++j){
			long double d = (a[j] - a[i]);
			d /= (j - i);
			long double aa = a[i] - i * d;
			int ans1 = n;
			for (int k=0;k<n;++k){
				if (abs(a[k] - aa) < 1e-9){
					ans1--;
				}
				aa+=d;
			}
			ans = min(ans, ans1);
		}
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