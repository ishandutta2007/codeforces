# include <cstdio>
# include <algorithm>
using namespace std;
const int MN = 1e3 + 44;
pair <int, int> dragons[MN];
int main()
{
    int s, n;
    scanf("%d%d", &s, &n);
    for (int i = 0; i < n; ++i)
        scanf("%d%d", &dragons[i].first, &dragons[i].second);
    sort(dragons, dragons + n);
    for (int i = 0; i < n; ++i)
        if (dragons[i].first >= s)
        {
            printf("NO\n");
            return 0;
        }
        else
            s += dragons[i].second;
    printf("YES\n");
}