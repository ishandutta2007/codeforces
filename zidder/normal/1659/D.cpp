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
	vector<int> c(n);
	for (int &i: c) scanf("%d", &i);
	// c[0] = first zero pos
	// c[1] = a[1] + (second zero pos - 1)
	// c[2] = a[2]*2 + (third zero pos - 2)
	// c[n-1] = a[n-1] * (n - 1) + (n-th zero pos - (n - 1))
	vector<int> a(n, -1);
	int prev = 0;
	for (int i=0;i<n;++i) {
		if (a[i] == -1) {
			if (c[i] == 0) a[i] = 0;
			else a[i] = 1;
		}
		// cout << i << " " << a[i] << " " << c[i] - a[i] * i + i << endl;
		for (;prev<c[i] - a[i] * i + i;++prev) a[prev] = 1;
		if (prev == n) break;
		a[prev++] = 0;
		if (prev == n) break;
	}

	for (int i: a) printf("%d ", i);
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