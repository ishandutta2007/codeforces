#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	long long a, b;
	cin >> a >> b;
	if (b > 2 * a || a > 2 * b){
		cout << "NO" << endl;
		return;
	}
	if ((a + b) % 3 == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}