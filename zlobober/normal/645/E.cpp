#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MOD = 1000 * 1000 * 1000 + 7;


inline int add(int a, int b) {
    int s = a + b;
    if (s >= MOD)
        s -= MOD;
    return s;
}

inline int neg(int a) {
    return (a == 0) ? 0 : (MOD - a);
}

inline int sub(int a, int b) {
    int s = a - b;
    if (s < 0)
        s += MOD;
    return s;
}

const int N = 1000500;
char buf[N];
int k;
int last[N];
int cur[N];

int pt = 0;
inline void put(int x) {
    int sum = 1;
    for (int j = 0; j < k; j++) {
        sum = add(sum, cur[j]); 
    }
    cur[x] = sum;
    last[x] = pt++;
}

int main() {
    int n;
    scanf("%d %d", &n, &k);
    scanf("%s", buf);
    int l = strlen(buf);
    memset(last, -1, sizeof(int) * k);
    for (int i = 0; i < l; i++) {
        put(buf[i] - 'a');
    }
    vector<int> order(k);
    for (int i = 0; i < k; i++)
        order[i] = i;
    sort(order.begin(), order.end(), [](int a, int b) { return last[a] < last[b]; });
    for (int i = 0; i < n; i++) {
        int j = order[i % k];
        put(j);
    }
    int ans = 1;
    for (int i = 0; i < k; i++) {
        ans = add(ans, cur[i]);
    }
    printf("%d\n", ans);
}