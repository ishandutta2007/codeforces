#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n, m;
		cin >> n;
		vector<int> A(n + 1);
		for(int i=1;i<=n;i++)
			cin >> A[i], A[i] += A[i-1];
		cin >> m;
		vector<int> B(m + 1);
		for(int i=1;i<=m;i++)
			cin >> B[i], B[i] += B[i-1];
		cout << *max_element(A.begin(), A.end()) + *max_element(B.begin(), B.end()) << '\n';
	}
}