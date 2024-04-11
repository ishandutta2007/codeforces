#include<iostream>
#include<algorithm>
using namespace std;
int a[1000], b[1000];
int vis[1000];
int main() {
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i], vis[a[i]] = 1;
	cin >> m;
	for (int i = 1; i <= m; i++)cin >> b[i], vis[b[i]] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!vis[a[i] + b[j]]) {
				cout << a[i] << " " << b[j] << endl;
				return 0;
			}
		}
	}
}