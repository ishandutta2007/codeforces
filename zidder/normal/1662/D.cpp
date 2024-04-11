#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	string s1, s2;
	cin >> s1 >> s2;
	int bc1 = 0, bc2 = 0;
	vector<char> ss1, ss2;
	auto check = [&](vector<char> &ss) -> bool {
		int l1 = ss.size();
		if (l1 > 1) {
			if (ss[l1-1] == ss[l1-2]) {
				ss.pop_back();
				ss.pop_back();
				return true;
			}
		}
		return false;
	};
	for (char c: s1) {
		if (c == 'B') {
			bc1++;
		}
		else ss1.push_back(c);
		while (check(ss1));
	}
	for (char c: s2) {
		if (c == 'B') {
			bc2++;
		}
		else ss2.push_back(c);
		while (check(ss2));
	}
	if (ss1 == ss2 && bc1 % 2 == bc2 % 2) {
		cout << "YES" << endl;
		return;
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