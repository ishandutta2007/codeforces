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
	for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

	int prevodd = -1, preveven = -1;
	for (int i=0;i<n;++i){
		if (a[i] % 2){
			if (a[i] < prevodd){
				cout << "NO" << endl;
				return;
			}
			prevodd = a[i];
		} else {
			if (a[i] < preveven){
				cout << "NO" << endl;
				return;
			}
			preveven = a[i];
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