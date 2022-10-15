#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int a, b;
	cin >> a >> b;
	int ans = b-a;
	for (int i=a;i<=b;++i){
		ans = min(ans, 1 + (i|b)-b+i-a);
	}
	for (int i=b;i<=(a|b);++i){
		if ((i&a) == a){
			ans = min(ans, 1 + i - b);
		}
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