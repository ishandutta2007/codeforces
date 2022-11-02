#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define int long long

char s[200010];

signed main() {
	int n; cin >> n;
	cin >> s + 1;
	int a=0, b=0;
	int c=0, d=0;
	for (int i = 1; i <= n / 2; i++) {
		if (s[i] == '?')c++;
		else a += s[i] - '0';
	}
	for (int i = n / 2 + 1; i <= n; i++) {
		if (s[i] == '?')d++;
		else b += s[i] - '0';
	}


	int sum = a - b - d * 9;
	int sum1 = sum + (c + d) / 2 * 9;
	if (sum1==0)cout << "Bicarp" << endl;
	else cout << "Monocarp" << endl;
}