#include <bits/stdc++.h>
using namespace std;

int t, n;
char s[105];

int main() {
	for(scanf("%d", &t); t; --t) {
		scanf("%s", s + 1); int n = strlen(s + 1);
		bool flag = 1;
		for(int i = 1; i < n; ++i) flag &= (s[i] == s[i + 1]);
		if(flag) {
			printf("%s\n", s + 1);
		} else {
			for(int i = 1; i <= n; ++i) printf("01");
			puts(""); 
		}
	}
	return 0;
}