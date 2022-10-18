#include <bits/stdc++.h>
using namespace std;

const int MAXN = 55;
const int MAXC = 550005;

int n, d, c[MAXN], dp[MAXC];
int main(){
	scanf("%d %d", &n, &d);
	for(int i = 0; i < n; i++)
		scanf("%d", &c[i]);

	sort(c, c + n);

	dp[0] = 1;

	int s = 0;
	for(int i = 0; i < n; i++){
		if(s + d < c[i]){
			n = i;
			break;
		}else{
			s += c[i];
			for(int j = MAXC - 1; j >= c[i]; j--)
				dp[j] |= dp[j - c[i]];
		}
	}

	printf("%d ", s);

	int t = 0, c = 0;
	while(c < s){
		for(int i = c + d; i > c; i--)if(dp[i]){
			c = i;
			break;
		}
		t++;
	}
	printf("%d\n", t);

	return 0;
}