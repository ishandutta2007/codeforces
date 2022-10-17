#include<bits/stdc++.h>
using namespace std;

int T,n;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int p=sqrt(n/6);
        int ans=1e9;
        for(int i=max(0,p-5);i<=p+5;i++)
            for(int j=i;j<=p+5;j++)
                for(int k=j;k<=p+5;k++)
                {
                    if(2*(i*j+j*k+k*i)>=n)
                        ans=min(ans,i+j+k);
                }
        printf("%d\n",ans);
    }
}