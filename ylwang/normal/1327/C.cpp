#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
int main()
{
    scanf("%d%d",&n,&m);
    printf("%d\n",n-1+m-1+n*m);
    for(int i=1;i<n;i++)
        printf("U");
    for(int i=1;i<m;i++)
        printf("L");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<m;j++)
            printf("%c",i%2==1?'R':'L');
        printf("D");
    }
    return 0;
}