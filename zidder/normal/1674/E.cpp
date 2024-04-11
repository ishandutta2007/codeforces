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
	vector<int> a(n);
	for (int &i: a) scanf("%d", &i);
	int ans = a[0] + a[1];
	for (int i=1;i<n;++i){
		// 2x + y >= a
		// x + 2y >= b
		// minimize x + y
		// 3x + 3y >= a + b
		int b = max(a[i], a[i-1]), c = min(a[i], a[i-1]);
		int cnt = min(b-c, (b+1)/2);
		b -= cnt * 2;
		c -= cnt;
		b = max(b, 0);
		c = max(c, 0);
		ans = min(ans, cnt + (b + c + 2) / 3);
	}

	for (int i=2;i<n;++i){
		int c = min(a[i], a[i-2]);
		ans = min(ans, (a[i]-c+1)/2 +c+(a[i-2]-c+1)/2);
	}

	sort(a.begin(), a.end());
	ans = min(ans, (a[0]+1)/2 + (a[1]+1)/2);
	cout << ans << endl;
}

int main(){
	int t=1;
	// cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}