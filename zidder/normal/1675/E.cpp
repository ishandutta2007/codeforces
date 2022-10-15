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
	vector<int> v(26);
	for (int i=0;i<26;++i) v[i] = i;
	for (int i=0;i<s.size();++i) {
		int d = s[i] - 'a';
		while (v[d] && k) {
			int vd = v[d];
			for (int j=0;j<26;++j) {
				if (v[j] != vd) continue;
				v[j] = v[vd-1];
			}
			k--;
		}
	}
	for (int i=0;i<s.size();++i) s[i] = 'a' + v[s[i]-'a'];
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