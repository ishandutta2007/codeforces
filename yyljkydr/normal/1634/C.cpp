#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n,k;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        if(n==1&&k>1)
        {
            puts("NO");
        }
        else if(k==1)
        {
            puts("YES");
            for(int i=1;i<=n;i++)
                printf("%d\n",i);
        }
        else
        {
            if(n%2==1)
                puts("NO");
            else
            {
                puts("YES");
                vector<int>num[2];
                for(int i=1;i<=n*k;i++)
                    num[i&1].push_back(i);
                for(int i=1;i<=n;i++)
                    for(int j=1;j<=k;j++)
                        printf("%d%c",num[i&1].back()," \n"[j==k]),num[i&1].pop_back();
            }
        }
    }
}