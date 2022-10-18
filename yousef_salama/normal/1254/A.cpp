#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

char chicken(int num){
	if(num < 10)return (num + '0');
	else if(num - 10 < 26)return (num - 10 + 'a');
	else return (num - 36 + 'A');
}

int T, r, c, k;
char g[MAXN][MAXN], res[MAXN][MAXN];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d %d %d", &r, &c, &k);
		
		int rice = 0;
		for(int i = 0; i < r; i++){
			scanf(" %s", g[i]);
			for(int j = 0; j < c; j++)
				if(g[i][j] == 'R')rice++;
		}
		
		
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++)
				res[i][j] = chicken(k - 1);
			res[i][c] = 0;
		}
		
		int x = 0, y = 0;
		for(int i = 0; i < k; i++){
			int cur = rice / k;
			if(i < (rice % k))cur++;
			
			while(cur > 0){
				res[x][y] = chicken(i);
				if(g[x][y] == 'R')cur--;
				
				if(x % 2 == 0){
					if(y == c - 1){
						x++;
					}else{
						y++;
					}
				}else{
					if(y == 0){
						x++;
					}else{
						y--;
					}
				}
			}
		}
		
		for(int i = 0; i < r; i++)
			printf("%s\n", res[i]);
	}
	return 0;
}