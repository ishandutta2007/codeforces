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
	set<int> a, b;
	for (int i=0;i<s.size();++i){
		if (s[i] == 'A') a.insert(i);
		else b.insert(i);
	}
	if (s.back() != 'B') {
		cout << "NO" << endl;
		return;
	}
	for (int i: b) {
		auto it = a.upper_bound(i);
		if (it == a.begin()) {
			cout << "NO" << endl;
			return;
		}
		--it;
		a.erase(it);
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