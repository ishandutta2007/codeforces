#include <bits/stdc++.h>
using namespace std;
long long n;
char c;
long long ans=0;
map<char, long long> ma;
int main()
{
    ma['f']=1;
    ma['e']=2;
    ma['d']=3;
    ma['a']=4;
    ma['b']=5;
    ma['c']=6;
    cin>>n>>c;
    if(n%4==1)
    {
        ans+=n-1;
        long long k=(n-1)/4;
        ans+=12*k;
        ans+=ma[c];
        cout<<ans<<endl;
    }
    else if(n%4==2)
    {
        ans+=n-1;
        long long k=(n-2)/4;
        ans+=12*k;
        ans+=6;
        ans+=ma[c];
        cout<<ans<<endl;
    }
    else if(n%4==3)
    {
        ans+=n-3;
        long long k=(n-3)/4;
        ans+=12*k;
        ans+=ma[c];
        cout<<ans<<endl;
    }
    else
    {
        ans+=n-3;
        long long k=(n-4)/4;
        ans+=12*k;
        ans+=6;
        ans+=ma[c];
        cout<<ans<<endl;
    }


    return 0;
}