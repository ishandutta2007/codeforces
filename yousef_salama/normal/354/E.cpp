#include <bits/stdc++.h>
using namespace std;

const int MAXN = 25;
const int MAXC = 5;

int t, n, dp[MAXN][MAXC], dpn4[MAXN][MAXC], dpn7[MAXN][MAXC];
char s[MAXN], r[6][MAXN];

int main(){
	scanf("%d", &t);

	while(t--){
		scanf("%s", s);
		n = strlen(s);

		reverse(s, s + n);
		for(int i = n; i >= 0; i--)
		for(int j = 0; j < MAXC; j++){
			if(i == n){
				if(j == 0)dp[i][j] = 1;
				else dp[i][j] = 0;
			}else{
				dp[i][j] = 0;
				for(int n4 = 0; n4 <= 6; n4++)
				for(int n7 = 0; n4 + n7 <= 6; n7++){
					int x = n4 * 4 + n7 * 7 + j;
					if(x % 10 == (s[i] - '0')){
						if(dp[i + 1][x / 10] == 0)continue;

						dpn4[i][j] = n4;
						dpn7[i][j] = n7;
						dp[i][j] = 1;
					}
				}
			}
		}

		if(dp[0][0] == 0)printf("-1\n");
		else{
			int i = 0, j = 0;
			while(i < n){
				int n4 = dpn4[i][j], n7 = dpn7[i][j];
				for(int k = 0; k < n7; k++)
					r[k][i] = '7';
				for(int k = n7; k < n7 + n4; k++)
					r[k][i] = '4';
				for(int k = n4 + n7; k < 6; k++)
					r[k][i] = '0';

				j = (n4 * 4 + n7 * 7 + j) / 10;
				i++;
			}

			for(int k = 0; k < 6; k++){
				if(k > 0)printf(" ");

				reverse(r[k], r[k] + n);
				r[k][n] = 0;

				int j = 0;
				while(j + 1 < n && r[k][j] == '0')j++;

				printf("%s", r[k] + j);
			}
			printf("\n");
		}
	}
	return 0;
}