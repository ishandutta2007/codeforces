#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

#define ll long long

using namespace std;

void solve(int test_ind){
	int n, x;
	cin >> n >> x;
	int a, b;
	cin >> a >> b;
	int c, d;
	c = min(a, b);
	d = max(a, b);
	cout << min(d - c + x, n - 1) << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}