#include<stdio.h>
using namespace std;
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    int ans=0;
    while (n)
    {
        ans++;
        n--;
        n=n+(ans%m==0);
    }
    printf("%d\n",ans);
}