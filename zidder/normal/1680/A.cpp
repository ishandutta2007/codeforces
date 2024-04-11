#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int l1, r1, l2, r2;
	cin >> l1 >> r1 >> l2 >> r2;
	int l = max(l1, l2);
	int r = min(r1, r2);
	if (r >= l) {
		cout << l << endl;
	} else {
		cout << l1 + l2 << endl;
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