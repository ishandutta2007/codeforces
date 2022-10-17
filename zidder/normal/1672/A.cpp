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
	int c = 0;
	for (int i=0;i<n;++i){
		int x;
		cin >> x;
		c += x-1;
	}
	if (c % 2) {
		cout << "errorgorn" << endl;
	} else {
		cout << "maomao90" << endl;
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