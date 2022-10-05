#include<bits/stdc++.h>
#define LL long long
#define P pair<LL, int>
#define mp make_pair
#define fst first
#define sed second
using namespace std;
LL sb[100100], ans[100100], sa;
int n, m, Q, x, b[100100], l, r;
P q[100100];
int main() {
	scanf("%d%d%d", &n, &m, &Q);
	for(int i = 1, f = 1; i <= n; i++, f = -f) {
		scanf("%d", &x);
		sa += x * f;
	}
	for(int i = 1, f = 1, l = 1; i <= m; i++, f = -f) {
		scanf("%d", &b[i]);
		b[i] *= f;
		if(i - l == n) l++, sb[l] = sb[l - 1] - b[l - 1];
		sb[l] += b[i];
	}
	for(int i = 2; i <= m - n + 1; i += 2) sb[i] = -sb[i];
	q[0] = mp(sa, 0);
	for(int i = 1; i <= Q; i++) {
		scanf("%d%d%d", &l, &r, &x);
		if((r - l + 1) & 1) 
			sa += ((l & 1) ? 1 : -1) * x;
		q[i] = mp(sa, i);
	}
	sort(q, q + Q + 1);
	sort(sb + 1, sb + m - n + 2);
	for (int i=0;i<Q;i++) if (q[i].fst>q[i+1].fst) assert(0);
	for (int i=1;i<m-n+1;i++) if (sb[i]>sb[i+1]) assert(0);
	int j = 1;
	for(int i = 0; i <= Q; i++) {
		while(abs(sb[j + 1] - q[i].fst) <= abs(sb[j] - q[i].fst) && j + 1 <= m - n + 1) j++;
		ans[q[i].sed] = abs(q[i].fst - sb[j]);
	}
	for(int i = 0; i <= Q; i++) printf("%I64d\n", ans[i]);
}