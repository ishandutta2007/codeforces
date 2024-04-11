#include<bits/stdc++.h>
using namespace std;

int T,n,k1,k2,w,b;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&k1,&k2);
        scanf("%d%d",&w,&b);
        int ok=0;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
            {
                if((k1==0||k2==0)&&i==1)
                    continue;
                if((n-k1==0||n-k2==0)&&j==1)
                    continue;
                int ow=i+(k1-i)/2+(k2-i)/2;
                int ob=j+(n-k1-j)/2+(n-k2-j)/2;
                if(ow>=w&&ob>=b)
                    ok=1;
            }
        if(ok)
            puts("YES");
        else
            puts("NO");
    }
}