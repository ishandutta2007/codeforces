#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	// x not in sequence => min x that n^x > m
	int n, m;
	cin >> n >> m;
	int mx = (1<<30);
	int x = 0;
	for (int i=30;i>=0;--i){
		if ((x^n) > m) {
			mx = min(mx, x);
		}
		if (((x^(1<<i)) ^ n) > m) {
			mx = min(mx, x^(1<<i));
		}
		if ((n&(1<<i)) != (m&(1<<i)))
			x ^= (1<<i);
	}
	cout << mx << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}