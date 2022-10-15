#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	vector<int> a(3);
	cin >> a[0] >> a[1] >> a[2];
	sort(a.begin(), a.end());
	if (a[2] == a[1] + a[0]) cout << "YES" << endl;
	else {
		if (a[1] == a[2] && a[0] % 2 == 0 || a[0] == a[1] && a[2] % 2 == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
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