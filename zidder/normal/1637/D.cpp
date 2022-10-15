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
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i=0;i<n;++i)
		cin>>b[i];
	

	// (n-1) * (sum ai^2) + ((sum ai)^2 - sum ai^2)
	// ((2n-3) * (sum ai^2) + (sum ai)^2)
	long long ans = 0;
	for (int i: a) ans += (n - 2) * i * i;
	for (int i: b) ans += (n - 2) * i * i;
	// cout << ans << endl;
	// get sm/2
	vector<int> d(n);
	int asum = 0;
	int sm = 0;
	for (int i=0;i<n;++i) {
		d[i] = abs(a[i] - b[i]);
		asum += min(a[i], b[i]);
		sm += abs(a[i] - b[i]);
	}

	auto knapsack = [&](){
		vector<bool> v(10001);
		v[0] = 1;
		for (int i=0;i<n;++i){
			// d[i]
			for (int j = 10000 - d[i];j>=0;--j){
				if (v[j]){
					v[j + d[i]] = 1;
				}
			}
		}
		int ans = 0;
		for (int i=0;i<10001;++i){
			if (v[i]){
				// cout << "i: " << i << " " << sm << endl;
				if (abs(ans - sm / 2) > abs(i - sm / 2))
					ans = i;
			}
		}
		return ans;
	};

	auto sq = [&](int x)->long long{
		return x * 1ll * x;
	};

	int dt = knapsack();
	// cout << dt << endl;
	ans += sq(asum + dt);
	ans += sq(asum + sm - dt);
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