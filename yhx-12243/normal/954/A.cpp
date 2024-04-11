#include <bits/stdc++.h>
#define N 105
using namespace std;

int n, ans = 0;
char s[N];

int main(){
	int i;
	// D: 68, R: 82, U: 85
	scanf("%d%s", &n, s);
	for(i = 0; i < n; ++i)
		if((s[i] ^ s[i + 1]) == 7){
			s[i] = 68; s[++i] = 0;
		}
	for(i = 0; i < n; ++i) ans += !!s[i];
	printf("%d\n", ans);
	return 0;
}