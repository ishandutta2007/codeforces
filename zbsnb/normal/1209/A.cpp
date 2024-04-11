#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long 

int vis[20000];
int a[110];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++)cin >> a[i], vis[a[i]] = 1;
	int ans = 0;
	for (int i = 1; i <= 100; i++) {
		if (vis[i] == 1) {
			ans++;
			for (int j = 1; j <= 100; j++) {
				vis[i*j] = 0;
			}
		}
	}
	cout << ans << endl;
}