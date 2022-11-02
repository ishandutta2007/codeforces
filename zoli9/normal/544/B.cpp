#include <iostream>
using namespace std;
int n, k, maxi;
char c[120][120];
int main()
{
    cin>>n>>k;
    if(n%2)
    {
        maxi=n*n;
        maxi++;
        maxi/=2;
    }
    else
    {
        maxi=n*n;
        maxi/=2;
    }
    if(k>maxi)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            c[i][j]='S';
        }
    }
    bool v=true;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i%2 and j%2 and k>0)
            {
                c[i][j]='L';
                k--;
            }
            else if(i%2==0 and j%2==0 and k>0)
            {
                c[i][j]='L';
                k--;
            }
        }
        if(k<=0)
        {
            break;
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cout<<c[i][j];
        }
        cout<<endl;
    }
    return 0;
}