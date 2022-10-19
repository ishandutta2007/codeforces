#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int T,n;

char a[N];

map<long long,int>cnt;

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        cnt.clear();
        scanf("%d",&n);
        scanf("%s",a+1);
        long long s=0,ans=0;
        cnt[0]++;
        for(int i=1,x;i<=n;i++)
        {
            x=a[i]-'0';
            s+=x;
            ans+=cnt[s-i];
            cnt[s-i]++;
        }
        printf("%lld\n",ans);
    }
}