#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		if(i * (i + 1) / 2 == n)
			return cout << "YES" << endl, 0;
	cout << "NO" << endl;
	return 0;
}