#include <cstdio>
#include <cassert>
#include <cstring>
using namespace std;

const int N = 200500;

char _A[N], _B[N];
int A[N], B[N];

int main()
{
    scanf("%s %s", _A, _B);
    int nA = strlen(_A);
    int nB = strlen(_B);
    for (int i = 0; i < nA; i++)
        A[nA - i - 1] = _A[i] - '0';
    for (int i = 0; i < nB; i++)
        B[nB - i - 1] = _B[i] - '0';
    for (int i = N - 10; i >= 0; i--)
    {
        if (A[i] && A[i + 1])
            A[i + 2]++, A[i]--, A[i + 1]--, i += 3;
    }
    for (int i = N - 10; i >= 0; i--)
    {
        if (B[i] && B[i + 1])
            B[i + 2]++, B[i]--, B[i + 1]--, i += 3;
    }
    for (int i = 0; i < N - 1; i++)
    {
        if (A[i])
            assert(!A[i + 1]);
    }
    for (int i = N - 1; i >= 0; i--)
    {
        if (A[i] != B[i])
        {
            if (A[i] < B[i])
                printf("<\n");
            else
                printf(">\n");
            return 0;
        }
    }
    printf("=\n");
    return 0;
}