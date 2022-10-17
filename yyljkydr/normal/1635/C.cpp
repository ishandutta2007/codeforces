#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int T;

int n,a[N];

int mn[N],mx[N];

typedef pair<int,int> pii;

pii cho[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        mx[n]=n;
        mx[n-1]=a[n-1]>a[n]?n-1:n;
        mn[n-1]=2e9;
        for(int i=n-2;i>=1;i--)
        {
            mx[i]=a[mx[i+1]]>a[i]?mx[i+1]:i;
            mn[i]=a[i+1]-a[mx[i+2]];
            if(min(mn[i],mn[i+1])>a[i])
                cho[i]=pii(-1,-1);
            else if(mn[i]<mn[i+1])
                cho[i]=pii(i+1,mx[i+2]);
            else
                cho[i]=cho[i+1];
            mn[i]=min(mn[i],mn[i+1]);
        }
        for(int i=1;i<=n-2;i++)
            a[i]=min(a[i],mn[i]);
        bool ok=1;
        for(int i=1;i<n;i++)
            if(a[i]>a[i+1])
                ok=0;
        if(!ok)
            puts("-1");
        else
        {
            int ct=0;
            for(int i=1;i<=n-2;i++)
                if(cho[i].first!=-1)
                    ct++;
            printf("%d\n",ct);
            for(int i=1;i<=n-2;i++)
                if(cho[i].first!=-1)
                    printf("%d %d %d\n",i,cho[i].first,cho[i].second);
        }
    }
}