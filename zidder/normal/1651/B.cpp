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

	// 2(a - b) < a + b
	// 2a - 2b < a + b
	// a < 3b
	vector<long long> a(n);
	a[0] = 1;
	const int INF = 1000000000;
	bool ok = true;
	for (int i=1;i<n;++i){
		a[i] = a[i-1] * 3;
		if (a[i] > INF) {
			ok = false;
			break;
		}
	}
	if (ok){
		cout << "YES" << endl;
		for (int i: a){
			cout << i << " ";
		}
		cout << endl;
	} else {
		cout << "NO" << endl;
	}
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}