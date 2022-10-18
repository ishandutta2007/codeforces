#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30005;

int n, t, a[MAXN];

int main(){
	scanf("%d %d", &n, &t);
	t--;
	
	for(int i = 0; i < n - 1; i++)
		scanf("%d", &a[i]);
		
	int u = 0;
	while(u != t && u < n - 1)
		u += a[u];
		
	if(u == t)printf("YES\n");
	else printf("NO\n");
	
	return 0;
}