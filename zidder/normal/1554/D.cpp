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
	if (n == 1) {
		cout << "a" << endl;
		return;
	}
	// aaaa b aaaaa
	string s = "";
	for (int i=0;i<n/2-1;++i) s += "a";
	s += "b";
	if (n%2) s += "c";
	for (int i=n/2+(n%2);i<n;++i) s += "a";
	cout << s << endl; 
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}