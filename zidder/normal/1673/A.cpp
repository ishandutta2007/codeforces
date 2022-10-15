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
	int ans = 0;
	for (int i=0;i<s.size();++i) ans += s[i] - 'a' + 1;
	if (s.size() % 2) {
		ans -= 2 * (min(s[0], s.back()) - 'a' + 1);
	}
	if (ans < 0) {
		cout << "Bob " << -ans << endl;
	} else {
		cout << "Alice " << ans << endl;
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