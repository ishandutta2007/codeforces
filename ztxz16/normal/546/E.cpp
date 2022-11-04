#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int NSIZE = 405;    // 
const int MSIZE = 100005; // 
const int INF = 1000000000; //
 
//tot
//1
 
struct MaxFlow {
    int e[MSIZE << 1], succ[MSIZE << 1], last[NSIZE], val[MSIZE << 1], sum; // 
    int tot; // 
    int dis[NSIZE], pre[NSIZE], gap[NSIZE], cur[NSIZE];
    
    void init (const int &_tot) {
        tot = _tot;
        sum = 1;
        for (int i = 0; i <= tot; i++) {
            last[i] = dis[i] = gap[i] = pre[i] = cur[i] = 0;
        }
        
        gap[0] = tot;
    }
    
    void add(const int &a, const int &b, const int &c, const int &d = 0) {
        e[++sum] = b, succ[sum] = last[a], last[a] = sum;
        e[++sum] = a, succ[sum] = last[b], last[b] = sum;
        val[sum - 1] = c, val[sum] = d;
    }
    
    int sap(const int &s, const int &t) {
        int ans = 0;
        for (int now = s; dis[s] < tot; ) {
            for (int &i = cur[now]; i; i = succ[i]) {
                if (val[i] && dis[now] == dis[e[i]] + 1) {
                    pre[e[i]] = i, now = e[i];
                    break;
                }
            }
            
            if (now == t) {
                int flow = INF;
                for (; now != s; now = e[pre[now] ^ 1]) {
                    flow = min(flow, val[pre[now]]);
                }
                
                ans += flow;
                for (now = t; now != s; now = e[pre[now] ^ 1]) {
                    val[pre[now]] -= flow, val[pre[now] ^ 1] += flow;
                }
            } else if (cur[now] == 0) {
                if (gap[dis[now]] == 1) {
                    return ans;
                }
                
                int _min = tot;
                for (int i = last[now]; i; i = succ[i]) {
                    if (val[i] && dis[e[i]] + 1 < _min) {
                        _min = dis[e[i]] + 1;
                        cur[now] = i;
                    }
                }
                
                gap[dis[now]]--, gap[_min]++, dis[now] = _min;
                if (now != s) {
                    now = e[pre[now] ^ 1];
                }
            }
        }
        
        return ans;
    }
} maxFlow;

const int N = 105;
int n, m, s, a[N], b[N];
int ans[N][N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        s += a[i];
    }
    
    int s2 = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        s2 += b[i];
    }
    
    if (s != s2) {
        printf("NO\n");
        return 0;
    }
    
    int source = n + n + 1, target = source + 1;
    maxFlow.init(target);
    for (int i = 1; i <= n; i++) {
        maxFlow.add(source, i, a[i]);
        maxFlow.add(i + n, target, b[i]);
        maxFlow.add(i, i + n, a[i]);
    }
    
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        maxFlow.add(x, y + n, a[x]);
        maxFlow.add(y, x + n, a[y]);
    }
    
    if (maxFlow.sap(source, target) == s) {
        printf("YES\n");
        for (int i = 1; i <= n; i++) {
            for (int x = maxFlow.last[i]; x; x = maxFlow.succ[x]) {
                int y = maxFlow.e[x];
                if (y > n && y <= n + n && !(x & 1)) {
                    ans[i][y - n] += maxFlow.val[x ^ 1];
                }
            }
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                printf("%d%c", ans[i][j], j == n ? '\n' : ' ');
            }
        }
    } else {
        printf("NO\n");
    }
    return 0;
}