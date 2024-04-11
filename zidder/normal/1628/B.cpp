#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
	cin >> n;
	vector<string> s(n);
	for (int i=0;i<n;++i){
		cin >> s[i];
	}
	for (string &si: s){
		string s1 = si;
		reverse(s1.begin(), s1.end());
		if (s1 == si){
			cout << "YES" << endl;
			return;
		}
	}
	// a X bca
	// ab X 
	multiset<string> ms;
	// first = 2
	for (string &si: s) ms.insert(si);
	for (int i=0;i<n;++i){
		ms.erase(ms.find(s[i]));
		if (s[i].size() == 2) {
			// ab + ba
			string ss = "";
			ss += s[i][1];
			ss += s[i][0];
			if (ms.find(ss) != ms.end()){
				cout << "YES" << endl;
				return;
			}
			// ab + cba
			for (int j=0;j<26;++j){
				if (ms.find((char)('a' + j) + ss) != ms.end()){
					cout << "YES" << endl;
					return;
				}
			}
		}
	}
	// last = 2
	for (string &si: s) ms.insert(si);
	for (int i=n-1;i>=0;--i){
		ms.erase(ms.find(s[i]));
		if (s[i].size() == 2) {
			// ab + ba
			string ss = "";
			ss += s[i][1];
			ss += s[i][0];
			if (ms.find(ss) != ms.end()){
				cout << "YES" << endl;
				return;
			}
			// abc + ba
			for (int j=0;j<26;++j){
				if (ms.find(ss + (char)('a' + j)) != ms.end()){
					cout << "YES" << endl;
					return;
				}
			}
		}
	}

	// first = last = 3 => abc + cba
	for (string &si: s) ms.insert(si);
	for (int i=n-1;i>=0;--i){
		ms.erase(ms.find(s[i]));
		if (s[i].size() == 3) {
			// abc + cba
			string s1 = s[i];
			reverse(s1.begin(), s1.end());
			if (ms.find(s1) != ms.end()){
				cout << "YES" << endl;
				return;
			}
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