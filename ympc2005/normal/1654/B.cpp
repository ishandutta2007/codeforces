#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int T, n, c[55];

char s[N];

int main() {
	scanf("%d", &T);
	
	while (T--) {
		scanf("%s", s + 1), n = strlen(s + 1);
		memset(c, 0, sizeof(c));
		
		for (int i = 1; i <= n; i++) {
			c[s[i] - 'a']++;
		}
		
		for (int i = 1; i <= n; i++) {
			c[s[i] - 'a']--;
			
			if (!c[s[i] - 'a']) {
				for (int j = i; j <= n; j++) {
					putchar(s[j]);
				}
				
				puts("");
				break;
			}
		}
	}
}