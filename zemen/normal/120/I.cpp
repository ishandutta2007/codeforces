#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

char tr[10] = { 119, 36, 93, 109, 46, 107, 123, 37, 127, 111 };
char s[200003];
int k, n;

int getgood(char a, char b) {
	char mask = tr[a] & tr[b];
	int res = 0;
	while (mask > 0) {
		if (mask % 2 == 1)
			++res;
		mask /= 2;
	}
	return res;
}

int main() {
	//li n, m;
	//cin >> n >> m;
	//cerr << getgood (n, m) << endl;
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
	gets(s);
	k = strlen(s);
	n = k / 2;
	int good = 0;
	for (int i = 0; i < k; ++i)
		s[i] -= '0';
	for (int i = k - 1; i >= 0; --i) {
		char a;
		if (i < n)
			a = s[i + n];
		else
			a = s[i - n];
		int cur = getgood(s[i], a);
		for (int j = s[i] + 1; j < 10; ++j) {
			if (getgood(a, (char) j) - cur + good > 0) {
				s[i] = (char) j;
				good += getgood(a, (char) j) - cur;
				//Modify

				for (int pos = i + 1; pos < k; ++pos) {
					char aa;
					if (pos < n)
						aa = s[pos + n];
					else
						aa = s[pos - n];
					int cur2 = getgood(s[pos], aa);
					for (int jj = 0; jj < 10; ++jj) {
						if (good - cur2 + getgood(aa, jj) > 0) {
							good += getgood(aa, jj) - cur2;
							s[pos] = jj;
							break;
						}
					}
				}

				for (int ii = 0; ii < k; ++ii)
					s[ii] += '0';
				puts(s);
				return 0;
			}
		}
		good += getgood(a, 8) - cur;
		s[i] = 8;
	}
	printf("-1");
}