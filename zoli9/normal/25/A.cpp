#include <iostream>
using namespace std;
int n;
int t[200];
int ptl=0;
int ps=0;
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
        if(t[i]%2==0)
        {
            ps++;
        }
        else
        {
            ptl++;
        }
    }

    if(ptl==1)
    {
        for(int i=1; i<=n; i++)
        {
            if(t[i]%2==1)
            {
                cout<<i;
                return 0;
            }
        }
    }
    else
    {
        for(int i=1; i<=n; i++)
        {
            if(t[i]%2==0)
            {
                cout<<i;
                return 0;
            }
        }
    }

    return 0;
}