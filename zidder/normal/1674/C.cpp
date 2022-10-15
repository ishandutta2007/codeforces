#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	string s, t;
	cin >> s >> t;
	bool ta=false;
	int csa = 0;
	if (t == "a") {
		cout << 1 << endl;
		return;
	}
	for (char i: s) if (i == 'a') csa++;
	for (char i: t) if (i == 'a') ta = true;
	if (ta) {
		cout << -1 << endl;
		return;
	}

	cout << (1ll<<csa) << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}