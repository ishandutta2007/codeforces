#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i=0;i<n;++i) scanf("%d", &a[i]);
	set<int> s(a.begin(), a.end());
	for (int i=0;i<n;++i) {
		if (s.count(a[i] + k)) {
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}