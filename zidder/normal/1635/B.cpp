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
	for (int i=0;i<n;++i) scanf("%d", &a[i]);
	vector<bool> lm(n, false);
	for (int i=1;i<n-1;++i) {
		lm[i] = (a[i] > a[i-1]) && (a[i] > a[i+1]);
	}
	int c = 0;
	for (int i=1;i<n-1;++i){
		if (lm[i] && i + 2 < n && lm[i+2]) {
			a[i + 1] = max(a[i+2], a[i]);
			i += 2;
			c++;
			continue;
		}
		if (lm[i]) {
			a[i] = max(a[i+1], a[i-1]);
			c++;
		}
	}
	printf("%d\n", c);
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