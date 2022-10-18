#include <bits/stdc++.h>
using namespace std;

const int MAXK = 2000005;

int n, k, ai, s[MAXK];
int main(){
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d", &ai);
		s[ai]++;
	}
	for(int i = 1; i < MAXK; i++)
		s[i] += s[i - 1];

	for(int g = MAXK - 1; g >= 1; g--){
		bool ok = true;
		for(int m = g; m < MAXK; m += g){
			if(m == g){
				if(s[m - 1] > 0)ok = false;
			}else{
				if(s[m - 1] - s[min(m - g + k, m - 1)] > 0)ok = false;
			}
		}
		if(ok){
			printf("%d\n", g);
			return 0;
		}
	}

	return 0;
}