 #include<stdio.h>
#include<algorithm>
using namespace std;
long long n,m,k,ans1,ans2;
int main()
{
    scanf("%I64d%I64d%I64d",&n,&m,&k);
    if (n>m)
    swap(n,m);
    if (n-1+m-1==k)
    {
        printf("1");
        return 0;
    }
    if (n-1+m-1<k)
    {
        printf("-1");
        return 0;
    }
    if(m-1>=k)  
    {  
       ans1=1ll*n/(k+1)*m;  
       ans2=1ll*m/(k+1)*n;  
    }  
    else  
    {  
       ans1=n/(k-(m-1)+1);  
       ans2=m/(k-(n-1)+1);  
    }  
    printf("%I64d",max(ans1,ans2));
}