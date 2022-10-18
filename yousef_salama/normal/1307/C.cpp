#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

char s[MAXN];
int n;
long long c[26], d[26][26];

int main(){
	scanf("%s", s);
	n = strlen(s);
	
	for(int i = n - 1; i >= 0; i--){
		for(int j = 0; j < 26; j++)
			d[s[i] - 'a'][j] += c[j];
		
		c[s[i] - 'a']++;
	}
	
	long long res = 0;
	for(int i = 0; i < 26; i++){
		res = max(res, c[i]);
		for(int j = 0; j < 26; j++)
			res = max(res, d[i][j]);
	}
	printf("%lld\n", res);
	
	return 0;
}