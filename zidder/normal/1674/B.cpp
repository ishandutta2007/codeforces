#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int ind = 1;
	string s;
	cin >> s;
	for (int i=0;i<26;++i){
		for (int j=0;j<26;++j){
			if (i == j) continue;
			if (i == s[0] - 'a' && j == s[1] - 'a'){
				cout << ind << endl;
				return;
			}
			ind++;
		}
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