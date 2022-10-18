#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int t, n, ai, cnt[MAXN];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		
		memset(cnt, 0, sizeof cnt);
		for(int i = 0; i < n; i++){
			scanf("%d", &ai);
			cnt[ai]++;
		}
		
		int res = 0, c = 2;
		for(int i = 0; i < MAXN; i++){
			if(cnt[i] == 0)break;
			else if(cnt[i] == 1)c = 1;
			
			res += c;
		}
		
		printf("%d\n", res);
	}
	return 0;
}