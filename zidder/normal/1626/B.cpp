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
	int sz = 0;
	int ind = 0;
	for (int i=1;i<s.size();++i){
		string s1 = to_string(s[i]-'0' + s[i-1]-'0');
		if (s1.size() > sz){
			sz = s1.size();
			ind = i;
		} else {
			if (s1.size() == 2) {
				ind = i;
			}
		}
	}
	string res = "";
	for (int i=0;i<s.size();++i){
		if (i + 1 == ind){
			string s1 = to_string(s[i]-'0' + s[i+1]-'0');
			res += s1;
			i++;
		} else {
			res += s[i];
		}
	}
	cout << res << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}