# include <cstdio>
# include <vector>
using namespace std;
const int MN = 222, MM = MN * (MN - 1) / 2;
vector <int> sets[MM];
bool inzeroth[MN];
bool ininter[MN];
int main()
{
    int n;
    scanf("%d", &n);
    int m = n * (n - 1) / 2;
    for (int i = 0; i < m; ++i)
    {
        int cou;
        scanf("%d", &cou);
        for (int k = 0; k < cou; ++k)
        {
            int x;
            scanf("%d", &x);
            sets[i].push_back(x);
        }
    }
    if (m == 1)
    {
        printf("1 %d\n%d", sets[0][0], (int) sets[0].size() - 1);
        for (int i = 1; i < sets[0].size(); ++i)
            printf(" %d", sets[0][i]);
        printf("\n");
        return 0;
    }
    for (auto x : sets[0])
        inzeroth[x] = true;
    for (int i = 1; i < m; ++i)
    {
        bool any = false;
        for (auto x : sets[i])
            if (inzeroth[x])
                any = true;
        if (any)
        {
            for (auto x : sets[i])
                ininter[x] = inzeroth[x];
            break;
        }
    }
    int cou = 0;
    for (int i = 0; i < MN; ++i)
        if (ininter[i])
            cou++;
    printf("%d", cou);
    for (int i = 0; i < MN; ++i)
        if (ininter[i])
            printf(" %d", i);
    printf("\n");
    for (int i = 0; i < m; ++i)
    {
        bool inters = false;
        for (auto x : sets[i])
            if (ininter[x])
                inters = true;
        if (inters)
        {
            vector <int> curr;
            for (auto x : sets[i])
                if (!ininter[x])
                    curr.push_back(x);
            printf("%d", (int) curr.size());
            for (auto x : curr)
                printf(" %d", x);
            printf("\n");
        }
    }
}