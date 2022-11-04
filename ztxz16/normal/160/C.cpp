#include <stdio.h>
#include <stdlib.h>

long long n,k,i,j,s,snow,a[100005];

void sort(long long l,long long r);

int main()
{
    scanf("%I64d %I64d",&n,&k);
    for(i=1;i<=n;i++)
       scanf("%I64d",&a[i]);
    sort(1,n);
    snow=0;
    for(i=1;i<=n;i++)
    {
       for(j=i+1;j<=n;j++)
          if (a[j]!=a[i]) break;
       j--;
       snow+=((j-i+1)*n);
       if (snow<k)
       {
          i=j;
          continue;
       }
       else
       {
           snow-=((j-i+1)*n);
           snow=(k-snow);
           printf("%I64d %I64d\n",a[i],a[(snow-1)/(j-i+1)+1]);
           return 0;
       }
    }
    return 0;
}

void sort(long long l,long long r)
{
     long long i=l,j=r,k,mid;
     mid=a[l+rand()%(r-l+1)];
     while (i<=j)
     {
           while (i<=j && a[i]<mid) i++;
           while (i<=j && a[j]>mid) j--;
           if (i<=j)
           {
              k=a[i],a[i]=a[j],a[j]=k;
              i++,j--;
           }
     }
     if (l<j) sort(l,j);
     if (i<r) sort(i,r);
     return;
}