#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	d -= a;
	e -= b;
	if (d > 0) c -= d;
	if (e > 0) c -= e;
	if (c < 0) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
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