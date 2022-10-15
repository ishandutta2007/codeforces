#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=55;
int t;
int n;
int p[maxn];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int x;scanf("%d",&x);
            p[x]=i;
        }
        int flag=1;
        for(int i=1;i<=n;i++)if(p[i]!=i){flag=0;break;}
        if(flag)
        {
            printf("0\n");continue;
        }
        if(p[1]==1||p[n]==n)
        {
            printf("1\n");continue;
        }
        if(p[1]!=n||p[n]!=1)
        {
            printf("2\n");continue;
        }
        if(p[1]==n&&p[n]==1)
        {
            printf("3\n");continue;
        }
    }
    return 0;
}