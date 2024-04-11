#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int T, n, a[MAXN], prv[MAXN];
int main(){
	scanf("%d", &T);
	
	memset(prv, -1, sizeof prv);
	while(T--){
		scanf("%d", &n);
		
		int ans = -1;
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			
			if(prv[a[i]] != -1){
				if(ans == -1 || i - prv[a[i]] + 1 < ans)ans = i - prv[a[i]] + 1;
			}
			prv[a[i]] = i;
		}
		printf("%d\n", ans);
		
		for(int i = 0; i < n; i++)
			prv[a[i]] = -1;
	}
	return 0;
}