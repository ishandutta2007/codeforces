#include<bits/stdc++.h>
using namespace std;

int T,n,k;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);
        vector<int>ans;
        for(int i=k+1;i<=n;i++)
            ans.push_back(i);
        for(int i=k-1;i>(k-1)/2;i--)
            ans.push_back(i);
        printf("%d\n",ans.size());
        for(auto x:ans)
            printf("%d ",x);
        puts("");
    }
}