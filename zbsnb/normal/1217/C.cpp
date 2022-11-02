#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

char s[200010];
int sum[200010];
int main() {
	int t; cin >> t;
	while(t--) {
		cin >> s + 1;
		int ans = 0;
		int n = strlen(s + 1);
		for (int i = 1; i <= n; i++)sum[i] = 0, s[i] -= '0';
		for (int i = 1; i <= n; i++) {
			sum[i] = sum[i - 1] + s[i];
			//cout << i << " " << sum[i] << endl;
		}
		//cout << n << endl;

		for (int i = 1; i <= n; i++) {
			int tmp = 0;
			if (s[i] == 0)continue;
			for (int j = 1; j <= 20 && i + j - 1 <= n; j++) {

				tmp <<= 1;
				tmp += s[i + j - 1];

				int x = sum[i - 1];
				int l = 0, r = i - 1, pos = i - 1;
				if (s[i - 1] == 0) {
					while (l <= r) {
						int m = l + r >> 1;
						if (sum[m] == x) {
							r = m - 1;
							pos = min(m,pos);
						}
						else {
							l = m + 1;
						}
					}
				}
				pos++;
				int cnt = j + i - pos;
				//cout << i << " " << j << " " << tmp << " " << cnt << " " << pos << endl;

				if (cnt >= tmp && tmp >= j)ans++;
			}
		}
		cout << ans << endl;
	}
}