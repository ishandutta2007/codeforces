#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int T;

int main() {
	cin >> T;
	while(T--) {
		int a , b;
		cin >> a >> b;
		int ans = 0x3f3f3f3f;
		for(int i = 0; i <= 1000; i++) {
			if(b + i == 1) continue;
			int t = a , temp = i;
			while(t != 0) t /= (b + i) , temp++;
			ans = min(ans , temp);
		}
		cout << ans << endl;
	}
	return 0;
}