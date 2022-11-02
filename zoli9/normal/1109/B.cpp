#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>s;
    n=s.size();
    bool lehet=false;
    for(int i=0; i<n; i++)
    {
        if(s[i]!=s[0])
        {
            if(n%2==0)
            {
                lehet=true;
            }
            else
            {
                if(i!=n/2) lehet=true;
            }
        }
    }
    if(!lehet)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    for(int kezd=1; kezd<n; kezd++)
    {
        bool elter=false;
        bool pal=true;
        for(int j=0; j<n/2; j++)
        {
            if(s[(kezd+j)%n]!=s[(kezd+n-j-1)%n])
            {
                pal=false;
                break;
            }
            if(elter) continue;
            if(s[(kezd+j)%n]!=s[j] || s[(kezd+n-j-1)%n]!=s[n-j-1]) elter=true;
        }
        if(pal && elter)
        {
            cout<<1<<endl;
            return 0;
        }
    }
    cout<<2<<endl;
    return 0;
}