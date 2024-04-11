#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	long long a, b, c;
	cin >> a >> b >> c;
	if ((2 * b - a) % c == 0 && (2 * b - a > 0) || (2 * b - c) % a == 0 && (2 * b - c > 0) || (a + c) % (2 * b) == 0){
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
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