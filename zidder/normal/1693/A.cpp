#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	// a1 a2-1 ... an-1 -s+n-1
	// a2 >= -a1
	// a3 >= -a2
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &i: a) scanf("%d", &i);
	if (n == 1) {
		if (a[0] == 0) {
			cout << "Yes" << endl;
		}
		else {
			cout << "No" << endl;
		}
		return;
	}
	long long d = 0;
	for (int i=0;i<n;++i){
		if (i == 0) {
			if (a[i] < 0) {
				cout << "No" << endl;
				return;
			}
			d = a[i];
			continue;
		}
		if (d == 0) {
			if (a[i] != 0) {
				cout << "No" << endl;
				return;
			}
			continue;
		}
		d += a[i];
		if (d < 0) {
			cout << "No" << endl;
			return;
		}
		if (i + 1 == n){
			if (d != 0) {
				cout << "No" << endl;
				return;
			}
		}
	}
	cout << "Yes" << endl;
	return;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}