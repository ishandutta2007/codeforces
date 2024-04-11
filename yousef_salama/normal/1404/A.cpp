#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300005;

int t, n, k, a[MAXN];
char s[MAXN];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d %s", &n, &k, s);
		
		for(int i = 0; i < k; i++)
			a[i] = -1;
			
		int x = 0, y = 0;
		bool ok = true;
		
		for(int i = 0; i < n; i++){
			if(s[i] == '0'){
				if(a[i % k] == 1){
					ok = false;
					break;
				}else if(a[i % k] == -1){
					x++;
					a[i % k] = 0;
				}
			}else if(s[i] == '1'){
				if(a[i % k] == 0){
					ok = false;
					break;
				}else if(a[i % k] == -1){
					y++;
					a[i % k] = 1;
				}
			}
		}
		
		if(!ok || 2 * x > k || 2 * y > k)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}