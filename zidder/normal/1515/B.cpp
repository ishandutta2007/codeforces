#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>

using namespace std;

void solve(int test_ind){
	int n;
	cin >> n;
	int s = sqrtl(n/4) - 4;
	for (int i=0;i<10;++i) {
		s++;
		if (s * 4ll * s == n) {
			cout << "YES" << endl;
			return;
		}
	}
	s = sqrtl(n/2) - 4;
	for (int i=0;i<10;++i) {
		s++;
		if (s * 2ll * s == n) {
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