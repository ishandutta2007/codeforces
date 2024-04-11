#include <iostream>
using namespace std;
int n;
int t[101];
int d[101];
int mini=0;
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
    }

    for(int i=2; i<=n-1; i++)
    {
        mini=0;
        for(int j=2; j<=n; j++)
        {
            if(j==i)
            {

            }
            else
            {
                if(j-1==i)
                {
                    mini=max(mini, t[j]-t[j-2]);
                }
                else
                {
                     mini=max(mini, t[j]-t[j-1]);
                }
            }
        }
        d[i]=mini;

    }
    int maxi=1000000;
    for(int i=2; i<=n-1; i++)
    {
        maxi=min(maxi, d[i]);
    }
    cout<<maxi;

    return 0;
}