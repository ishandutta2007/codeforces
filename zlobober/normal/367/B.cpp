#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

const int N = 400500;

typedef long long llong;

int A[N], B[N];
int cnt[N];
int nd[N];

int df = 0;

inline void add(int x)
{
    df -= abs(cnt[x] - nd[x]);
    cnt[x]++;
    df += abs(cnt[x] - nd[x]);
}

inline void del(int x)
{
    df -= abs(cnt[x] - nd[x]);
    cnt[x]--;
    df += abs(cnt[x] - nd[x]);
}

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

int apt = 0;
int ans[N];

int main()
{
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);
    map<int, int> M;
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]), M[A[i]];
    for (int i = 0; i < m; i++)
        scanf("%d", &B[i]), M[B[i]];
    int pt = 0;
    for (map<int, int>::iterator it = M.begin(); it != M.end(); it++)
        it->second = pt++;
    for (int i = 0; i < n; i++)
        A[i] = M[A[i]];
    for (int j = 0; j < m; j++)
        B[j] = M[B[j]];
    for (int j = 0; j < m; j++)
        nd[B[j]]++;
    df = m;
    for (int s = 0; s < p; s++)
    {
        if (s + (llong)(m - 1) * p >= n)
            continue;
        for (int i = 0; i < m; i++)
            add(A[s + i * p]);
        int beg = s, end = s + (m - 1) * p;
        while (true)
        {
            eprintf("%d %d -> %d\n", beg, end, df);
            if (df == 0)
            {
                ans[apt++] = beg;
            }
            if (end + p < n)
            {
                del(A[beg]);
                beg += p;
                end += p;
                add(A[end]);
            }
            else
                break;
        }
        for (int i = beg; i <= end; i += p)
            del(A[i]);
    }
    sort(ans, ans + apt);
    printf("%d\n", apt);
    for (int i = 0; i < apt; i++)
        printf("%d ", ans[i] + 1);
}