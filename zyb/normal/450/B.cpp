#include<stdio.h>
int main()
{
   __int64 a[10],x,y,n;
    int i;
    scanf("%I64d%I64d",&x,&y);
    a[1]=x;a[2]=y;
    for(i=3;i<=6;i++)
        a[i]=a[i-1]-a[i-2];
    a[0]=a[6];
    scanf("%I64d",&n);
    n=n%6;
    while(1)
    {
        if(a[n]<0)
            a[n]+=1000000007;
        else break;
    }
    printf("%I64d\n",a[n]%1000000007);
    return 0;
}