#include<bits/stdc++.h>
using namespace std;

int a[1000];

int main() {
	int n;
	cin >> n;
	for(int i=1;i<=n;i++)
		cin >> a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				if(i != j && j != k && k != i && a[i] == a[j] + a[k])
					return cout << i << ' ' << j << ' ' << k << endl, 0;
	cout << -1 << endl;
}