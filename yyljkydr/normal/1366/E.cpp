#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7,P=998244353;

int n,m;

int a[N],b[N];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&b[i]);
    vector<int>v;
    for(int i=1;i<=n;i++)
    {
        while(v.size()&&a[i]<=a[v.back()])
            v.pop_back();
        v.push_back(i);
    }
    reverse(v.begin(),v.end());
    int la=0;
    long long ans=1;
    if(a[v.back()]!=b[1])
    {
        puts("0");
        return 0;
    }
    for(int i=2;i<=m;i++)
    {
        while(v.size()&&a[v.back()]!=b[i])
            la=v.back(),v.pop_back();
        if(!v.size())
        {
            puts("0");
            return 0;
        }
        ans=ans*(v.back()-la)%P;
    }
    printf("%lld\n",ans);
}