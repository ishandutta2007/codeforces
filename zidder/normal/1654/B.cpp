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
	vector<vector<int> > inds(26);
	for (int i=0;i<s.size();++i){
		inds[s[i]-'a'].push_back(i);
	}
	int res = s.size();
	for (int i=0;i<26;++i){
		if (inds[i].size()){
			res = min(res, inds[i].back());
		}
	}
	cout << s.substr(res) << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}