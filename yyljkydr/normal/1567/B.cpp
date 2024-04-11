#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T;

char s[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int pxor=0;
        for(int i=a-1;i>=0&&i%4!=3;i--)
            pxor^=i;
        int ans=a;
        if(pxor!=b)
        {
            int sp=pxor^b;
            if(sp==a)
                ans+=2;
            else
                ans++;
        }
        printf("%d\n",ans);
    }
}