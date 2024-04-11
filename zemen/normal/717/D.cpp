#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int M = 128;

int n;

struct Prob {
    ld p[M];

    Prob() {
        fill(p, p + M, 0.);
    }

    ld& operator[](int x) {
        return p[x];
    }
} E, P;

Prob comb(Prob A, Prob B) {
    Prob C;

    for (int i = 0; i < M; ++i)
        for (int j = 0; j < M; ++j)
            C[i ^ j] += A[i] * B[j];

    ld sum = 0.;
    for (int i = 0; i < M; ++i)
        sum += C[i];

    for (int i = 0; i < M; ++i)
        C[i] /= sum;

    return C;
}

Prob bin(Prob A, int to) {
    Prob B = E;
    while (to) {
        if (to & 1) 
            B = comb(B, A);
        A = comb(A, A);
        to >>= 1;
    }
    return B;
}

void read() {
    cin >> n;
    int x;
    cin >> x;
    for (int i = 0; i <= x; ++i)
        cin >> P[i];
}

void kill() {
    cout << 1. - bin(P, n)[0] << endl;
}

int main() {
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif

    cout.precision(10);
    cout << fixed;

    E[0] = 1.;

    read();
    kill();
}