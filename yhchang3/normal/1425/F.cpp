#include<bits/stdc++.h>
using namespace std;

int a[2000];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i=2;i<=n;i++){
		cout << "?" << ' ' << 1 << ' ' << i << endl;
		cin >> a[i];
	}
	for(int i=n;i>=3;i--)
		a[i] -= a[i-1];
	cout << "?" << ' ' << 2 << ' ' << 3 << endl;
	int x;
	cin >> x;
	int y = x - a[3];
	a[1] = a[2] - y;
	a[2] = y;
	cout << "!";
	for(int i=1;i<=n;i++)
		cout << ' ' << a[i];
	cout << endl;
}