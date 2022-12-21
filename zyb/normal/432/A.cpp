#include<stdio.h>
using namespace std;
int main()
{
    int i,j,k,l,s,m,n;
    scanf("%d%d",&n,&k);
    s=0;
    for (i=1;i<=n;i++)
    {
        scanf("%d",&j);
        if (j+k<=5)
        s++;
    }
    printf("%d",s/3);
}