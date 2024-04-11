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
	for (int i=0;i<n;++i) cin >> a[i];
	vector<bool> ok(n, false);
	while (true) {
		int mx = 0, c = 0, mi = 0;
		for (int i=0;i<n;++i){
			if (ok[i]) continue;
			if (a[i] > mx){
				mx = a[i];
				mi = i;
			}
			c++;
		}
		if (c == 0) break;
		if (mx > c){
			a[mi] /= 2;
		}
		if (mx < c){
			cout << "NO" << endl;
			return;
		}
		if (mx == c){
			ok[mi] = true;
		}
	}
	cout << "YES" << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}