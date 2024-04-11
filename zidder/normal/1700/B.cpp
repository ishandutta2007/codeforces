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
	string num;
	cin >> num;
	if (num[0] == '9') {
		string s = "";
		int c = 11;
		for (int i=n-1;i>=0;--i) {
			c -= num[i] - '0';
			s += '0' + c%10;
			c = c / 10 + 10;
		}
		reverse(s.begin(), s.end());
		cout << s << endl;
	} else {
		string s = "";
		for (int i=0;i<n;++i) s += '0' + ('9' - num[i]);
		cout << s << endl;
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