#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, k;
	string s;
	cin >> n >> k;
	int kk = k;
	cin >> s;
	vector<int> f(n);
	for (int i=0;i<n-1;++i){
		if (k && (s[i] == '1') == (kk%2)) {
			f[i] = 1;
			k--;
		}
	}

	auto other = [&](char a) -> char {
		if (a == '1') return '0';
		else return '1';
	};

	auto poww = [&](char a, int p) -> char {
		if (p % 2) return other(a);
		return a;
	};

	f[n-1] = k;
	for (int i=0;i<n;++i){
		s[i] = poww(s[i], kk - f[i]);
	}

	cout << s << endl;
	for (int i: f) cout << i << " ";
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