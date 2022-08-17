#include <cstdio>
using namespace std;

const int N = 42;

int A[N], H[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &H[i], &A[i]);
    }
    int q = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (A[j] == H[i])
                q++;
        }
    printf("%d\n", q);

}