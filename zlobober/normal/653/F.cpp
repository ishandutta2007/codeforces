#include <cstdio>
#include <cassert>
#include <algorithm>
#include <memory.h>
using namespace std;

typedef long long llong;

namespace emaxx_SA {
    int n;
     
    const int maxlen = 1 << 21;
    const int alphabet = 1 << 21;
    int s[maxlen];
    
    int p[maxlen], cnt[maxlen], c[maxlen];
    int pn[maxlen], cn[maxlen];
    int ip[maxlen], lcp[maxlen];
    void build_SA() {
        memset (cnt, 0, alphabet * sizeof(int));
        for (int i=0; i<n; ++i)
            ++cnt[s[i]];
        for (int i=1; i<alphabet; ++i)
            cnt[i] += cnt[i-1];
        for (int i=0; i<n; ++i)
            p[--cnt[s[i]]] = i;
        c[p[0]] = 0;
        int classes = 1;
        for (int i=1; i<n; ++i) {
            if (s[p[i]] != s[p[i-1]])  ++classes;
            c[p[i]] = classes-1;
        }
        
        for (int h=0; (1<<h)<n; ++h) {
            for (int i=0; i<n; ++i) {
                pn[i] = p[i] - (1<<h);
                if (pn[i] < 0)  pn[i] += n;
            }
            memset (cnt, 0, classes * sizeof(int));
            for (int i=0; i<n; ++i)
                ++cnt[c[pn[i]]];
            for (int i=1; i<classes; ++i)
                cnt[i] += cnt[i-1];
            for (int i=n-1; i>=0; --i)
                p[--cnt[c[pn[i]]]] = pn[i];
            cn[p[0]] = 0;
            classes = 1;
            for (int i=1; i<n; ++i) {
                int mid1 = (p[i] + (1<<h)) % n,  mid2 = (p[i-1] + (1<<h)) % n;
                if (c[p[i]] != c[p[i-1]] || c[mid1] != c[mid2])
                    ++classes;
                cn[p[i]] = classes-1;
            }
            memcpy (c, cn, n * sizeof(int));
        }

        for (int i = 0; i < n; i++)
            ip[p[i]] = i;
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (k > 0)
                k--;
            if (ip[i] == n - 1)
                lcp[n - 1] = 0, k = 0;
            else {
                int j = p[ip[i] + 1];
                while (j + k < n && i + k < n && s[i + k] == s[j + k])
                    k++;
                lcp[ip[i]] = k;
            }
        }
    }
}

const int N = 1 << 20;

int P1 = 1000 * 1000 * 1000 + 7, P2 = 42424243;
struct hsh {
    int x1, x2;
    hsh(int x) {
        x1 = x % P1, x2 = x % P2;
    }
    inline hsh(int x1, int x2) {
        this->x1 = x1;
        this->x2 = x2;
    }
    inline friend hsh operator +(hsh a, hsh b) {
        a.x1 += b.x1;
        if (a.x1 >= P1)
            a.x1 -= P1;
        a.x2 += b.x2;
        if (a.x2 >= P2)
            a.x2 -= P2;

        return hsh(a.x1, a.x2);
    }
    inline friend hsh operator -(hsh a, hsh b) {
        a.x1 -= b.x1;
        if (a.x1 < 0)
            a.x1 += P1;
        a.x2 -= b.x2;
        if (a.x2 < 0)
            a.x2 += P2;

        return hsh(a.x1, a.x2);
    }
    inline friend hsh operator *(hsh a, hsh b) {
        return hsh(1ll * a.x1 * b.x1 % P1, 1ll * a.x2 * b.x2 % P2);
    }
    inline friend bool operator <(hsh a, hsh b) {
        if (a.x1 != b.x1)
            return a.x1 < b.x1;
        return a.x2 < b.x2;
    }
    inline friend bool operator ==(hsh a, hsh b) {
        return a.x1 == b.x1 && a.x2 == b.x2;;
    }
    hsh() {
    }
};


char buf[N];

int cnt[2 * N];
int bal[2 * N];
int pos[2 * N];
hsh H[2 * N];
hsh AA[2 * N];

hsh A(12345, 6789);

hsh get_hash(int l, int r) {
    return H[r] - H[l] * AA[r - l];
}

int T[2 * N];
int get_min(int l, int r) {
    l += N;
    r += N;
    int mn = 1e9;
    while (l <= r) {
        if (l & 1)
            mn = min(mn, T[l]);
        if (!(r & 1))
            mn = min(mn, T[r]);
        l = (l + 1) >> 1;
        r = (r - 1) >> 1;
    }
    return mn;
}


int pt = 0;
hsh str[2 * N];
hsh dstr[2 * N];
int main() {
    int n;
    scanf("%d %s", &n, buf);
    int curbal = 0;
    for (int i = 0; i <= n; i++) {
        T[i + N] = curbal;
        cnt[curbal + N]++;
        if (i == n)
            continue;
        curbal += (buf[i] == '(') ? 1 : -1;
    }
    for (int i = N - 1; i >= 1; i--)
        T[i] = min(T[2 * i], T[2 * i + 1]);
    curbal = 0;
    for (int i = 1; i < 2 * N; i++)
        cnt[i] += cnt[i - 1];
    for (int i = 2 * N - 1; i > 0; i--)
        cnt[i] = cnt[i - 1];
    for (int i = 0; i <= n; i++) {
        bal[cnt[curbal + N]] = curbal;
        pos[cnt[curbal + N]] = i;
        cnt[curbal + N]++;
        if (i == n)
            break;
        curbal += (buf[i] == '(') ? 1 : -1;
    }

    AA[0] = hsh(1, 1);
    for (int i = 1; i < N; i++)
        AA[i] = AA[i - 1] * A;
    for (int i = 0; i < n; i++)
        H[i + 1] = H[i] * A + hsh(buf[i]);    

    llong max_poss = 0;
    for (int l = 0, r = 0; l <= n; l = r) {
        while (r != n + 1 && bal[r] == bal[l] && (r == l || get_min(pos[r - 1], pos[r]) >= bal[l]))
            r++;
        if (l == r) {
            r++;
            l++;
            continue;
        }
        int lpt = pt;
        for (int i = l; i < r - 1; i++) {
            int a = pos[i], b = pos[i + 1];
            hsh h = get_hash(a, b);
            str[pt] = h;
            dstr[pt] = h;
            pt++;
        }
        int rpt = pt;
        int len = rpt - lpt;
        max_poss += 1ll * len * (len + 1) / 2;
        str[pt] = hsh(424243, l);
        dstr[pt] = str[pt];
        pt++;
        assert(pt < 2 * N);
    }
    sort(dstr, dstr + pt);
    int rpt = unique(dstr, dstr + pt) - dstr;
    for (int i = 0; i < pt; i++) {
        emaxx_SA::s[i] = lower_bound(dstr, dstr + rpt, str[i]) - dstr;
    }
    emaxx_SA::n = pt;
    emaxx_SA::build_SA();
    
    llong ans = 0;
    for (int i = 0; i < pt - 1; i++) {
        ans += emaxx_SA::lcp[i];
    }
    ans = max_poss - ans;
    printf("%lld\n", ans);
}