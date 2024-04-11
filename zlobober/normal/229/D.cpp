#include <cstdio>
using namespace std;

const int N = 5050;

int A[N];

int D[N];
int H[N];



int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &A[i]);
    A[n + 1] = 1000000500;
    A[0] = 0;
    H[0] = 0;
    D[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int q = A[i];
        int pt = i;
        while (q < H[pt - 1])
        {
            pt--;
            q += A[pt];
        }
        D[i] = 1 + D[pt - 1];
        H[i] = q;
    }
    printf("%d\n", n - D[n]);
    return 0;
}