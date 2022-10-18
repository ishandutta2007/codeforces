#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

char s[1000005];
int main(){
	scanf("%s", &s);
	int n = strlen(s);

	int b = 0, r = 0;
	for(int i = n - 1; i >= 0; i--){
		if(s[i] == 'b')b++;
		else{
			r = (r + b) % MOD;
			b = (b * 2) % MOD;
		}
	}
	printf("%d\n", r);

	return 0;
}