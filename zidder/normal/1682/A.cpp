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
	int m = n / 2;
	int l = m, r = m;
	while (l>=0 && s[l] == s[m]) l--;
	l++;
	while (r<n && s[r] == s[m]) r++;
	cout << r - l << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}