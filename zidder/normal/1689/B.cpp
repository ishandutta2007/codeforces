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
	vector<int> p(n), q(n);
	for (int &i: p) scanf("%d", &i);
	if (n == 1) {
		cout << -1 << endl;
		return;
	}
	set<int> nums;
	for (int i=1;i<=n;++i) nums.insert(i);
	for (int i=2;i<n;++i){
		auto it = nums.begin();
		if (*it == p[i-2]) it++;
		q[i-2] = *it;
		nums.erase(it);
	}
	int a = *nums.begin(), b = *nums.rbegin();
	if (a == p[n-2] || b == p[n-1]) {
		q[n-2] = b;
		q[n-1] = a;
	} else {
		q[n-1] = b;
		q[n-2] = a;
	}
	for (int i: q) printf("%d ", i);
	cout << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}