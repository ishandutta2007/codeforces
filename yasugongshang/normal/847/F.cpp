/*
nk
ma





100
*/
#include<bits/stdc++.h>
using namespace std;

const int maxn = 109;
int cnt[maxn], last[maxn], rk[maxn], ans[maxn];
int n, K, m, a, t;

bool check1(int x){
	int tmp[maxn], N = 0, sum = 0;
	for (int i=1; i<=n; i++){
		if (i == x) continue;
		if (cnt[i] < cnt[x]) tmp[++N] = cnt[x] - cnt[i] + 1;
		else if (cnt[i] == cnt[x] && (!cnt[x] || last[i] > last[x])) tmp[++N] = 1;
		else tmp[++N] = 0;
	}
	sort(tmp+1, tmp+N+1);
	for (int i=1; i<=K&&i<=N; i++)
		sum += tmp[i];
	return cnt[x] && (K == n || sum > m-a);
}

bool check3(int x){
	int sum = 0;
	cnt[x] += m-a;
	for (int i=1; i<=n; i++)
		if (i != x && cnt[i] >= cnt[x]) sum++;
	cnt[x] -= m-a;
	return sum >= K;
}

bool cmp(int a, int b){
	return cnt[a] > cnt[b] || cnt[a] == cnt[b] && last[a] < last[b];
}

void solve(){
	for (int i=1; i<=n; i++) rk[i] = i;
	sort(rk+1, rk+n+1, cmp);
	for (int i=1; i<=K; i++) if (cnt[rk[i]]) ans[rk[i]] = 1; else ans[rk[i]] = 3;
	for (int i=K+1; i<=n; i++) ans[rk[i]] = 3;
	for (int i=1; i<=n; i++) printf("%d ", ans[i]);
}

int main(){
	scanf("%d%d%d%d", &n, &K, &m, &a);
	for (int i=1; i<=a; i++){
		scanf("%d", &t); cnt[t]++; last[t] = i;
	}
	if (a == m) { solve(); return 0; }
	for (int i=1; i<=n; i++)
		if (check1(i)) { putchar('1'); putchar(' '); }
		else if (check3(i)) { putchar('3'); putchar(' '); }
		else { putchar('2'); putchar(' '); }
	return 0;
}