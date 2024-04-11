#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 1e6 + 7;
int n, m;
bool Prime[N];
int p[N], tot, nxt[N];
void xxs(int x) {
	L(i, 2, x) {
		if(!Prime[i]) p[++tot] = i;
		for(int j = 1; p[j] * i <= x && j <= tot; j ++) {
			Prime[p[j] * i] = 1;
			if(i % p[j] == 0) break;
		}
	}
	R(i, x, 1) if(!Prime[i]) {
		nxt[i] = i;
	}
	else nxt[i] = nxt[i + 1];
}
char s[N];
void Main() {
	scanf("%d", &n);
	int a = nxt[n + 1];
	printf("%lld\n", (ll) a * nxt[a + n]);
}
int main() {
	xxs(1000000);
	int T; scanf("%d", &T);
	while(T--) Main();
	return 0;
}