#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;

int t, n, a[MAXN], b[MAXN];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		
		long long suma = 0, sumb = 0;
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			suma += a[i];
		}
		for(int i = 0; i < n; i++){
			scanf("%d", &b[i]);
			sumb += b[i];
		}
		
		if(sumb < suma){
			printf("NO\n");
			continue;
		}
		
		long long mn = 0, s = b[0], p = 0;
		for(int i = 1; i < n; i++){
			s += -a[i] + b[i];
			mn = min(mn, s - p);
			p = max(p, s - b[i]);
		}
		
		s = a[0], p = 0;
		for(int i = 1; i < n; i++){
			s += a[i] - b[i - 1];
			mn = min(mn, sumb - suma + s - p);
			p = max(p, s - a[i]);
		}
		
		if(mn < 0)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}