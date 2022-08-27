#include <bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;

typedef long long ll;
const ll S = 12243012243ll;

ll A[4];

int main() {
	int x, y, z; ll T;
	std::ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> A[1] >> A[2] >> A[3];
	cout << "First" << endl;
	cout << S << endl;
	cin >> x, A[x] += S;

	T = A[x] * 3 - A[1] - A[2] - A[3];
	cout << T << endl;
	cin >> y, A[y] += T;

	assert(A[y] - A[x] == A[x] - A[x ^ y]);
	cout << A[y] - A[x] << endl;
	cin >> z, assert(!z);

	return 0;
}