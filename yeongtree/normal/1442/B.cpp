#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <utility>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss

using namespace std;

const int Q = 998'244'353;
int N;
int A[202020];
int ord[202020];
bool vst[202020];
int B[202020];
int C[202020];
int L[202020];
int R[202020];
int fen[202020];

void upd(int pos)
{
    ++pos;
    while(pos <= N)
    {
        ++fen[pos];
        pos += pos & -pos;
    }
}

int qr(int pos)
{
    int ret = 0;
    while(pos)
    {
        ret += fen[pos];
        pos &= pos - 1;
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while(T--)
    {
        int n, m; cin >> n >> m; N = n;
        for(int i = 0; i <= n; ++i) ord[i] = -1, vst[i] = false;
        for(int i = 0; i < n; ++i) cin >> A[i], --A[i], ord[A[i]] = i;
        for(int i = 0; i < m; ++i) cin >> B[i], --B[i], C[i] = ord[B[i]], vst[C[i]] = true;

        for(int i = 0; i <= n; ++i) L[i] = i - 1, R[i] = i + 1;
        for(int i = 0; i <= n; ++i) fen[i] = 0;

        for(int i = 0; i < n; ++i) if(!vst[i])
        {
            if(R[i] != n) L[R[i]] = L[i];
            if(L[i] != -1) R[L[i]] = R[i];
        }

        int ans = 1;
        for(int i = 0; i < m; ++i)
        {
            int d = 0;
            if(C[i] - L[C[i]] - 1 > qr(C[i]) - qr(L[C[i]] + 1)) ++d;
            if(R[C[i]] - C[i] - 1 > qr(R[C[i]]) - qr(C[i] + 1)) ++d;
            ans = 1ll * ans * d % Q;

            if(R[C[i]] != n) L[R[C[i]]] = L[C[i]];
            if(L[C[i]] != -1) R[L[C[i]]] = R[C[i]];
            upd(C[i]);
        }

        cout << ans << '\n';
    }
}