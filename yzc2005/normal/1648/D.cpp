#include <bits/stdc++.h>
using namespace std;
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define Flush FastIO::Fflush()
namespace FastIO {
    const int SIZE = 1 << 16;
    char buf[SIZE], obuf[SIZE], str[60];
    int bi = SIZE, bn = SIZE, opt;
    int read(char *s) {
        while (bn) {
            for (; bi < bn && buf[bi] <= ' '; bi++);
            if (bi < bn) break;
            bn = fread(buf, 1, SIZE, stdin);
            bi = 0;
        }
        int sn = 0;
        while (bn) {
            for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
            if (bi < bn) break;
            bn = fread(buf, 1, SIZE, stdin);
            bi = 0;
        }
        s[sn] = 0;
        return sn;
    }
    bool read(int& x) {
        if(x) x = 0;
        int n = read(str), bf = 0;
        if (!n) return 0;
        int i = 0; if (str[i] == '-') bf = 1, i++; else if (str[i] == '+') i++;
        for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
        if (bf) x = -x;
        return 1;
    }
    bool read(long long& x) {
        if(x) x = 0;
        int n = read(str), bf;
        if (!n) return 0;
        int i = 0; if (str[i] == '-') bf = -1, i++; else bf = 1;
        for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
        if (bf < 0) x = -x;
        return 1;
    }
    void write(int x) {
        if (x == 0) obuf[opt++] = '0';
        else {
            if (x < 0) obuf[opt++] = '-', x = -x;
            int sn = 0;
            while (x) str[sn++] = x % 10 + '0', x /= 10;
            for (int i = sn - 1; i >= 0; i--) obuf[opt++] = str[i];
        }
        if (opt >= (SIZE >> 1)) {
            fwrite(obuf, 1, opt, stdout);
            opt = 0;
        }
    }
    void write(long long x) {
        if (x == 0) obuf[opt++] = '0';
        else {
            if (x < 0) obuf[opt++] = '-', x = -x;
            int sn = 0;
            while (x) str[sn++] = x % 10 + '0', x /= 10;
            for (int i = sn - 1; i >= 0; i--) obuf[opt++] = str[i];
        }
        if (opt >= (SIZE >> 1)) {
            fwrite(obuf, 1, opt, stdout);
            opt = 0;
        }
    }
    void write(unsigned long long x) {
        if (x == 0) obuf[opt++] = '0';
        else {
            int sn = 0;
            while (x) str[sn++] = x % 10 + '0', x /= 10;
            for (int i = sn - 1; i >= 0; i--) obuf[opt++] = str[i];
        }
        if (opt >= (SIZE >> 1)) {
            fwrite(obuf, 1, opt, stdout);
            opt = 0;
        }
    }
    void write(char x) {
        obuf[opt++] = x;
        if (opt >= (SIZE >> 1)) {
            fwrite(obuf, 1, opt, stdout);
            opt = 0;
        }
    }
    void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt = 0;}
};
const int N = 5e5 + 5;
int n, q;
long long a[N], b[N], c[N], dp[N];
vector<pair<int, int>> v[N];
long long mx1[N << 3], mx2[N << 3];
struct node {
	priority_queue<int, vector<int>, greater<int>> p1, p2;
	inline void insert(int x) { p1.push(x); }
	inline void erase(int x) { p2.push(x); }
	inline int get() {
		while (!p1.empty()) {
			int x = p1.top(); 
			if (!p2.empty() && x == p2.top()) p1.pop(), p2.pop();
			else return x;
		}
		return -1;
	}
} s[N << 2];
inline void update(int p) {
	mx2[p] = max(mx2[p << 1], mx2[p << 1 | 1]);
	int x = s[p].get();
	if (~x) mx2[p] = max(mx2[p], mx1[p] - x);
}
inline void push_up(int p) { mx1[p] = max(mx1[p << 1], mx1[p << 1 | 1]), update(p); }
void modify(int p, int l, int r, int pos, long long x) {
	if (l == r) {
		mx1[p] = max(mx1[p], x), update(p);
		return;
	}
	int mid = (l + r) >> 1;
	if (mid >= pos) modify(p << 1, l, mid, pos, x);
	else modify(p << 1 | 1, mid + 1, r, pos, x);
	push_up(p);
}
void push(int p, int l, int r, int ll, int rr, int x) {
	if (l >= ll && r <= rr) {
		if (x > 0) s[p].insert(x);
		else s[p].erase(-x);
		update(p); return; 
	}
	int mid = (l + r) >> 1;
	if (mid >= ll) push(p << 1, l, mid, ll, rr, x);
	if (mid < rr) push(p << 1 | 1, mid + 1, r, ll, rr, x);
	push_up(p);
}
int main() {
	FI(n), FI(q);
	for (int i = 1; i <= n; ++i) 
		FI(a[i]), a[i] += a[i - 1];
	for (int i = 1; i <= n; ++i) 
		FI(b[i]), b[i] += b[i - 1];
	for (int i = 1; i <= n; ++i) 
		FI(c[i]), c[i] += c[i - 1];
	for (int i = 1; i <= q; ++i) {
		int l, r, x;
		FI(l), FI(r), FI(x);
		v[l].emplace_back(l - 1, x);
		v[r + 1].emplace_back(l - 1, -x);
	}
	long long ans = -1e18;
	memset(dp, 0xcf, sizeof dp);
	memset(mx1, 0xcf, sizeof mx1);
	memset(mx2, 0xcf, sizeof mx2);
	for (int i = 1; i <= n; ++i) {
		long long val = a[i] - b[i - 1];
		modify(1, 0, n, i - 1, val);
		for (auto it : v[i]) {
			int l = it.first, x = it.second;
			push(1, 0, n, l, n, x);
		}
		modify(1, 0, n, i, dp[i] = mx2[1]);
		ans = max(ans, dp[i] + b[i] + c[n] - c[i - 1]);
	}
	printf("%lld\n", ans);
	return 0;
}