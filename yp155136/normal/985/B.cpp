#include <bits/stdc++.h>
using namespace std;

const int N = 2006;

bitset<N> bst[N];

int main ()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;n>=i;i++)
    {
        getchar();
        for (int j=1;m>=j;j++)
        {
            char c = getchar();
            if (c == '1') bst[i][j] = true;
        }
    }
    for (int i=1;n>=i;i++)
    {
        bitset<N> ee;
        for (int j=1;n>=j;j++)
        {
            if (j != i)
            {
                ee |= bst[j];
            }
        }
        if (ee.count() == m)
        {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
}