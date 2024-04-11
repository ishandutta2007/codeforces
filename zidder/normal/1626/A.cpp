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
	vector<int> a(26);
	for (char i: s) a[i-'a']++;
	for (int i=0;i<26;++i){
		if (a[i] == 1){
			a[i] = 0;
			cout << (char)('a'+i);
		}
	}
	for (int i=0;i<26;++i){
		if (a[i]){
			cout << char(i + 'a');
			a[i]--;
		}
	}
	for (int i=0;i<26;++i){
		for (int j=0;j<a[i];++j)
			cout << char(i + 'a');
	}
	cout << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}