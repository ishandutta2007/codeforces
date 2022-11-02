#include<iostream>
#include<algorithm>
using namespace std;

int h[500010];
int c[500010];
int n;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int tmp; cin >> tmp;
		h[tmp] = 1;
	}
	int pos = 0;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		if (c[i] == 1)pos = i;
	}
	if (pos != 0) {
		int flg = 1;
		for (int i = pos; i <= n; i++) {
			if (c[i] != c[pos] + i - pos)flg = 0;
		}
		int fir = n - pos + 1;
		for (int i = 1; i <= pos - 1; i++) {
			if (c[i] != 0 && c[i] - fir <= i)flg = 0;
		}
		if (flg) {
			cout << pos - 1 << endl;
			return 0;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		//cout << i << " " << i - c[i] + 1 << endl;
		if (c[i] != 0)ans = max(ans, i - c[i] + 1);
	}
	ans += n;
	cout << ans << endl;
}