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
int n, m, a[N], b[N], cnt[N], p[N];
void getans(int t) {
	puts("YES");
	printf("%d\n", t + a[n]);
	L(i, 1, n) cnt[a[i]] ++;
	int A, B;
	cnt[t] --, cnt[a[n]] --;
	printf("%d %d\n", t, a[n]);
	int las = a[n];
	R(i, n - 1, 1) {
		if(!cnt[a[i]]) continue;
		cnt[a[i]] --;
		A = a[i];
		cnt[las - a[i]] --;
		B = las - a[i];
		printf("%d %d\n", A, B);
		las = a[i];
	}
	L(i, 1, n) cnt[a[i]] = 0;
}
void Main() {
	bool flag = 0;
	scanf("%d", &n);
	n = n * 2;
	L(i, 1, n) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	L(t, 1, n - 1) {
		L(i, 1, n) cnt[a[i]] ++;
		cnt[a[t]] --, cnt[a[n]] --;
		int las = a[n];
		bool ok = 1;
		R(i, n - 1, 1) {
			if(!cnt[a[i]]) continue;
			cnt[a[i]] --;
			if(!cnt[las - a[i]]) {
				ok = 0;
				break;
			}
			cnt[las - a[i]] --;
			las = a[i];
		}
		L(i, 1, n) cnt[a[i]] = 0;
		if(!ok) continue;
		getans(a[t]);
		flag = 1;
		break;
	}
	if(!flag) puts("NO");
}
int main() {
	int T; scanf("%d", &T);
	while(T--) Main();
	return 0;
}