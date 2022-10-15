#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	// z = c
	// y = b
	// x = b * 1000000000ll + a
	int a, b, c;
	cin >> a >> b >> c;
	long long x = b * 1000000000ll + a, y=b, z=c;
	if (x%y!=a || y%z != b || z%x!=c) cout<<"hey" <<endl;
	cout << x << " " << y << " " << z << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}