#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4005;

int a, n;
char s[MAXN];
map <int, int> S;

int main(){
	scanf("%d %s", &a, s);
	n = strlen(s);

	for(int i = 0; i < n; i++){
		int sc = 0;
		for(int j = i; j < n; j++){
			sc += s[j] - '0';
			S[sc]++;
		}
	}

	if(a == 0){
		long long t = n * (n + 1) / 2;
		printf("%I64d\n", t * t - (t - S[0]) * (t - S[0]));
	}else{
		long long res = 0;
		for(int d = 1; d * d <= a; d++)if(a % d == 0){
			int r = a / d;

			if(d == r){
				long long t = S[d];
				res += t * t;
			}else{
				res += 2LL * S[d] * S[r];
			}
		}
		printf("%I64d\n", res);
	}

	return 0;
}