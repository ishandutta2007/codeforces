#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, k, a, cur;
long long ans;

struct Trie {
	int son[N << 5][2], end[N << 5], cnt;
	inline void insert(int x) {
		int p = 0, c;
		for(int i = 29; ~i; --i) {
			c = x >> i & 1;
			if(!son[p][c]) son[p][c] = ++cnt;
			p = son[p][c], ++end[p];
		}  
	}
	inline int query(int x) {
		int p = 0, ans = 0;
		for(int i = 29; ~i; --i) {
			int cx = x >> i & 1, ck = k >> i & 1;
			if(ck) p = son[p][cx ^ 1];
			else {
				ans += end[son[p][cx ^ 1]];
				p = son[p][cx];
			}
			if(!p) return ans;
			if(!i) return ans + end[p]; 
		}
	}
} trie;

int main() {
	scanf("%d%d", &n, &k);
	while(n--) {
		trie.insert(cur);
		scanf("%d", &a), cur ^= a;
		ans += trie.query(cur); 
	}
	printf("%lld\n", ans);
	return 0;
}