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
	vector<int> v(n);
	for (int i=0;i<n;++i) scanf("%d", &v[i]);
	bool plus = true;
	for (int i=0;i<n;++i){
		if (plus) {
			v[i]++;
			if (i + 1 < n && v[i+1] > v[i]) {
				plus = false;
			}
		} else {
			if (v[i] - v[i-1] == 1) continue;
			if (v[i] - v[i-1] == 2) {
				v[i]--;
			}
		}
	}	
	for (int i=1;i<n;++i){
		if (v[i] - 1 != v[i-1]) {
			cout << "NO" << endl;
			return;
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