#include<bits/stdc++.h>
using namespace std;

int T,n;

map<int,int>cnt,cc;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        cnt.clear();
        cc.clear();
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            cc[cnt[x]]--;
            cnt[x]++;
            cc[cnt[x]]++;
        }
        auto [a,b]=*cc.rbegin();
        printf("%d\n",(n-a*b)/(a-1)+b-1);
    }
}