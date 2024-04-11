#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	long long n, x, y;
	cin >> n >> x >> y;
	vector<long long> a(n);
	long long s = 0;
	for (int i=0;i<n;++i) scanf("%lld", &a[i]);
	for (auto i: a) s += i;
	s %= 2;
	if (s == 0){
		if (x%2 == y%2){
			cout << "Alice" << endl;
		} else {
			cout << "Bob" << endl;
		}
	} else {
		if (x%2 == y%2){
			cout << "Bob" << endl;
		} else {
			cout << "Alice" << endl;
		}
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