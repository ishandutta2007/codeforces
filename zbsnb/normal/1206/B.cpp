#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long 
int main() {
	int n; cin >> n;
	ll ans = 0;
	int flg = 0;
	int state = 1;
	for (int i = 1; i <= n; i++) {
		int tmp; cin >> tmp;
		if (tmp == 0) {
			flg = 1;
			ans++;
		}
		else {
			if (abs(tmp - 1) < abs(tmp + 1)) {
				ans += abs(tmp - 1);
			}
			else {
				state = -state;
				ans += abs(tmp + 1);
			}
		}
	}
	if (state == 1) {
		cout << ans << endl;
	}
	else {
		if (flg)cout << ans << endl;
		else cout << ans + 2 << endl;
	}
}