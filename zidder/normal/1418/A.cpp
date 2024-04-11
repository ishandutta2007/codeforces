#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
    long long x, y, k, r;
    cin >> x >> y >> k;
    r = k * (y + 1);
    long long t = (r - 1 + x - 2) / (x - 1);
    t += k;
    cout << t << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}