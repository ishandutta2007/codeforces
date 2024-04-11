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
	vector<bool> q(26);
	for (int i=0;i<s.size();++i) q[s[i]-'a'] = true;
	for (int k=0;k<26;++k){
		if (!q[k]) continue;
		bool b = false;
		vector<int> cnts(26);
		for (int i=0;i<s.size();++i) {
			if (s[i] -'a' == k) {
				if (!b) {
					b = true;
				} else {
					for (int j=0;j<26;++j) if (q[j] && cnts[j] != 1) {
						cout << "NO" << endl;
						return;
					}
				}
				for (int j=0;j<26;++j) cnts[j] = 0;
			}
			cnts[s[i]-'a']++;
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