#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int t, n, x, a[MAXN];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &x);
		
		bool found = false;
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			
			if(x == a[i])found = true;
		}
		
		if(found)printf("1\n");
		else{
			int mx = *max_element(a, a + n);
			printf("%d\n", max(2, (x + mx - 1) / mx));
		}
	}
	
	return 0;
}