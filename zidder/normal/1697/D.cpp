#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

char ask1(int i){
	cout << "? 1 " << i + 1 << endl;
	fflush(stdout);
	char c;
	cin >> c;
	return c;
}

int ask2(int l, int r){
	cout << "? 2 " << l + 1 << " " << r + 1 << endl;
	fflush(stdout);
	int x;
	cin >> x;
	return x;
}

void answer(string s){
	cout << "! " << s << endl;
	fflush(stdout);
	exit(0);
}

void solve(int test_ind){
	int n;
	cin >> n;
	string s = "";
	for (int i=0;i<n;++i) s += "0";
	vector<int> linds(26, -1);
	for (int i=0;i<n;++i) {
		vector<int> cur;
		for (int i: linds) if (i!=-1) cur.push_back(i);
		sort(cur.begin(), cur.end());
		if (cur.empty()) {
			s[i] = ask1(i);
			linds[s[i]-'a'] = i;
			continue;
		}
		int l = 0, r = cur.size(); // new and old/new
		while (l + 1 != r) {
			int m = (l + r) / 2;
			if (ask2(cur[m], i) == cur.size() - m) {
				// old
				l = m;
			} else {
				// new
				r = m;
			}
		}
		if (r == 1) {
			if (ask2(cur[0], i) != cur.size()) {
				s[i] = ask1(i);
				linds[s[i]-'a'] = i;
				continue;
			}
		}
		int cl = cur[l];
		for (int j=0;j<26;++j) if (cl == linds[j]) {
			s[i] = j + 'a';
		}
		linds[s[i] - 'a'] = i;
	}
	answer(s);
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}