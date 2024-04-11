#include <cstdio>
using namespace std;

const int N = 1000500;

#define eprintf(...) fprintf(stderr,  __VA_ARGS__)

int A[2 * N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        A[i] = i + 1;
    for (int k = 2; k <= n; k++)
    {
        int p = k - 2 + n;
        for (int i = (((n - 1) / k) * k); i >= 0; i -= k)
        {
            A[p] = A[k - 2 + i];
            p = k - 2 + i;
        }
        A[p] = 0;
    }
    for (int i = n - 1; i < -1 + 2 * n; i++)
        printf("%d%c", A[i], " \n"[i + 1 == -1 + 2 * n]);
}