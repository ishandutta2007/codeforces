# include <cstdio>
# include <algorithm>
using namespace std;
int checked[5]={0, 1, 2, 3, 4};
int mat[5][5];
int main()
{
    for (int i=0; i<5; ++i)
        for (int k=0; k<5; ++k)
            scanf("%d", &mat[i][k]);
    int maxx=0;
    do
    {
        int res=0;
        for (int i=0; i<5; ++i)
            for (int k=i; k<4; k+=2)
                res+=mat[checked[k]][checked[k+1]]+mat[checked[k+1]][checked[k]];
        if (res>maxx)
            maxx=res;
    }
    while (next_permutation(checked, checked+5));
    printf("%d\n", maxx);
}