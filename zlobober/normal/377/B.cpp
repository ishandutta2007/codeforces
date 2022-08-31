#include <cstdio>
#include <cassert>
#include <algorithm>
#include <set>
using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

const int N = 100500;
int A[N], B[N], C[N];
int nB[N];
int nA[N];
pair<pair<int, int>, int> pr1[N];
pair<int, int> pr2[N];
int n, m, s;

typedef long long llong;

int fix[N];

bool can(int d, llong mxs, bool genans = false)
{
    set<pair<int, int> > S;
    int pt = 0;
    llong s = 0; 
    for (int b = 0; b < m; b += d)
    {
        int r = B[b];
        while (pt != n && A[pt] >= r)
            S.insert(make_pair(C[pt], pt)), pt++;
        if (S.empty())
            return false;
        pair<int, int> bst = *S.begin();
        S.erase(S.begin());
        s += bst.first;
        if (s > mxs)
            return false;
        if (genans)
        {
            for (int i = b; i < min(m, b + d); i++)
                fix[nB[i]] = nA[bst.second];
        }
    }
    return true;
}


int main()
{
    scanf("%d %d %d", &n, &m, &s);
    for (int i = 0; i < m; i++)
        scanf("%d", &B[i]);
    for (int i = 0; i < m; i++)
        pr2[i] = make_pair(B[i], i);
    sort(pr2, pr2 + m);
    reverse(pr2, pr2 + m);
    for (int i = 0; i < m; i++)
        nB[i] = pr2[i].second, B[i] = pr2[i].first;
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &C[i]);
    for (int i = 0; i < n; i++)
        pr1[i] = make_pair(make_pair(A[i], C[i]), i);
    sort(pr1, pr1 + n);
    reverse(pr1, pr1 + n);
    for (int i = 0; i < n; i++)
        A[i] = pr1[i].first.first, C[i] = pr1[i].first.second, nA[i] = pr1[i].second;
    int l = 0, r = m + 2;
    while (r - l > 1)
    {
        int t = (l + r) / 2;
        if (can(t, s))
            r = t;
        else
            l = t;
    }
    if (l == m + 1)
        printf("NO\n");
    else
    {
        printf("YES\n");
        eprintf("t = %d\n", r);
        assert(can(r, s, true));
        for (int i = 0; i < m; i++)
            printf("%d%c", fix[i] + 1, " \n"[i + 1 == m]);
    }
}