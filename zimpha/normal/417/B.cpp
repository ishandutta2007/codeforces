#include <iostream>
using namespace std;

int T[1000000];

int main() {
	int n; cin >> n; 
	bool flag = false;
	for (int i = 0; i < n; ++ i) {
		int x, k; cin >> x >> k;
		if (T[k] == x) T[k] ++;
		else if (T[k] >= x) continue;
		else flag = true;
	}
	if (flag) cout << "NO\n";
	else cout << "YES\n";
	return 0;
}