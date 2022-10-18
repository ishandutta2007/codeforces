#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int t, n, ai, c[MAXN], col[11], p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
bool d[11];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		
		memset(d, false, sizeof d);
		
		for(int i = 0; i < n; i++){
			scanf("%d", &ai);
			
			for(int j = 0; j < 11; j++){
				if(ai % p[j] == 0){
					d[j] = true;
					c[i] = j;
					break;
				}
			}
		}
		
		int m = 0;
		for(int i = 0; i < 11; i++){
			if(d[i]){
				col[i] = ++m;
			}
		}
		
		printf("%d\n", m);
		for(int i = 0; i < n; i++){
			if(i > 0)printf(" ");
			printf("%d", col[c[i]]);
		}
		printf("\n");
	}
	return 0;
}