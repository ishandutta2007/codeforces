#include <bits/stdc++.h>
#define N 105
using namespace std;

int n;
char s[N];

int main(){
	int i;
	scanf("%d%s", &n, s);
	for(i = n >> 1; i; --i)
		if(!memcmp(s, s + i, i)) return printf("%d\n", n - i + 1), 0;
	printf("%d\n", n);
	return 0;
}