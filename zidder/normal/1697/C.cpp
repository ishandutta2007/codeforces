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
	string s, t;
	cin >> s >> t;
	int c = 0;
	string s1 = "", t1 = "";
	for (int i=0;i<n;++i) {c += (s[i] == 'b'); if (s[i] !='b')s1+=s[i];}
	for (int i=0;i<n;++i) {c -= (t[i] == 'b'); if (t[i] !='b')t1+=t[i];}
	vector<int> sb, tb;
	for (int i=0;i<n;++i) {
		if (s[i] == 'b') sb.push_back(i);
		if (t[i] == 'b') tb.push_back(i);
	}
	if (c == 0 && t1 == s1) {
		set<int> inds[3];
		set<int> indt[3];
		for (int i=0;i<n;++i) inds[s[i]-'a'].insert(i);
		for (int i=0;i<n;++i) indt[t[i]-'a'].insert(i);
		for (int i=n-1;i>=0;--i) {
			if (s[i] == t[i]) {
				inds[s[i]-'a'].erase(*inds[s[i]-'a'].rbegin());
				indt[t[i]-'a'].erase(*indt[t[i]-'a'].rbegin());
				continue;
			}
			// cout << s[i] << " " << t[i] << endl;
			if (s[i] == 'b' && t[i] == 'a') {
				int ai = *inds[0].rbegin();
				s[i] = 'a';
				s[ai] = 'b';
				inds[0].erase(ai);
				inds[1].insert(ai);
				inds[1].erase(i);
				indt[0].erase(*indt[0].rbegin());
				continue;
			}
			if (s[i] == 'c' && t[i] == 'b') {
				s[i] = 'b';
				int bi = *inds[1].rbegin();
				s[bi] = 'c';
				// cout << i << " " << bi << endl;
				inds[1].erase(bi);
				inds[2].insert(bi);
				inds[2].erase(i);
				indt[1].erase(*indt[1].rbegin());
				continue;
			}
			break;
		}
		if (s == t) cout << "YES" << endl;
		else cout << "NO" << endl;
	} else {
		cout << "NO" << endl;
	}
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}