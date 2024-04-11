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
	int z=0, o=0;
	for (int i=0;i<s.size();++i){
		if (s[i] == '0') z++;
		else o++;
	}
	if (o == z) o--;
	cout << min(o, z) << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}