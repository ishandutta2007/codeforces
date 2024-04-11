#include <iostream>
using namespace std;
int a[1000100],i,x,n,ans,b[1000100];
int main()
{
    cin>>n;
    for (i=1; i<=n; i++)
    {
        cin>>x;
        a[x]++;
        b[x]=i;
    }
    ans=1;
    for (i=2; i<=1000000; i++)
    {
        if (a[ans]>a[i]) continue;
        if (a[ans]<a[i])
        {
            ans=i;
            continue;
        }
        if (b[ans]>b[i]) ans=i;
    }
    cout<<ans<<endl;
    return 0;
}