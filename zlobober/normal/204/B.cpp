#include <cstdio>
#include <map>
using namespace std;

const int N = 100500;

int A[N], B[N];
map<int, int> M;

int n;

int go(int x)
{
    int col = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == x)
            col++;
    }
    if (col >= (n + 1) / 2)
        col = (n + 1) / 2;
    int rem = (n + 1) / 2 - col;
    int can = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] != x)
            if (B[i] == x)
                can++;
    }
    if (can >= rem)
        return rem;
    else
        return N + 2;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &A[i], &B[i]), M[A[i]]++, M[B[i]]++;
    int ans = N + 42;
    for (map<int, int>::iterator it = M.begin(); it != M.end(); it++)
    {
        int q = it->second;
        int c = it->first;
        if (q >= (n + 1) / 2)
            ans = min(ans, go(c));
    }
    if (ans > N)
        printf("%d\n", -1);
    else
        printf("%d\n", ans);
    return 0;
}