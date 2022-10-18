#include <bits/stdc++.h>
using namespace std;

int c[10];
const char *s = "codeforces";
long long k;

int main(){
	scanf("%lld", &k);
	
	for(int i = 0; i < 10; i++)
		c[i] = 1;
	
	long long p = 1;
	while(p < k){
		int ind = min_element(c, c + 10) - c;
		p += p / c[ind];
		c[ind]++;
	}
	
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < c[i]; j++)
			printf("%c", s[i]);
	}
	printf("\n");
	
	return 0;
}