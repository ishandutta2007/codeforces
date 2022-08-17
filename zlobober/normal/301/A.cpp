#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1000;

int A[N];

bool cmp(int a, int b)
{
    return abs(a) < abs(b);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n - 1; i++)
    {
        scanf("%d", &A[i]);
    }
    int ans = 0;
    if (n % 2 == 1)
    {
        n = 2 * n - 1;
        for (int i = 0; i < n; i++)
            ans += abs(A[i]);
    }
    else
    {
        n = 2 * n - 1;
        sort(A, A + n, cmp);
        int neg = 0;
        bool zer = 0;
        int ans1 = 0;
        int ans2 = 0;
        for (int i = 0; i < n; i++)
            neg += A[i] < 0, zer += A[i] == 0, ans1 += abs(A[i]), ans2 += ((i == 0) ? -abs(A[i]) : abs(A[i]));
        if (zer || neg % 2 == 0)
            ans = ans1;
        else
            ans = ans2;
    }
    printf("%d\n", ans);
}