#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int n, m, erased[MAXN];
char s[MAXN][MAXN];

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++)
		scanf("%s", s[i]);

	for(int itr = 0; itr < m; itr++){
		bool ok = true;

		for(int i = 0; i + 1 < n; i++){
			int c = -1;
			for(int j = 0; j < m; j++)if(!erased[j]){
				if(s[i][j] < s[i + 1][j])break;
				else if(s[i][j] > s[i + 1][j]){
					c = j;
					break;
				}
			}
			if(c != -1){
				erased[c] = true;
				ok = false;
				break;
			}
		}
		if(ok){
			printf("%d\n", itr);
			return 0;
		}
	}
	printf("%d\n", m);

	return 0;
}