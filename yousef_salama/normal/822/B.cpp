#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n, m;
char s[MAXN], t[MAXN];

int main(){
	scanf("%d %d", &n, &m);
	scanf("%s %s", s, t);

	int r = 1 << 20, k = 0;
	for(int i = 0; i + n <= m; i++){
		int rc = 0;
		for(int j = 0; j < n; j++)
			if(s[j] != t[i + j])rc++;

		if(rc < r){
			r = rc;
			k = i;
		}
	}

	printf("%d\n", r);

	int f = 1;
	for(int j = 0; j < n; j++)
		if(s[j] != t[k + j]){
			if(f)f = 0;
			else printf(" ");

			printf("%d", j + 1);
		}
	printf("\n");

	return 0;
}