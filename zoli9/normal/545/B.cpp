#include <iostream>
using namespace std;
string s, t;
int n, tav;
int a[100009];
int b[100009];
int main()
{
    cin>>s>>t;
    tav=0;
    n=s.length();
    for(int i=0; i<n; i++)
    {
        a[i+1]=s[i]-'0';
        b[i+1]=t[i]-'0';
        if(a[i+1]!=b[i+1])
        {
            tav++;
        }
    }
    if(tav%2)
    {
        cout<<"impossible";
        return 0;
    }
    tav=0;
    for(int i=1; i<=n; i++)
    {
        if(a[i]==b[i])
        {
            cout<<a[i];
        }
        else
        {
            if(tav%2)
            {
                cout<<a[i];
            }
            else
            {
                cout<<b[i];
            }
            tav++;
        }
    }
    return 0;
}