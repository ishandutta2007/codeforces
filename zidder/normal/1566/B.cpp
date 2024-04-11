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
	bool zero=true;
	for (char i : s){
		if (i == '0') zero=false;
	}
	if (zero){cout << 0 << endl;return;}
	int lz=-1, rz=s.size()-1;
	for (int i=0;i<s.size();++i){
		if (s[i] != '0') continue;
		if (lz == -1) lz = i;
		rz = i;
	}
	bool one = true;
	for (;lz<=rz;lz++){
		if (s[lz] != '0')
			one = false;
	}
	if (one){cout << 1 << endl; return;}
	cout << 2 << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}