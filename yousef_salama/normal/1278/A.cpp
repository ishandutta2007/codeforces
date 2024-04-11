#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int t, n, m;
char oh[MAXN], p[MAXN], h[MAXN];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%s %s", p, h);
		n = strlen(p);
		m = strlen(h);
		
		sort(p, p + n);
		
		for(int i = 0; i < m; i++)
			oh[i] = h[i];
		
		bool found = false;
		for(int i = 0; i + n - 1 < m; i++){
			bool ok = true;
			
			sort(h + i, h + i + n);
			for(int j = 0; j < n; j++){
				if(h[i + j] != p[j]){
					ok = false;
					break;
				}
			}
			
			if(ok){
				found = true;
				break;
			}
			
			for(int j = 0; j < n; j++)
				h[i + j] = oh[i + j];
		}
		
		if(found)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}