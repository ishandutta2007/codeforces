#include<stdio.h>
using namespace std;
long long mi=~0llU>>1,ma,si,sa,n,j,i;
int main()
{
    scanf("%I64d",&n);
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&j);
        if (j>ma)
        {
            ma=j;sa=1;
        }
        else
        if (j==ma)
        sa++;
        if (j<mi)
        {
            mi=j;si=1;
        }
        else
        if (j==mi)
        si++;
    }
    long long ans=sa*si;
    if (ma==mi)
    {
        //orz yjn
        //orz gtw
        //orz syf
        //orz jsj
        //orz jsb
        //orz lmq
        ans=sa*(sa-1)/2;
    } 
    printf("%I64d %I64d",ma-mi,ans);
}