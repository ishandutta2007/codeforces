#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int T;

int main() {
	cin >> T;
	while(T--) {
		int a , b;
		cin >> a >> b;
		long long ans = 0;
		for(int i = 1; i < b; i++) {
			int j = a / i;
			j = min(j , b + 1);
			if(j - i - 1 <= 0)
				break;
			ans += j - i - 1;
		}
		cout << ans << endl;
	}
	return 0;
}