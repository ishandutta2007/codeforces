#include <iostream>
using namespace std;
int k, h, x;
string s;
int main()
{
    cin>>s;
    cin>>k;
    h=s.length();
    if(h%k!=0)
    {
        cout<<"NO";
        return 0;
    }
    x=h/k;
    int j=0;
    for(int i=1; i<=k; i++)
    {
        for(int u=0; u<x; u++)
        {
            if(s[j]!=s[i*x-u-1])
        {
            cout<<"NO";
            return 0;
        }
        j++;
        }

    }
    cout<<"YES";
    return 0;
}