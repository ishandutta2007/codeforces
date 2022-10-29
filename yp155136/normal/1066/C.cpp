/*input
10
L 100
R 100000
R 123
L 101
? 123
L 10
R 115
? 100
R 110
? 115
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 200006;

int id[N];

int main () {
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	int l=1,r=0;
	while (n--) {
		char c;
		int x;
		cin >> c >> x;
		if (c == '?') {
			cout << min(abs(id[x]-l),abs(id[x]-r)) << endl;
		}
		else if (c == 'L') {
			id[x] = (--l);
		}
		else if (c == 'R') {
			id[x] = (++r);
		}
	}
}