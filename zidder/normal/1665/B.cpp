#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
	cin >> n;
	map<int, int> mc;
	for (int i=0;i<n;++i) {
		int x;
		scanf("%d", &x);
		mc[x]++;
	}
	int m = 0;
	for (auto &p: mc) m = max(m, p.second);
	int n1 = n;
	int ans = 0;
	while (n1 > m) {
		int n2 = (n1 + 1) / 2;
		if (n2 > m) {
			ans += 1 + n1 - n2;
		} else {
			ans += 1 + n1 - m;
		}
		n1 = n2;
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