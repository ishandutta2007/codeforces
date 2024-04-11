#include <cstdio>
#include <memory.h>
using namespace std;

const int N = 1000;
char A[N][N];

void add_edge(int a, int b)
{
    A[a][b] = A[b][a] = 'Y';
}

int main()
{
    int k;
    scanf("%d", &k);
    memset(A, 'N', sizeof(A));
    int pt = 3;
    add_edge(1, pt);
    for (int r = 0; r <= 40; r++)
    {
        add_edge(pt, pt + 3);
        add_edge(pt + 1, pt + 4);
        add_edge(pt + 1, pt + 5);
        add_edge(pt + 2, pt + 4);
        add_edge(pt + 2, pt + 5);
        pt += 3;
    }
    if ((k & 1))
        add_edge(pt, 2);
    add_edge(pt + 1, 2);
    add_edge(pt + 2, 2);
    for (int i = 1; i <= 30; i++)
    {
        if ((k >> i) & 1)
        {
            add_edge(pt - 3 * i, pt - 3 * i + 3 + 1);
            add_edge(pt - 3 * i, pt - 3 * i + 3 + 2);
        }
    }
    pt += 2;
    printf("%d\n", pt);
    for (int i = 1; i <= pt; i++)
    {
        for (int j = 1; j <= pt; j++) 
            printf("%c", A[i][j]);
        puts("");
    }
    return 0;
}