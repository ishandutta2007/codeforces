#include<bits/stdc++.h>
using namespace std;

const int N=111;

int T;

int n,l;

int a[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&l);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int ans=0;
        for(int j=l-1;j>=0;j--)
        {
            int c=0;
            for(int i=1;i<=n;i++)
                if(a[i]&(1<<j))
                    c++;
            if(c*2>n)
                ans|=(1<<j);
        }
        printf("%d\n",ans);
    }
}