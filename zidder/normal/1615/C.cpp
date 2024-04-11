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
	string s, b;
	cin >> s;
	cin >> b;
	int s1=0, b1=0;
	for (int i=0;i<n;++i){
		if(s[i]=='1')s1++;
		if(b[i]=='1')b1++;
	}
	int m = -1;
	if (s1 == b1){
		int d = 0;
		for (int i=0;i<n;++i){
			if (s[i] == '1' && b[i] == '0')d++;
		}
		m = d * 2;
	}
	if (s1 > 0 && b1 > 0 && s1 - 1 == (n - b1)){
		int d = 0;
		bool c = false;
		for (int i=0;i<n;++i){
			if (s[i] == '1' && b[i] == '1')c=true;
			if (s[i] == '0' && b[i] == '0')d++;
			if (s[i] == '1' && b[i] == '1')d++;
		}
		if (c){
			if (m == -1 || m > d)m = d;
		}
	}
	cout << m << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}