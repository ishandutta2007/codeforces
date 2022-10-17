#include <bits/stdc++.h>
using namespace std;
#define fu(i, a, b) for(int i = a; i <= b; ++i)
 
int t, n;
char s[3005];
 
inline bool odd(int p) {
	return (s[p] - '0') & 1;
}
 
int main() {
	scanf("%d", &t); 
	while(t--) {
		scanf("%d", &n);
		scanf("%s", s + 1);
		bool cnt = 0, flg = 0;
		fu(i, 1, n) cnt ^= odd(i);
		while(!odd(n) && n) --n;
		if(!n) {
			puts("-1");
			continue;
		}
		if(!cnt) {
			bool f = 0;
			fu(i, 1, n) {
				if(s[i] == '0' && !f) continue;
				f = 1;
				printf("%c", s[i]); 
			}
			puts("");
			continue;
		}
		fu(i, 1, n - 1) if(odd(i)) {
			bool f = 0;
			fu(j, 1, n) {
				if(j == i) continue;
				if(s[j] == '0' && !f) continue;
				f = 1;
				printf("%c", s[j]); 
			}
			puts("");
			flg = 1; break;
		}
		if(!flg) puts("-1");
	}
	return 0;
}