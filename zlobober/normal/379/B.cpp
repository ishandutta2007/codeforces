#include <cstdio>
using namespace std;

const int N = 350;

int A[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < A[i]; j++)
        {
            if (i)
                printf("LRP");
            else
                printf("RLP");
        }
        if (i + 1 != n)
            printf("R");
    }
    return 0;
}