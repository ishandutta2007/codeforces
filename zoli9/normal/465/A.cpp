#include <iostream>
using namespace std;
int n;
char c[109];
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>c[i];
    }
    int ans=0;
    for(int i=0; i<n; i++)
    {
        if(c[i]=='0')
        {
            cout<<ans+1;
            return 0;
        }
        else
        {
            ans++;
            if(i==n-1)
            {
                cout<<ans;
                return 0;
            }
        }
    }

    return 0;
}