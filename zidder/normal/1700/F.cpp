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
	vector<vector<int> > a(2, vector<int>(n));
	vector<vector<int> > b(2, vector<int>(n));
	for (int i=0;i<2;++i) for (int &j: a[i]) scanf("%d", &j);
	for (int i=0;i<2;++i) for (int &j: b[i]) scanf("%d", &j);

	// x, y at d -> abs(k) + (x+k, y-k) at d
	// x, y at d -> abs(x) + abs(y) + (x - delta[d][0], y - delta[d][1]) at d + 1

	long long ans = 0;
	int x = 0, y = 0;
	for (int i=0;i<n;++i) {
		ans += abs(x) + abs(y);
		x += a[0][i] - b[0][i];
		y += a[1][i] - b[1][i];
		if (x < 0 && y > 0) {
			if (-x < y) {
				ans -= x;
				y += x;
				x = 0;
			} else {
				ans += y;
				x += y;
				y = 0;
			}
		}
		if (x > 0 && y < 0) {
			if (-y < x) {
				ans -= y;
				x += y;
				y = 0;
			} else {
				ans += x;
				y += x;
				x = 0;
			}
		}
	}
	// cout << x << " " << y << endl;
	if (x == 0 && y == 0)
		cout << ans << endl;
	else
		cout << -1 << endl;
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}