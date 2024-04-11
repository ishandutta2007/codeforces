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
	int r=0, g=0, b=0;
	for (int i=0;i<6;++i){
		if (s[i] == 'r'){
			r++;
		}
		if (s[i] == 'g') g++;
		if (s[i] == 'b') b++;
		if (s[i] == 'R') {
			if (r) r--;
			else {
				cout << "NO" << endl;
				return;
			}
		}
		if (s[i] == 'B') {
			if (b) b--;
			else {
				cout << "NO" << endl;
				return;
			}
		}
		if (s[i] == 'G') {
			if (g) g--;
			else {
				cout << "NO" << endl;
				return;
			}
		}
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