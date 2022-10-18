#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int t, n, k, c[26];
char s[MAXN];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %s", &n, &k, s);
		
		int res = 0;
		for(int i = 0; i < k; i++){
			if(k - 1 - i < i)break;
			else if(k - 1 - i > i){
				memset(c, 0, sizeof c);
				for(int j = 0; j < n; j += k){
					c[s[j + i] - 'a']++;
					c[s[j + (k - 1 - i)] - 'a']++;
				}
				
				int tot = 2 * (n / k), mn = 1 << 20;
				for(int j = 0; j < 26; j++)
					mn = min(mn, tot - c[j]);
				res += mn;
			}else{
				memset(c, 0, sizeof c);
				for(int j = 0; j < n; j += k)
					c[s[j + i] - 'a']++;
				
				int tot = n / k, mn = 1 << 20;
				for(int j = 0; j < 26; j++)
					mn = min(mn, tot - c[j]);
				res += mn;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}