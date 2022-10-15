#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, r, b;
	cin >> n >> r >> b;
	int ans = r / (b + 1);
	int cnt = b+1-r % (b + 1);
	int cur = 0;
	string s = "";
	while (n--){
		if (cur < ans){
			cur++;
			s += "R";
			r--;
		} else {
			cur = 0;
			s += "B";
			cnt--;
			if (cnt == 0) ans++;
		}
	}
	cout << s << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}