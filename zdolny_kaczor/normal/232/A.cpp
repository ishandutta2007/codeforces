# include <cstdio>
const int MN = 100;
bool graph[MN][MN];
int cou = 0;
void adde(int a, int b)
{
    if ((a + 1) > cou)
        cou = a + 1;
    if ((b + 1) > cou)
        cou = b + 1;
    if (a != b)
        graph[a][b] = graph[b][a] = true;
}
int main()
{
    int k;
    scanf("%d", &k);
    int groupsize;
    for (groupsize = 0; (groupsize + 1) * groupsize * (groupsize - 1) / 6 <= k; ++groupsize)
        ;
    for (int i = 0; i < groupsize; ++i)
        for (int k = i + 1; k < groupsize; ++k)
            adde(i, k);
    int next = groupsize;
    k -= groupsize * (groupsize - 1) * (groupsize - 2) / 6;
    for (int i = groupsize; k > 0; --i)
        while (i * (i - 1) / 2 <= k)
        {
            for (int x = 0; x < i; ++x)
                adde(next, x);
            next++;
            k -= i * (i - 1) / 2;
        }
    printf("%d\n", cou);
    for (int i = 0; i < cou; ++i)
    {
        for (int k = 0; k < cou; ++k)
            printf("%d", graph[i][k]);
        printf("\n");
    }
}