#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;
int main()
{long long a[1005],b[1005];
 long long i,j,k,l,d,m,n,s=0;
    scanf("%d",&n);
  for(i = 1; i <= n; i++)
    {scanf("%d",&a[i]);
    b[i]=0;}
        b[1]=2;
    for(i=2;i<=n;i++)
        {
       for(j=a[i];j<i;j++)
            {
          b[i]+=b[j];       
          b[i]=b[i] % 1000000007;
            }
          b[i]+=2;
          b[i]%=1000000007;
        }
    for(i=1;i<=n;i++)
     s=(s+b[i])%1000000007;
    printf("%d",s);   
    return 0;
}