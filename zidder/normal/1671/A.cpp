#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	string s;
	cin >> s;
	int a=0, b=0;
	auto f = [&](int x) {
		return (x == 0 || x >= 2);
	};
	for (int i=0;i<s.size();++i){
		if (s[i] == 'b') {
			if (!f(a)) {
				cout << "NO" << endl;
				return;
			}
			a = 0;
			b++;
		}
		if (s[i] == 'a') {
			if (!f(b)) {
				cout << "NO" << endl;
				return;
			}
			b = 0;
			a++;
		}
	}

	if (!f(a)) {
		cout << "NO" << endl;
		return;
	}
	if (!f(b)) {
		cout << "NO" << endl;
		return;
	}
	cout << "YES" << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}