#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int MOD = 1000000007;

void solve(int test_ind){
	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n);
	for (int &i: a) scanf("%d", &i);
	for (int &i: b) scanf("%d", &i);
	for (int &i: c) scanf("%d", &i);
	vector<int> aind(n+1), bind(n+1);
	for (int i=0;i<n;++i) aind[a[i]] = i;
	for (int i=0;i<n;++i) bind[b[i]] = i;
	int ans = 1;
	vector<bool> visited(n, false);
	for (int i=0;i<n;++i){
		if (visited[i]) continue;
		if (c[i] == a[i]) {
			for (int j=b[i];j!=a[i];j=b[aind[j]]) {
				// cout << aind[j] << " to " << j << endl;
				c[aind[j]] = j;
				visited[aind[j]] = true;
			}
		} else {
			if (c[i] == b[i]) {
				for (int j=a[i];j!=b[i];j=a[bind[j]]) {
					// cout << bind[j] << " to " << j << endl;
					visited[bind[j]] = true;
					c[bind[j]] = j;
				}
			}
		}
	}
	for (int i=0;i<n;++i){
		if (c[i]) continue;
		if (a[i] == b[i]) continue;
		ans = 2 * ans % MOD;
		for (int j=b[i];j!=a[i];j=b[aind[j]]) {
			c[aind[j]] = j;
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