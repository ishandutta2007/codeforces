#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1050;

char A[N], B[N];

int main()
{
    gets(A);
    gets(B);
    int a = 0;
    int b = 0;
    int n = strlen(A);
    int m = strlen(B);
    for (int i = 0; i < n; i++)
        a += A[i] == '1';
    for (int i = 0; i < m; i++)
        b += B[i] == '1';
    if (a % 2)
        a++;
    if (a >= b)
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}