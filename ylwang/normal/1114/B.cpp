#include <bits/stdc++.h>
using namespace std;
int n,k,m;
int a[200010],b[200010];
map<int,int> mp;
int main()
{
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    sort(b+1,b+n+1);
    long long ans=0;
    for(int i=n,j=1;j<=(k*m);i--,j++)
    {
        mp[b[i]]++;
        ans+=b[i];
    }
    cout<<ans<<endl;
    for(int i=1,now=0,qaq=0;i<=n;i++)
    {
        if(mp[a[i]])
        {
            now++;
            mp[a[i]]--;
        }
        if(now>=k)
        {
            printf("%d ",i);
            qaq++;
            now=0;
        }
        if(qaq==m-1)
        {
            return 0;
        }
    }
}