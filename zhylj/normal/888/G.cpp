#include <bits/stdc++.h>

typedef long long ll;

const int kMaxN = 2e5 + 5;
const int kMaxDep = 31;
const int kTrie = kMaxN * kMaxDep + 5;
const int kInf = 0x3f3f3f3f;

int T[kTrie][2], L[kTrie], R[kTrie], a[kMaxN], n, cnt = 0;
void Insert(int cur, int v, int pos) {
	for(int bit = kMaxDep; ~bit; --bit) {
		//printf("%d %d\n", cur, bit);
		int x = (v >> bit) & 1;
		if(!T[cur][x]) { T[cur][x] = ++cnt; L[cnt] = pos; R[cnt] = pos; }
		L[cur] = std::min(pos, L[cur]); R[cur] = std::max(pos, R[cur]);
		cur = T[cur][x];
	}
}
ll Query(int cur, int bit, int v) {
	ll ret = 1 << (bit + 1);
	for(; ~bit; --bit) {
		int x = (v >> bit) & 1;
		if(!T[cur][x]) { ret |= 1 << bit; x ^= 1; }
		cur = T[cur][x];
	}
	return ret;
}
ll Dfs(int cur, int bit) {
	if(!bit) return (T[cur][0] && T[cur][1]) ? (a[L[T[cur][0]]] ^ a[L[T[cur][1]]]) : 0;
	//printf("%d %d\n", cur, bit);
	ll ret = 0, minn = kInf;
	if(T[cur][0]) ret += Dfs(T[cur][0], bit - 1);
	if(T[cur][1]) ret += Dfs(T[cur][1], bit - 1);
	if(!T[cur][0] || !T[cur][1]) return ret;
	for(int i = L[T[cur][0]]; i <= R[T[cur][0]]; ++i)
		minn = std::min(minn, Query(T[cur][1], bit - 1, a[i]));
	return ret += minn;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d", a + i);
	std::sort(a + 1, a + n + 1);
	L[0] = kInf; R[0] = 0;
	for(int i = 1; i <= n; ++i)
		Insert(0, a[i], i);
	printf("%lld", Dfs(0, kMaxDep));
	return 0;
}