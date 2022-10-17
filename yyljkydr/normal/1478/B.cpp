#include<bits/stdc++.h>
using namespace std;

int f[11][1001];

bool chk(int x,int y)
{
    while(x)
    {
        if(x%10==y)
            return 1;
        x/=10;
    }
    return 0;
}

int main()
{
    for(int d=1;d<=9;d++)
    {
        f[d][0]=1;
        for(int i=1;i<=1000;i++)
            for(int j=0;j<i;j++)
            {
                f[d][i]|=f[d][j]&chk(i-j,d);
                if(f[d][i])
                    break;
            }
    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int q,d;
        scanf("%d%d",&q,&d);
        while(q--)
        {
            int x;
            scanf("%d",&x);
            if(x<=1000)
                puts(f[d][x]?"YES":"NO");
            else
                puts("YES");
        }
    }
}