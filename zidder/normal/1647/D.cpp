#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

bool is_nprime(int x){
	for (int y = 2;y*1ll*y<=x;++y){
		if (x % y == 0){
			return true;
		}
	}
	return false;
}

bool is_d(int x, int d){
	for (int y = 2;y*1ll*y<=x;++y){
		if (x % y == 0){
			if (y % d != 0 || (x / y) % d != 0){
				return false;
			}
		}
	}
	return true;
}

void solve(int test_ind){
	int x, d;
	cin >> x >> d;
	int c = 0;
	while (x % d == 0){
		x /= d;
		c++;
	}
	if (c < 2) {
		cout << "NO" << endl;
		return;
	}
	if (!is_nprime(x)) {
		if (c > 2){
			if (c > 3 && is_nprime(d)){
				cout << "YES" << endl;
				return;
			}			
			// d, d, d * p
			// if any divisor of d is divisible by d / p, then no
			if (is_nprime(d)){
				if (d % x != 0 || !is_d(d, d / x)){
					cout << "YES" << endl;
					return;
				}
			}
		}
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		return;
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