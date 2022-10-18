#include <bits/stdc++.h>
using namespace std;

const int MAXN = 305;

int t, n, m, a[MAXN][MAXN];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		
		bool ok = true;
		for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++){
			int d = (i != 0) + (i != n - 1) + (j != 0) + (j != m - 1);
			
			scanf("%d", &a[i][j]);
			if(a[i][j] > d){
				ok = false;
			}else{
				a[i][j] = d;
			}
		}
		
		if(ok){
			printf("YES\n");
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					if(j > 0)printf(" ");
					printf("%d", a[i][j]);
				}
				printf("\n");
			}
		}else{
			printf("NO\n");
		}
	}
	
	return 0;
}