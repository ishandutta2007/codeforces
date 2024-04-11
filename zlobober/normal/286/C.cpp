#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1000500;

int pt = 0;
int S[N];
bool op[N];
int A[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    reverse(A, A + n);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int t;
        scanf("%d", &t);
        op[n - t] = true;
    }
    for (int i = 0; i < n; i++)
    {
        int q = A[i];
        if (op[i])
            S[pt++] = q;
        else
        {
            if (pt != 0 && S[pt - 1] == q)
                --pt;
            else
                S[pt++] = q, op[i] = true;
        }
    }
    if (pt != 0)
        printf("NO\n");
    else
    {
        printf("YES\n");
        for (int i = 0; i < n; i++)
            printf("%d ", A[n - i - 1] * (op[n - i - 1] ? -1 : 1));
        printf("\n");
    }
    return 0;
}