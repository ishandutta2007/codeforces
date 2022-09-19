# include <cstdio>
char num[10];
int main()
{
    scanf("%s", num);
    int res=0;
    for (int i=0; num[i]; ++i)
        if (num[i]-'0'>res)
            res=num[i]-'0';
    printf("%d\n", res);
    for (int i=0; i<res; ++i)
    {
        bool in=false;
        for (int k=0; num[k]; ++k)
            if (num[k]-'0'>i)
            {
                in=true;
                printf("1");
            }
            else if (in)
                printf("0");
        if (i==res-1)
            printf("\n");
        else
            printf(" ");
    }
}