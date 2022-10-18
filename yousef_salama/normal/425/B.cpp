#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int e, n, m, k, a[MAXN][MAXN];
int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)
		scanf("%d", &a[i][j]);

	if(n <= 10){
		int r = 1 << 30;
		for(int mask = 0; mask < (1 << n); mask++){
			int s = 0;
			for(int j = 0; j < m; j++){
				int c = 0;
				for(int i = 0; i < n; i++){
					if(a[i][j] == 1 && !(mask & (1 << i)))c++;
					if(a[i][j] == 0 && (mask & (1 << i)))c++;
				}
				s += min(c, n - c);
			}
			r = min(r, s);
		}
		if(r > k)printf("-1\n");
		else printf("%d\n", r);
	}else{
		int r = 1 << 30;
		for(int i = 0; i < n; i++){
			int s = 0;
			for(int j = 0; j < n; j++){
				int c = 0;
				for(int k = 0; k < m; k++)
					c += (a[i][k] != a[j][k]);
				s += min(c, m - c);
			}
			r = min(r, s);
		}
		if(r > k)printf("-1\n");
		else printf("%d\n", r);
	}

	return 0;
}