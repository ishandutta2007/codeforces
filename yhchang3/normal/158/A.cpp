#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> v(n + 1);
	for(int i=1;i<=n;i++)
		cin >> v[i];
	sort(v.begin() + 1, v.end(), greater<int>());
	int res = 0;
	for(int i=1;i<=n;i++)
		if(v[i] >= v[k] && v[i] > 0)
			res++;
	cout << res << endl;
}