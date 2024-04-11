#include <iostream>
using namespace std;
int n, s, a, b;
int maxi=-1;
int main()
{
    cin>>n>>s;
    for(int i=1; i<=n; i++)
    {
        cin>>a>>b;
        if(b==0)
        {
            if(s>=a)
            {
               maxi=max(maxi, 0);
            }
        }
        else
        {
            if(s>a)
            {
                maxi=max(maxi, 100-b);
            }
        }
    }
    cout<<maxi;
    return 0;
}