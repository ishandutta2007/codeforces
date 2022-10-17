#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string s1 = s;
	reverse(s1.begin(), s1.end());
	if (k == 0 || s == s1){
		cout << 1 << endl;
	} else {
		cout << 2 << endl;
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