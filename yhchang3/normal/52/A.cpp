#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(3 + 1);
	for(int i=0,x;i<n;i++)
		cin >> x, v[x] ++;
	cout << n - *max_element(v.begin() + 1, v.end()) << endl;
}