#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int t,n;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        bool ok=0;
        for(int i=1,x1=-1,x2;i<=n;i++)
        {
            scanf("%d",&x2);
            if(abs(x1-x2)>1 && !ok && x1!=-1)
                printf("YES\n%d %d\n",i-1,i),ok=1;
            x1=x2;
        }
        if(!ok)
            puts("NO");
    }
    return 0;
}