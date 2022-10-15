#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int a, b, ab, ba;
	cin >> a >> b >> ab >> ba;
	string s;
	cin >> s;
	int c[2] = {0, 0};
	for (int i=0;i<s.size();++i){
		c[s[i]-'A']++;
	}
	if (c[0] != a + ab + ba || c[1] != b + ab + ba) {
		cout << "NO" << endl;
		return;
	}
	vector<int> aba, abab, baba; // aba = bab
	for (int i=0;i<s.size();++i){
		int i1 = i;
		while (i + 1 < s.size() && s[i] != s[i+1]) i++;
		if (i1 % 2 == i % 2){
			aba.push_back((i - i1 + 1) / 2);
		} else {
			if (s[i1] == 'A') abab.push_back((i - i1 + 1) / 2);
			else baba.push_back((i - i1 + 1) / 2);
		}
	}
	sort(abab.begin(), abab.end());
	sort(baba.begin(), baba.end());
	reverse(abab.begin(), abab.end());
	reverse(baba.begin(), baba.end());
	// cout << aba.size() << " " << abab.size() << " " << baba.size() << endl;
	while (ab && !abab.empty()) {
		if (abab.back() > ab) {
			abab[abab.size() - 1] -= ab;
			ab = 0;
			break;
		}
		ab -= abab.back();
		abab.pop_back();
	}

	while (ba && !baba.empty()) {
		if (baba.back() > ba) {
			baba[baba.size() - 1] -= ba;
			ba = 0;
			break;
		}
		ba -= baba.back();
		baba.pop_back();
	}

	if (ab == 0) {
		int ss = 0;
		for (int i: abab) ss += i - 1;
		for (int i: baba) ss += i;
		for (int i: aba) ss += i;
		if (ss >= ba) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		return;
	}
	if (ba == 0) {
		int ss = 0;
		for (int i: abab) ss += i;
		for (int i: baba) ss += i - 1;
		for (int i: aba) ss += i;
		if (ss >= ab) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		return;
	}

	int ss = 0;
	for (int i: aba) ss += i;
	if (ss < ab + ba) {
		cout << "NO" << endl;
		return;
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