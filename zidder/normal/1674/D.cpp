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
	for (int i=n-1;i>=0;--i) {
		if (i) {
			if (a[i] < a[i-1]) swap(a[i], a[i-1]);
			i--;
		}
	}
	for (int i=1;i<n;++i) if (a[i] < a[i-1]) {
		cout << "NO" << endl;
		return;
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