#include <bits/stdc++.h>
using namespace std;

int n,x,y,p,q,c;

void work()
{
    while(~scanf("%d",&n))
    {
        puts("YES");
        for(int i=0;i<n;i++)
        {
            scanf("%d%d%d%d",&x,&y,&p,&q);
            c=(x%2+2)%2*2 + (y%2+2)%2 + 1;
            printf("%d\n",c);
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
    work();
    return 0;
}