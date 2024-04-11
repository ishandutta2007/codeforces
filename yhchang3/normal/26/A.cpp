#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int res = 0;
	for(int i=2;i<=n;i++) {
		int cnt = 0;
		int x = i;
		for(int j=2;j<=i;j++) {
			if(x % j == 0) {
				cnt++;
				while(x % j == 0)
					x /= j;
			}
		}
		res += (cnt == 2);
	}
	cout << res << endl;
}