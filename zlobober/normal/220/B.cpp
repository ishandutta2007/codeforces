#include <cstdio>
#include <vector>
using namespace std;

const int N = 100500;
int cnt[N];

int ans[N];
vector<int> good;

int tmp[N];
int L[N], R[N];
int A[N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
        if (A[i] >= N)
            continue;
        cnt[A[i]]++;
    }
    for (int i = 1; i < N; i++)
    {
        if (cnt[i] >= i)
            good.push_back(i);
    }
    for (int i = 0; i < m; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        L[i] = l, R[i] = r;
    }
    for (int i = 0; i < good.size(); i++)
    {
        int x = good[i];
        tmp[0] = 0;
        for (int j = 0; j < n; j++)
            tmp[j + 1] = tmp[j] + (A[j] == x);
        for (int j = 0; j < m; j++)
        {
            ans[j] += ((tmp[R[j]] - tmp[L[j] - 1]) == x);
        }
    }
    for (int i = 0; i < m; i++)
        printf("%d\n", ans[i]);
    return 0;
}