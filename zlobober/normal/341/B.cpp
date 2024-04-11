#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100500;

int A[N];
int D[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
        
    D[0] = -N;
    for (int i = 1; i <= n; i++)
        D[i] = N;
 
    for (int i = 0; i < n; i++)
    {
        int j = upper_bound(D, D + n + 1, A[i]) - D;
        D[j] = A[i];
    }
    int ans = n;
    while (D[ans] > N - 1)
        ans--;
    printf("%d\n", ans);
    return 0;
}