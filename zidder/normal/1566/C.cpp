#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
	string s1, s2;
	cin >> n >> s1 >> s2;
	int ans = 0;
	int one = 0, zero=0;
	for (int i=0;i<n;++i){
		if (s1[i] != s2[i]){ans+=2+zero;zero=one=0;continue;}
		if (s1[i] == '1') {if (zero){ans+=2;one=zero=0;} else{one=1;}}
		if (s1[i] == '0') {if (zero){ans+=1;}else{if (one){ans+=2;one=zero=0;}else{zero=1;}}}
	}
	cout << ans + zero << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}