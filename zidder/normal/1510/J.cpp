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
	// opens
	int frst = -1;
	for (int i=0;i<s.size();++i) {
		if (s[i] == '#') {frst = i; break;}
	}
	if (frst == -1) { cout << 0 << endl; return; }
	int lst = -1;
	for (int i=s.size()-1;i>=0;--i) {
		if (s[i] == '#') {lst = i;break;}
	}
	if (frst == 0 && lst == s.size() - 1) {
		bool ok = true;
		for (int i=1;i<s.size();++i){
			if (s[i] == s[i-1] && s[i] == '_') ok = false;
		}
		if (ok){
			vector<int> ans;
			for (int i=0;i<s.size();++i){
				int ifrst = i;
				while (i < s.size() && s[i] == '#') ++i;
				ans.push_back(i - ifrst);
			}
			cout << ans.size() << endl;
			for (int i: ans) printf("%d ", i);
			cout << endl;
			return;
		}
	}
	bool ok = true;
	int cnt = 0;
	for (int i=frst;i<=lst;++i){
		if (s[i] == '#') {
			if (cnt%2) ok = false;
			cnt = 0;
		}
		else cnt++;
	}
	if (frst % 2 == 0) ok = false;
	if ((s.size() - lst) % 2) ok = false;
	if (ok) {
		vector<int> ans;
		for (int i=0;i<s.size();++i){
			if (s[i] == '_') {
				if (i+1<s.size() && s[i+1] == '#') continue;
				ans.push_back(1);
				++i;
			}
			else {
				// s[i] == '#'
				int ifrst = i;
				while (s[i] == '#') i++;
				ans.push_back(i - ifrst + 1);
			}
		}
		cout << ans.size() << endl;
		for (int i: ans) printf("%d ", i);
		cout << endl;
		return;
	}
	// no 4, no 1, 2
	cnt = 0;
	ok = true;
	for (int i=frst;ok&&i<=lst;++i){
		if (s[i] == '#') {
			if (cnt==4) ok = false;
			if (cnt==2) ok = false;
			if (cnt==1) ok = false;
			cnt = 0;
		}
		else cnt++;
	}
	if (frst < 2 || frst == 3) ok = false;
	if (lst + 2 >= s.size() || lst + 4 == s.size())	ok = false;
	if (!ok) {
		ok = true;
		// k = 3
		cnt = 0;
		ok = true;
		for (int i=frst;ok&&i<=lst;++i){
			if (s[i] == '#') {
				if (cnt==5) ok = false;
				if (cnt==3) ok = false;
				if (cnt==2) ok = false;
				if (cnt==1) ok = false;
				cnt = 0;
			}
			else cnt++;
		}
		if (frst < 3 || frst == 4) ok = false;
		if (lst + 3 >= s.size() || lst + 5 == s.size())	ok = false;
		if (ok) {
			vector<int> ans;
			for (int i=2;i<=lst;++i){
				if (s[i] == '_') {
					++i;
					if (i<s.size() && s[i] == '#') {--i;continue;}
					if (i+1 < s.size() && s[i+1] == '#') {ans[ans.size()-1] = 2;}
					else ans.push_back(1);
				}
				else {
					// s[i] == '#'
					int ifrst = i;
					while (s[i] == '#') i++;
					ans.push_back(i - ifrst + 3);
					i++;
					i++;
				}
			}
			reverse(s.begin(), s.end());
			for (int i=2;i<s.size();++i){
				if (s[i] == '_') {
					++i;
					if (i<s.size() && s[i] == '#') {--i;continue;}
					if (i+1 < s.size() && s[i+1] == '#') {ans[ans.size()-1] = 2;}
					else ans.push_back(1);
				}
				else {
					break;
				}
			}
			cout << ans.size() << endl;
			for (int i: ans) printf("%d ", i);
			cout << endl;
		} else {
			cout << -1 << endl;
		}
	}
	else {
		vector<int> ans;
		for (int i=1;i<=lst;++i){
			if (s[i] == '_') {
				++i;
				if (i<s.size() && s[i] == '#') {--i;continue;}
				if (i+1 < s.size() && s[i+1] == '#') {ans[ans.size()-1] = 2;}
				else ans.push_back(1);
			}
			else {
				// s[i] == '#'
				int ifrst = i;
				while (s[i] == '#') i++;
				ans.push_back(i - ifrst + 2);
				i++;
			}
		}
		reverse(s.begin(), s.end());
		for (int i=1;i<s.size();++i){
			if (s[i] == '_') {
				++i;
				if (i<s.size() && s[i] == '#') {--i;continue;}
				if (i+1 < s.size() && s[i+1] == '#') {ans[ans.size()-1] = 2;}
				else ans.push_back(1);
			}
			else {
				break;
			}
		}
		cout << ans.size() << endl;
		for (int i: ans) printf("%d ", i);
		cout << endl;
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