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
	vector<int> a(n), b(n);
	for (int i=0;i<n;++i){
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b.begin(), b.end());
	if (a == b) {
		cout << 0 << endl;
		return;
	}

	if (a.back() < 0) {
		cout << -1 << endl;
		return;
	}
	if (a[n-2] > a[n-1]) {
		cout << -1 << endl;
		return;
	}
	printf("%d\n", n-2);
	for (int i=n-3;i>=0;--i){
		printf("%d %d %d\n", i+1, i+2, n);
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