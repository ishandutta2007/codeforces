#include <cstdio>
#include <bitset>
#include <vector>
using namespace std;

const int M = 142;
const int N = 142;
bitset<M> Q[N];

int A[N][N];

vector<int> E[N];

bool was[N];

void DFS(int x)
{
    was[x] = true;
    for (int i = 0; i < E[x].size(); i++)
    {
        int y = E[x][i];
        if (was[y])
            continue;
        DFS(y);
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int sk = 0;
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        int t;
        for (int j = 0; j < k; j++)
            scanf("%d", &t), Q[i][t] = 1;
        sk += k;
    }
    if (sk == 0)
    {
        if (n == 1)
            printf("%d\n", 0);
        else
            printf("%d\n", n);
        return 0;
    }


    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if ((Q[i] & Q[j]).any())
                E[i].push_back(j), E[j].push_back(i);
    int comp = 0;
    for (int i = 0; i < n; i++)
        if (!was[i])
            DFS(i), comp++;
    printf("%d\n", comp - 1);
    return 0;
}