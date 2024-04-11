#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, m;
	cin >> n >> m;
	if (n == m && n == 1){
		cout << 0 << endl;
		return;
	}
	if (n == 1 || m == 1){
		cout << 1 << endl;
		return;
	}

	cout << 2 << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}