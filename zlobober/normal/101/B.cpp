#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

const int N = 1 << 18;

pair<int, int> A[N];

map<int, int> M;
#define mp make_pair

int T[2 * N];

const int MOD = 1000000007;

void set(int x, int v)
{
    x += N - 1;
    T[x] += v;
    T[x] = T[x] % MOD;
    for (x /= 2; x; x >>= 1)
        T[x] = (T[2 * x] + T[2 * x + 1]) % MOD;
}

int get(int l, int r, int L, int R, int v)
{
    if (r < L || l > R)
        return 0;
    if (l <= L && R <= r)
        return T[v];
    
    return (get(l, r, L, (L + R) / 2, 2 * v) + 
            get(l, r, (L + R) / 2 + 1, R, 2 * v + 1)) % MOD;
}

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int main()
{
    int n, m;
    cin >> n >> m;
    swap(n, m);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i].first >> A[i].second;
        M[A[i].first] = M[A[i].second] = -1;
    }
    int cur = 1;
    for (map<int, int>::iterator it = M.begin(); it != M.end(); it++)
        it->second = cur++;
    if (M.find(m) == M.end() || M.find(0) == M.end())
    {
        cout << 0;
        return 0;
    }
    
    for (int i = 0; i < n; i++)
        A[i] = mp(M[A[i].first], M[A[i].second]);
    
    set(1, 1);
    
    sort(A, A + n, cmp);
    for (int i = 0; i < n; i++)
        set(A[i].second, get(A[i].first, A[i].second - 1, 1, N, 1));
    cout << get(M[m], M[m], 1, N, 1);
    return 0;
}