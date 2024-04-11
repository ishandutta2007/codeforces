#include <iostream>
using namespace std;
int n, t, a, akt;
int main()
{
    akt=1;
    cin>>n>>t;
    if(t==1)
    {
        cout<<"YES";
        return 0;
    }
    for(int i=1; i<=n-1; i++)
    {
        cin>>a;
        if(akt==i)
        {
            akt+=a;
        }
        if(akt==t)
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;



    return 0;
}