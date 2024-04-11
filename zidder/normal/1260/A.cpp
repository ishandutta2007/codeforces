#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	long long c, s, ans = 0;
	cin >> c >> s;
	while(c){
		long long d = s/c;
		ans += d*d;
		c--;
		s-=d;
	}
	cout << ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}