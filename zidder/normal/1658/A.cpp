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
	string s;
	cin >> s;
	int last = -5;
	int ans = 0;
	for (int i=0;i<n;++i){
		if (s[i] == '0') {
			if (i - last < 3) {
				ans += 3 - (i - last);
			}
			last = i;
		}
	}
	cout << ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}