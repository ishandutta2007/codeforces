#include<bits/stdc++.h>
using namespace std;

const int N=5e5+1e3+7;

int T;

int n,a[N],b[N],c[N];

vector<int>up,dw;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int s=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int ans=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        dw.clear(),up.clear();
        for(int i=1;i<=n;i++)
            if(a[i]>b[i])
                for(int j=1;j<=a[i]-b[i];j++)
                    dw.push_back(i);
            else
                for(int j=1;j<=b[i]-a[i];j++)
                    up.push_back(i);
        if(dw.size()!=up.size())
            puts("-1");
        else
        {
            printf("%d\n",dw.size());
            for(int i=0;i<up.size();i++)
                printf("%d %d\n",dw[i],up[i]);
        }
    }
}