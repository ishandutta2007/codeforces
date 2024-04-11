#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

bool check(string s, string p, int ind){
	vector<int> xs(26, 0), xp(26, 0);
	for(int i=0;i<s.size();++i)
		xs[s[i]-'a']++;
	for(int i=0;i<s.size();++i)
		xp[p[i+ind]-'a']++;
	for(int i=0;i<26;++i)
		if (xs[i] != xp[i])
			return false;
	return true;
}

void solve(int test_ind){
	string s, p;
	cin >> s >> p;
	for(int i=0;i<=(int)p.size() - (int)s.size();++i){
		if (check(s, p, i)){
			cout << "YES" << endl;
			return;
		}
	}
	cout << "NO" << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}