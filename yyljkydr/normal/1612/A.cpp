#include<bits/stdc++.h>
using namespace std;

int T,x,y;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&x,&y);
        if((x+y)&1)
            puts("-1 -1");
        else
        {
            if(x<y)
                printf("%d %d\n",x,y-(x+y)/2);
            else
                printf("%d %d\n",(x+y)/2,0);
        }
    }
}