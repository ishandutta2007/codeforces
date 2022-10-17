#include<bits/stdc++.h>
using namespace std;

const int N=101;

int T,n,a[N];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        map<int,int>cnt;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),cnt[a[i]]++;
        int mex=0;
        while(cnt[mex])
            mex++;
        for(int i=0;i<mex;i++)
            printf("%d ",i),cnt[i]--;        
        for(int i=0;i<=100;i++)
            while(cnt[i])
                printf("%d ",i),cnt[i]--;
        puts("");
    }
}