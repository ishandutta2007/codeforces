#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int K = 26;
const int N = 205;
typedef long long llong;

struct vertex {
    int next[K];
    int leaf;
    int w = -1;
    int p;
    char pch;
    int link;
    int go[K];
};

vertex t[N+1];
int sz;

void init() {
    t[0].p = t[0].link = -1;
    memset (t[0].next, 255, sizeof t[0].next);
    memset (t[0].go, 255, sizeof t[0].go);
    sz = 1;
}

void add_string (const string & s, int dw) {
    int v = 0;
    for (size_t i=0; i<s.length(); ++i) {
        int c = s[i]-'a';
        if (t[v].next[c] == -1) {
            memset (t[sz].next, 255, sizeof t[sz].next);
            memset (t[sz].go, 255, sizeof t[sz].go);
            t[sz].link = -1;
            t[sz].p = v;
            t[sz].pch = c;
            t[v].next[c] = sz++;
        }
        v = t[v].next[c];
    }
    t[v].leaf += dw;
}

int go (int v, int c);

int get_link (int v) {
    if (t[v].link == -1) {
        if (v == 0 || t[v].p == 0)
            t[v].link = 0;
        else
            t[v].link = go (get_link (t[v].p), t[v].pch);
    }
    return t[v].link;
}

int go (int v, int c) {
    if (t[v].go[c] == -1) {
        if (t[v].next[c] != -1)
            t[v].go[c] = t[v].next[c];
        else
            t[v].go[c] = v==0 ? 0 : go (get_link (v), c);
    }
    return t[v].go[c];
}

llong A[N];

const llong inf = 1e17;

struct mat {
    llong A[N][N];
    mat() {
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                A[i][j] = (i == j) ? 0 : -inf;
            }
        }
    }
    friend mat operator *(mat a, mat b) {
        mat res;
        for (int i = 0; i < sz; i++) {
            for (int j = 0; j < sz; j++) {
                llong val = -inf;
                for (int k = 0; k < sz; k++) {
                    val = max(val, a.A[i][k] + b.A[k][j]);
                }
                res.A[i][j] = val;
            }
        }
        return res;
    }
};

mat powmod(mat a, llong b) {
    mat res;
    while (b) {
        if (b & 1) {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

int getw(int v) {
    if (v <= 0)
        return 0;
    if (t[v].w != -1)
        return t[v].w;
    return t[v].w = t[v].leaf + getw(get_link(v));
}


int main() {
    int n;
    llong l;
    scanf("%d %lld", &n, &l);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &A[i]);
    }
    init();
    for (int i = 0; i < n; i++) {
        char buf[N + 10];
        scanf("%s", buf);
        string s = buf;
        add_string(s, A[i]);
    }
    for (int i = 0; i < sz; i++) {
        t[i].w = getw(i); //t[i].leaf + t[get_link(i)].w;
    }
    mat M;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            M.A[i][j] = -inf;
        }
    }
    for (int i = 0; i < sz; i++) {
        for (int c = 0; c < K; c++) {
            int j = go(i, c);
            M.A[i][j] = max(M.A[i][j], (llong)t[j].w);
        }
    }
    mat res = powmod(M, l);
    llong ans = -inf;
    for (int i = 0; i < sz; i++) {
        ans = max(ans, res.A[0][i]);
    }
    printf("%lld\n", ans);
}