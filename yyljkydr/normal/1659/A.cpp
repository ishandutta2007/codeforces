#include<bits/stdc++.h>
using namespace std;

int T,n,r,b;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&r,&b);
        int mx=r/(b+1);
        int res=r%(b+1);
        int t=b+1;
        for(int i=1;i<=t;i++)
        {
            int k=i<=res?mx+1:mx;
            for(int j=1;j<=k;j++)
                putchar('R'),r--;
            if(b)
                putchar('B'),b--;
        }
        puts("");
    }
}