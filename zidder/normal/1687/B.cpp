#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int ask(string &s){
	cout << "? " << s << endl;
	fflush(stdout);
	int x;
	cin >> x;
	return x;
}

void solve(int test_ind){
	int n, m;
	cin >> n >> m;
	string e = "";
	for (int i=0;i<m;++i) e += "0";
	string s = e;
	vector<pair<int, int> > ed(m);
	for (int i=0;i<m;++i) {
		s = e;
		s[i] = '1';
		ed[i].second = i;
		ed[i].first = ask(s);
	}
	sort(ed.begin(), ed.end());
	s = e;
	int prev = 0;
	for (int i=0;i<m;++i){
		s[ed[i].second] = '1';
		int cur = ask(s);
		if (cur - prev == ed[i].first) {
			prev = cur;
			continue;
		}
		s[ed[i].second] = '0';
	}
	cout << "! " << prev << endl;
	fflush(stdout);
	return;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}