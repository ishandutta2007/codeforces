#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

int n, res[MAXN];
char s[5];

int main(){    
    scanf("%d", &n);
    
    int p = 1000;
    for(int i = 0; i < n; i++){
		scanf("%s", s);
		
		int x = -1;
		for(int j = 0; j < 4; j++)
		for(int d = 0; d <= 9; d++){
			int c = 0;
			for(int k = 0; k < 4; k++){
				if(j == k)c = 10 * c + d;
				else c = 10 * c + (s[k] - '0');
			}
			
			if(p <= c && c <= 2011){
				if(x == -1 || c < x){
					x = c;
				}
			}
		}
		
		if(x == -1){
			printf("No solution\n");
			return 0;
		}
		
		res[i] = x;
		p = x;
	}
	
	for(int i = 0; i < n; i++)
		printf("%d\n", res[i]);
    
    return 0;
}