#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, m, rb, rd, cb, cd;
	cin >> n >> m >> rb >> cb >> rd >> cd;
	if (rb == rd || cb == cd) {
		cout << "0" << endl;
		return;
	}
	int dr = rd - rb;
	if (dr < 0) dr = n - rb + n - rd;
	int dc = cd - cb;
	if (dc < 0) dc = m - cb + m - cd;
	cout << min(dr, dc) << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}