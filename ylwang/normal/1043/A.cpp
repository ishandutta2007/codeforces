#include<bits/stdc++.h>
using namespace std;
int n;
int x;
int sum;
int maxx;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        sum+=x;
        maxx=max(x,maxx);//
    }
    if(maxx*n-sum>sum)//1
    {
        printf("%d",maxx);
        return 0;
    }
    int res;
    int sum2=sum+1;
    if((sum+sum2)%n)//2,3
        res=(sum+sum2)/n+1;
    else
        res=(sum+sum2)/n;
    printf("%d",res);
    return 0;
}