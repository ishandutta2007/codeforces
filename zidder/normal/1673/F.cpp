#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, k;
	cin >> n >> k;
	vector<int> p = {
		1,
		2,
		1,
		4,
		1,
		2,
		1,
		8,
		1,
		2,
		1,
		4,
		1,
		2,
		1,
		16,
		1,
		2,
		1,
		4,
		1,
		2,
		1,
		8,
		1,
		2,
		1,
		4,
		1,
		2,
		1,
	};
	vector<int> a(32);
	for (int i=0;i<31;++i) {
		a[i+1] = a[i] ^ p[i];
	}
	auto f = [&](int i){
		return 16 * (i&16) + 8 * (i&8) + 4 * (i&4) + 2 * (i&2) + 1 * (i&1);
	};
	int s = 0;
	for (int i=0;i<n;++i){
		for (int j=0;j<n-1;++j){
			cout << f(p[j]) << " ";
			s += f(p[j]);
		}
		cout << endl;
	}
	for (int i=0;i<n-1;++i){
		for (int j=0;j<n;++j){
			cout << f(p[i]) * 2 << " ";
			s += f(p[i]) * 2;
		}
		cout << endl;
	}

	auto print = [&](int A){
		for (int i=0;i<=31;++i){
			for (int j=0;j<=31;++j){
				int a1 = f(a[i]);
				int a2 = f(a[j]) * 2;
				if ((a1 ^ a2) == A) {
					cout << j + 1 << " " << i + 1 << endl;
					fflush(stdout);
					return;
				}
			}
		}
	};

	fflush(stdout);
	int prv = 0;
	for (int i=0;i<k;++i){
		int d;
		cin >> d;
		d ^= prv;
		print(d);
		prv = d;
	}
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}