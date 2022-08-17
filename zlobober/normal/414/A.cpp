#include <cstdio>
using namespace std;

const int S = 2 * 1000 * 1000 * 100 + 42;



int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    if (n == 1)
    {
        if (k == 0)
            puts("1");
        else
            puts("-1");
        return 0;
    }
    if (k < n / 2)
        puts("-1");
    else
    {
        printf("%d %d ", (k - n / 2 + 1), 2 * (k - n / 2 + 1));
        for (int i = 0; i < n - 2; i++)
        {
            printf("%d ", S + i);
        }
        printf("\n");
    }
}