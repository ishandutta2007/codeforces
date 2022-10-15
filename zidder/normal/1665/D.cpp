#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

long long ask(long long a, long long b) {
	cout << "? " << a << " " << b << endl;
	fflush(stdout);
	long long x;
	cin >> x;
	return x;
}

void solve(int test_ind){
	int k = 30;
	long long a = 0, b = (1ll << k);
	for (int i=0;i<k;++i){
		long long p = (1ll << i);
		if (b + p > 2000000000) {
			if (ask(a, b) % (2*p) != 0) {
				a += p;
				b += p;
			}
		} else 
		if ((ask(a + p, b + p) % (2 * p)) == 0) {
			a += p;
			b += p;
		}
	}
	cout << "! " << (1ll<<k) - a << endl;
	fflush(stdout);
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}