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
	int mn = 1000000000, mx = 0;
	for (int i=0;i<n;++i){
		int x;
		cin >> x;
		mn = min(mn, x);
		mx = max(mx, x);
	}
	cout << mx - mn << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}