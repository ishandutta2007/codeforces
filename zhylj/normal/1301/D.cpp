#include <bits/stdc++.h>

const int kMaxN = 1e5 + 5;

int n, m, k, f[kMaxN]; std::string s[kMaxN];

int main() {
	std::cin >> n >> m >> k;
	if(k > 4 * n * m - 2 * n - 2 * m) printf("NO");
	else {
		int a = 0;
		if(k < m) { a = 1; f[1] = k; s[1] = "R"; k = 0; }
		else if(k < 2 * m - 2) {
			a = 2; f[1] = m - 1; s[1] = "R"; k -= m - 1;
			f[2] = k; s[2] = "L"; k = 0;
		} else {
			a = 2; f[1] = m - 1; s[1] = "R";
			f[2] = m - 1; s[2] = "L";
			k -= 2 * m - 2;
		}
		if(k >= 1) { --k; f[++a] = 1; s[a] = "D"; }
		for(int i = 2; i <= n && k; ++i) {
			//printf("%d %d\n", i, k);
			if(k >= 3) { ++a; s[a] = "RUD"; }
			for(int j = 1; j < m && k; ++j) {
			//printf("?");
				if(k >= 3) k -= 3, ++f[a];
				else if(k == 2) { k = 0; f[++a] = 1; s[a] = "RU"; }
				else if(k == 1) { k = 0; f[++a] = 1; s[a] = "R"; }
			}
			if(k >= m - 1) { k -= m - 1; f[++a] = m - 1; s[a] = "L"; }
			else if(k != 0) { f[++a] = k; k = 0; s[a] = "L"; }
			//printf("%d %d");
			if(k >= 1 && i != n) { --k; f[++a] = 1; s[a] = "D"; }
		}
		if(k) { f[++a] = k; s[a] = "U"; }
		a = 1e5;
		for(int i = 1; i <= 1e5; ++i)
			if(f[i] == 0) --a;
		std::cout << "YES\n" << a << std::endl;
		for(int i = 1; i <= 1e5; ++i)
			if(f[i] != 0)
				std::cout << f[i] << " " << s[i] << std::endl;
	}
	return 0;
}