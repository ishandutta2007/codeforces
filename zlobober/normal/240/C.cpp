#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    int q = n;
    --q;
    int ans = 0;
    while (q)
        q >>= 1, ans++;
    printf("%d\n", ans);
    for (int i = 0; i < ans; i++)
    {
        vector<int> to;
        for (int j = 0; j < n; j++)
            if ((j >> i) & 1)
                to.push_back(j + 1);
        printf("%d ", to.size());
        for (int j = 0; j < to.size(); j++)
            printf("%d ", to[j]);
        printf("\n");
    }
    return 0;
}