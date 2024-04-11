# include <cstdio>
# include <algorithm>
using namespace std;
const int MN=5010;
int tab[MN];
int main()
{
    int n;
    scanf("%d", &n);
    if (n==2)
        printf("1\n1\n");
    else if (n==3)
        printf("2\n1 3\n");
    else
    {
        for (int i=0; i<n; ++i)
            tab[i]=i+1;
        while (true)
        {
            random_shuffle(tab, tab+n);
            bool OK=true;
            for (int i=0; i<n-1; ++i)
                if (tab[i]+1==tab[i+1] || tab[i]-1==tab[i+1])
                {
                    OK=false;
                    break;
                }
            if (OK)
            {
                printf("%d\n", n);
                for (int i=0; i<n; ++i)
                    printf("%d ", tab[i]);
                printf("\n");
                return 0;
            }
        }
    }
}