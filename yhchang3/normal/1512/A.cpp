#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		map<int,int> m;
		vector<int> a(n + 1);
		for(int i=1;i<=n;i++)
			cin >> a[i], m[a[i]] ++;
		for(int i=1;i<=n;i++)
			if(m[a[i]] == 1)
				cout << i << '\n';
	}
}