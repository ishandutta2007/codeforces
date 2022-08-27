#include <bits/stdc++.h>
#define N 100034
using namespace std;

typedef char state;
typedef long long ll;

int n, m;
char s[N];
ll f[N][8];

int main(){
	int i, j, k; state p;
	int q[3], nq[3];
	scanf("%d%d%s", &n, &m, s + 1);
	for(i = 1; i <= n; ++i) s[i] &= 31;
	for(i = 1; i <= m; ++i){
		p = 1; // lcs[1][0] = 1
		if(i == s[1]) p |= 2; // lcs[1][1] = 1
		if(i == s[1] || i == s[2]) p |= 4; // lcs[1][2] = 1;
		++f[1][p];
	}
	for(i = 1; i < n; ++i)
		for(j = 0; j < 8; ++j)
			if(f[i][j]){
				q[0] = i - 2 + (j & 1);
				q[1] = i - 1 + (j >> 1 & 1);
				q[2] = i - 1 + (j >> 2 & 1);
				for(k = 1; k <= m; ++k){
					nq[0] = (k == s[i] ? q[0] + 1 : q[1]);
					nq[1] = (k == s[i + 1] ? q[1] + 1 : max(nq[0], q[2]));
					nq[2] = (k == s[i + 2] ? q[2] + 1 : nq[1]);
					if(nq[0] < i - 1 || nq[1] < i || nq[2] < i) continue;
					p = nq[0] - (i - 1);
					p |= (nq[1] - i) << 1;
					p |= (nq[2] - i) << 2;
					f[i + 1][p] += f[i][j];
				}
			}
	printf("%lld\n", f[n][0] + f[n][1] + f[n][4] + f[n][5]);
	return 0;
}