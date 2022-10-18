#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int t, n, a[MAXN];
int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		
		bool found = false;
		for(int i = 0; i < n - 1; i++){
			if(abs(a[i] - a[i + 1]) < 2)continue;
			
			printf("YES\n%d %d\n", i + 1, i + 2);
			found = true;
			break;
		}
		
		if(!found)printf("NO\n");
	}
	return 0;
}