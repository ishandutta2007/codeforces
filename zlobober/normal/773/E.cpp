#include <cstdio>
#include <tuple>
#include <set>
#include <algorithm>
#include <cassert>
using namespace std;

const int N = 1 << 20;

int A[N];
pair<int, int> prs[N];
int pos[N];

set<pair<int, int>> ord;
set<pair<int, int>>::iterator ordit;
int ordpos;

inline pair<int, int> orditval() {
    return ordit == ord.end() ? make_pair(N + 100, N + 100) : *ordit;
}

struct mapping {
    int a, c;

    // u(v(x))
    inline friend mapping operator *(mapping u, mapping v) {
        mapping res = {min(u.a - v.c, v.a), u.c + v.c};
        return res;
    }

    inline int apply(int x) {
        return c + min(a, x);
    }
};

const mapping neut = {2 * N, 0};

mapping T[2 * N];

mapping get(int l, int r) {
    l += N;
    r += N;
    mapping A = neut;
    mapping B = neut;
    while (l <= r) {
        if (l & 1) {
            A = T[l] * A;
        }
        if (!(r & 1)) {
            B = B * T[r];
        }
        l = (l + 1) >> 1;
        r = (r - 1) >> 1;
    }
    return B * A;
}

void upd(int i, mapping mp) {
    i += N;
    T[i] = mp;
    while ((i >>= 1) > 0) {
        T[i] = T[2 * i + 1] * T[2 * i];
    }
}

pair<int, int> add(int x, int i) {
    pair<int, int> pr(x, i);
    ord.insert(pr);
    upd(i, {x - 1, 1});
    if (orditval() > pr) {
        ordpos++;
    }
    while (orditval().first < -ordpos) {
        ++ordpos;
        ++ordit;
    }
    while (true) {
        if (ordit != ord.begin()) {
            auto pit = ordit;
            --pit;
            int ppos = ordpos - 1;
            if (pit->first >= -ppos) {
                ordit = pit;
                ordpos = ppos;
            } else {
                break;
            }
        } else {
            break;
        }
    }
    /*for (auto it = ord.begin();; ) {
        auto nit = it;
        ++nit;
        if (nit == ord.end())
            break;
        assert(it->second < nit->second);
        it = nit;
    }
    fprintf(stderr, "pos = %d, posT = %d\n", ordpos, orditval().second);*/
    return make_pair(-ordpos, orditval().second);
}

int main() {
    int n;
    scanf("%d", &n);
    //n = 500000;
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        //A[i] = ((rand() << 15) + rand()) % 10000001- 500000;
        prs[i] = make_pair(A[i], i);
    }
    sort(prs, prs + n);
    for (int i = 0; i < n; i++) {
        pos[prs[i].second] = i;
    }
    for (int i = 0; i < 2 * N; i++) {
        T[i] = neut;
    }
    ordit = ord.end();
    ordpos = 0;
    for (int i = 0; i < n; i++) {
        int x, l;
        tie(x, l) = add(A[i], pos[i]);
        auto mp = get(l, N - 1);
        printf("%d\n", mp.apply(x));
    }
}