#include <iostream>
using namespace std;
int n;
int ossz;
int ans;
int t[109];
int main()
{
    cin>>n;
    ossz=0;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
        ossz+=t[i];
    }
    if(ossz==n)
    {
        cout<<n-1;
        return 0;
    }
    ans=ossz;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            int ossz2=ossz;
            for(int k=i; k<=j; k++)
            {
                if(t[k]) ossz2--;
                else ossz2++;
            }
            ans=max(ans, ossz2);
        }
    }
    cout<<ans;
    return 0;
}