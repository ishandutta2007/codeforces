#include<iostream>
#include<algorithm>
using namespace std;
int n, x;
int sum[270000];
bool vis[270000];
void solve() {
	int p = 0;
	for (int i = 0; i < (1 << n); i++) {
		if(!vis[i])sum[p++] = i;
		if (x < (1 << n))vis[i^x] = 1;
	}
	cout << p - 1 << endl;
	for (int i = 1; i < p; i++) {
		cout << (sum[i] ^ sum[i - 1]) << " ";
	}
	cout << endl;
}
int main() {
	cin >> n >> x;
	solve();
}