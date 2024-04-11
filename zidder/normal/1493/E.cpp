#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

string add1(string x){
	string y = x;
	int c = 1;
	for (int i=y.size()-1;i>=0;--i){
		if (y[i] == '1') {
			y[i] = '0';
		} else {
			y[i] = '1';
			break;
		}
	}
	return y;
}

void solve(int test_ind){
	int n;
	cin >> n;
	string l, r;
	cin >> l >> r;
	if (r[0] == '0' || l == r) {
		cout << r << endl;
		return;
	}
	if (l[0] == '1') {
		if (add1(l) != r)
			r[n-1] = '1';
		cout << r << endl;
		return;
	}
	// r with 1
	for (int i=0;i<n;++i) printf("1");
	cout << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}