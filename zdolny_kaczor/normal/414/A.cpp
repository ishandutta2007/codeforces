# include <cstdio>
# include <set>
using namespace std;
set <int> used;
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    if (n == 1)
    {
        if (k == 0)
            printf("1\n");
        else
            printf("-1\n");
        return 0;
    }
    if (k < n / 2)
    {
        printf("-1\n");
        return 0;
    }
    else
    {
        int x = k - n / 2 + 1;
        printf("%d %d ", x, x * 2);
        used.insert(x);
        used.insert(x * 2);
    }
    int left = n / 2 - 1;
    for (int i = 1; left > 0; ++i)
    {
        if (used.find(i) == used.end() && used.find(i + 1) == used.end())
        {
            used.insert(i);
            used.insert(i + 1);
            printf("%d %d ", i, i + 1);
            left --;
        }
    }
    if (n % 2)
        for (int i = 75319; ; ++i)
            if (used.find(i) == used.end())
            {
                printf("%d ", i);
                return 0;
            }
}