#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long 

int a[110],b[110];
char s[200];

int main() {
	int n; cin >> n;
	cin >> s + 1;
	for (int i = 1; i <= n; i++)s[i] -= '0';
	for (int i = 1; i <= n; i++)cin >> a[i] >> b[i];
	int  ans = 0;
	for (int t = 1; t <= 10000; t++) {
		int  tmp = 0;
		for (int i = 1; i <= n; i++)tmp += s[i];
		ans = max(ans, tmp);
		for (int i = 1; i <= n; i++) {
			if (t == b[i]) {
				s[i] = 1 - s[i];
				b[i] += a[i];
			}
		}
	}
	cout << ans << endl;
}