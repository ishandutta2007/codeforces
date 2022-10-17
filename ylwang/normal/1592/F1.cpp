#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 5;
int a[N][N];
char s[N]; 
int main() {
	int n, m; scanf("%d %d", &n, &m); 
	for(int i = 1; i <= n; i++) {
		scanf("%s", s + 1);
		for(int j =	1; j <= m; j++)
			a[i][j] = s[j] == 'B';
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			a[i][j] ^= a[i][j + 1] ^ a[i + 1][j] ^ a[i + 1][j + 1], cnt += a[i][j] == 1;
//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= m; j++) {
//			cerr << a[i][j] << ' ';
//		}
//		cerr << endl; 
//	} 
//	cerr << cnt << endl; 
	if(a[n][m] == 0) printf("%d\n", cnt);
	else {
		for(int i = 1; i < n; i++)
			for(int j = 1; j < m; j++) 
				if(a[i][j] && a[n][j] && a[i][m]) {
//					cerr << i << ' ' << j <<endl; 
					printf("%d\n", cnt - 1);
					return 0;
				}
		printf("%d\n", cnt); 
	}
	return 0;	
}