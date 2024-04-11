#include <iostream>
using namespace std;
int diff(int p, int q)
{
    int i,ret=0;
    for (i=0; i<6; i++)
    {
        if (p%10!=q%10) ret++;
        p/=10;
        q/=10;
    }
    return ret;
}
int a[1010],n,i,ans=6,j;
int main()
{
    cin>>n;
    if (n==1)
    {
        cout<<6<<endl;
        return 0;
    }
    for (i=0; i<n; i++)
        cin>>a[i];
    for (i=0; i<n; i++)
        for (j=i+1; j<n; j++)
             ans=min(ans,diff(a[i],a[j]));
    cout<<(ans-1)/2<<endl;
    return 0;
}