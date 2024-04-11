#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 300500;
pair<int, int> pr[N];

int ans[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &pr[i].first), pr[i].second = i;
    sort(pr, pr + n);
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        if (cur < pr[i].first)
            cur = pr[i].first;
        ans[pr[i].second] = cur;
        cur++;        
    }
    for (int i = 0; i < n; i++)
        printf("%d%c", ans[i], " \n"[i + 1 == n]);
}