#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int k;
char s[MAXN];

int main(){
	scanf("%d", &k);

	if(k == 0){
		printf("a\n");
	}else{
		int n = 0, c = 0;
		for(int i = 1000; i >= 2; ){
			if(i * (i - 1) / 2 > k){
				i--;
				continue;
			}

			for(int j = 0; j < i; j++)
				s[n++] = c + 'a';
			c++;

			k -= i * (i - 1) / 2;
		}
		s[n] = 0;

		printf("%s\n", s);
	}

	return 0;
}