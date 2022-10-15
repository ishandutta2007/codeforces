#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	long long n;
	cin >> n;
	if (n == 2 || n % 2 == 1) {
		cout << -1 << endl;
		return;
	}
	n /= 2;
	if (n%3 == 0) {
		cout << n / 3 << " ";
	} else if (n%3 == 2) {
		cout << 1 + n / 3 << " ";
	} else {
		cout << 2 + (n - 4) / 3 << " ";
	}
	if (n%2) {
		cout << 1 + (n - 3) / 2 << endl;
	} else {
		cout << n / 2 << endl;
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