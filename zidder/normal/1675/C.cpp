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
	int l;
	for (l=0;l<s.size();++l) {
		if (s[l] == '0') {
			break;
		}
	}
	int r;
	for (r=s.size()-1;r>=0;--r){
		if (s[r] == '1') {
			break;
		}
	}
	if (l == s.size()) {
		if (r == -1) {
			cout << s.size() << endl;
		} else {
			cout << s.size() - r << endl;
		}
		return;
	}
	if (r == -1) {
		cout << l + 1 << endl;
		return;
	}
	cout << l - r + 1 << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}