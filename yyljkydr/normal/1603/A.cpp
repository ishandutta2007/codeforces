#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

int T;

int n,a[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&a[i]);
        }   
        int ok=1;
        for(int i=1;i<=min(n,100);i++)
        {
            bool fd=0;
            for(int j=i;j>=1;j--)
                if(a[i]%(j+1)!=0)
                    fd=1;
            ok&=fd;
        }
        puts(ok?"YES":"NO");
    }
}