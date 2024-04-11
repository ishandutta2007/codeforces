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
	if (s.size() == 2) {
		cout << s[1] << endl;
	} else {
		char c = '9';
		for (char ci: s) c = min(c, ci);
		cout << c << endl;
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