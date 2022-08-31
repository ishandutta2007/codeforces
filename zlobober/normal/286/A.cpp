#include <cstdio>
using namespace std;

const int N = 100500;
int A[N];

int main()
{
    int n;
    scanf("%d", &n);
    if (n % 4 == 2 || n % 4 == 3)
    {
        printf("-1\n");
        return 0;
    }
    for (int i = 0; i < n; i++)
        A[i] = i;
    for (int i = 0; i < n / 2; i += 2)
    {
        A[i] = i + 1;
        A[i + 1] = n - i - 1;
        A[n - i - 1] = n - i - 2;
        A[n - i - 2] = i;
    }
    for (int i = 0; i < n; i++)
        printf("%d%c", A[i] + 1, " \n"[i == n - 1]);
    return 0;
}