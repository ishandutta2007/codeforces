#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, T, a[55], b[55], c[55], m;

string s, t;

int main() {
	cin>>T;

	while (T--) {
		cin>>s; n = s.size();

		memset(a, 0, sizeof(a));

		for (char x : s) {
			a[x - 'a']++;
		}

		m = 0;

		for (int i = 0; i < 26; i++) {
			if (a[i]) {
				b[++m] = i;
				c[m] = a[i];
			}
		}

		if (m == 1) {
			cout<<s<<'\n';
			continue;
		}

		bool ok = 0;

		for (int i = 1; i <= m; i++) {
			if (c[i] == 1) {
				s = 'a' + b[i];
				c[i]--;

				for (int j = 1; j <= m; j++) {
					for (int k = 1; k <= c[j]; k++) {
						s += 'a' + b[j];
					}
				}

				cout<<s<<'\n';
				ok = 1;
				break;
			}
		}

		if (ok) {
			continue;
		}

		if (n - c[1] >= c[1] - 2) {
			s = 'a' + b[1];
			s += 'a' + b[1];

			t = "";

			for (int i = 2; i <= m; i++) {
				for (int j = 1; j <= c[i]; j++) {
					t += 'a' + b[i];
				}
			}

			int pos = 0;

			for (int i = 3; i <= c[1]; i++) {
				s += t[pos++];
				s += 'a' + b[1];
			}

			for (int i = pos; i < (int) t.size(); i++) {
				s += t[i];
			}

			cout<<s<<'\n';
			continue;
		}

		if (m > 2) {
			s = 'a' + b[1];
			s += 'a' + b[2];

			for (int i = 2; i <= c[1]; i++) {
				s += 'a' + b[1];
			}

			s += 'a' + b[3];
			
			for (int i = 2; i <= c[2]; i++) {
				s += 'a' + b[2];
			}

			c[3]--;

			for (int i = 3; i <= m; i++) {
				for (int j = 0; j < c[i]; j++) {
					s += 'a' + b[i];
				}
			}

			cout<<s<<'\n';
			continue;
		}

		s = 'a' + b[1];

		for (int i = 1; i <= c[2]; i++) {
			s += 'a' + b[2];
		}

		for (int i = 2; i <= c[1]; i++) {
			s += 'a' + b[1];
		}

		cout<<s<<'\n';
	}
}