#include <bits/stdc++.h>
using namespace std;

int cnt[1234];

int main ()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int ans=0;
    for (int i=1;m>=i;i++)
    {
        int x;
        scanf("%d",&x);
        ++cnt[x];
        bool can=true;
        for (int j=1;n>=j;j++)
        {
            can &= (cnt[j]!=0);
        }
        if (can)
        {
            ++ans;
            for (int j=1;n>=j;j++)
            {
                --cnt[j];
            }
        }
    }
    printf("%d\n",ans);
}