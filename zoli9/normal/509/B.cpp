#include <iostream>
using namespace std;
int n, k, mini, maxi;
int t[110][110];
int main()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i][0];
    }
    mini=t[1][0];
    maxi=t[1][0];
    for(int i=2; i<=n; i++)
    {
        if(t[i][0]<mini)
        {
            mini=t[i][0];
        }
        if(t[i][0]>maxi)
        {
            maxi=t[i][0];
        }
    }
    if(k<maxi-mini)
    {
        cout<<"NO";
        return 0;
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=mini; j++)
        {
            t[i][j]=1;
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=mini+1; j<=t[i][0]; j++)
        {
            t[i][j]=j-mini;
        }
    }
    cout<<"YES"<<endl;
    for(int i=1; i<=n; i++)
    {
        cout<<t[i][1];
        for(int j=2; j<=t[i][0]; j++)
        {
            cout<<" "<<t[i][j];
        }
        cout<<endl;
    }



    return 0;
}