#include <cstdio>
#include <map>
using namespace std;

map<int, int> M;

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    int t;
    for (int i = 0; i < n; i++)
        scanf("%d", &t), M[t]++;
    for (int i = 0; i < m; i++)
        scanf("%d", &t), M[t]--;
    int s = 0;
    for (map<int, int>::reverse_iterator it = M.rbegin(); it != M.rend(); it++)
    {
        s += it->second;
        if (s > 0)
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}