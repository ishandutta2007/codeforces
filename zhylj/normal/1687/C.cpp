    #include <bits/stdc++.h>
     
    #define gc() getchar()
    template <typename T> inline void rd(T& x) {
    	int si = 1; char c = gc(); x = 0;
    	while(!isdigit(c)) si = c == '-' ? -1 : si, c = gc();
    	while(isdigit(c)) x = x * 10 + c - 48, c = gc();
    	x *= si;
    }
    template <typename T, typename... Args>
    inline void rd(T& x, Args&... args) { rd(x); rd(args...); }
    #define fi first
    #define se second
    #define mkp std::make_pair
    typedef unsigned ui;
    typedef long long ll;
    typedef unsigned long long ull;
    typedef double ff;
    typedef std::pair <int, int> pii;
    const int N = 5e5 + 5;
     
    int n, m, fa[N]; ll a[N];
    std::vector <int> L[N], R[N];
    std::queue <int> que;
     
    int cnt = 0;
    int Find(int x) { return x == fa[x] ? x : fa[x] = Find(fa[x]); }
    void Merge(int x, int y) { fa[Find(x)] = Find(y); }
    void Color(int l, int r) {
    	if(a[l] || a[r]) return;
    	std::vector <int> tmp;
    	for(int i = l; i <= r; i = Find(i) + 1) {
    		if(a[i]) {
    			a[i] = 0;
    			que.push(i);
    		}
    		tmp.push_back(i);
    	}
    	for(int i : tmp) {
    		++cnt;
    		Merge(i, r);
    	}
    }
     
    int main() {
    #ifndef ONLINE_JUDGE
    	freopen("a.in", "r", stdin);
    	freopen("a.out", "w", stdout);
    #endif
    	int test_case_cnt = 1; rd(test_case_cnt);
    	while(test_case_cnt--) {
    		rd(n, m);
    		for(int i = 0; i <= n + 1; ++i) {
    			a[i] = 0;
    			L[i].clear(); R[i].clear(); fa[i] = i;
    		}
    		for(int i = 1; i <= n; ++i) rd(a[i]);
    		for(int i = 1; i <= n; ++i) {
    			int x; rd(x); a[i] -= x;
    			a[i] = a[i - 1] + a[i];
    		}
    		for(int i = 1; i <= m; ++i) {
    			int l, r; rd(l, r); --l;
    			R[l].push_back(r);
    			L[r].push_back(l);
    		}
    		if(a[n] != 0) {
    			printf("NO\n");
    			continue;
    		}
    		for(int i = 0; i <= n; ++i)
    			if(!a[i]) que.push(i);
    		while(!que.empty()) {
    			int u = que.front(); que.pop();
    			for(int l : L[u]) Color(l, u);
    			for(int r : R[u]) Color(u, r);
    		}
    		bool flag = true;
    		for(int i = 0; i <= n; ++i)
    			if(a[i] != 0) { flag = false; }
    		if(flag) printf("YES\n");
    		else printf("NO\n");
    	} return 0;
    }