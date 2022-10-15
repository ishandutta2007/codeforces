#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	vector<int> d(n+1);
	for (int i=0;i<n;++i){
		d[i+1] = d[i] + (s[i] == '1');
	}
	long long x = d[n];
	if ((x * m) % n != 0) {
		cout << -1 << endl;
		return;
	}
	int y = x * m / n;
	for (int i=m;i<=n;++i){
		if (d[i] - d[i-m] == y){
			cout << 1 << endl << i-m+1 << " " << i << endl;
			return;
		}
	}
	// 0 to n%m  + last m - i
	for (int j=0;j<n-m;++j){
		for (int i=1;i<m;++i){
			if (d[i] - d[0] + d[n-j] - d[n-j-m+i] == y) {
				cout << 2 << endl << 1 << " " << i << endl << n-j-m+i+1 << " " << n-j << endl;
				return;
			}
			if (d[n-j] - d[n-j-i] + d[m-i] - d[0] == y) {
				cout << 2 << endl << 1 << " " << m - i << endl << n-j - i + 1 << " " << n-j << endl;
				return;
			}
		}
	}
	throw "error";
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}