#include<stdio.h>
using namespace std;
int main()
{
    int i,j,k,l,s,m,n;
    scanf("%d%d%d",&n,&m,&l);
    i=1;
    j=1;
    int yy=0;
    for (k=1;k<l;k++)
    {
        printf("2 ");
        printf("%d %d ",i,j);
        if (!yy)
        j++;
        else
        j--;
        if (j>m)
        {
            i++;
            j=m;
            yy^=1;
        }
        if (j<=0)
        {
            i++;
            j=1;
            yy^=1;
        }
        printf("%d %d\n",i,j);
        if (!yy)
        j++;
        else
        j--;
        if (j>m)
        {
            i++;
            j=m;
            yy^=1;
        }
        if (j<=0)
        {
            i++;
            j=1;
            yy^=1;
        }
    }
    s=n*m-2*(l-1);
    printf("%d ",s);
    while (s)
    {
         printf("%d %d ",i,j);
         if (!yy)
        j++;
        else
        j--;
        if (j>m)
        {
            i++;
            j=m;
            yy^=1;
        }
        if (j<=0)
        {
            i++;
            j=1;
            yy^=1;
        }
        s--;
    }
}