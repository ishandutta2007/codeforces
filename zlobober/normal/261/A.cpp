#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100500;

int Q[N];
int V[N];

int main()
{
    int s;
    scanf("%d", &s);
    for (int i = 0; i < s; i++)
        scanf("%d", &Q[i]);
    int mnq = *min_element(Q, Q + s);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &V[i]);
    sort(V, V + n);
    reverse(V, V + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % (mnq + 2) < mnq)
            ans += V[i];
    }
    printf("%d\n", ans);
}