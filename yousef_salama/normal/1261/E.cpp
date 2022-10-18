#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n, a[MAXN];
char g[MAXN][MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
		
	for(int i = 0; i < n + 1; i++){
		for(int j = 0; j < n; j++){
			g[i][j] = '0';
		}
		g[i][n] = 0;
	}
		
	int j = 0;
	for(int i = 0; i < n; i++){
		bool found = false;
		for(int x = 0; x < n; x++){
			if(a[x] == n - i){
				found = true;
				
				for(int y = 0; y < n; y++)if(a[y] == a[x] && x != y){
					g[j][y] = '1';
					a[y]--;
				}
				
				for(int y = 0; y < a[x]; y++)
					g[j + y + 1][x] = '1';
				a[x] = 0;
				
				j++;
				
				break;
			}
		}
		
		if(found)continue;
		
		for(int x = 0; x < n; x++){
			if(a[x] > 0){
				for(int y = 0; y < a[x]; y++)
					g[n - i - y + j][x] = '1';
				
				a[x] = 0;
				
				break;
			}
		}
	}
	
	
	printf("%d\n", n + 1);
	for(int i = 0; i < n + 1; i++)
		printf("%s\n", g[i]);
		
	return 0;
}