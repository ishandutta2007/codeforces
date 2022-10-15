#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	int cnt = 0;
	for (int i=2;i<s.size();++i){
		if (s[i-2] == 'a' && s[i-1] == 'b' && s[i] == 'c')cnt++;
	}
	for (int i=0;i<q;++i){
		int pos;
		char c;
		cin >> pos >> c;
		pos--;
		for (int j=max(pos, 2);j<=min(pos+2, (int)s.size());++j){
			if (s[j-2] == 'a' && s[j-1] == 'b' && s[j] == 'c')cnt--;
		}
		s[pos] = c;
		for (int j=max(pos, 2);j<=min(pos+2, (int)s.size());++j){
			if (s[j-2] == 'a' && s[j-1] == 'b' && s[j] == 'c')cnt++;
		}
		cout << cnt << endl;
	}
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}