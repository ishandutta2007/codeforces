#include<bits/stdc++.h>
using namespace std;

const int N=1e6+1e3+7;

int T,n,a[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        int p;
        scanf("%d",&p);
        scanf("%d",&n);
        n++;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int ans=0;
        for(int i=19;i>=0;i--)
        {
            vector<int>cnt(2);
            for(int j=1;j<=n;j++)
                cnt[(j-1)>>i&1]++,cnt[a[j]>>i&1]--;
            if(cnt[0])
                ans^=1<<i;
        }
        printf("%d\n",ans);
    }
}